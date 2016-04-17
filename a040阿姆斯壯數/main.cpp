#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/* 大於 1000000 的阿姆斯壯數不會超過25個 */
int ArmstrongList[25] = { 0 }, ArmstrongListLast = 0;

inline void addArmstrong(int num)
{
	if (ArmstrongList[ArmstrongListLast - 1] < num)
		ArmstrongList[ArmstrongListLast++] = num;
}

bool Armstrong(int num)
{
	const int numBit = (int)log10(num) + 1;
	int bit, numTemp = num;
	for (bit = 0; bit < numBit; bit++)
	{
		num -= pow(numTemp % 10, numBit);
		if (num < 0)
			return false;

		numTemp /= 10;
	}

	return (num == 0);
}

void findArmstrong(int max)
{
	int num;
	for (num = ArmstrongList[ArmstrongListLast] + 1;
		num <= max; num++)
	{
		if (Armstrong(num))
			addArmstrong(num);
	}
}

int main(int argc, char *argv[])
{
	addArmstrong(1);

	int max, min;

	while (scanf("%d %d", &min, &max) != EOF)
	{
		if (ArmstrongList[ArmstrongListLast] < max)
			findArmstrong(max);

		bool isNone = true;

		int aList_i;
		for (aList_i = 0;
			aList_i < ArmstrongListLast;
			aList_i++)
		{
			if (min <= ArmstrongList[aList_i] &&
				ArmstrongList[aList_i] <= max)
			{
				isNone = false;
				printf("%d ", ArmstrongList[aList_i]);
			}
		}
		if (isNone)
			printf("none");
		printf("\n");
	}

	return 0;
}
