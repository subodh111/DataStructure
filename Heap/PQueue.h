#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>
using namespace std;

	class PQueue
	{

	private:
	int* heap;
	int size;
	int bottom;
	void ReHeapUp();
	void ReHeapDown();	
	public:
	PQueue(int s);
	~PQueue();
	void enqueue(int);
	void dequeue();
	int top() const;	

	};

	//constructor - accepts an integer as it's only argument and dynamically allocates an array with that many elements,
	//stores the argument in size, and initializes bottom to -1.  Address of the new array is stored in heap.
	PQueue::PQueue(int s) {

		size = s;
		heap = new int[size];
		bottom = -1;
	}

	//destructor - deallocates the array
	PQueue::~PQueue()
	{
		delete[] heap;
	}

	//enqueue - if there's enough free space in the heap, adds it's argument to the heap.
	void PQueue::enqueue(int value)
	{
		if (bottom != size - 1)
		{

			bottom = bottom + 1;
			heap[bottom] = value;
			ReHeapUp();
		}
	}
	//dequeue - if the heap isn't empty, removes the top of the heap from the heap.
	void PQueue::dequeue()
	{
		if (bottom > -1)
		{
			int temp = heap[0];
			heap[0] = heap[bottom];
			heap[bottom] = temp;

			bottom = bottom - 1;
			ReHeapDown();
		}
	}

	//top - returns a copy of the value on the top of the heap, doesn't change the heap in any way.  Returns -1 if the heap is empty.
	int PQueue::top()const {
		if (bottom != -1)
			return heap[0];
		else
			return -1;
	}

	//ReHeapUp - called by enqueue to rebuild the heap.
	void PQueue::ReHeapUp()
	{
		int btemp = bottom;
		int p;
		while (btemp != 0)
		{
			p = (btemp - 1) / 2;
			if (heap[p] < heap[btemp])
			{
				int x = heap[p];
				heap[p] = heap[btemp];
				heap[btemp] = x;
			}
			else
				break;

			btemp = p;
		}

	}

	//ReHeapDown - called by dequeue to rebuild the heap.
	void PQueue::ReHeapDown()
	{
		int bc;
		int p = 0;
		while (true)
		{ 
			int lc = 2 * p + 1;
			int rc = 2 * p + 2;
			if (lc > bottom)
				break;

			if (rc <= bottom)
			{
				if (heap[lc] < heap[rc])
					bc = rc;
				else
					bc = lc;
			}
			else
				bc = lc;
			if (heap[p] < heap[bc])
			{
				int tp = heap[p];
				heap[p] = heap[bc];
				heap[bc] = tp;
			}
			else
				break;

			p = bc;

		}
	}
	
#endif