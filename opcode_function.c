#include "monty.h"

/**
 * o_add - A function that add up the 2 topmost
 * elements on the stack.
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void o_add(stack_t **head, unsigned int c)
{
	int i = 0;
	stack_t *buf = NULL;

	buf = *head;

	while (buf != NULL)
	{
		buf = buf->next;
		i++;
	}
	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	buf = (*head)->next;
	buf->n += (*head)->n;
	o_pop(head, c);
}

/**
 * o_nop - A function that does nothing
 * @head: Thge head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void o_nop(stack_t **head, unsigned int c)
{
	(void)head;
	(void)c;
}

/**
 * o_sub - A function that subtracts the top element from the second
 * element at the top of the stack
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void o_sub(stack_t **head, unsigned int c)
{
	int v = 0;
	stack_t *buf = NULL;

	while (buf != NULL)
	{
		buf = buf->next;
		v++;
	}
	if (v < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	buf = (*head)->next;
	buf->n -= (*head)->n;
	o_pop(head, c);
}


/**
 * o_queue - A function that set the data format to a queue (FIFO)
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void o_queue(stack_t **head, unsigned int c)
{
	(void)head;
	(void)c;

	global_var.quest = 0;
}

/**
 * o_stack - A function that set the data format to a stack (LIFO)
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return nothing
 */
void o_stack(stack_t **head, unsigned int c)
{
	(void)head;
	(void)c;

	global_var.quest = 1;
}
