#ifndef MONTY_HEADER_FILE
#define MONTY_HEADER_FILE

#define _POSIX_C_SOURCE 2000809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


/**	Structure Definition	**/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob - the global structure to use in the functions
 * @quest:  flag that changes alternate queue and stack as required
 * @line: current line
 * @arg: second parameter on the current line
 * @head: doubly linked list
 * @fdes: monty file descriptor
 * @buff: buffer that holds the input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO project
 */
typedef struct globals
{
	int quest;
	unsigned int line;
	char  *arg;
	stack_t *head;
	FILE *fdes;
	char *buffer;
} glob_v;

extern glob_v global_var;

/*	Basic Monty Opcode Functions	*/
stack_t *add_endnode(stack_t **head, const int n);
stack_t *add_leadnode(stack_t **head, const int n);
void free_node(stack_t *head);
void (*sel_func(char *code))(stack_t **stack, unsigned int count);

/*	Instruction Code	*/
void o_push(stack_t **head, unsigned int c);
void o_pall(stack_t **head, unsigned int c);
void o_pint(stack_t **head, unsigned int c);
void o_pop(stack_t **head, unsigned int c);
void o_swap(stack_t **head, unsigned int c);
void o_queue(stack_t **head, unsigned int c);
void o_stack(stack_t **head, unsigned int c);
void o_add(stack_t **head, unsigned int c);
void o_nop(stack_t **head, unsigned int c);
void o_sub(stack_t **head, unsigned int c);
void o_div(stack_t **head, unsigned int c);
void o_mul(stack_t **head, unsigned int c);
void o_mod(stack_t **head, unsigned int c);
void o_pchar(stack_t **head, unsigned int c);
void o_pstr(stack_t **head, unsigned int c);
void o_rotl(stack_t **head, unsigned int c);
void o_rotr(stack_t **head, unsigned int c);


/*	Other Basic Important Functions For Opcode Operation	*/
char *_strngcut(char *str, char *de);
int _strcmp(char *s1, char *s2);
int _search(char *str, char c);

/*	Main Monty Opcode Functions	*/
void free_globalvar(void);
void globalvar_int(FILE *des);
FILE *check(int argc, char *argv[]);
int main(int argc, char *argv[]);
#endif /** MONTY_HEADER_FILE **/
