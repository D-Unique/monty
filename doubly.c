#include "monty.h"

/**
 * add_endnode - A function that add node at the end of a
 * doubly linked list.
 * @head: The first position of the linked list
 * @e: The data to store
 *
 * Return: A doubly linked list
 */
stack_t add_endnode(stack_t **head, const int e)
{
	stack_t *tmp, *buff;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_globalvar();
		exit(EXIT_FAILURE);
	}
	tmp->e = e;

	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}

	buff = *head;
	while (buff->next)
		buff = buff->next;
	tmp->next = buff->next;
	tmp->prev = buff;
	buff->next = tmp;
	return (buff->next);
}

/**
 * add_leadnode - A function that add a node at the beginning of
 * a doubly linked list
 * @head: The head of the doubly linked list
 * @e: The data to be stored
 *
 * Return: A doubly linked list
 */
stack_t *add_leadnode(stack_t **head, const int e)
{
	stack_t *buf;

	if (head == NULL)
		return (NULL);
	buf = malloc(sizeof(stack_t));
	if (!buf)
	{
		dprintf(2, "Error: malloc failed\n");
		free_globalvar();
		exit(EXIT_FAILURE);
	}
	buf->e = e;
	if (*head == NULL)
	{
		buf->next = *head;
		buf->prev = NULL;
		*head = buf;
		return (*head);
	}
	(*head)->prev = buf;
	buf->next = (*head);
	buf->prev = NULL;
	*head = buf;
	return (*head);
}

/**
 * free_node - A function that freed doubly linked list
 * @head: Head of the doubly linked list
 *
 * Return: Return nothing
 */
void free_node(stack_t *head)
{
	stack_t *buf;

	while ((buf = head) != NULL)
	{
		head = head->next;
		free(buf);
	}
}

/**
 * sel_func - A function that select the right function to perform
 * required operation on given opcode.
 * @code: opcode
 *
 * Return: A pointer to the function that executes the opcode
 */
void (*sel_func(char *code))(stack_t **stack, unsigned int count)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"queue", _queue},
		{"stack", _stack},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	int c;

	for (c = 0; instruct[c].opcode; c++)
	{
		if (_strcmp(instruct[c].opcode, code) == 0)
			break;
	}
	return (instruct[c].f);
}
