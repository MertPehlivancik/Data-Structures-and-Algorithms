/*
 ============================================================================
 Name        : main.c
 Author      : Mert PEHLİVANCIK
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Queue implementation
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Linkedqueue.h"

int main(void) {
	LINKED_QUEUE myqueue = linkedqueue_init();
	linkedqueue_enqueue(myqueue, 1);
	linkedqueue_enqueue(myqueue, 2);
	linkedqueue_enqueue(myqueue, 3);
	linkedqueue_enqueue(myqueue, 4);

	int x = *((int*) linkedqueue_dequeue(myqueue));
	printf("%d is dequeue\n", x);
	x = *((int*) linkedqueue_dequeue(myqueue));
	printf("%d is dequeue\n", x);
	x = *((int*) linkedqueue_dequeue(myqueue));
	printf("%d is dequeue\n", x);
	x = *((int*) linkedqueue_dequeue(myqueue));
	printf("%d is dequeue\n", x);
	return 0;
}

