#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
	struct node* perv;
	int data;
	struct node* next;
}*head, *last;

void append()
{
	struct node* temp;
	if (head == NULL)
	{
		head = (struct node*) malloc(sizeof(struct node));
		head->perv = NULL;
		printf("Enter the data: ");
		scanf("%d", &head->data);
		head->next = NULL;
		last = head;
	}
	else
	{
		temp = (struct node*) malloc(sizeof(struct node));
		printf("Enter the data: ");
		scanf("%d", &temp->data);
		temp->next = NULL;
		temp->perv = last;
		last->next = temp;
		last = temp;
	}
}

void display(struct node* print)
{
	while (print != NULL)
	{
		printf("The data is = %d\n", print->data);
		print = print->next;
	}
	getch();
}

void insert(int index)
{
	struct node* temp;
	struct node *before, *after;
	before = head;
	after = before->next;

	if (index == 0)
	{
		temp = (struct node*) malloc(sizeof(struct node));
		temp->data = 100;
		temp->perv = NULL;
		temp->next = head;
		head = temp;
	}
	else
	{
		while (--index > 0)
		{
			before = before->next;
		}
		temp = (struct node*) malloc(sizeof(struct node));
		temp->data = 100;
		temp->next = before->next;
		temp->perv = before;
		if (before->next != NULL)
		{
			before->next->perv = temp;
		}
		before->next = temp;

	}
}

void deleteNode(int index)
{
	struct node *pointer = head;

	if (index == 1)
	{
		pointer = pointer->next;
		pointer->prev = NULL;
		head = pointer;
		pointer = pointer->prev;
		free(pointer);
	}
	else
	{
		while (--index > 0)
		{
			pointer = pointer->next;
		}
		pointer->prev->next = pointer->next;
		if (pointer->next)
		{
			pointer->next->prev = pointer->prev;
		}
		free(pointer);
	}
}

int main()
{
	int choice,index;

	do
	{
		system("cls");
		printf("Please select an option:\n 1.Append\n 2.Display\n 3.Exit\n 4.Insert\n 5.Delete\nYour choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: append(); break;

		case 2: display(head); break;

		case 3: printf("Thank-you !!!"); break;

		case 4: printf("Please enter the index at which you want to insert: ");
			scanf("%d", &index);
			insert(index);
			break;
         case 5: printf("Please enter the index at which you want to delete: ");
            scanf("%d", &index);
            break;
		default: printf("Enter Valid Input");
			break;
		}

	} while (choice != 3);
	getch();
	return 0;
}
