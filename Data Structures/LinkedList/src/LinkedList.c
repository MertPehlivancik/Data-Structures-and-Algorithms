/*
 ============================================================================
 Name        : LinkedList.c
 Author      : Mert PEHLİVANCIK
 Version     : 1.2
 Copyright   : Your copyright notice
 Description : Linked list operations
 ============================================================================
 */
#include "LinkedList.h"

// Creating linked list.
LINKED_LIST linked_list_init() {
	LINKED_LIST list = (LINKED_LIST) malloc(sizeof(LINKED_LIST_t));
	list->head = NULL;
	return list;
}

// Creating node.
LINKED_LIST_NODE linked_list_node_init(int data) {
	LINKED_LIST_NODE node = (LINKED_LIST_NODE) malloc(
			sizeof(LINKED_LIST_NODE_t));
	node->data = data;
	node->next = NULL;
	return node;
}

// Adding node after last node of linked list.
void linked_list_append(LINKED_LIST list, int data) {
	if (list->head == NULL) {
		list->head = linked_list_node_init(data);
	} else {
		LINKED_LIST_NODE node = list->head;
		while (node->next != NULL) {
			node = node->next;
		}
		node->next = linked_list_node_init(data);
	}
}

// Adding node before first node of linked list.
void linked_list_prepend(LINKED_LIST list, int data) {
	if (list->head == NULL) {
		list->head = linked_list_node_init(data);
	} else {
		LINKED_LIST_NODE node = linked_list_node_init(data);
		node->next = list->head;
		list->head = node;
	}
}

// Adding node to linked list as a given position.
void linked_list_insert(LINKED_LIST list, int position, int data) {
	LINKED_LIST_NODE temp = list->head;
	if (position == 0) {
		linked_list_prepend(list, data);
	}
	while (position != 1) {
		if (temp == NULL) {
			break;
		}
		temp = temp->next;
		position--;
	}
	if (temp != NULL) {
		LINKED_LIST_NODE node = linked_list_node_init(data);
		node->next = temp->next;
		temp->next = node;
	}
}

// Deleting node as a given key value.
// If one value, which is not in list, is given, function doesn't run. Solve it.
void linked_list_delete_node_as_key(LINKED_LIST list, int data) {
	LINKED_LIST_NODE prev = list->head;
	if (prev->data == data) {
		list->head = prev->next;
		free(prev);
		return;
	}
	while (prev != NULL) {
		if (prev->next->data == data) {
			break;
		}
		prev = prev->next;
	}
	LINKED_LIST_NODE node;
	node = prev->next;
	prev->next = node->next;
	free(node);
}

// Deleting node as a given position of list.
void linked_list_delete_node_as_position(LINKED_LIST list, int position) {
	if (list == NULL) {
		return;
	}
	LINKED_LIST_NODE node = list->head;
	LINKED_LIST_NODE prev = list->head;
	// if head of linked list needs to be removed.
	if (position == 0) {
		list->head = node->next;
		free(node);
	} else {
		// Finding previous node of the node to be deleted.
		for (int i = 0; prev != NULL && i < position - 1; i++) {
			prev = prev->next;
			// if given position for deleting node is more than number of nodes
			if (prev == NULL || prev->next == NULL) {
				return;
			}
		}
		node = prev->next;
		prev->next = node->next;
		free(node);
	}
}
// -1 0 1 2 3 4 NULL
// Deleting all list as node by node from memory
void linked_list_delete_list(LINKED_LIST list) {
	LINKED_LIST_NODE node = list->head;
	LINKED_LIST_NODE temp = list->head;
	while (node != NULL) {
		temp = temp->next;
		free(node);
		node = temp;
	}
}

// Finding length of linked list using iterative function.
int linked_list_find_length_iterative(LINKED_LIST list) {
	LINKED_LIST_NODE node = list->head;
	int counter = 0;
	while (node != NULL) {
		node = node->next;
		counter++;
	}
	return counter;
}

// Finding length of linked list using recursive function.
int linked_list_find_length_recursive(LINKED_LIST_NODE node) {
	if (node == NULL) {
		return 0;
	}
	return 1 + linked_list_find_length_recursive(node->next);
}

// Searching given value from given linked list with iterative function. If value is in linked list, function returns true. If not, return false.
bool linked_list_search_element_iterative(LINKED_LIST list, int data) {
	LINKED_LIST_NODE node = list->head;
	while (node != NULL) {
		if (node->data == data) {
			return true;
		}
		node = node->next;
	}
	return false;
}

// Searching given value from given linked list with recursive function. If value is in linked list, function returns true. If not, return false.
bool linked_list_search_element_recursive(LINKED_LIST_NODE node, int data) {
	if (node == NULL) {
		return false;
	} else if (node->data == data) {
		return true;
	}
	return linked_list_search_element_recursive(node->next, data);
}

// The function returns one of list's data from given position
int linked_list_getNth_data(LINKED_LIST list, int getNth) {
	LINKED_LIST_NODE node = list->head;
	for (int i = 0; i < getNth; i++) {
		node = node->next;
	}
	return node->data;
}

// The function returns one of list's node from given position
LINKED_LIST_NODE linked_list_getNth_node(LINKED_LIST_NODE node, int getNth) {
	int length = linked_list_find_length_recursive(node);
	if (getNth > 0 && getNth <= length - 1) {
		for (int i = 0; i < getNth; i++) {
			node = node->next;
		}
		return node;
	} else {
		node = NULL;
		return node;
	}
}

// Finding middle node of linked list with fast node method.
// Explanation of algorithm
// Definitions: f = fast node, s = slow node, -1 0 1 2 3 4 --> Linked list
// -1	0	1	2	3	4	NULL
// fs
// -1	0	1	2	3	4	NULL
// 		s	f
// -1	0	1	2	3	4	NULL
// 			s		f
// -1	0	1	2	3	4	NULL
// 				s			 f
// s->data is 2 and 2 is middle node of given linked list.
LINKED_LIST_NODE linked_list_find_middle_node_with_fastnodeMethod(
		LINKED_LIST list) {
	LINKED_LIST_NODE slowNode = list->head;
	LINKED_LIST_NODE fastNode = list->head;
	if (list != NULL || list->head != NULL) {
		while (fastNode != NULL && fastNode->next != NULL) {
			fastNode = fastNode->next->next;
			slowNode = slowNode->next;
		}
		return slowNode;
	} else {
		free(fastNode);
		free(slowNode);
		list->head = NULL;
		return list->head;
	}
}

// Finding middle node of linked list using length of linked list
LINKED_LIST_NODE linked_list_find_middle_node(LINKED_LIST list) {
	LINKED_LIST_NODE node = list->head;
	if (list != NULL && list->head != NULL) {
		int length = linked_list_find_length_iterative(list);
		length = length / 2;
		for (int i = 0; i < length; i++) {
			node = node->next;
		}
		return node;
	} else {
		free(node);
		list->head = NULL;
		return list->head;
	}
}

// Counting given number how many times was repeated in the given linked list.
int linked_list_count_repetitive_number(LINKED_LIST list, int number) {
	LINKED_LIST_NODE node = list->head;
	int counter = 0;
	while (node != NULL) {
		if (node->data == number) {
			counter++;
			node = node->next;
		} else {
			node = node->next;
		}
	}
	return counter;
}

// Finding loop in linked list with Floyd's Cycle Finding Algorithm
bool linked_list_detect_loop_with_FloydCycleFindingAlgorithm(LINKED_LIST list) {
	LINKED_LIST_NODE slowNode = list->head;
	LINKED_LIST_NODE fastNode = list->head;
	while (fastNode != NULL && fastNode->next != NULL) {
		slowNode = slowNode->next;
		fastNode = fastNode->next->next;
		if (fastNode == slowNode) {
			return true;
		}
	}
	return false;
}

// This function detects loop in given linked list and count how many nodes are present in loop.
int linked_list_detectAndCountLoop(LINKED_LIST list) {
	int counter = 0;
	LINKED_LIST_NODE slowNode = list->head;
	LINKED_LIST_NODE fastNode = list->head;
	while (fastNode != NULL && fastNode->next != NULL) {
		slowNode = slowNode->next;
		fastNode = fastNode->next->next;
		counter++;
		if (fastNode == slowNode) {
			return counter;
		}
	}
	counter = counter - counter;
	return counter;
}

// This function swap given data of nodes
void linked_list_swap_data(LINKED_LIST_NODE first_node,
		LINKED_LIST_NODE second_node) {
	LINKED_LIST_NODE temp = linked_list_node_init(first_node->data);
	first_node->data = second_node->data;
	second_node->data = temp->data;
	free(temp);
}

// This function controls that data of given linked list were sorted or not.
bool linked_list_isSorted(LINKED_LIST list) {
	LINKED_LIST_NODE node = list->head;
	while (node->next != NULL) {
		if (node->data > node->next->data) {
			return false;
		}
		node = node->next;
	}
	return true;
}

// This function sorts given linked list with bubble sort algorithm.
// This function needs "linked_list_swap_data" and "linked_list_isSorted" functions for running.
void linked_list_bubbleSort(LINKED_LIST list) {
	while (linked_list_isSorted(list) == false) {
		LINKED_LIST_NODE node = list->head;
		while (node->next != NULL) {
			if (node->data > node->next->data) {
				linked_list_swap_data(node, node->next);
			}
			node = node->next;
		}
	}
}

// Given node is deleted in given linked list
void linked_list_delete_node_as_givenNode(LINKED_LIST list,
		LINKED_LIST_NODE node) {
	LINKED_LIST_NODE prev = list->head;
	if (node == prev) {
		list->head = node->next;
		free(node);
		return;
	}
	while (prev->next != node) {
		if (prev->next == node) {
			break;
		}
		prev = prev->next;
	}
	prev->next = node->next;
	free(node);
}

// Remove duplicates from a sorted linked list
void linked_list_remove_duplicates_sortedList(LINKED_LIST list) {
	LINKED_LIST_NODE node = list->head;
	while (node->next != NULL) {
		if (node->data == node->next->data) {
			linked_list_delete_node_as_givenNode(list, node->next);
			continue;
		}
		node = node->next;
	}
}

// Printing elements of linked list.
void linked_list_print(LINKED_LIST list) {
	LINKED_LIST_NODE node = list->head;
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}



