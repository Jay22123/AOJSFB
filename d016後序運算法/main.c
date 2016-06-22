#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int getLine(char *strBuf)
{
	char input;

	int isEOF = 0, seek = ftell(stdin);
	while (1)
	{
		isEOF = fscanf(stdin, "%c", &input);
		if (input == '\n')
			break;
		if (isEOF == EOF)
		{
			if (seek + 1 < ftell(stdin))
			{
				fseek(stdin, -1, SEEK_CUR);
				isEOF = 1;
			}
			break;
		}
		*(strBuf++) = input;
	}
	*(strBuf++) = '\0';

	return isEOF;
}

/* 堆疊相關程式 開始 */
typedef struct _Stack
{
	int data;
	struct _Stack *prev;
}Stack;

void push(Stack **stack, int data)
{
	Stack *input = (Stack *)malloc(sizeof(Stack));
	input->data = data;
	input->prev = *stack;
	*stack = input;
}

int pop(Stack **stack)
{
	Stack *popStack = *stack;
	*stack = popStack->prev;
	int result = popStack->data;

	free(popStack);
	return result;
}
/* 堆疊相關程式 結束 */

int main(int argc, char *argv[])
{
	char input[1000] = { NULL };

	while (getLine(input) != EOF)
	{
		debug(printf("[DEBUG] %s\n", input));

		Stack *numStack = NULL;

		int i;
		for (i = 0; i < strlen(input); i++)
		{
			if (isdigit(input[i]))
			{
				int num;
				sscanf(&input[i], "%d", &num);
				push(&numStack, num);

				i += (int)log10(num) + 1;
			}
			else if (ispunct(input[i]))
			{
				int b = pop(&numStack),
					a = pop(&numStack),
					c = 0;

				switch (input[i])
				{
				case '+': c = a + b; break;
				case '-': c = a - b; break;
				case '*': c = a * b; break;
				case '/': c = a / b; break;
				case '%': c = a % b; break;
				}
				push(&numStack, c);
			}
		}
		printf("%d\n", pop(&numStack));
	}

	return 0;
}
