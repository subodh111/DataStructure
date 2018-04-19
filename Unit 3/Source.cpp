#include "AVLTree.h"
#include <iostream>

using namespace std;

int main()
{
	    AVLTree a;
		a.append(2);
		a.append(3);
		a.append(4);
		a.append(5);
		a.append(6);		
		a.print();
		cout << endl;
		cout << "Found number:" << a.find(3);
		cout << endl;
		cout << "Found number:" << a.find(0);
		cout << endl;
		cout << endl;
		cout << "isFull:" << a.isFull();
		cout << endl;
		cout << "isEmpty:" << a.isEmpty();
		cout << endl;	
		a.print();
		cout << endl;
		a.print();
		cout << endl;
		a.print();
		cout <<"dd"<< endl;
		cout<< a.count();		
		a.clear();
		a.print();
		
		 

	}
	