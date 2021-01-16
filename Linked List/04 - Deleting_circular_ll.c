#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	int data;
	struct node* next;
}*last, *head;

void create() {
	int A[] = { 1,2,3,4,5 };
	struct node *temp;

	head = (struct node*) malloc(sizeof(struct node));
	head->data = A[0];
	head->next = NULL;
	last = head;

	for (int i = 1; i < 5; i++)
	{
		temp = (struct node*) malloc(sizeof(struct node));
		temp->next = NULL;
		temp->data = A[i];
		last->next = temp;
		last = temp;
	}
	last->next = head;
}

void display(struct node* p)
{
	do
	{
		printf("The data is : %d\n", p->data);
		p = p->next;
	} while (p != head);

}

void deleteNode(int n)
{
	struct node *before,*after;
	before = head;
	after = before->next;
	
	if (n == 1)
	{
		last->next = after;
		head = after;
		free(before);
	}
	else
	{
		for (int i = 1; i < n - 1; i++)
		{
			before = before->next;
			after = before->next;
		}
		before->next = after->next;
		free(after);
	}

}
int main()
{
	int choice;
	create();
	display(head);
	printf("Please enter the place where you wanna delete: ");
	scanf("%d", &choice);
	deleteNode(choice);
	display(head);
	getch();
	return 0;
}
