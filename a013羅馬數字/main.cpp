#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef struct _RomeNumValue
{
	char romeNum[3];
	int value;
}RomeNumValue;

const RomeNumValue ROME_NUM[] = {
	{ "I", 1 },
	{ "V", 5 },
	{ "X", 10 },
	{ "L", 50 },
	{ "C", 100 },
	{ "D", 500 },
	{ "M", 1000 }
};

const RomeNumValue SUB_ROME_NUM[] = {
	{ "IV", 4 },
	{ "IX", 9 },
	{ "XL", 40 },
	{ "XC", 90 },
	{ "CD", 400 },
	{ "CM", 900 }
};

int RomeToInt(char *romeNum)
{
	if (*(romeNum) != '\0')
	{
		int RN_i, sum = 0;

		for (RN_i = 0;
			RN_i < sizeof(ROME_NUM) / sizeof(RomeNumValue);
			RN_i++)
		{
			bool end = false;
			while (*(romeNum) != '\0'
				&& strchr(ROME_NUM[RN_i].romeNum, *(romeNum)) != NULL)
			{
				sum += ROME_NUM[RN_i].value;
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

char *IntToRome(int num, char romeNum[20])
{
	char *romeNumHead = romeNum;
	if (num == 0)
	{
		sprintf(romeNumHead, "%s", "ZERO");
		romeNumHead += strlen("ZERO");
	}
	else
	{
		int RN_i;
		for (RN_i = sizeof(ROME_NUM) / sizeof(RomeNumValue) - 1;
			RN_i >= 0;
			RN_i--)
		{
			if (RN_i <= sizeof(SUB_ROME_NUM) / sizeof(RomeNumValue) - 1)
			{
				if (num >= SUB_ROME_NUM[RN_i].value)
				{
					num -= SUB_ROME_NUM[RN_i].value;
					sprintf(romeNumHead, "%s",
						SUB_ROME_NUM[RN_i].romeNum);
					romeNumHead += strlen(SUB_ROME_NUM[RN_i].romeNum);
				}
			}
			while (num >= ROME_NUM[RN_i].value)
			{
				num -= ROME_NUM[RN_i].value;
				sprintf(romeNumHead, "%s", ROME_NUM[RN_i].romeNum);
				romeNumHead += strlen(ROME_NUM[RN_i].romeNum);
			}
		}
	}
	//sprintf(romeNumHead, "%c", '\0');

	return romeNum;
}

int main(int argc, char *argv[])
{
	while (true)
	{
		char romeNum[3][20] = { '\0' };

		scanf("%s", &romeNum[0]);

		if (romeNum[0][0] == '#')
			break;

		scanf("%s", &romeNum[1]);

		int num[2] = {
			RomeToInt(romeNum[0]),
			RomeToInt(romeNum[1])
		};
		debug(printf("[DEBUG]%d %d\n", num[0], num[1]));

		printf("%s\n", IntToRome(abs(num[0] - num[1]), romeNum[2]));
	}

	return 0;
}
