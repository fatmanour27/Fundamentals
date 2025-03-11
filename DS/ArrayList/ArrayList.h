#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>
#include <exception>
using namespace std;

template <class T>  //To avoid the repetition of template before each function in another file.cpp to implement the header, instead that we use the header file to implementation and declaration
class ArrayList
{
	T* ptrArr;
	int capacity;
	int length;

	void ResizeArray()
	{
		T* temp = new T[capacity + 10];

		for (int i = 0; i < length; i++)
		{
			temp[i] = ptrArr[i];
		}
		delete[] ptrArr;
		ptrArr = temp;

		capacity += 10;
	}
	void validateIndex(int index)
	{
		if (index < 0 || index > length)
		{
			throw invalid_argument("The index out of range");
		}
	}
public:
	//Constructor
	ArrayList(int newCapacity = 10)
	{
		if (newCapacity <= 0)
		{
			throw invalid_argument("The capacity must be greater than 0");
		}
		else
		{
			capacity = newCapacity;
			length = 0;
			ptrArr = new T[newCapacity];
		}
	}
	//Destructor
	~ArrayList()
	{
		delete[] ptrArr;
	}
	//Functions.
	int getCapacity(){ return capacity; }
	int getLength(){ return length; }
	
	void append(T item)
	{
		if (length >= capacity)
		{
			ResizeArray();
		}
		ptrArr[length] = item;
		length++;
	}
	void display()
	{
		cout << "The elements of ArrayList:" << endl;
		for (int i = 0; i < length; i++)
		{
			cout << ptrArr[i] << endl;
		}
	}
	//to access specific item in array
	T& operator[](int i)
	{
		if (i >= capacity || i < 0)
		{
			throw invalid_argument("out of range!");
		}
		return ptrArr[i];
	}
	int search(T key)
	{
		int index = -1;

		for (int i = 0; i < length; i++)
		{
			if (ptrArr[i] == key)
			{
				index = i;
				break;
			}
		}
		return index;
	}
	void insert(int index, T value)
	{
		validateIndex(index);
		if (length == capacity)
		{
			throw runtime_error("The array is full you can't insert any item");
		}
		for (int i = length; i > index; i--)
		{
			ptrArr[i] = ptrArr[i - 1];
		}
		ptrArr[index] = value;
		length++;
	}
	void Delete(int index)
	{
		validateIndex(index);
		for (int i = index; i < length - 1; i++)
		{
			ptrArr[i] = ptrArr[i + 1];
		}
		length--;
	}
	void reverse(int lengthTemp)
	{
		if (lengthTemp != length)
		{
			throw runtime_error("Two lengths of temp and ptrArr can't be not equal");
		}
		T* temp = new T[length];
		for (int i = 0; i < length; i++)
		{
			temp[i] = ptrArr[length - 1 - i];
		}
		delete[] ptrArr;
		ptrArr = temp;
	}
};

#endif
