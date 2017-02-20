#pragma once
#include <iostream>
using namespace std;
typedef int elemType;

class node
{
public:
	elemType data;
	node * next;
	node() { data = 0; next = NULL; }
	node(elemType data) { this->data = data; next = NULL; }
};

void traverse(node * head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

void reverseTraverse(node * head)
{
	if (head == NULL) return;
	reverseTraverse(head->next);
	cout << head->data << " ";
}

bool isEmpty(node ** head)
{
	return (*head) == NULL ? true : false;
}
void insertFront(node ** head, elemType data)
{
	if (isEmpty(head)) *head = new node(data);
	else
	{
		node * newNode = new node(data);
		newNode->next = *head;
		*head = newNode;
	}
}
void insertEnd(node ** head, elemType data)
{
	if (isEmpty(head)) *head = new node(data);
	else
	{
		node * walk = *head;
		while (walk->next != NULL) walk = walk->next;
		walk->next = new node(data);
	}
}

void deleteFirst(node ** head)
{
	if (isEmpty(head)) return;
	node * temp = *head;
	(*head) = (*head)->next;
	delete temp;
}

void deleteLast(node ** head)
{
	if (isEmpty(head)) return;
	node * walk = *head;
	node * prev = NULL;
	while (walk->next != NULL)
	{
		prev = walk;
		walk = walk->next;
	}
	prev->next = NULL;
	delete walk;
}

int numberOfElements(node *head) 
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

void insertToPosition(node ** head,elemType data, int position) // The function that adds new node to a specific position
{
	if (isEmpty(head)) *head = new node(data);
	else
	{
		node * newNode = new node(data);
		if (position == 0)
		{
			newNode->next = *head;
			*head = newNode;
		}
		else
		{
			node * temp = *head;
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

void insertSorted(node ** head, elemType data) 
{
	if (isEmpty(head)) *head = new node(data);
	else
	{
		node * temp = *head;
		node * prev = NULL;
		node * newNode = new node(data);
		while (temp != NULL)
		{
			if (data < temp->data)
			{
				if (prev == NULL)
				{
					newNode->next = temp;
					*head = newNode;
					return;
				}
				else
				{
					prev->next = newNode; 
					newNode->next = temp;
					return;
				}
			}
			prev = temp;
			temp = temp->next;
		}
		prev->next = newNode; 
	}
}

void reverse(node ** head) 
{
	node * prev = NULL;
	node * curr = *head;
	node * next = NULL;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

void deleteAtPosition(node ** head, int position)
{
	if (isEmpty(head)) return; 
	node * prev = NULL;
	node * curr = *head;
	for (int i = 0; i < position; i++)
	{
		if (curr == NULL) return; 
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	delete curr;
}