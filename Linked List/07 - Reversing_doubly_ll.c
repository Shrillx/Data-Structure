	#include <stdio.h>
	#include <conio.h>
	#include <stdlib.h>

	struct node {
		struct node* prev;
		int data;
		struct node* next;
	}*head, *last;

	void append()
	{
		struct node *temp;

		if (head == NULL)
		{
			head = (struct node*) malloc(sizeof(struct node));
			printf("Please enter data: ");
			scanf("%d", &head->data);
			head->prev = NULL;
			head->next = NULL;
			last = head;
		}
		else
		{
			temp = (struct node*) malloc(sizeof(struct node));
			printf("Please enter data: ");
			scanf("%d", &temp->data);
			temp->prev = last;
			last->next = temp;
			temp->next = NULL;
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

	void reverse(struct node *p)
	{
		//reversing the linked lists
		struct node *temp;
		while (p)
		{
			temp = p->next;
			p->next = p->prev;
			p->prev = temp;

			if (p != NULL && p->next == NULL)
			{
				head = p; 
			}
		}
	}

	int main()
	{
		int choice;
		int index;
		do
		{
			system("cls");
			printf("Please select you option:\n");
			printf(" 0.Exit \n 1.Append\n 2.Display\n 3.Delete\nEnter your choice: ");
			scanf("%d", &choice);

			switch (choice)
			{
			case 0: printf("Thank-you !!!");
				break;
			case 1: append();
				break;
			case 2: reverse(head); display(head);
				break;
			case 3: printf("Enter the index: ");
				scanf("%d", &index);
				deleteNode(index);
				break;
			case 4:
				break;
			}
		} while (choice != 0);
		getch();
		return 0;
	}
