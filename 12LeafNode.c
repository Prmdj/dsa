/*12. Given the root node of binary tree, write a program that will compute the following a. The number of leaf nodes
b. Total number of nodes in the tree.
c. Display all the values of the nodes
refer https://www.geeksforgeeks.org/count-full-nodes-binary-tree-iterative-recursive/*/

#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Function to get the count of leaf nodes in a binary tree*/
unsigned int getLeafCount(struct node* node)
{
  if(node == NULL)
    return 0;
  if(node->left == NULL && node->right==NULL)
    return 1;
  else
    return getLeafCount(node->left)+
           getLeafCount(node->right);
}
unsigned int getFullNodeCount(struct node* node)
{
    if (node == NULL)
       return 0;

    int res = 0;
    if  (node->left && node->right)
       res++;

    res += (getFullNodeCount(node->left) +
            getFullNodeCount(node->right));
    return res;
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}
void printPreorder(struct node* node)
{
     if (node == NULL)
          return;

     /* first print data of node */
     printf("%d ", node->data);

     /* then recur on left sutree */
     printPreorder(node->left);

     /* now recur on right subtree */
     printPreorder(node->right);
}


/*Driver program to test above functions*/
int main()
{
  /*create a tree*/

  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
    printf("The binary tree is\n");
    printf("\t1\n      2   3\n    4  5");
  /*get leaf count of the above created tree*/
  printf("\nTotal number of leaf nodes in tree is %d\n", getLeafCount(root));
  printf("\nTotal number of nodes in tree is %d\n", getLeafCount(root)+getFullNodeCount(root));
  printf("All the values of the nodes\n");
  printPreorder(root);
  getchar();
  return 0;
}
