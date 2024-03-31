#include "monty"

/**
 * _push - An opcode that pushes an element to the stack
 * @head: The head of the linked list
 * @c: counter of the line number
 *
 * Return: nothing
 */
void _push(stack_t **head, unsigned int c)
{
	int p, r, flag = 0;

	if (!global_var.arg)
	{
		dprintf(2, "L%u: ", c);
		dprintf(2, "usage: push integer\n");
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	for (r = 0; global_var.arg[r] != '\0'; r++)
	{
		if (!isdigit(global_var.arg[r]) && global_var.arg[r] != '-')
		{
			dprint(2, "L%u: ", c);
			dprint(2, "usage: push integer\n");
			free_globalvar();
			exit(EXIT_FAILURE);
		}
	}

	p = atoi(global_var.arg);

	if (global_var.quest == 1)
		add_leadnode(head, p);
	else
		add_endnode(head, p);
}

/**
 * _pall - A function that prints the values on the stack
 *
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void _pall(stack_t **head, unsigned int c)
{
	stack_t *buf;
	(void)c;

	buf = *head;

	while (buf)
	{
		printf("%d\n", buf->e);
		buf = buf->next;
	}
}

/**
 * _pint - A function that prints the value of data at the
 * top of the stack
 *
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 *
 * Return: nothing
 */
void _pint(stack_t **head, unsigned int c)
{
	(void)c;

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", c);
		dprintf(2, "can't pint, stack empty\n");
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * _pop - A function that removes the topmost element from the stack
 * @head: The head of the doubly linked list
 * @c: The count of the line
 *
 * Return: nothing
 */
void _pop(stack_t **head, unsigned int c)
{
	stack_t *buf;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", c);
		free_globalvar();
		exit(EXIT_FAILURE);
	}
	buf = *head;
	*head = (*head)->next;
	free(buf);
}

/**
 * _swap - A function that swaps the top two elements of a
 * given stack
 * @head: The head of the doubly linked list
 * @c: The count of the line number
 * Return: nothing
 */
void _swap(stack_t **head, unsigned int c)
{
	int n = 0;
	stack_t *buf = NULL;

	buf = *head;

	while (buf != NULL)
	{
		buf = buf->next;
		n++;
	}

	if (n < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", c)
			free_globalvar();
		exit(EXIT_FAILURE);
	}

	buf = *head;
	*head = (*head)->next;
	buf->next = (*head)->next;
	buf->prev = *head;
	(*head)->next = buf;
	(*head)->prev = NULL;
}
