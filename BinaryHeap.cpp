#include <stdio.h>
#include <iostream>
using namespace std;
void insertInToHeap(int A[], int n)
{
	int i = n, temp;
	temp = A[i];
	while (i > 1 && temp > A[i / 2])
	{
		A[i] = A[i / 2];
		i = i / 2;
	}
	A[i] = temp;
}
int deleteFromHeap(int A[], int n)
{
	int i, j, x, temp, val;
	val = A[1];
	x = A[n];
	A[1] = A[n];
	A[n] = val;
	i = 1, j = i * 2;
	while (j < n - 1)
	{
		if (A[j + 1] > A[j])
			j = j + 1;
		if (A[i] < A[j])
		{
			swap(A[i], A[j]);
			i = j;
			j = 2 * j;
		}
		else 
		break;
	}
	return n;
}

void printHeap(int H[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", H[i]);
		printf(" ");
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	int H[] = { 0,10,20,30,25,5,40,35 };
	insertInToHeap(H,2);
	insertInToHeap(H,3);
	insertInToHeap(H,4);
	insertInToHeap(H,5);
	insertInToHeap(H,2);
	for (int i = 2; i <= 7; i++)
		insertInToHeap(H, i);

	//Output is 40, 25, 35, 10, 5, 20, 30
	printHeap(H, 7);

	printf("Deleted value is %d\n", deleteFromHeap(H,7));
	printHeap(H,7);
	printf("Deleted value is %d\n", deleteFromHeap(H,6));
	printHeap(H,7);
	for (int i = 7; i > 1; i--)
	{
		deleteFromHeap(H, i);
	}
	printf("\n");

	system("pause");
	return 0;
}
