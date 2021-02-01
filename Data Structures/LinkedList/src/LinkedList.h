/*
 ============================================================================
 Name        : LinkedList.h
 Author      : Mert PEHLİVANCIK
 Version     : 1.2
 Copyright   : Your copyright notice
 Description : Linked list structures and function definitions
 ============================================================================
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;
typedef struct LINKED_LIST_NODE_s {
	int data;
	LINKED_LIST_NODE next;
} LINKED_LIST_NODE_t[1];

typedef struct LINKED_LIST_s *LINKED_LIST;
typedef struct LINKED_LIST_s {
	LINKED_LIST_NODE head;
} LINKED_LIST_t[1];

LINKED_LIST linked_list_init();
LINKED_LIST_NODE linked_list_node_init(int data);
void linked_list_append(LINKED_LIST list, int data);
void linked_list_prepend(LINKED_LIST list, int data);
void linked_list_insert(LINKED_LIST list, int position, int data);
void linked_list_delete_node_as_key(LINKED_LIST list, int data);
void linked_list_delete_node_as_position(LINKED_LIST list, int position);
void linked_list_delete_list(LINKED_LIST list);
int linked_list_find_length_iterative(LINKED_LIST list);
int linked_list_find_length_recursive(LINKED_LIST_NODE node);
void linked_list_print(LINKED_LIST list);

#endif /* LINKEDLIST_H_ */