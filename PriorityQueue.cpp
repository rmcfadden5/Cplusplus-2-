#include<stdio.h> 
#include<stdlib.h> 
#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	int priority;
	struct node* next;
	node*front = NULL;
	node*rear = NULL;
}Node;


Node* newNode(int data, int priority)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->priority = priority;
	temp->next = NULL;
	return temp;
}

void dequeue(Node** head)
{
	Node* temp = *head;
	(*head) = (*head)->next;
}

void enqueue(Node** head, int data, int pointer)
{
	Node*front = (*head);

	Node* temp = newNode(data, pointer);

	while (front->next != NULL && front->next->priority < pointer)
	{
		front = front->next;
	}

	temp->next = front->next;
	front->next = temp;
}

int peek(Node** top)
{
	return (*top)->data;
}

void display(Node*queue)
{
	while (queue != NULL)
	{
		cout << queue->data << " ";
		dequeue(&queue);
	}
}


int main()
{
	Node* queue = newNode(10, 1);
	enqueue(&queue, 30, 3);
	enqueue(&queue, 20, 2);
	enqueue(&queue, 50, 5);
	enqueue(&queue, 40, 4);
	dequeue(&queue);
	enqueue(&queue, 10, 6);
	display(queue);
	system("pause");
	return 0;
}
