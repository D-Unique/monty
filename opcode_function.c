#include "monty.h"

/**
 * _add - A function that add up the 2 topmost
 * elements on the stack.
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void _add(stack_t **head, unsigned int c)
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
	buf->e += (*head)->e;
	_pop(head, c);
}

/**
 * _nop - A function that does nothing
 * @head: Thge head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void _nop(stack_t **head, unsigned int c)
{
	(void)head;
	(void)c;
}

/**
 * _queue - A function that set the data format to a queue (FIFO)
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void _queue(stack_t **head, unsigned int c)
{
	(void)head;
	(void)c;

	global_var.quest = 0;
}

/**
 * _stack - A function that set the data format to a stack (LIFO)
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return nothing
 */
void _stack(stack_t **head, unsigned int c)
{
	(void)head;
	(void)c;

	global_var.quest = 1;
}
