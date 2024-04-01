#include "function.c"

void push(struct stack, int ele)
{
 if(isfull(stack))
 {
	 printf("stack is full");
	 return;
 }

 stack->array[++stack->top]  = ele;
}
