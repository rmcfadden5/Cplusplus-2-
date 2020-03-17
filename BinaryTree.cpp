#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include<stdio.h>
struct Node *root = NULL;
using namespace std;
void treeCreate()
{
	struct Node *p, *t;
	int x;
	struct Queue q;
	create(&q, 100);
	printf("Enter the root value ");
	scanf_s("%d", &x);
	root = new Node;
	root->data = x;
	root->lchild = root->rchild = NULL;
	enqueue(&q, root);
	while (!isEmpty(q))
	{
		//Write the logic here
		p = dequeue(&q);
		cout << "Enter left child of " << p->data;
		cin >> x;
		if (x != -1)
		{
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = 0;
			p->lchild = t;
			enqueue(&q, t);
			
		}
		
		cout << "Enter right child of " << p->data;
		cin >> x;
		if (x != -1)
		{
			t = new Node;
			t->data = x;
			t->lchild = t->rchild = 0;
			p->rchild = t;
			enqueue(&q, t);
			//p = dequeue(&q);
		}
	}
	dequeue(&q);
}

void preOrderRecursive(struct Node *p)
{
	if (p)
	{
		//Write the logic here
		if (p != NULL)
		{
			cout << p->data;
			preOrderRecursive(p->lchild);
			preOrderRecursive(p->rchild);
		}
	}
}
void postOrderRecursive(struct Node *p)
{
	if (p)
	{
		//Write the logic here
		if (p != NULL)
		{
			postOrderRecursive(p->lchild);
			postOrderRecursive(p->rchild);
			cout << p->data;
		}
	}
}
void inOrderRecursive(struct Node *p)
{
	if (p != NULL)
	{
		//Write the logic here

		if (p != NULL)
		{
			inOrderRecursive(p->lchild);
			cout << p->data;
			inOrderRecursive(p->rchild);
		}
	}
}

void levelOrderIterative(struct Node *p)
{
	struct Queue q;
	create(&q, 100);
	printf("%d ", p->data);
	enqueue(&q, p);
	while (!isEmpty(q))
	{
		//Write the logic here
		p = dequeue(&q);
		if (p->lchild != NULL)
		{
			cout << p->lchild->data;
			enqueue(&q, p->lchild);
		}
		if (p->rchild != NULL)
		{
			cout << p->rchild->data;
			enqueue(&q, p->rchild);
		}
	}
}

int count(struct Node *p, int degree)
{
	int x = 0;
	int y = 0;
	if (p != NULL)
	{
		x = count(p->lchild, degree);
		y = count(p->rchild, degree);
		if (degree == 0)
		{
			//Write the logic for leaves here
			if (!p->lchild && !p->rchild)
				return x + y + 1;
			else
				return x + y;
		}
		
		if (degree == 2)		
		{
			// Write logice for degree 2s here
			if (p->lchild && p->rchild)
				return x + y + 1;
			else
				return x + y;
		}

		if (degree == 1)
		{
			// Write logic for degree 1s here
			if (p->lchild != NULL ^ p->rchild != NULL)
				return x + y + 1;
			else
				return x + y;
		}

		if (degree == 2 || degree == 1)			
		{
			// Write logic for degree 1 n 2s here
			if (p->lchild || p->rchild)
				return x + y + 1;
			else
				return x + y;
		}

	}
	return 0;
}

int height(struct Node *p)
{
	//Write the logic here
	int x = 0;
	int y = 0;
	if (p == 0)
		return 0;
	x = height(p->lchild);
	y = height(p->rchild);
	if (x > y)
		return x + 1;
	else
		return y + 1;

	return 0;
}

void preOrderIterative(struct Node *p)
{
	struct Stack stk;
	stackCreate(&stk, 100);
	while (p || !isEmpty(stk))
	{
		//Write the logic here
		if (p != NULL)
		{
			cout << p->data;
			push(&stk, p);
			p = p->lchild;
		}
		else
		{
			p = pop(&stk);
			p = p->rchild;
		}
	}
}

void postOrderIterative(struct Node *p)
{
	struct Stack stk;
	stackCreate(&stk, 100);
	push(&stk, p);
		//Write the logic here
	while (!isEmpty(stk))
	{
			push(&stk, p);
			p = p->lchild;
			cout << p->data;
			p = pop(&stk);
			p = p->rchild;
			cout << p->data;
			p = pop(&stk);
			cout << p->data;
	}
}

void inOrderIterative(struct Node *p)
{
	struct Stack stk;
	stackCreate(&stk, 100);
	while (p || !isEmpty(stk))
	{
		//Write the logic here
		if (p != NULL)
		{
			push(&stk, p);
			p = p->lchild;
		}
		else
		{
			p = pop(&stk);
			cout << p->data;
			p = p->rchild;
		}
	}
}

int sumOfAllNodes(struct Node *p)
{
	//Write the logic here
	int sum = 0;
	sum = sum + p->data;
	
	struct Queue q;
	create(&q, 100);
	printf("%d ", p->data);
	enqueue(&q, p);
	while (!isEmpty(q))
	{
		//Write the logic here
		p = dequeue(&q);
		if (p->lchild != NULL)
		{
			sum = sum + p->lchild->data;
			enqueue(&q, p->lchild);
		}
		if (p->rchild != NULL)
		{
			sum = sum + p->rchild->data;
			enqueue(&q, p->rchild);	
		}
	}

	return sum;
}

int displayMenu()
{
	int choice;
	printf("1. Create the Binary Tree \n");
	printf("2. Recursive Preorder Traversal \n");
	printf("3. Iterative Preorder Traversal \n");
	printf("4. Recursive Inorder Traversal \n");
	printf("5. Iterative Inorder Traversal \n");
	printf("6. Recursive Postorder Traversal \n");
	printf("7. Iterative Postorder Traversal \n");
	printf("8. Iterative Levelorder Traversal \n");
	printf("9. Find the height of binary tree \n");
	printf("10. Find the total number of nodes in the tree \n");
	printf("11. Find the number of leaf (external) (degree 0) nodes in the tree \n");
	printf("12. Find the number of nodes with degree 1 in the tree \n");
	printf("13. Find the number of nodes with degree 2 in the tree \n");
	printf("14. Find the number of internal nodes (nodes with either degree 1 or 2) i.e., excluding leaf nodes \n");
	printf("15. Sum of all nodes in the tree \n");
	printf("16. Mirror of the tree, Bonus marks implementation \n");
	printf("Enter your choice (0 to  exit)\n");
	scanf_s("%d", &choice);
	return choice;
}

int main()
{
	int sel = 1;
	while (sel = displayMenu())
	{
		printf("The option selected is %d\n", sel);
		switch (sel)
		{
		case 1:
			treeCreate();
			cout << endl;
			break;
		case 2:
			preOrderRecursive(root);
			cout << endl;
			break;
		case 3:
			preOrderIterative(root);
			cout << endl;
			break;
		case 4:
			inOrderRecursive(root);
			cout << endl;
			break;
		case 5:
			inOrderIterative(root);
			cout << endl;
			break;
		case 6:
			postOrderRecursive(root);
			cout << endl;
			break;
		case 7:
			postOrderIterative(root);
			cout << endl;
			break;
		case 8:
			levelOrderIterative(root);
			cout << endl;
			break;
		case 9:
			printf("The height of the tree is %d ", height(root));
			cout << endl;
			cout << endl;
			break;
		case 10:
			printf("Total number of nodes in the trees : %d ", count(root, 0) + count(root, 1) + count(root, 2));
			cout << endl;
			break;
		case 11:
			printf("Number of leaf nodes (with degree 0) : %d ", count(root, 0));
			cout << endl;
			break;
		case 12:
			printf("Number of nodes with degree 1: %d ", count(root, 1));
			cout << endl;
			break;
		case 13:
			printf("Number of nodes with degree 2:  %d ", count(root, 2));
			cout << endl;
			break;
		case 14:
			printf("Number of nodes with degree 2 or 1 (internal nodes): %d ", count(root, 1) + count(root, 2));
			cout << endl;
			break;
		case 15:
			printf("Sum of all nodes is %d ", sumOfAllNodes(root));
			cout << endl;
			break;
		case 16:
			printf("Mirror the tree ");
			//call appropriate function
			cout << endl;
			break;
		default:
			printf("Not a valid option\n");
		}
	}
	//system("pause");
	return 0;
}
