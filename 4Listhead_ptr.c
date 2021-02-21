/* refer https://github.com/hasancse91/data-structures/blob/master/Source%20Code/Linked%20List%20%5Bcreate%2C%20insert%2C%20delete%2C%20search%5D.c */
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int number;
    struct node *next;
};
struct head
{
    struct node *head_ptr;
    int num;
};
typedef struct node node;
node *last=NULL;
*head_ptr=NULL;
num=0;

void create_node();
void print_node();
void insert_at_last(int value);
void insert_at_first(int value);
void insert_after(int key, int value);
void delete_item(int value);

int main()
{
    int key, value,c;
    while(1)
    {
        printf("Menu\n");
        printf("1.Create Linked List\n2.Insert new item at last\n3.Insert new item at first\n4.Insert after an element\n5.Delete an element\n6.Display\n7.Exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: create_node();
                    break;
            case 2: printf("Enter the element to insert\n");
                    scanf("%d", &value);
                    insert_at_last(value);
                    break;
            case 3: printf("Enter the element to insert\n");
                    scanf("%d", &value);
                    insert_at_first(value);
                    break;
            case 4: printf("Enter the key element\n");
                    scanf("%d", &key);
                    printf("\nInsert new item after %d KEY\n", key);
                    scanf("%d", &value);
                    insert_after(key, value);
                    break;
            case 5: printf("\nEnter a value, which you want to delete from list\n");
                    scanf("%d", &value);
                    delete_item(value);
                    break;
            case 6: print_node();
                    break;
            case 7: exit(0);

        }
    }


    return 0;
}


/*
    User Defined Functions
*/
void create_node()
{
    int val;

    while(1)
    {
        printf("Input a number. (Enter -1 to exit)\n");

        scanf("%d", &val);

        if(val==-1)
            break;

        insert_at_last(val);

    }


}


void insert_at_last(int value)
{
    node *temp_node;
    temp_node = (node *) malloc(sizeof(node));

    temp_node->number=value;
    temp_node->next=NULL;

    //For the 1st element
    if(head_ptr==NULL)
    {
        head_ptr=temp_node;
        last=temp_node;
    }
    else
    {
        last->next=temp_node;
        last=temp_node;
    }
    num++;

}


void insert_at_first(int value)
{
    node *temp_node = (node *) malloc(sizeof(node));

    temp_node->number=value;
    temp_node->next = head_ptr;

    head_ptr = temp_node;
    num++;
}

void insert_after(int key, int value)
{
    node *myNode = head_ptr;
    int flag = 0;

    while(myNode!=NULL)
    {
        if(myNode->number==key)
        {
            node *newNode = (node *) malloc(sizeof(node));
            newNode->number = value;
            newNode->next = myNode->next;
            myNode->next = newNode;

            printf("%d is inserted after %d\n", value, key);

            flag = 1;
            num++;

            break;
        }
        else
            myNode = myNode->next;

    }

    if(flag==0)
        printf("Key not found!\n");

}


void delete_item(int value)
{
    node *myNode = head_ptr, *previous=NULL;
    int flag = 0;

    while(myNode!=NULL)
    {
        if(myNode->number==value)
        {
            if(previous==NULL)
                head_ptr = myNode->next;
            else
                previous->next = myNode->next;

            printf("%d is deleted from list\n", value);
            num--;
            flag = 1;
            free(myNode); //need to free up the memory to prevent memory leak
            break;
        }

        previous = myNode;
        myNode = myNode->next;
    }

    if(flag==0)
        printf("Key not found!\n");
}



void print_node()
{
    printf("\nYour full linked list is\n");

    node *myList;
    myList = head_ptr;

    while(myList!=NULL)
    {
        printf("%d ", myList->number);

        myList = myList->next;
    }
    puts("");
    printf("Total number of elements are %d",num);
    puts("");
}
