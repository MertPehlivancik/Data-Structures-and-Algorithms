/*
 ============================================================================
 Name        : arraystack.c
 Author      : Mert PEHLİVANCIK
 Version     : 1.1
 Copyright   : Your copyright notice
 Description : Implementing Stack using Arrays
 ============================================================================
 */
#include "arraystack.h"

// function to create a stack of given capacity. It initializes size of
// stack as 0
ARRAY_STACK createStack(unsigned capacity) {
	ARRAY_STACK stack = (ARRAY_STACK) malloc(sizeof(ARRAY_STACK_t));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));
	return stack;
}

// Stack is full when top is equal to the last index
int isFull(ARRAY_STACK stack) {
	return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(ARRAY_STACK stack) {
	return stack->top == -1;
}

// Function to add an item to stack.  It increases top by 1
void push(ARRAY_STACK stack, int item) {
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
	printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
int pop(ARRAY_STACK stack) {
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
int peek(ARRAY_STACK stack) {
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top];
}
