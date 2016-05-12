#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_INPUT_TEST_DATA 200000
#define PRIME_TABLE_MAX      46341  //sqrt(2147483647)

int primeNumListCount = 0;
int primeNumList[PRIME_TABLE_MAX] = { 0 };

#define getListMaxPrime() (primeNumList[primeNumListCount - 1])
#define addPrimeNumToList(x) (primeNumList[primeNumListCount++] = (x))

void initprimeNumList()
{
	if (primeNumListCount > 0)
		return;

	addPrimeNumToList(2);
	addPrimeNumToList(3);
	addPrimeNumToList(5);
	addPrimeNumToList(7);
	addPrimeNumToList(11);
}

void primeNumListPlus(unsigned int newLimit)
{
	int sqrtLimit = sqrt(newLimit);
	if (sqrtLimit > getListMaxPrime())
	{
		// 狦借计程计穝耎糤借计
		int num;
		for (num = getListMaxPrime() + 2;
			num < sqrtLimit;
			num += 2)
		{
			bool isPrime = true;
			int list_i;
			for (list_i = 0;
				list_i < primeNumListCount;
				list_i++)
			{
				if (num % primeNumList[list_i] == 0)
				{
					isPrime = false;
					break;
				}
			}
			if (isPrime)
				addPrimeNumToList(num);
		}
	}
}

int main(int argc, char *argv[])
{
	initprimeNumList();

	int num;
	while (scanf("%d", &num) != EOF)
	{
		debug(printf("[DEBUG] %d\n", num));
		primeNumListPlus(num);

		if (num <= getListMaxPrime())
		{
			bool isPrime = false;
			int list_i;
			for (list_i = 0;
				list_i < primeNumListCount;
				list_i++)
			{
				if (num == primeNumList[list_i])
					isPrime = true;
			}
			if (isPrime)
				printf("借计\n");
			else
				printf("獶借计\n");
		}
		else
		{
			bool isPrime = true;
			int list_i;
			for (list_i = 0;
				list_i < primeNumListCount;
				list_i++)
			{
				if (num % primeNumList[list_i] == 0)
				{
					isPrime = false;
					break;
				}
			}
			if (isPrime)
				printf("借计\n");
			else
				printf("獶借计\n");
		}
	}

	debug(
		int debug_i;
	for (debug_i = 0;
		debug_i < primeNumListCount;
		debug_i++)
	{
		printf("[DEBUG] primeNumList[%d] = %d\n",
			debug_i, primeNumList[debug_i]);
	});

	return 0;
}
