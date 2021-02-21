#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[50];
    int salary;
    char desig[50];
    struct node *link;
};

typedef struct node *NODE;



NODE insert(char name[50],int salary,char desig[50],NODE first);
NODE delete(char name[50],NODE first);
void search(char key[50],NODE first);
void avg_salary(NODE first);

int main(int argc, char const *argv[])
{
    char name[50],key[50];
    int salary;
    char desig[50];

    NODE first; 
    first=NULL;

    while(1)
    {
        int ch;
        printf("1.Insert\t2.Delete\t3.Search\t4.Average Salary\t5.Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("Enter Name:");
            scanf("%s",name);
            printf("Enter salary:");
            scanf("%d",&salary);
            printf("Enter designation:");
            scanf("%s",desig);
            first=insert(name,salary,desig,first);
            
            break;
        case 2:
            printf("Enter name to be deleted:");
            scanf("%s",name);
            delete(name,first);
            
            break;
        case 3:
            printf("Enter name to be searched:");
            scanf("%s",key);
            search(key,first);
            
            break;
        case 4:
            avg_salary(first);
            break;
        case 5:
            exit(0);

        
        default:
            break;
        }

    }
    return 0;
}

NODE getnode()
{
    NODE x;
    x = (NODE*)malloc(sizeof(struct node));
    return x;
}

NODE insert(char name[],int salary,char desig[],NODE first)
{
    NODE temp;
    temp = getnode();
    temp->link = NULL;
    strcpy(temp->name,name);
    strcpy(temp->desig,desig);
    temp->salary = salary;

    temp->link=first;
    
    return temp;
}

NODE delete(char name[],NODE first)
{
    NODE cur,prev;
    cur=first;
    prev=NULL;

    if(first==NULL)
        printf("Underflow");

    if (first->link==NULL)
    {
        free(first);
        return NULL;
    }
    

    while (cur->link!=NULL)
    {
        if (cur->name==name)
        {
            prev->link=cur->link;
            free(cur);
        }

        cur=cur->link;
        prev=cur;

    }
        
}

void search(char key[],NODE first)
{
    NODE cur;
    cur=first;
   
    while (cur!=NULL)
    {
         printf("%s\n",cur->name);
         printf("%s\n",key);
        if (strcmp(cur->name,key)==0)
        {
            printf("Found!!!\n");
            printf("Name:%s\nSalary:%d\nDesignation:%s\n",cur->name,cur->salary,cur->desig);
            return;
        }

        cur=cur->link;
        
    }

    printf("Not Found!!!");
}

void avg_salary(NODE first)
{
    int total=0,count=0;
    float avg;
    NODE cur;
    cur=first;
    while (cur!=NULL)
    {
        if(strcmp(cur->desig,"mgr")==0)
        {
            total+=cur->salary;
            count++;
        }
        cur=cur->link;
    }

    avg=(float)total/(float)count;

    printf("Average salary is %f\n",avg);
    
}
