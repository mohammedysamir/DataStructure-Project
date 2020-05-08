#pragma once
#include<iostream>
using namespace std;
template<typename T>
struct Node{
	T data;
	Node* next;
};

template<typename T>
class LinkedList {
Node<T>* front, * last;
int length;
void removefirst(){
	if (isEmpty())
		cout << "empty list can't be removed" << endl;
	else if (length == 1)
	{
		delete front;
		front = last = NULL;
	}
	else {
		Node<T>* current = front;
		front = front->next;
		delete current;
	}
	length--;
}
void removelast(){
	if (isEmpty())
		cout << "empty list can't be removed" << endl;
	else if (length == 1)
	{
		delete last;
		front = last = NULL;
	}
	else {
		Node<T>* current = front->next;
		Node<T>* pre = front;
		while (current != last)
		{
			pre = current;
			current = current->next;
		}
		delete current;
		pre->next = NULL;
		last = pre;

	}
	length--;
}
void insertfirst(T element) {
	Node<T>* newnode = new Node<T>;
	newnode->data = element;
	if (length == 0) {
		front = last = newnode;
		newnode->next = NULL;
	}
	else
	{
		newnode->next = front;
		front = newnode;
	}
	length++;
}
void insertlast(T element){
	Node<T>* newnode = new Node<T>;
	newnode->data = element;
	if (length == 0) {
		newnode->next = NULL;
		front = last = newnode;
	}
	else {
		last->next = newnode;
		newnode->next = NULL;
		last = newnode;
	}
	length++;
}
bool isEmpty() {
	return length == 0;
}
public:
	LinkedList() { front = last = NULL; length = 0; }
	void insert(T value){
	//check if it's a first element
		if (isEmpty())
			insertfirst(value);
		else
			insertlast(value);
			
	}
	void deleteval(T element){
		if (isEmpty())
			cout << "empty list can't be removed" << endl;
		Node<T>* current;
		Node<T>* pre;
		if (front->data == element)
		{
			removefirst();
			if (length == 0)
				last = NULL;
		}
		else {
			current = front->next;
			pre = front;
			while (current != NULL && current->data != element) {
				pre = current;
				current = current->next;
			}
			if (current == NULL) {
				cout << "not found" << endl;
			}
			else {
				pre->next = current->next;
				if (last == current)
					last = pre;
				delete current;
				length--;

			}
		}
	}
	void insertpos(int index,T element){
		Node<T>* newnode = new Node<T>();
		newnode->data = element;
		Node<T>* current = front;
		if (index<0 || index>length)
			cout << "out of range" << endl;
		else {
			Node<T>* newnode = new Node<T>();
			newnode->data = element;
			if (index == 0)
				insertfirst(element);
			else if (index == length)
				insertlast(element);
			else {
				Node<T>* current = front;
				for (int i = 1; i < index; i++)
					current = current->next;
				newnode->next = current->next;
				current->next = newnode;
			}
			length++;
		}
	}
	void deletepos(int index){
		//check boundries
	if(index<0||index>length)
		cout << "out of range" << endl;
	else {
		if (index == 0)
			removefirst();
		if (index == length)
			removelast();
		Node<T>* pre = front;
		Node<T>* current = front->next;
		for (int i = 1; i < index; i++)				//move current
		{
			current = current->next;
		}
		pre = current;
		current = current->next;
		pre->next = current->next;
		delete current;
	}
	}
	static void print(Node<T>* f) {
		while (f != NULL) {
			cout << f->data << " ";
			f = f->next;
		}
		cout << endl;
	}
	Node<T>* getfront() { return front; }
	Node<T>* getlast() { return last; }
	static void concatenate(Node<T>* a, Node<T>* b) {
		a->next = b;
		LinkedList::print(a);
	}
};
