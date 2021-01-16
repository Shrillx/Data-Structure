#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
} *head, *last;

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

void insert(int n)
{
	struct node *temp,*hold,*after;

	if (n == 0)
	{
		temp = (struct node*) malloc(sizeof(struct node));
		temp->data = 100;
		temp->next = NULL;
		last->next = temp;
		temp->next = head;
		head = temp;
	}

	else 
	{
		hold = head;
		after = hold->next;
		temp = (struct node*) malloc(sizeof(struct node));
		temp->data = 100;
		temp->next = NULL;

		while (--n > 0)
		{
			hold = hold->next;
			after = hold->next;
		}
		hold->next = temp;
		temp->next = after;
	}
}
void display(struct node* p)
{
	do
	{
		printf("The data is : %d\n", p->data);
		p = p->next;
	} while (p != head);

}
int main()
{
	int choice;
	create();
	display(head);
	printf("Please enter the place where you wanna insert: ");
	scanf("%d", &choice);
	insert(choice);
	display(head);
	getch();
	return 0;
}
