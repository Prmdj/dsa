#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left, *right, *temp;
};
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

      return node;
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;

      while (current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    struct node *temp;
    if (root == NULL) return root;

     if (key < root->key)
        root->left = deleteNode(root->left, key);

     else if (key > root->key)
        root->right = deleteNode(root->right, key);

     else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

	     temp = minValueNode(root->right);

          root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void main()
{
    /* Let us create following BST
	      50
	   /     \
	  30      70
	 /  \    /  \
    20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("Given tree is\n");
    printf("\t50\n     30    70\n  20 40  60  80");
    printf("\n\nInorder traversal of the given tree \n");
    inorder(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

}
