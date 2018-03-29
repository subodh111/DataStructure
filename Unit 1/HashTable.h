#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<cstring>
#include <string>
#include <iostream>
using namespace std;

class HashTable {

private:
	struct Element
	{
		string key;
		int mark;
	};

	Element*  table;
	int size;
	int hash(string);
public:
	HashTable(int);
	~HashTable();
	void insert(string);
	void remove(string);
	bool isFull();
	bool isEmpty();
	void clear();
	void print();
	bool find(string);
};


//hash - The hash function.  It accepts a String as it's only argument and returns an index into the hash table.  Design your hash function any way you wish.  I gave a couple suggestions in class. 
int HashTable:: hash(string s) {
	char ch;
	int sum = 0;
	for (unsigned int i = 0; i < s.length(); i++)
	{
		ch = s.at(i);
		sum += (int)ch;
	}
	int hashvalue = (sum+1) % s.size();;
	
	return hashvalue;

}

//constructor - accepts an integer as it's only argument, creating a hash table that can store that many values (a dynamically allocated array of Elements).
HashTable::HashTable(int x)
{
	size = x;
	table = new Element[size];
	for (int i = 0; i < size; i++)
	{
		table[i].mark = 0;
	}


}

//destructor - frees all memory used.
HashTable::~HashTable()
{
	delete[] table;
}


//clear() - empties the hash table by setting each elements mark to 0.
void HashTable::clear()
{
	for (int i = 0; i < size; i++)
	{
		table[i].mark = 0;
	}

}
//insert() - accepts a string as it's only argument, which is added to the hash table, setting the element's mark where it is stored to 2.
void HashTable::insert(string s)
{

	if (!isFull())
	{
		int hv = hash(s);
		for (int i = 0; i < size; i++)
		{
			if (table[hv].mark != 2)
			{
				table[hv].key = s;
				table[hv].mark = 2;
				break;
			}
			hv = hv + 1;
		}
	}
}

//isFull() - returns true if the hash table is full, false otherwise.

bool HashTable::isFull()
{
	int i = 0;
	while (table[i].mark == 2)
	{
		i++;
		if (i == size)
		{
			return true;
		}
	}
	return false;
}

//isEmpty() - returns true if the hash table is empty, false otherwise.
bool HashTable::isEmpty()
{
	for (int i = 0; i < size; i++)
	{
		if (table[i].mark == 2)
		{
			return	false;
		}
	}
	return true;

}


//print() - displays the contents of the hash table to the screen.  That is, only the elements that are being used (marked with 2)
void HashTable::print()
{
	for (int i = 0; i < size; i++)
	{
		if (table[i].mark == 2)
		{
			cout << table[i].key << endl;
		}
	}
}


//remove() - accepts a string as it's only argument, and removes the string from the hash table (if found) by setting it's mark to 1.

void HashTable::remove(string s)
{

	if (!isEmpty())
	{
		int hv = hash(s);
		for (int i = 0; i < size; i++)
		{
			if (table[hv].mark == 2)
			{
				if (table[hv].key == s)
				{
					table[hv].mark = 1;
					return;
				}
			}
			hv = hv + 1;
		}
	}
}

//find() - accepts a string as it's only argument.  Returns true if it is found in the hash table, false otherwise.
bool HashTable::find(string s)
{
	int hv = hash(s);
	for (int i = 0; i < size; i++)
	{
		if (table[hv].mark == 2)
		{
			if (table[hv].key == s)
			{
				return true;
			}		
		}
		hv = hv + 1;
	}
	return false;
}


#endif