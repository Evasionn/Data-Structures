#pragma once
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef int elemType;

typedef struct node
{
	elemType data;
	node * next;
}Node;

Node * createNode(elemType data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("Allocation error!");
		exit(1);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
int isEmpty(Node ** head)
{
	return (*head) == NULL ? TRUE : FALSE;
}

void insertFront(Node ** head, elemType data)
{
	if (isEmpty(head)) (*head) = createNode(data);
	else
	{
		Node * newNode = createNode(data);
		newNode->next = (*head);
		(*head) = newNode;
	}
}

void insertEnd(Node ** head, elemType data)
{
	if (isEmpty(head)) (*head) = createNode(data);
	else
	{
		Node * temp = (*head);
		while (temp->next != NULL) temp = temp->next;
		temp->next = createNode(data);
	}
}

void deleteFirst(Node ** head)
{
	if (isEmpty(head)) return;
	
	Node * temp = (*head);
	(*head) = (*head)->next;
	free(temp);
}

void deleteLast(Node ** head)
{
	if (isEmpty(head)) return;
	Node * curr = (*head);
	Node * prev = NULL;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	free(curr);
}
void deleteAtPosition(Node ** head, int position)
{
	if (isEmpty(head)) return;
	Node * curr = (*head);
	Node * prev = NULL;
	for (int i = 0; i < position; i++)
	{
		if (curr == NULL) return;
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	free(curr);

}
int numberOfElements(Node * head)
{
	int counter = 0;
	while (head != NULL)
	{
		counter++;
		head = head->next;
	}
	return counter;
}

void clearList(Node ** head)
{
	Node * temp = (*head);
	Node * next = NULL;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	(*head) = NULL;
}

void traverse(Node * head)
{
	while (head != NULL)
	{
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}