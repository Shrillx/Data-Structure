#include <iostream>
#include <conio.h>
using namespace std;

struct stack
{
	int size;
	int *A;
	int top;
};

int peek(struct stack st,int position) //used to peek the value
{
	if (st.top - position + 1 < 0) cout << "Invalid Request";
	else return st.A[st.top - position + 1];
}

int is_full(struct stack *st)	// to check stack is full
{
	if (st->top++ == st->size) return 1;
	return 0;
}

int is_Empty(struct stack *st) //to check stack is empty
{
	if (st->top == -1) return 1;
	return 0;
}

int stack_top(struct stack *st) // to find the top element
{
	if (st->top == -1) return -1;
	return st->A[st->top];
}

int pop (struct stack *st) // to delete a number
{
	int x;
	if (st->top == -1) 
	{
		cout << "Stack Underflow" << '\n';
	}
	else x = st->A[st->top--];

	return x;
}

void push(struct stack *st, int value) // to push a value
{
	if (st->top >= st->size-1) cout << "Stack Overflow" << '\n';
	else
	{
		st->top++;
		st->A[st->top] = value;
	}
}

void display(struct stack *st) // to display stack 
{
	int i = st->top;
	if (st->top == -1) cout << "Stack is Empty" << '\n';
	else 
	{ 
		while (i >= 0)
		{
			cout << st->A[i] << " ";
			i--;
		}
	}
	getch();
}

void create(struct stack *st)		//creates the stack
{
	cout << "Enter the size of array : ";
	cin >> st->size;
	st->A = (int *)malloc(sizeof(int) * st->size-1);
	st->top = -1;
	
}

int main()
{
	struct stack st;
	create(&st);

	int choice;
	int i,j;
	do 
	{
		system("cls");
		cout << "Please select any operation : " << '\n';
		cout << " 1.Push\n" << " 2.Pop\n" << " 3.Display\n" << " 4.Stack Top\n" << " 5.Check Empty\n" << " 6.Check Full\n" << " 7.Peek\n"<< " 8.Exit\n" << "Enter You Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1: cout << "Enter value to be pushed : "; cin >> i;
			push(&st, i);
			break;
		case 2: cout << "Deleted Element " << pop(&st);
			break;
		case 3: display(&st);
			break;
		case 4: if (stack_top(&st) == -1) cout << "Stack is Empty" << '\n';
				else cout << "Stack top is " << stack_top(&st) << '\n';
				break;
		case 5: if (is_Empty(&st)) cout << "Stack is Empty" << '\n'; 
				else cout << "Stack is not Empty" << '\n';
		 		break;
		case 6: if (is_full(&st)) cout << "Stack is Full" << '\n';
				else cout << "Stack is Empty" << '\n';
				break;
		case 7: cout << "Enter the position to check : ";
				cin >> j;
				cout << "The data at " << j << " is " << peek(st, j) << '\n';
				break;
		default: cout << "Enter Valid Choice" << '\n';
			break;
		}
	} while (choice != 8);
	system("pause");
}
