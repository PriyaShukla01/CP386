#include <stdlib.h>
#include <stdio.h>
#include "pri_queue.h"
/** @file pri_queue.c */
static Node_ptr_t head = NULL;
/**
 * Insert a Node into a priority queue.
 * @param priority
 * @param data
 * @author Ryan Murari
 */
void PQ_insert(int priority, char *data) {
	// create the node that holds the data and priority
	Node_t *temp = (Node_t*) malloc(sizeof(Node_t));
	temp->priority = priority;
	temp->data = data;

	// if queue is empty, head is new node and it points to null
	if (head == NULL) {
		head = temp;
		head->next = NULL;
		return;
	}

	//iterate through the queue till it reaches the end or a node of
	//which the priority is greater than or equal to the node to be inserted
	Node_t *current = head;
	Node_t *prev = NULL;
	while (current != NULL && temp->priority <= current->priority) {
		prev = current;
		current = current->next;
	}
	//insert node at the head if node has the highest priority
	if (current == head) {
		head = temp;
		head->next = current;
	}
	//insert node at the end if priority of node is lowest
	else if (current == NULL) {
		prev->next = temp;
		temp->next = NULL;
	}
	//insert node after current node if the priorities are equal
	else if (current->priority == temp->priority) {
		temp->next = current->next;
		current->next = temp;
	}
	//insert node before current node if new node has a greater priority than current
	else if (current->priority < temp->priority) {
		temp->next = current;
		prev->next = temp;
	}

}
/**
 * Delete and return the node with the highest priority.
 * @return The highest priority Node.
 */
Node_ptr_t PQ_delete() {
	// add your code here
	if (head == NULL)							//base case, if queue is empty
		return head;
	Node_ptr_t temp = head;//if not empty, store the head value of the queue and then remove
	head = head->next;		//head is not the node after the orignal head node
	return temp;
}

/**
 * Do NOT modify this function.
 * @return A pointer to the head of the list.  (NULL if list is empty.)
 */
Node_ptr_t PQ_get_head() {
	return head;
}

/**
 * Do NOT modify this function.
 * @return the number of items in the queue
 */
int PQ_get_size() {
	int size = 0;
	Node_ptr_t tmp;
	for (tmp = head; tmp != NULL; tmp = tmp->next, size++)
		;
	return size;
}
