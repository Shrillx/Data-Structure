#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
	struct node* prev;
	int data;
	struct node* next;
}*head,*middle,*end;

int main()
{
	head = (struct node*) malloc(sizeof(struct node));
	middle = (struct node*) malloc(sizeof(struct node));
	end = (struct node*) malloc(sizeof(struct node));

	struct node* p;
	//inserting data in all the three nodes i.e, head, middle, end;

	head->data = 10;
	middle->data = 20; 
	end->data = 30;

	//now linking the node to the forward node

	head->next = middle;
	middle->next = end;
	end->next = NULL;

	//now linking the node to the previous node

	head->prev = NULL;
	middle->prev = head;
	end->prev = middle;

	//now printing the node in a forward way
	p = head;
	printf("The data in the forward directon is: \n");
	while (p != NULL)
	{
		printf("The data is = %d\n", p->data);
		p = p->next;
	}
	
	p = end;
	printf("The data in the backward direction is: \n");
	while (p != NULL)
	{
		printf("The data is = %d\n", p->data);
		p = p->prev;
	}
	getch();
	return 0;
}
