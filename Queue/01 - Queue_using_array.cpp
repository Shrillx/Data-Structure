#include <iostream>
using namespace std;

struct queue {
	int first;
	int rear;
	int size;
	int *A;
};


void enqueue(struct queue *qu, int value)	//this function adds value to the queue 
{
	if (qu->first == qu->size)
	{
		cout << "Queue is full" << endl;
	}
	else
	{
		qu->A[qu->rear] = value;
		qu->rear++;
	}
}

int dequeue(struct queue *qu) // this function removes a value form queue
{
	int x;
	if (qu->first > qu->rear)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		x = qu->A[qu->first++];
		return x;
	}
}

void is_Empty() // this function checks that is the queue empty or not
{
	struct queue qu;

	if ( (qu.rear == qu.first) || (qu.rear == -1))
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		cout << "Queue is not empty" << endl;
	}
}

void display (struct queue qu)		//this function displays the values in quueus 
{
	
	if ((qu.rear == qu.first) || (qu.rear == -1))
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		for (int i = qu.first; i < qu.rear; i++)
		{
			cout << qu.A[i] << endl;
		}
	}
}

void create(struct queue *qu)		//this function creates the inital queue which can be later modified 
{
	qu->size = 5;
	qu->A = new int[sizeof(int)*qu->size];
	qu->first = -1;
	qu->rear = -1;
}

int main()
{
	struct queue qu;

	create(&qu);
	enqueue(&qu, 10);
	enqueue(&qu, 20);
	enqueue(&qu, 30);
	enqueue(&qu, 40);
	enqueue(&qu, 50);
	display(qu);

	cout << "The deleted value is " << dequeue(&qu) << endl;
	cout << "The deleted value is " << dequeue(&qu) << endl;
	cout << "The deleted value is " << dequeue(&qu) << endl;

	system("pause");
	return 0;
}
