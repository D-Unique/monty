#include "monty.h"

/**
 * o_div - A function that divides the second element on the
 * stack by the topmost element on the stack
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void o_div(stack_t **head, unsigned int c)
{
	int v = 0;
	stack_t *buf = NULL;

	buf = *head;

	while (buf != NULL)
	{
		buf = buf->next;
		v++;
	}
	if (v < 2)
	{
		dprintf(2, "L%u: can't div, stack is too short\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	buf = (*head)->next;
	buf->n /= (*head)->n;
	o_pop(head, c);
}

/**
 * o_mul - A function that multiplies the topmost element on the
 * stack with the second element on the stack
 * @head: The head of the doubly linked list
 * @c; The count of the line number
 *
 * Return: nothing
 */
void o_mul(stack_t **head, unsigned int c)
{
	int v = 0;
	stack_t *buf = NULL;

	buf = *head;

	while (buf != NULL)
	{
		buf = buf->next;
		v++;
	}
	if (v < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	buf = (*head)->next;
	buf->n *= (*head)->n;
	o_pop(head, c);
}

/**
 * o_mod - A function that gives the reminder from a division of
 * of the second element on the stack with the first element.
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void o_mod(stack_t **head, unsigned int c)
{
	int v = 0;
	stack_t *buf = NULL;

	buf = *head;

	while (buf != NULL)
	{
		buf = buf->next;
		v++;
	}

	if (v < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	buf = (*head)->next;
	buf->n %= (*head)->n;
	o_pop(head, c);
}

/**
 * o_pchar - A function that print the char value of the first
 * element on the stack.
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void o_pchar(stack_t **head, unsigned int c)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
 * o_pstr - A function that prints the string on the stack
 *
 * @head: head of the doubly linked list
 * @c: The count of the line number(s)
 *
 * Return: nothing
 */
void o_pstr(stack_t **head, unsigned int c)
{
	stack_t *buf;
	(void)c;

	buf = *head;

	while (buf && buf->n > 0 && buf->n < 128)
	{
		printf("%c", buf->n);
		buf = buf->next;
	}
	printf("\n");
}
