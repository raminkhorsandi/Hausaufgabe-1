#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	int size;
	s_elem *head;	// head = pointer des Stacks = HEAD = START VOM STACK, einzige Stelle wo man sehen, weiter stappeln oder ein Element rausnehmen kann
};
/* Beginning of assignment -------------------------------------------------------------------------- */
struct s_elem
{
	char *name; //Anfang vom String
	int index;
	s_elem *predec; //pointer to the element under this one (predecessor), Referenz auf Predecesor! (einfache verkettete Liste)
	// TODO: One element of a stack consists of a name, an integer index and a pointer to the element under this one (predecessor)
};

Stack* stack_new()
{
	//TODO
	Stack *stack = malloc(sizeof(stack)); //Speicherplatz fuer Stack alluzieren 
	if(stack == NULL) return NULL; //falls Speicherplatz voll
	//stack->head = NULL; //head ist am Anfang NULL da Stack leer ist
	stack->size = 0;
	return stack; //returns adress=Pointer of Stack
	return NULL;
}

s_elem* s_elem_new(char* name)
{
	//TODO
	s_elem* elem = malloc(sizeof(s_elem));	////Speicherplatz fuer ein Element alluzieren
	if(elem == NULL) return NULL; //falls Speicherplatz voll
	elem->name = name; //An Adresse von name den Wert vonm Pointer des Argumentes name schreiben 
	elem->index = -1;
	elem->predec=NULL;
	return elem; //returns adress=Pointer of Element
	return NULL;
}

void stack_free(Stack *stack)
{
	//TODO
	free(stack);
	return;
}

char* stack_push(Stack *stack, s_elem* newElem)
{
  //TODO
	if(stack == NULL) return NULL; //error occurred
	if(stack->size == 0){	//falls Stack leer 
		stack->head = newElem; //newElem oder *newElem? ->Erstes Element
		newElem->index = 0;
		stack->size++;	//Stack wird ein Element groesser
		return newElem->name;
	}
	else{	//newElem ist nicht erstes Element im Stack
		newElem->predec = stack->head;
		newElem->index = stack->head->index + 1;
		stack->head = newElem; //neues Head
		stack->size++; //Stack wird ein Element groesser
		return newElem->name;
	}
}

char* stack_peek(Stack *stack)
{
	//TODO
	if(stack->size == 0){
		return NULL;
	}
	else{
		return stack->head->name;
	}
	return NULL; //falls Fehler
}

void stack_pop(Stack *stack, char **name)
{
	//TODO
	stack->size--;
	char* altName;
	stack->head->name = altName;
	stack->head=stack->head->predec; 
	//free(headPtr->name); //oder headPtr.name damit nur Adresse von Name?
	free(altName);
	//return **name;
	return;
}

int stack_size(Stack *stack){
	//TODO
	if(stack == NULL) return -1;
  return stack->size;
}

void stack_print(Stack *stack)
{
 	//TODO
 	if(stack->size == 0) return;
 	s_elem* current = stack->head;
 	while(current->predec != NULL){
 		printf("(%d,%s)\n",current->index,current->name);
 	}
  return;
}
/* End of assignment -------------------------------------------------------------------------- */
