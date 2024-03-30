#include "monty.h"

/**
 * free_globalvar - A function that free up global variable
 *
 * Return: nothing
 */
void free_globalvar(void)
{
	free_node(global_var.head);
	free(global_var.buffer);
	fclose(global_var.fdes);
}

/**
 * globalvar_init - A function that initialise the global variable
 *
 * @fdes: file descriptor
 *
 * Return: nothing
 */
void globalvar_init(FILE *fdes)
{
	global_var.quest = 1;
	global_var.line = 1;
	global_var.arg = NULL;
	global_var.head = NULL;
	global_var.fdes = fdes;
	global_var.buff = NULL;
}

/**
 * check - A function that checks if a file exit and can be opened
 * @argc: count of the argument
 * @argv: Argument array vector
 *
 * Return: file struct
 */
FILE *check(int argc, char *argv[])
{
	FILE *fdes;

	if (argc == 1 || argc > 2)
	{
		dprint(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fdes = fopen(argv[1], "r");

	if (fdes == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fdes);
}

/**
 * main - The main function
 *
 * @argc: Count of the argument(s)
 * @argv: Array of the argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fdes;
	size_t sz = 256;
	ssize_t line_no = 0;
	char *line[2] = {NULL, NULL};

	fdes = check(argc, argv);
	globalvar_init(fdes);
	line_no = getline(&global_var.buff, &sz, fdes);
	while (line_no >= 0)
	{
		line[0] = _strngcut(global_var.buff, " \t\n");
		if (line[0] && line[0][0] != '#')
		{
			f = sel_func(line[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", global_var.line);
				dprintf(2, "unknown instruction %s\n", line[0]);
				free_globalvar();
				exit(EXIT_FAILURE);
			}
			global_var.arg = _strngcut(NULL, " \t\n");
			f(&global_var.head, global_var.line);
		}
		line_no = getline(&global_var.buff, &sz, fdes);
		global_var.line++;
	}

	free_globalvar();
	return (0);
}
