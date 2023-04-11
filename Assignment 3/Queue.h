#pragma once
#include <iostream>

using namespace std;

//Creation of Class Queue and everything that will used/needed
template <typename T>
class Queue {
private:
	int front;
	int back;
	int size;
	int cap;
	T* data;

public:
	Queue();
	~Queue();
	void Empty();
	int Q_Size();
	void enqueue(T element);
	T dequeue();
	void PrintQ();
	void print_front();



};