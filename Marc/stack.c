#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	int size;
	s_elem *head;
};
/* Beginning of assignment -------------------------------------------------------------------------- */
struct s_elem
{
	char *name;
	int index;
	s_elem *predecessor;
};

Stack* stack_new()
{
	Stack *stack = malloc(sizeof(Stack)); // reserviere Speicherplatz

	if (NULL == stack) // Speicherplatz voll, oder Problem mit malloc
		return NULL;

	// Initialisieren der Variablen
	stack->size = 0;
	stack->head = NULL;

	return stack;
}

s_elem* s_elem_new(char* name)
{
	s_elem *elem = malloc(sizeof(s_elem)); // reserviere Speicherplatz

	if (NULL == elem) // Speicherplatz voll, oder Problem mit malloc
		return NULL;

	// Initialisieren der Variablen
	elem->name = name;
	elem->index = -1; // kein real moeglicher Index
	elem->predecessor = NULL;

	return elem;
}

void stack_free(Stack *stack)
{
	// stack
	// all Elements





	s_elem *current = stack->head;
	s_elem *next = NULL;
	while(NULL != next) {
		next = current->predecessor;

		free(current->name);
		free(current->predecessor);
		free(current);

		current = next;
	}
	free(stack);
	free(stack->head);

	printf("mem is freed\n");

	return;
}

char* stack_push(Stack *stack, s_elem* newElem)
{
  if (NULL == stack || NULL == newElem) // Falls Pointer ungueltig sind
		return NULL;

	newElem->predecessor = stack->head; // mache voriges oberstes Element zugaenglich
	stack->head = newElem; // neues Element ist head

	stack->head->index = stack->size; // index des neuen Elements

	stack->size++; // Groesse des Stacks anpassen

	return stack->head->name;
}

char* stack_peek(Stack *stack)
{
	if (NULL == stack) // Falls Pointer ungueltig ist
		return NULL;
	return stack->head->name;
}

void stack_pop(Stack *stack, char **name)
{
	stack = NULL;
	name = NULL;
	return;
}

int stack_size(Stack *stack){
  return stack->size;
}

void stack_print(Stack *stack)
{
	if (0 == stack->size)
		return;

	s_elem *current = stack->head;
	for(int i = 0; i < stack_size(stack); i++) {
		printf("(%d, %s)\n", current->index, current->name);
		current = current->predecessor;
	}

  return;
}
/* End of assignment -------------------------------------------------------------------------- */
