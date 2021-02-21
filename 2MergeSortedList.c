/* Consider two liked list A and B in sorted order. Write a program to merge the linked list A and B such that the final list C is in sorted order.
refer http://www.techiedelight.com/merge-given-sorted-linked-lists/ */

#include <stdio.h>
#include <stdlib.h>

// Data Structure to store a linked list node
struct Node
{
	int data;
	struct Node* next;
};

// Helper function to print given linked list
void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");
}

// Helper function to insert new Node in the beginning of the linked list
void push(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

// Function that takes the node from the front of the source, and move it
// to the front of the destination
void MoveNode(struct Node** destRef, struct Node** sourceRef)
{
	// if the source list empty, do nothing
	if (*sourceRef == NULL)
		return;

	struct Node* newNode = *sourceRef;  // the front source node

	*sourceRef = (*sourceRef)->next;	// Advance the source pointer

	newNode->next = *destRef;   	// Link the old dest off the new Node
	*destRef = newNode; 			// Move dest to point to the new Node
}

// Takes two lists sorted in increasing order, and merge their nodes
// together to make one big sorted list which is returned
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
	// a dummy first node to hang the result on
	struct Node dummy;
	dummy.next = NULL;

	// Points to the last result node -- so tail->next is the place
	// to add new Nodes to the result.
	struct Node* tail = &dummy;

	while (1)
	{
		// if either list runs out, use the other list
		if (a == NULL)
		{
			tail->next = b;
			break;
		}
		else if (b == NULL)
		{
			tail->next = a;
			break;
		}

		if (a->data <= b->data)
			MoveNode(&(tail->next), &a);
		else
			MoveNode(&(tail->next), &b);

		tail = tail->next;
	}

	return dummy.next;
}

// main method
int main(void)
{
	// input keys
	int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(keys)/sizeof(keys[0]);

	struct Node *a = NULL, *b = NULL;
	for (int i = n - 1; i >= 0; i = i - 2)
		push(&a, keys[i]);

	for (int i = n - 2; i >= 0; i = i - 2)
		push(&b, keys[i]);

	// print both linked list
	printf("A List  :  ");
	printList(a);

	printf("B List : ");
	printList(b);

	struct Node* head = SortedMerge(a, b);
	printf("After Merge C List: ");
	printList(head);

	return 0;
}
