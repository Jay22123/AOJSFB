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

int LnumTemp[L_NUM_BITS] = { 0 };
inline void clearTemp()
{
	memset(LnumTemp, 0, sizeof(LnumTemp));
}

void printLnum(int Lnum[L_NUM_BITS])
{
	int bit;
	bool isValidBit = false;
	for (bit = L_NUM_BITS - 1; bit >= 0; bit--)
	{
		if (!isValidBit && Lnum[bit] != 0)
			isValidBit = true;

		if (isValidBit)
			printf("%d", Lnum[bit]);
	}
	if (!isValidBit)
		printf("0");
}

void strToLnum(char numStr[501], int Lnum[L_NUM_BITS])
{
	char *numStrPtr = numStr;
	int bit, numStrLen = strlen(numStr);

	for (bit = numStrLen - 1; bit >= 0; bit--)
	{
		sscanf(numStrPtr++, "%1d", &Lnum[bit]);
	}

	debug(
		printf("[DEBUG]toLnum - ");
	printLnum(Lnum);
	printf("\n");
	);
}

void LnumAdd(int a[L_NUM_BITS], int b[L_NUM_BITS], int sum[L_NUM_BITS])
{
	clearTemp();
	int bit;
	for (bit = 0; bit < L_NUM_BITS; bit++)
	{
		LnumTemp[bit] += (a[bit] + b[bit]);

		if (bit + 1 < L_NUM_BITS && LnumTemp[bit] >= L_NUM_VALUE_MAX)
			LnumTemp[bit + 1] += LnumTemp[bit] / L_NUM_VALUE_MAX;

		LnumTemp[bit] %= L_NUM_VALUE_MAX;
	}
	memcpy(sum, LnumTemp, sizeof(LnumTemp));

	debug(
		printf("[DEBUG]LnumAdd - ");
	printLnum(sum);
	printf("\n");
	);
}

void LnumSub(int a[L_NUM_BITS], int b[L_NUM_BITS], int sub[L_NUM_BITS])
{
	clearTemp();
	int bit;
	for (bit = 0; bit < L_NUM_BITS; bit++)
	{
		LnumTemp[bit] = (LnumTemp[bit] + a[bit] - b[bit]);

		if ((LnumTemp[bit] < 0)
			&& ((bit + 1) < L_NUM_BITS))
		{
			--LnumTemp[bit + 1];
			LnumTemp[bit] += L_NUM_VALUE_MAX;
		}
	}
	memcpy(sub, LnumTemp, sizeof(LnumTemp));

	debug(
		printf("[DEBUG]LnumAdd - ");
	printLnum(sub);
	printf("\n");
	);
}

void shift(int num[L_NUM_BITS], int shiftBit)
{
	clearTemp();
	debug(printf("[DEBUG](sizeof(num) * L_NUM_BITS)=%d\n", sizeof(num) * L_NUM_BITS));
	memcpy(LnumTemp, num, sizeof(num) * L_NUM_BITS);
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
			num[bit] = LnumTemp[bit - shiftBit];
		}
		else
			num[bit] = 0;
	}

	debug(
		printf("[DEBUG]shift - num: ");
	printLnum(num);
	printf("\n");
	);
}

void LnumMul(int a[L_NUM_BITS], int b[L_NUM_BITS], int product[L_NUM_BITS])
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

void LnumDiv(int a[L_NUM_BITS], int b[L_NUM_BITS], int quotient[L_NUM_BITS])
{
	int bit;
	for (bit = 0; bit < L_NUM_BITS; bit++)
	{
		int count;
		for (count = 0; count < b[bit]; count++)
		{
			LnumAdd(quotient, a, quotient);
		}
		shift(a, 1);
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
			/*LnumAdd(num[0], num[1], num[2]);*/ break;
		default:
			debug(printf("[DEBUG]op != '+'.'-'.'*'.'/'\n"));
			break;
		}

		printLnum(num[2]);
		printf("\n");
	}

	return 0;
}
