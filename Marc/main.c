#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
/*
This main function is an example to test the implemented data structure and its functions.
Be advised that further tests will be conducted to grade the submission.
*/
int main()
{

	Stack *stack = NULL;
	stack = stack_new();
	char *tempName = NULL;
	printf("---\n");
	stack_push(stack, s_elem_new("Null"));
	stack_push(stack, s_elem_new("Eins"));
	stack_push(stack, s_elem_new("Zwei"));
	stack_print(stack);
	printf("---\n");
	stack_pop(stack, &tempName);
	stack_print(stack);
	printf("---\n");
	stack_push(stack, s_elem_new("Zwei"));
	stack_push(stack, s_elem_new("Drei"));
	stack_push(stack, s_elem_new("Vier"));
	stack_print(stack);

	printf("%s\n", tempName);

	// free(tempName);
	stack_free(stack);
	printf("%s\n", tempName);

	return 0;
}
