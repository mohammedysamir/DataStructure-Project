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
}

