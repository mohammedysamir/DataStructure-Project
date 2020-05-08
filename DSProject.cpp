#include <iostream>
#include"LinkedList.h"
using namespace std;
int main()
{
	LinkedList<int> first;
	first.insert(1);
	first.insert(20);
	LinkedList<int> second;
	second.insert(3);
	second.insert(4);
	LinkedList<int>::concatenate(first.getfront(), second.getfront());
	LinkedList<int>::print(first.getfront());
	first.deletepos(1);
	LinkedList<int>::print(first.getfront());
	first.deleteval(20);
	LinkedList<int>::print(first.getfront());
	first.insertpos(30,1);
	LinkedList<int>::print(first.getfront());
	first.deletepos(10);
	first.insertpos(40,11);
	return 0;
}

