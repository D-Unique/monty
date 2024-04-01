#include <stdlib.h>
#include <stdio.h>

typedef struct stack_s
{int top;
int unsigned n; 
int* array;
}stack;

struct stack* create(unsigned int n)
{
	struct stack* stack = malloc(sizeof(struct stack));
	struct stack->n = n;
	struct stack->top = -1;
	struct stack->array = (int*)malloc(n * sizeof(int));
			return (struct stack);
}


int isfull(struct stack* stack){

	return(struct stack->top == stack->n - 1);
}

int isempty(struct stack* stack)
{
	return (struct stack->top == -1);
}
