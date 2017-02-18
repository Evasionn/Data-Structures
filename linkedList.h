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
private:
	node * head;
};

