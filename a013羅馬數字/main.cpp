#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct _RomeNumValue
{
	char romeNum;
	int num;
}RomeNumValue;

const RomeNumValue ROME_NUM[] = {
	{ 'I', 1 },
	{ 'V', 5 },
	{ 'X', 10 },
	{ 'L', 50 },
	{ 'C', 100 },
	{ 'D', 500 },
	{ 'M', 1000 }
};

int RomeToInt(char *romeNum)
{
	if (*(romeNum) != '\0')
	{
		int RN_i, sum = 0;

		for (RN_i = 0; RN_i < 7; RN_i++)
		{
			bool end = false;
			while (*(romeNum) != '\0'
				&& *(romeNum) == ROME_NUM[RN_i].romeNum)
			{
				sum += ROME_NUM[RN_i].num;
				++romeNum;
				end = true;
			}
			if (end)
				break;
		}

		int num = RomeToInt(romeNum);

		if (sum < num)
			sum = -sum;

		return sum + num;
	}

	return 0;
}

char *IntToRome(int num)
{
	if (num == 0)
		return "ZERO";

	return 0;
}

int main(int argc, char *argv[])
{
	while (true)
	{
		char romeNum[2][20] = { '\0' };

		scanf("%s", &romeNum[0]);

		if (romeNum[0][0] == '#')
			break;

		scanf("%s", &romeNum[1]);

		int num[2] = {
			RomeToInt(romeNum[0]),
			RomeToInt(romeNum[1])
		};
		debug(printf("[DEBUG]%d %d\n", num[0], num[1]));

		printf("%s\n", IntToRome(num[0] - num[1]));
	}

	return 0;
}
