#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <stdbool.h>

#define MAX_INPUT_BITS 12

bool checkZero(int *num, int bit)
{
	bool isZero = true;
	int i;
	for (i = bit; i >= 0 && isZero; i--)
	{
		isZero = isZero && (*(num + i) == 0);
	}

	return isZero;
}

int main(int argc, char *argv[])
{
	int input;
	while (scanf("%d", &input) != EOF)
	{
		if (input == 0)
		{
			printf("¹s\n");
			continue;
		}

		int num[MAX_INPUT_BITS] = { 0 };

		int i;
		for (i = 0;
			i < MAX_INPUT_BITS;
			i++)
		{
			num[i] = input % 10;
			input /= 10;
			if (input == 0)
				break;
		}

		debug(
			printf("[DEBUG] ");
		int DEBUG_i;
		for (DEBUG_i = MAX_INPUT_BITS - 1;
			DEBUG_i >= 0;
			DEBUG_i--)
		{
			printf("%d", num[DEBUG_i]);
		}
		printf("\n");
		);

		bool isZero = true, isContinue = false;
		for (i = MAX_INPUT_BITS - 1;
			i >= 0;
			i--)
		{
			if (checkZero(num, i))
				break;

			isZero = isZero && (num[i] == 0);
			if (isZero)
				continue;
			switch (num[i])
			{
			case 1:printf("³ü"); isContinue = false; break;
			case 2:printf("¶L"); isContinue = false; break;
			case 3:printf("°Ñ"); isContinue = false; break;
			case 4:printf("¸v"); isContinue = false; break;
			case 5:printf("¥î"); isContinue = false; break;
			case 6:printf("³°"); isContinue = false; break;
			case 7:printf("¬m"); isContinue = false; break;
			case 8:printf("®Ã"); isContinue = false; break;
			case 9:printf("¨h"); isContinue = false; break;
			case 0:
				if (!isContinue)
					printf("¹s");
				isContinue = true;
			}

			if (isContinue)
				continue;

			switch (i % 4)
			{
			case 1:printf("¬B"); break;
			case 2:printf("¨Õ"); break;
			case 3:printf("¥a"); break;
			}

			switch (i / 4)
			{
			case 1:printf("¸U"); break;
			case 2:printf("»õ"); break;
			}
		}
		printf("\n");

	}

	return 0;
}