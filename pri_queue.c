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
	// add your code here
	Node_t *temp = (Node_t*) malloc(sizeof(Node_t));
	temp->priority = priority;
	temp->data = data;
	if (head == NULL) {
		head = temp;
		head->next = NULL;
		return;
	}
	Node_t *current = head;
	Node_t *prev = NULL;
	while (current != NULL && current->priority <= current->next->priority) {
		prev = current;
		current = current->next;
	}
	if (current == head) {
		head = temp;
		head->next = current;
	}

}
/**
 * Delete and return the node with the highest priority.
 * @return The highest priority Node.
 */
Node_ptr_t PQ_delete() {
	// add your code here
	if (head == NULL)
		return head;
	Node_ptr_t *temp = head;
	int size = PQ_get_size();
	head = head->next;
	size--;
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

