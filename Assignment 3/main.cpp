#include <iostream>
#include "functions.h"
#include <stack>
#include <string>
#include "Queue.h"
#include "Queue.cpp"



using namespace std;


int main()
{
	string userInfix; 


	bool choice = true;
	while (choice)
	{
		cout << "Enter your infix expression ==> ";
		cin >> userInfix;
		

		if (IsInfixBalanced(userInfix)) {
			cout << "The expression is balanced" << endl << endl;
			cout << "will now convert to postfix ==>";
			cout << infixToPostfix(userInfix);
		}

		else
		{
			cout << "The expression is NOT balanced";
		}

		char again;
		cout << endl;

		cout << "Do you want to go again? Y or N " << endl;
		cin >> again;

		if (again == 'y' || again == 'Y')
		{
			choice = true;
		}

		else if (again == 'n' || again == 'N')
		{
			choice = false;
		}
	}


	/*Uses the class Queue created to create a Queue and
	push elements inside then prints the queue*/
	Queue<int> newQueue;
	newQueue.enqueue(10);
	newQueue.enqueue(20);
	newQueue.enqueue(30);
	newQueue.enqueue(40);

	cout << "The Current Queue is ";
	newQueue.PrintQ();
	cout << endl;

	cout << "Front element has been deleted: " << newQueue.dequeue();

	cout << endl;
	cout << "The Current Queue is "; 
	newQueue.PrintQ();
	cout << endl;

	newQueue.Empty();

	cout << "The front element is ";
	newQueue.print_front();
	cout << endl;

	cout << "The size of Queue is " << newQueue.Q_Size() << endl;

}
