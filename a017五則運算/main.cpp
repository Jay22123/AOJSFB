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

	popStack->prev = NULL;
	free(popStack);
	return result;
}

int last(Stack **stack)
{
	return (*stack)->data;
}
/* 堆疊相關程式 結束 */


/* 後序式運算 */
int postfixCal(char *input)
{
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

	return pop(&numStack);
}


// 運算式結尾定義
enum
{
	EOE = 0
};

// 輸入優先級
int icp(char op)
{
	switch (op)
	{
	case '+':
	case '-': return 12;
	case '*':
	case '/':
	case '%': return 13;
	case '(': return 20;
	case ')': return 19;
	case EOE: return EOE;
	}
}

// 堆疊優先級
int isp(char op)
{
	switch (op)
	{
	case '+':
	case '-': return 12;
	case '*':
	case '/':
	case '%': return 13;
	case '(': return 0;
	case ')': return 19;
	case EOE: return EOE;
	}
}


int main(int argc, char *argv[])
{
	char str[200] = { NULL };

	while (getLine(str) != EOF)
	{
		debug(printf("[DEBUG] %s\n", str));

		char equation[200] = "";

		Stack *opStack = NULL;
		push(&opStack, EOE);
		char *strPtr = str;
		for (; *strPtr != '\0'; strPtr++)
		{
			if (*strPtr == ' ')
				continue;
			else if (isdigit(*strPtr))
			{
				int num = 0;
				sscanf(strPtr, "%d", &num);
				sprintf(equation, "%s %d", equation, num);
				strPtr += (int)log10(num);
			}
			else if (ispunct(*strPtr))
			{
				if (*strPtr == ')')
				{
					while (last(&opStack) != '(')
					{
						sprintf(equation, "%s %c", equation, pop(&opStack));
					}
					pop(&opStack); // pop '('
				}
				else
				{
					while ((isp(last(&opStack)) >= icp(*strPtr)))
					{
						sprintf(equation, "%s %c", equation, pop(&opStack));
					}
					push(&opStack, *strPtr);
				}
			}
		}

		while (last(&opStack) != EOE)
		{
			sprintf(equation, "%s %c", equation, pop(&opStack));
		}
		pop(&opStack); // pop 'EOE'

		debug(printf("[DEBUG] %s\n", equation));
		printf("%d\n", postfixCal(equation));
	}

	return 0;
}
