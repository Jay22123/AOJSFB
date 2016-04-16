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
#define L_NUM_SIZE sizeof(int) * L_NUM_BITS

#define MAX(a,b) ((a) > (b))?(a):(b)

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
	char *numStrPtr = numStr;
	int bit, numStrLen = strlen(numStr);

	for (bit = numStrLen - 1; bit >= 0; bit--)
	{
		sscanf(numStrPtr++, "%1d", (Lnum + bit));
	}

	debug(
		printf("[DEBUG]toLnum - ");
	printLnum(Lnum);
	printf("\n");
	);
}

void LnumAdd(int *a, int *b, int *sum)
{
	clearLnum(LnumTemp);
	int bit;
	for (bit = 0; bit < L_NUM_BITS; bit++)
	{
		*(LnumTemp + bit) += (*(a + bit) + *(b + bit));

		if (bit + 1 < L_NUM_BITS && LnumTemp[bit] >= L_NUM_VALUE_MAX)
			*(LnumTemp + bit + 1) += *(LnumTemp + bit) / L_NUM_VALUE_MAX;

		*(LnumTemp + bit) %= L_NUM_VALUE_MAX;
	}
	memcpy(sum, LnumTemp, L_NUM_SIZE);

	debug(
		printf("[DEBUG]LnumAdd - ");
	printLnum(sum);
	printf("\n");
	);
}

void LnumIncr(int *a)
{
	int Lnum_1[L_NUM_BITS] = { 0 };
	Lnum_1[0] = 1;
	LnumAdd(a, Lnum_1, a);
}

int getMSB(int *num)
{
	int bit;
	for (bit = L_NUM_BITS - 1; bit >= 0; bit--)
	{
		if (*(num + bit) != 0)
			return bit;
	}

	return 0;
}

/* is (A < B) ? */
bool lessThan(int *a, int *b)
{
	bool notEqual = true;
	int bit;
	for (bit = MAX(getMSB(a), getMSB(b)); bit >= 0; bit--)
	{
		if (*(a + bit) > *(b + bit))
			return false;
		else if (*(a + bit) == *(b + bit))
			notEqual &= false;
	}

	return (notEqual == false);
}

void LnumSub(int *a, int *b, int *sub)
{
	clearLnum(LnumTemp);

	int *max, *min;

	bool negative = lessThan(a, b);
	if (negative)
	{
		max = b;
		min = a;
	}
	else
	{
		max = a;
		min = b;
	}

	int bit;
	for (bit = 0; bit < L_NUM_BITS; bit++)
	{
		LnumTemp[bit] += (*(max + bit) - *(min + bit));

		if ((LnumTemp[bit] < 0)
			&& ((bit + 1) < L_NUM_BITS))
		{
			--LnumTemp[bit + 1];
			LnumTemp[bit] += L_NUM_VALUE_MAX;
		}
	}

	if (negative)
		LnumTemp[getMSB(LnumTemp)] *= -1;
	memcpy(sub, LnumTemp, L_NUM_SIZE);

	debug(
		printf("[DEBUG]LnumSub - ");
	printLnum(sub);
	printf("\n");
	);
}

void shift(int *num, int shiftBit)
{
	clearLnum(LnumTemp);
	memcpy(LnumTemp, num, L_NUM_SIZE);
	debug(
		printf("[DEBUG]shift - src: ");
	printLnum(LnumTemp);
	printf("\n");
	);

	int bit;
	for (bit = 0; bit < L_NUM_BITS; bit++)
	{
		if ((bit - shiftBit) >= 0
			&& (bit - shiftBit) < L_NUM_BITS)
		{
			*(num + bit) = LnumTemp[bit - shiftBit];
		}
		else
			*(num + bit) = 0;
	}

	debug(
		printf("[DEBUG]shift - num: ");
	printLnum(num);
	printf("\n");
	);
}

void LnumMul(int *a, int *b, int *product)
{
	int bit;
	for (bit = 0; bit < L_NUM_BITS; bit++)
	{
		int count;
		for (count = 0; count < b[bit]; count++)
		{
			LnumAdd(product, a, product);
		}
		shift(a, 1);
	}

	debug(
		printf("[DEBUG]LnumMul - ");
	printLnum(product);
	printf("\n");
	);
}

void LnumDiv(int *a, int *b, int *quotient)
{
	debug(
		printf("[DEBUG]LnumDiv - (a < b) = ");
	if (lessThan(a, b))
		printf("true\n");
	else
		printf("false\n");
	);

	while (lessThan(a, b) != true)
	{
		LnumSub(a, b, a);
		LnumIncr(quotient);
	}

	debug(
		printf("[DEBUG]LnumDiv - ");
	printLnum(quotient);
	printf("\n");
	);
}

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
