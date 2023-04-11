#include <iostream>
#include "Queue.h"

using namespace std;

template <typename T>

/*Basic constructor for Queue for all attributes needed*/
Queue<T>::Queue()
{
	cap = 50; //Subject to change if needed depending on the capacity. 
	back = -1;
	front = 0;
	size = 0;
	data = new T[cap];
}



template <typename T>
Queue<T>::~Queue()
{
	delete[] data;

}


template <typename T>
void Queue<T>::Empty()
{
	if (size == 0)   /*Checks whether the queue is empty based on the size*/
	{
		cout << "The Queue is empty" << endl;
	}

	else
		cout << "The Queue is not empty" << endl;
}


template <typename T>
int Queue<T>::Q_Size()
{
	return size;
}


template <typename T>
void Queue<T>::enqueue(T element)
{
	if (size == cap)
	{
		cout << "OVERFLOW!!!!" << endl;
		exit(EXIT_FAILURE);
	}

	back++;
	data[back] = element;
	size++;

}



template <typename T>
T Queue<T>::dequeue()
{

	/*If the queue is not empty this will get rid of the front element
	and return it*/
	if (size == cap)
	{
		cout << "OVERFLOW!!!!" << endl;
		exit(EXIT_FAILURE);
	}

	else if (size == 0)
	{
		cout << "QUEUE IS EMPTY" << endl;
		exit(EXIT_FAILURE);
	}

	T Final = data[front];
	front++;
	size--;
	return Final;

}

template <typename T>
void Queue<T>::PrintQ()
{
	//Goes through the queue and prints it out for the user based on contents inside

	for (int i = front; i <= back; i++)
	{
		cout << data[i] << " ";
	}
}


template <typename T>
void Queue<T>::print_front()
{
	if (size == 0)
	{
		cout << "The queue is empty" << endl;
	}

	else
	{
		cout << data[front];
	}
}

