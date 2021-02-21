/* Write a program to insert N employee information into the Binary tree. Write a function to
a. Search an Employee and display his details.
b. Display the Average salary of Employees between the age 20 and 25.
refer https://cboard.cprogramming.com/c-programming/160746-company-employees-using-binary-trees.html*/
# include <stdio.h>
# include <stdlib.h>

typedef struct BST
{
    int data;
    char name[20];
    int age;
    int id;
    int salary;
    struct BST *lchild,*rchild;
}node;



void insert(node *,node *);
void *search(node *,int);
int *average(node *);

void main()
{
 int choice;
 char ans='N';
 int key;
 node *new_node,*root,*tmp,*parent;
 node *get_node();
 root=NULL;

 printf("\nEmployees list \n");
 do
 {
   printf("\n1.Create");
   printf("\n2.Search");
   printf("\n3.Display the Average salary of Employees between the age 20 and 25");
   printf("\n4.Exit");
   printf("\n\nEnter your choice: ");
   scanf("%d",&choice);

   switch(choice)
   {
    case 1:
           do
             {
             new_node=get_node();

             printf("\nInformation about employee with id number: ");
             scanf("%d",&new_node->data);
             printf("\n    Name: ");
             scanf("%s",&new_node->name);
             printf("\n    Age: ");
             scanf("%d",&new_node->age);
             printf("\n    Monthly salary: ");
             scanf("%d",&new_node->salary);

             if(root==NULL)   /* Tree is not Created */
                 root=new_node;
             else
                 insert(root,new_node);

             printf("\nDo you wish to enter a new employe?(y/n)");
             ans=getch();

             }while(ans=='y');

             break;

     case 2:
             printf("\Enter the employee id number you're looking for: ");
             scanf("%d",&key);
             search(root,key);
             break;

    case 3: printf("Average salary of employees between the age 20 and 25 is %d",average(root));
            break;
    }
 }while(choice!=4);
}
/*
  Get new Node
*/
node *get_node()
 {
 node *temp;
 temp=(node *)malloc(sizeof(node));
 temp->lchild=NULL;
 temp->rchild=NULL;
 return temp;
 }
/*
  This function is for creating a binary search tree
*/
void insert(node *root,node *new_node)
{
  if(new_node->data < root->data)
     {
     if(root->lchild==NULL)
         root->lchild = new_node;
     else
         insert(root->lchild,new_node);
     }

  if(new_node->data > root->data)
     {
     if(root->rchild==NULL)
         root->rchild=new_node;
     else
         insert(root->rchild,new_node);
     }
}
/*
This function is for searching the node from
      binary Search Tree
*/
void *search(node *root,int key)
{
 node *temp;
 temp=root;
    while(temp!=NULL)
    {

      if(temp->data==key)
         {
         printf("\n Employe with id number %d is present\n",temp->data);
         printf("Employee name: ");
         puts(temp->name);
         printf("Id : %d\nAge: %d\nSalary : %d \n",temp->data,temp->age,temp->salary);
         return;
         }
     //*parent=temp;

      if(temp->data>key)
         temp=temp->lchild;
      else
         temp=temp->rchild;
    }
    printf("\n Employee with id number %d is not present\n",key);
}

int *average(node *root)
{
    int avg=0,e=0;
 node *temp;
 temp=root;
    while(temp!=NULL)
    {

      if(temp->age>19 && temp->age <26)
         {
            avg=avg+temp->salary;
         }
     //*parent=temp;

            temp=temp->rchild;

    }
    return avg;

}
