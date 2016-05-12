#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <math.h>

#define MAX_INPUT_TEST_DATA 200000

int main(int argc, char *argv[])
{
	int input[MAX_INPUT_TEST_DATA],
		input_count = 0,
		maxValue = 0;

	while (scanf("%d", &input[input_count]) != EOF)
	{
		maxValue = fmax(maxValue, input[input_count]);
		input_count++;
	}

	const int max_sqrt = ((int)ceil(sqrt(maxValue)));
	int i,
		primeTable[max_sqrt],
		tableCount = 0;

	primeTable[tableCount++] = 2;
	for (i = 3; i <= max_sqrt; i += 2)
	{
		int j, flag = 0;
		for (j = 0; j < tableCount; j++)
		{
			if (i % primeTable[j] == 0)
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			primeTable[tableCount++] = i;
		}
	}
	/*
	for(i = 0; i < tableCount; i++)
	{
	printf("primeTable[%d] = %d\n", i, primeTable[i]);
	}
	*/
	for (i = 0; i < input_count; i++)
	{
		int j, flag = 0;
		for (j = 0; j < tableCount && input[i] > primeTable[j]; j++)
		{
			if (input[i] % primeTable[j] == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			printf("非質數\n");
		}
		else
		{
			printf("質數\n");
		}
	}


	return 0;
}
