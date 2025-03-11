#ifndef DOUBLE_LINKEDLIST
#define DOUBLE_LINKEDLIST

#include <iostream>
#include <exception>
using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node* next;
	Node* prev;
};
template <class T>
class LinkedList
{
	Node<T>* head;

	bool isEmpty()
	{
		return (head == nullptr);
	}
public:
	LinkedList():head(nullptr){}
	~LinkedList() //destruct without retrieving value.
	{
		if (!head) return;
		if (head)
		{
			Node<T>* deleter = head;
			head = head->next;
			delete deleter;
		}
	}
	//functions
	void addFirst(T item)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = item;
		if (isEmpty())
		{
			newNode->next = nullptr;  //I can use constructor for initializing new node but I Prefere use this way to see details in every step to remember it *_^ .
			newNode->prev = nullptr;
			head = newNode;
		}
		else
		{
			newNode->next = head;
			newNode->prev = nullptr;
			head->prev = newNode;
			head = newNode;
		}
	}
	void addSpecific(T indexValue, T newValue)
	{
		if (isEmpty())
		{
			addFirst(newValue);
			return;
		}
		if (!search(indexValue))
		{
			throw runtime_error("Sorry but the indexValue not found");
		}
		Node<T>* temp = head;
		Node<T>* newNode = new Node<T>();
		newNode->data = newValue;
		while (temp->next->data != indexValue)
		{
			temp = temp->next;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next = newNode;
		temp->next->prev = newNode->next;
	}
	void append(T newValue)
	{
		if (isEmpty())
		{
			addFirst(newValue);
			return;
		}
		
		Node<T>* temp = head;
		Node<T>* newNode = new Node<T>();
		newNode->data = newValue;

		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		newNode->prev = temp;
		newNode->next = nullptr;
		temp->next = newNode;
	}
	void display()
	{
		if (isEmpty())
		{
			throw runtime_error("The list is empty you can't display any items");
		}
		Node<T>* temp = head;
		cout << "The elements of likedList is:" << endl;
		while (temp != nullptr)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}

	}
	void displayReverse()
	{
		if (isEmpty())
		{
			throw runtime_error("The list is empty you can't display any items");
		}
		Node<T>* temp = head;
		cout << "The elements of likedList in reverse order is:" << endl;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		
		while (temp->next == nullptr && temp->prev != nullptr)
		{
			if (temp->prev != nullptr)
			{
				cout << temp->data << endl;
				temp = temp->prev;
				temp->next = nullptr;
			}
			
		}
		cout << temp->data << endl;
	}
	bool search(T key)
	{
		if (isEmpty())
		{
			throw runtime_error("The linkedList is empty, there is no items to search for");
		}
		Node<T>* temp = head;

		while (temp != nullptr)
		{
			if (temp->data == key)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	int count()
	{
		if (isEmpty())
		{
			throw runtime_error("LinkedList is empty, there is no items to be counted");
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
	T deleteFirstAndRetrieve()
	{
		T copy;
		if (isEmpty())
		{
			throw runtime_error("LinkedList is empty, there is no anything to be deleted");
		}
		if (head != nullptr && head->next == nullptr)
		{
			copy = head->data;
			delete head;
			cout << "LinkedList became empty now since we deleted the lonely one item" << endl;
		}
		if (head)
		{
			Node<T>* deleter = head;
			copy = deleter->data;
			head = head->next;
			delete deleter;
		}
		return copy;
	}

	T deleteSpecificAndRetrieve(T item)
	{
		if (isEmpty())
		{
			throw runtime_error("LinkedList is empty, no items to be deleted");
		}
		if (!search(item))
		{
			throw runtime_error("The item will be deleted not found");
		}
		if (head != nullptr && head->data == item)
		{
			
			return deleteFirstAndRetrieve();
		}
		T copy;
		Node<T>* deleter = head;
		Node<T>* previous = nullptr;
		while (deleter != nullptr && deleter->data != item)
		{
			previous = deleter;
			deleter = deleter->next;
		}
		copy = deleter->data;

		if (deleter->next == nullptr)  //if delete the last node
		{
			if (previous != nullptr)
			{
				previous->next = nullptr;
			}
		}
		else
		{
			deleter->next->prev = previous;

			if (previous != nullptr)
			{
				previous->next = deleter->next;
			}
		}
		delete deleter;
		return copy;
	}

};

#endif
