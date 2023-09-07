#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (monty.arg)
	{
		if (monty.arg[0] == '-')
			j++;
		for (; monty.arg[j] != '\0'; j++)
		{
			if (monty.arg[j] > 57 || monty.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(monty.file);
			free(monty.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(monty.file);
		free(monty.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(monty.arg);
	if (monty.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
