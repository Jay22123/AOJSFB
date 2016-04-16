#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdbool.h>

#define L_NUM_VALUE_MAX 10
#define L_NUM_BITS 500
#define L_NUM_SIZE (sizeof(int) * L_NUM_BITS)

int LnumTemp[L_NUM_BITS] = { 0 };

inline void clearLnum(int *Lnum)
{
	memset(Lnum, 0, L_NUM_SIZE);
}

void printLnum(int *Lnum)
{
	int bit;
	bool isValidBit = false;
	for (bit = L_NUM_BITS - 1; bit >= 0; bit--)
	{
		if (!isValidBit && *(Lnum + bit) != 0)
			isValidBit = true;

		if (isValidBit)
			printf("%d", *(Lnum + bit));
	}
	if (!isValidBit)
		printf("0");
}

void strToLnum(char *numStr, int *Lnum)
{
	clearLnum(Lnum);

	char *numStrPtr = numStr;
	int bit, numStrLen = strlen(numStr);

	for (bit = numStrLen - 1; bit >= 0; bit--)
	{
		sscanf(numStrPtr++, "%1d", (Lnum + bit));
	}

	debug(
		printf("[DEBUG]strToLnum: ");
	printLnum(Lnum);
	printf("\n");
	);
}

int getMSB(int *Lnum)
{
	int bit;
	for (bit = L_NUM_BITS - 1; bit >= 0; bit--)
	{
		if (*(Lnum + bit) != 0)
			return bit;
	}
	return 0;
}

inline bool isNegative(int *Lnum)
{
	return (*(Lnum + getMSB(Lnum)) < 0);
}

void shift(int *Lnum, int *shift, int offset)
{
	clearLnum(shift);

	int bit;
	for (bit = 0; bit < L_NUM_BITS; bit++)
	{
		if (bit + offset >= 0 &&
			bit + offset < L_NUM_BITS)
			*(shift + bit + offset) = *(Lnum + bit);
		else
			*(shift + bit + offset) = 0;
	}

	debug(
		printf("[DEBUG]shift: ");
	printLnum(shift);
	printf("\n");
	);
}

void LnumAdd(int *a, int *b, int *result)
{
	clearLnum(result);

	int bit;
	for (bit = 0; bit < L_NUM_BITS; bit++)
	{
		*(result + bit) += *(a + bit) + *(b + bit);
		if (*(result + bit) >= L_NUM_VALUE_MAX)
		{
			if ((bit + 1) < L_NUM_BITS)
				*(result + bit + 1) += *(result + bit) / 10;
			*(result + bit) %= 10;
		}
	}

	debug(
		printf("[DEBUG]LnumAdd: ");
	printLnum(result);
	printf("\n");
	);
}

void LnumSub(int *a, int *b, int *result)
{}

void LnumMul(int *a, int *b, int *result)
{}

void LnumDiv(int *a, int *b, int *result)
{}

int main(int argc, char *argv[])
{
	char op, numStr[2][501] = { NULL };

	while (scanf("%s %c %s\n", numStr[0], &op, numStr[1]) != EOF)
	{
		debug(printf("[DEBUG]%s %c %s\n", numStr[0], op, numStr[1]));

		int num[3][L_NUM_BITS] = { 0 };

		strToLnum(numStr[0], num[0]);
		strToLnum(numStr[1], num[1]);

		switch (op)
		{
		case '+':
			LnumAdd(num[0], num[1], num[2]); break;
		case '-':
			LnumSub(num[0], num[1], num[2]); break;
		case '*':
			LnumMul(num[0], num[1], num[2]); break;
		case '/':
			LnumDiv(num[0], num[1], num[2]); break;
		default:
			debug(printf("[DEBUG]op != '+'.'-'.'*'.'/'\n"));
			break;
		}

		printLnum(num[2]);
		printf("\n");
	}

	return 0;
}
