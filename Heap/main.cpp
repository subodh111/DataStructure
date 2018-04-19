#include "PQueue.h"
#include <iostream>

int main()
{	//max on the top
	PQueue q(7);
	q.enqueue(32);
	q.enqueue(52);
	q.enqueue(5);
	q.enqueue(8);
	q.enqueue(49);
	q.dequeue();
	q.dequeue();

	
	
	cout <<"the top is  "<< q.top()<<endl;

}

