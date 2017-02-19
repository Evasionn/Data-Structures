/*
	C++ LinkedList header for education purposes

	ÇANKAYA UNIVERSITY - Computer Engineering | Melihþah AKIN
*/
#pragma once
#include <iostream>

using namespace std;
template <class T>
class linkedList
{
	struct node
	{
		T data;
		node * next;
	};


public:
	linkedList() { head = NULL; } // set head to NULL


	node * createNode(T data)  // The method that creates new linkedlist nodes
	{
		node * newNode = new node(); // create node
		newNode->data = data; // set value
		newNode->next = NULL;
		return newNode;
	}
	
	int isEmpty()
	{
		return head == NULL ? true : false; // if head is NULL ( it means our list is empty), returned value is TRUE, otherwise the value is FALSE
	}
	void insertFront(T data) // The method that adds new node to front of the list
	{
		if (isEmpty()) head = createNode(data); 
		else
		{
			node * newNode = createNode(data);
			newNode->next = head; // make the node point to the next node
			head = newNode; // make the head point at the new node
		}
	}
	void insertEnd(T data) // The method that adds new node to end of the list
	{
		if (isEmpty()) head = createNode(data);
		else
		{
			node * walk = head; // walk is temprary pointer of the head because we don't want to change head point
			while (walk->next != NULL) walk = walk->next; // go to end of the list with temprary pointer
			walk->next = createNode(data); // create new node if the next is empty
		}
	}

	void insertToPosition(T data, int position) // The function that adds new node to a specific position
	{
		if (isEmpty()) head = createNode(data);
		else
		{
			node * newNode = createNode(data);
			if (position == 0)
			{
				newNode->next = head;
				head = newNode;
			}
			else
			{
				node * temp = head;
				node * prev = NULL;
				int counter = 0;
				for (int i = 0; i < position; i++)
				{
					if (temp == NULL)
					{
						prev->next = newNode;
						break;
					}
					else
					{
						prev = temp;
						temp = temp->next;
					}
				}
				newNode->next = temp;
				prev->next = newNode;
			}
		}
	}

	void insertSorted(T data) // The function that allows adding new node in sorted 
	{
		if (head == NULL) head = createNode(data);
		else
		{
			node * temp = head;
			node * prev = NULL;
			node * newNode = createNode(data);
			while (temp != NULL)
			{
				if (data < temp->data)
				{
					if (prev == NULL) // Adding node for smallest data
					{
						newNode->next = temp;
						head = newNode;
						return;
					}
					else
					{
						prev->next = newNode; // Adding node if the data's position is middile of the list
						newNode->next = temp;
						return;
					}
				}
				prev = temp;
				temp = temp->next;
			}
			prev->next = newNode; // adding node to end for biggest data
		}
	}
	int numberOfElements() // The method that returns number of elements that list has
	{
		int counter = 0;
		node * walk = head;
		while (walk != NULL)
		{
			counter++;
			walk = walk->next;
		}
		return counter;
	}
	void traverse() // The function that prints out whole list
	{
		node * walk = head;
		while (walk != NULL)
		{
			cout << walk->data << " -> ";
			walk = walk->next;
		}
		cout << "NULL" << endl;
	}


	void reverseTraverse(node * head) // The function that prints out whole list members in reverse order.  Head is private member so I designed it in 2 part
	{
		if (head == NULL) return;
		reverseTraverse(head->next);
		cout << head->data << " -> ";
	}
	
	void reverseTraverse()
	{
		reverseTraverse(head);
		cout << "NULL" << endl;
	}
	
	void reverse() // The function that reverse a linked list
	{
		node * prev = NULL;
		node * curr = head;
		node * next = NULL;
		while (curr != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
	void deleteFirst()
	{
		if (isEmpty()) return; // if the list is empty, do nothing
		node * temp = head; // store head pointer in a temprary pointer
		head = head->next; // slide head 
		delete temp; // and delete temprary node
	}
	
	void deleteLast()
	{
		if (isEmpty()) return; // if the list is empty, do nothing
		node * prev = NULL; // we need to store previous node  
		node * curr = head;
		while (curr->next != NULL)
		{
			prev = curr; 
			curr = curr->next; // Sliding pointers at the same time. 
		}
		prev->next = NULL; // previous will be our last node so it's next node is empty. 
		delete curr;
	}
	void deleteAtPosition(int position)
	{
		if (isEmpty()) return; // if the list is empty, do nothing
		node * prev = NULL;
		node * curr = head;
		for (int i = 0; i < position; i++)
		{
			if (curr == NULL) return; // if the current node is already empty, do nothing ( we're checking if the given position is out of range or not
			prev = curr;
			curr = curr->next; // Sliding pointers at the same time.
		}
		prev->next = curr->next; // previous node points current node's next because current node can be in the middile of the list, not at the end.
		delete curr;
	}

	linkedList(const linkedList & obj) // COPY CONSTRUCTOR
	{
		head = createNode(obj.head->data); 
		node * tempObj = obj.head->next;
		node * temp = head;
		while (tempObj != NULL)
		{
			temp->next = createNode(tempObj->data);
			temp = temp->next;
			tempObj = tempObj->next;
		}
	}

	void operator = (const linkedList obj) // Overloaded '=' operator
	{
		head = createNode(obj.head->data);
		node * tempObj = obj.head->next;
		node * temp = head;
		while (tempObj != NULL)
		{
			temp->next = createNode(tempObj->data);
			temp = temp->next;
			tempObj = tempObj->next;
		}
	}
	
	bool operator ==(const linkedList obj) // To compare two linked list. If they are equal to each other, returned value is true, otherwise it is false
	{
		node * temp = head;
		node * tempObj = obj.head;
		while (temp != NULL && tempObj != NULL)
		{
			if (temp->data != tempObj->data) return false;
			temp = temp->next;
			tempObj = tempObj->next;
		}
		if (temp != NULL) return false;
		if (tempObj != NULL) return false;
		return true;
	}

	bool operator !=(const linkedList obj) // Negative of equality function
	{
		return !operator == (obj);
	}

	void clearList() // The function that deletes all members of linked list
	{
		node * temp = head;
		node * deleted = NULL;
		while (temp != NULL)
		{
			deleted = temp;
			temp = temp->next;
			delete deleted;
		}
		head = NULL;
	}

			~linkedList() // Destructor
		{
			if (isEmpty()) delete head;
			else
			{
				node * temp = NULL;
				while (head != NULL)
				{
					temp = head;
					head = head->next;
					delete temp;
				}
			}
		}
	
private:
	node * head;
};

