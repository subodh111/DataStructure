#ifndef MyIntDeque_h
#define MyIntDeque_h
#include <iostream>
class MyIntDeque
{
private:
	struct Node
	{
		int value;
		Node* next;
		Node* prev;

		Node(int val, Node* prev = NULL, Node* next = NULL)
		{
			this->value = val;
			this->prev = prev;
			this->next = next;
		}
	};

	Node* frontptr;
	Node* backptr;

public:
	MyIntDeque()
	{
		frontptr = NULL;
		backptr = NULL;
	}

	~MyIntDeque()
	{
		clear();
	}

	void push_back(int val)
	{
		Node* n = new Node(val, backptr, NULL);

		if (frontptr == NULL)//adding 1st node
			frontptr = n;
		else
			backptr->next = n;
		backptr = n;
	}

	void push_front(int val)
	{
		Node* n = new Node(val, NULL, frontptr);

		if (backptr == NULL)//adding 1st node
			backptr = n;
		else
			frontptr->prev = n;
		frontptr = n;
	}

	void pop_back()
	{
		if (!isEmpty())
		{
			Node* temp = backptr;
			backptr = backptr->prev;
			delete temp; //delete the old last node
			if (backptr != NULL) //there is atleast some node in hte deque, upate the new backptr's next to point ot NULLL
				backptr->next = NULL;
			else //Now the deque is empty
				frontptr = NULL;
		}
	}

	void pop_front()
	{
		if (!isEmpty())
		{
			Node* temp = frontptr;
			frontptr = frontptr->next;
			delete temp; //delete the old frontptr node
			if (frontptr != NULL) //there is atleast some node in hte deque, upate the new frontptr's previous to point ot NULLL
				frontptr->prev = NULL;
			else //Now the deque is empty
				backptr = NULL;
		}
	}

	int size()
	{
		int count = 0;
		Node* curr = frontptr;
		while (curr != NULL)
		{
			count++;
			curr = curr->next;
		}
		return count;
	}

	int front()
	{
		if (isEmpty())
			return -1;
		else
			return frontptr->value;

	}

	int back()
	{
		if (isEmpty())
			return -1;
		else
			return backptr->value;
	}

	bool isFull()
	{
		//try creating a temporary and see if we are able to create more nodes. If not return false.
		Node* temp = new Node(0);
		if (temp == NULL)
			return true;
		else
		{
			delete temp;
			return false;
		}
	}

	bool isEmpty()
	{
		if (frontptr == NULL)
			return true;
		else
			return false;
	}
	void clear()
	{
		while (!isEmpty())
			pop_front();

		frontptr = NULL;
		backptr = NULL;
	}

};
#endif 