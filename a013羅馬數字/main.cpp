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

int RomeToInt(char *romeNum, unsigned int strLen)
{
	if (strLen > 0)
	{
		bool end = false;
		int i, RN_i, sum = 0, num;

		for (RN_i = 0;
			RN_i < 7, sum == 0, end != true;
			RN_i++)
		{
			for (i = 0;
				*(romeNum + i) == ROME_NUM[RN_i].romeNum, i < strLen;
				i++)
			{
				sum += ROME_NUM[RN_i].romeNum;
				end = true;
			}
		}

		num = RomeToInt(romeNum, strLen - i);
		if (sum < num)
			sum = -sum;

		return sum + num;
	}

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
			RomeToInt(romeNum[0], strlen(romeNum[0])),
			RomeToInt(romeNum[1], strlen(romeNum[1]))
		};
		debug(printf("[DEBUG]%d %d", num[0], num[1]));

		printf("\n");
	}

	return 0;
}
