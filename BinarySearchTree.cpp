#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
struct Node
{
	struct Node *lchild;
	int data;
	struct Node *rchild;
}*root = NULL;

struct Node *iterativeInsert(struct Node *t, int key)
{
	struct Node *r = NULL, *p;
	if (t == NULL)
	{
		p = new Node;
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
		return root;
	}
	while (t != NULL)
	{
		r = t;
		if (key < t->data)
			t = t->lchild;
		else if (key > t->data)
			t = t->rchild;
	}
	p = new Node;
	p->data = key;
	p->lchild = p->rchild = NULL;
	if (key < r->data)
		r->lchild = p;
	else
		r->rchild = p;
	return p;
}

struct Node *recursiveInsert(struct Node *t, int key)
{
	struct Node *p = NULL;
	if (t == NULL)
	{
		p = new Node;
		p->data = key;
		p->lchild = p->rchild = NULL;
		return p;
	}
	if (key < t->data)
		t->lchild = recursiveInsert(t->lchild, key);
	else if (key > t->data)
		t->rchild = recursiveInsert(t->rchild, key);
	return t;
}

void inOrderRecursive(struct Node *t)
{

	if (t != NULL) {
		inOrderRecursive(t->lchild);
		cout << t->data;
		inOrderRecursive(t->rchild);
	}

}

struct Node * iterativeSearch(Node *t, int key)
{
	while (t != NULL)
	{
		if (key == t->data)
			return t;
		else if (key < t->data)
			t = t->lchild;
		else
			t = t->rchild;
	}
	return NULL;
}

struct Node * recursiveSearch(Node *t, int key)
{
	if (t == NULL)
		return NULL;
	if (key == t->data)
		return t;
	else if (key < t->data)
		return recursiveSearch(t->lchild, key);
	else
		return recursiveSearch(t->rchild, key);
}


int height(struct Node *t)
{
	int x, y;
	if (t == NULL) return 0;
	x = height(t->lchild);
	y = height(t->rchild);
	return x > y ? x + 1 : y + 1;
}

struct Node * inOrderPredecessor(struct Node *t)
{
	while (t && t->rchild != NULL)
		t = t->rchild;
	return t;
}

struct Node * inOrderSucessor(struct Node *t)
{
	while (t && t->lchild != NULL)
		t = t->lchild;
	return t;
}

struct Node* recursiveDelete(struct Node *t, int key)
{
	
		// base case 
		if (t == NULL) return t;

		// If the key to be deleted is smaller than the root's key, 
		// then it lies in left subtree 
		if (key < t->data)
			t->lchild = recursiveDelete(t->lchild, key);

		// If the key to be deleted is greater than the root's key, 
		// then it lies in right subtree 
		else if (key > t->data)
			t->rchild = recursiveDelete(t->rchild, key);

		// if key is same as root's key, then This is the node 
		// to be deleted 
		else
		{
			// node with only one child or no child 
			if (t->lchild == NULL)
			{
				struct Node *temp = t->rchild;
				free(t);
				return temp;
			}
			else if (t->rchild == NULL)
			{
				struct Node *temp = t->lchild;
				free(t);
				return temp;
			}

			// node with two children: Get the inorder successor (smallest 
			// in the right subtree) 
			struct Node* temp = inOrderSucessor(t->rchild);

			// Copy the inorder successor's content to this node 
			t->data = temp->data;

			// Delete the inorder successor 
			t->rchild = recursiveDelete(t->rchild, temp->data);
		}
		
		return t;
	}



struct Node* iterativeDelete(struct Node *t, int key)
{
	return NULL;
}


int displayMenu()
{
	int choice;
	printf("1. Iteratively insert a key into Binary Search Tree \n");
	printf("2. Recursively insert a key into Binary Search Tree \n");
	printf("3. Recursive Inorder Traversal (sorted order) \n");
	printf("4. Iteratively search for a key in Binary Search Tree \n");
	printf("5. Recursively search for a key in Binary Search Tree \n");
	printf("6. Iteratively delete the specified key from the Binary Search Tree (Bonus) \n");
	printf("7. Recursively delete the specified key from the Binary Search Tree \n");
	printf("8. Display the height of the Binary Search Tree \n");
	printf("Enter your choice (0 to  exit)\n");
	scanf_s("%d", &choice);
	return choice;
}

int main()
{
	int sel = 1;
	int key;
	struct Node *searchNode;
	while (sel = displayMenu())
	{
		printf("The option selected is %d\n", sel);
		switch (sel)
		{
		case 1:
			printf("Enter the key to insert (iterative) : ");
			scanf_s("%d", &key);
			iterativeInsert(root, key);
			cout << endl;
			break;
		case 2:
			printf("Enter the key to insert (recursively) : ");
			scanf_s("%d", &key);
			recursiveInsert(root, key);
			cout << endl;
			break;
		case 3:
			printf("Inorder traversal  :");
			inOrderRecursive(root);
			cout << endl;
			break;
		case 4:
			printf("Enter the key to search (iterative) : ");
			scanf_s("%d", &key);
			searchNode = iterativeSearch(root, key);
			if (searchNode)
				printf("Key exists in Binary Search Tree");
			else
				printf("Your key cannot be found");
			cout << endl;
			break;
		case 5:
			printf("Enter the key to search (recursive) : ");
			scanf_s("%d", &key);
			searchNode = recursiveSearch(root, key);
			if (searchNode)
				printf("Key exists in Binary Search Tree");
			else
				printf("Your key cannot be found");
			cout << endl;
			break;
		case 6:
			printf("Enter the key to delete (iterative) : ");
			scanf_s("%d", &key);
			searchNode = iterativeDelete(root, key);
			if (searchNode)
				printf("Key exists in Binary Search Tree and the key is now deleted");
			else
				printf("Your key cannot be found and therefore, cannot be deleted");
			cout << endl;
			break;
		case 7:
			printf("Enter the key to delete (recursive) : ");
			scanf_s("%d", &key);
			searchNode = recursiveDelete(root, key);
			if (searchNode)
				printf("Key exists in Binary Search Tree and the key is now deleted");
			else
				printf("Your key cannot be found and therefore, cannot be deleted");
			cout << endl;
			break;
		case 8:
			printf("The height of is : %d ", height(root));
			cout << endl;
			break;
		default:
			printf("Not a valid option\n");
		}
	}
	system("pause");
	return 0;
}
