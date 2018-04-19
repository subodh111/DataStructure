#include "MyIntDeque.h"
#include <iostream>
using namespace std;


int main()
{
	MyIntDeque v;
	v.push_back(8);
	v.push_back(99);
	v.push_front(78);
	v.push_back(66);
	v.push_front(33);
	v.push_front(00);
	v.pop_back();
	v.pop_front();
	cout <<"front "<< v.front()<<endl;
	cout << "back " << v.back();

}