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
struct s_elem // done
{
	char *name; // name "string"
	int index;
	s_elem *predecessor; // points to element below the current one
};

Stack* stack_new() // done
{
	Stack *stack = malloc(sizeof(Stack)); // Speicher für den Stack
	if(NULL == stack)
		return NULL;
	else
		return stack;
}

s_elem* s_elem_new(char* name) // done
{
	s_elem *element = malloc(sizeof(s_elem)); // Speicher für element
	if (NULL == element)
		return NULL;

	element->name = malloc(sizeof(*name)); // Speicher für name
	if (NULL == element->name)
		return NULL;
	else
		element->name = name;
	element->index = -1;

	element->predecessor = malloc(sizeof(s_elem)); // Speicher für predecessor
	if (NULL == element->predecessor)
		return NULL;

	return element;
}

// void stack_free(Stack *stack)
// {
// 	s_elem *current = stack->head;
// 	s_elem *next;
// 	do {
// 		next = current->predecessor;
//
// 		free(current->name);
// 		free(current->predecessor);
// 		free(current);
//
// 		current = next;
// 	} while(NULL != next);
//
// 	free(stack);
//
// 	return;
// }

char* stack_push(Stack *stack, s_elem* newElem)
{
	// if stack or element are not valid
	if (NULL == stack || NULL == newElem) {
		return NULL;
	}

	// new head element - make old head accessible via *predecessor
	newElem->predecessor = stack->head;
	stack->head = newElem;

	(stack->head)->index = stack->size;
	// increase size of stack
	++(stack->size);

	return (stack->head)->name;
}

char* stack_peek(Stack *stack)
{
	if (NULL == stack || NULL == stack->head) {
		return NULL;
	}

	return (stack->head)->name;
}

// void stack_pop(Stack *stack, char **name)
// {
//
// 	//TODO
// 	return;
// }

int stack_size(Stack *stack){
  return stack->size;
}

void stack_print(Stack *stack)
{
 	// for (s_elem *elem = stack->head; NULL != elem->predecessor; elem = elem->predecessor) {
	// 	printf("(%s, %d)\n", elem->name, elem->index);
	// }
	// s_elem *elem = stack->head;
	// for (int i = 0; i < stack_size(stack); i++) {
	// 	printf("(%s, %d)\n", elem->name, elem->index);
	// 	elem = elem->predecessor;
	// }
	// free(elem);
	stack = NULL;
  return;
}

/* End of assignment -------------------------------------------------------------------------- */
