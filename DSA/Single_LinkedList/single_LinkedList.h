#ifndef SINGLE_LINKEDLIST
#define SINGLE_LINKEDLIST

#include <iostream>
#include <exception>

using namespace std;

template<class T>
class Node
{
public:
	T data;
	Node<T>* next;
};
template<class T>
class LinkedList
{
	Node<T>* head;

	bool isEmpty()
	{
		return (head == nullptr);
	}
public:
	LinkedList(): head(nullptr){}
	~LinkedList()
	{
		if (!head) return;
		if (head)
		{
			Node<T>* deleter = head;
			head = head->next;
			delete deleter;
		}
	}
	//Add item at the beginning of linkedList, whether linkedList is empty or include elements
	void add(T item)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = item;

		if (isEmpty())
		{
			newNode->next = nullptr;
			head = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}
	//Add item at specific location in linkedList: add item before another item.
	void addBefore(T indexValue, T newValue)
	{
		if (isEmpty() || head->data == indexValue) //if the indexValue is the only one value at the first in linkedList
		{
			add(newValue);
			return;
		}
		//check if indexValue exist
		if (!search(indexValue))
		{
			throw runtime_error("The indexValue you try insert before was not found");
		}
		Node<T>* temp = head;
		Node<T>* newNode = new Node<T>();
		newNode->data = newValue;
		while (temp->next->data != indexValue)
		{
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}

	void display()
	{
		if (isEmpty())
		{
			throw runtime_error("The list is empty, no elements for be displayed");
		}
		else
		{
			Node<T>* temp = head;
			cout << "The elements of LinkedList: "<<endl;
			while (temp != nullptr)
			{
				cout <<temp->data << endl;
				temp = temp->next;
			}
		}
	}
	int count()
	{
		if (isEmpty())
		{
			throw runtime_error("The list is empty, no elements for be counted");
		}
		int counter = 0;
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			counter++;
			temp = temp->next;
		}
		return counter;
	}
	bool search(T key)
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{ 
			if(temp->data == key)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	void append(T newValue)
	{
		if (isEmpty())
		{
			add(newValue);
		}
		else
		{
			Node<T>* temp = head;
			Node<T>* newNode = new Node<T>();
			newNode->data = newValue;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = nullptr;
		}
		//notice:
		//temp->next = nullptr : temp stand after the last node
		//temp = nullptr: temp stand at the last node
	}
	//To delete the first item in linkedList
	void deleteFirst()  
	{
		if (isEmpty())
		{
			throw runtime_error("Can't delete. the linkedList is empty");
		}
		if(head != nullptr && head->next == nullptr)  //if linkedList has one item
		{
			delete head;
			cout << "The linkedList became empty now after deleting the lonely element" << endl;
		}
		if (head)  //if linkedList has more than one element
		{
			Node<T>* deleter;
			deleter = head;
			head = head->next;
			delete deleter;
		}
	}
	//To delete specific item in linkedList
	void deleteSpecific(T item)
	{
		if (isEmpty())
		{
			throw runtime_error("Can't delete. the linkedList is empty");
		}
		if (!search(item))
		{
			throw runtime_error("This item not found to be deleted");
		}
		if (head->data == item)
		{
			deleteFirst();
		}
		else
		{
			Node<T>* previous = nullptr;
			Node<T>* deleter = head;

			while (deleter->data != item)
			{
				previous = deleter;
				deleter = deleter->next;
			}
			previous->next = deleter->next;
			delete deleter;
		}
	}
};
#endif
