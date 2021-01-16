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

void print(struct node *temp) {
	 
	static int flag = 0;
	if (temp != head || flag == 0) {
		flag = 1;
		printf("The data is %d\n", temp->data);
		print(temp->next);
	}
	flag = 0;
}
int main()
{
	create();
	print(head);
	getch();
	return 0;
}
