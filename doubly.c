#include "monty.h"

/**
 * add_endnode - A function that add node at the end of a
 * doubly linked list.
 * @head: The first position of the linked list
 * @n: The data to store
 *
 * Return: A doubly linked list
 */
stack_t *add_endnode(stack_t **head, const int n)
{
	stack_t *newnode, *buff;

	if (head == NULL)
		return (NULL);
	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		dprintf(2, "Error: malloc failed\n");
		free_globalvar();
		exit(EXIT_FAILURE);
	}
	newnode->n = n;

	if (*head == NULL)
	{
		newnode->next = *head;
		newnode->prev = NULL;
		*head = newnode;
		return (*head);
	}

	buff = *head;
	while (buff->next)
		buff = buff->next;
	newnode->next = buff->next;
	newnode->prev = buff;
	buff->next = newnode;
	return (buff->next);
}

/**
 * add_leadnode - A function that add a node at the beginning of
 * a doubly linked list
 * @head: The head of the doubly linked list
 * @n: The data to be stored
 *
 * Return: A doubly linked list
 */
stack_t *add_leadnode(stack_t **head, const int n)
{
	stack_t *newnode;

	if (head == NULL)
		return (NULL);
	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		dprintf(2, "Error: malloc failed\n");
		free_globalvar();
		exit(EXIT_FAILURE);
	}
	newnode->n = n;
	if (*head == NULL)
	{
		newnode->next = *head;
		newnode->prev = NULL;
		*head = newnode;
		return (*head);
	}
	(*head)->prev = newnode;
	newnode->next = (*head);
	newnode->prev = NULL;
	*head = newnode;
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
 * @code: The opcode passed to the function
 *
 * Return: A pointer to the function that executes the opcode
 */
void (*sel_func(char *code))(stack_t **head, unsigned int c)
{
	instruction_t instruct[] = {
		{"push", o_push},
		{"pall", o_pall},
		{"pint", o_pint},
		{"pop", o_pop},
		{"swap", o_swap},
		{"queue", o_queue},
		{"stack", o_stack},
		{"add", o_add},
		{"nop", o_nop},
		{"sub", o_sub},
		{"mul", o_mul},
		{"div", o_div},
		{"mod", o_mod},
		{"pchar", o_pchar},
		{"pstr", o_pstr},
		{"rotl", o_rotl},
		{"rotr", o_rotr},
		{NULL, NULL}
	};
	int a;

	for (a = 0; instruct[a].opcode; a++)
	{
		if (_strcmp(instruct[a].opcode, code) == 0)
			break;
	}
	return (instruct[a].f);
}
