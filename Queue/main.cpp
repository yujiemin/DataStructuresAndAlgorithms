
#include "ArrayQueue.h"
#include "ListQueue.h"

int main()
{
	LQueue<int> lQueue;
	lQueue.EnQueue(1);
	lQueue.EnQueue(2);
	lQueue.DeQueue();
	lQueue.DeQueue();
	lQueue.DeQueue();
	lQueue.Display();

	return 0;
}

int main1()
{
	AQueue<int, 5> aQueue;
	aQueue.EnQueue(1);
	aQueue.EnQueue(2);
	aQueue.EnQueue(3);
	aQueue.EnQueue(4);
	aQueue.EnQueue(5);

	aQueue.Display();
	aQueue.DeQueue();
	aQueue.Display();
	aQueue.EnQueue(6);
	aQueue.EnQueue(7);
	aQueue.Display();
	aQueue.DeQueue();
	aQueue.DeQueue();
	aQueue.Display();
	aQueue.EnQueue(8);
	aQueue.Display();
	aQueue.Clear();
	aQueue.Display();

	aQueue.DisplayAll();

	return 0;
}