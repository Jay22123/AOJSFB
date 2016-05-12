#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

const int VALUE[] = {
	10, /*A*/
	11, /*B*/
	12, /*C*/
	13, /*D*/
	14, /*E*/
	15, /*F*/
	16, /*G*/
	17, /*H*/
	34, /*I*/
	18, /*J*/
	19, /*K*/
	20, /*L*/
	21, /*M*/
	22, /*N*/
	35, /*O*/
	23, /*P*/
	24, /*Q*/
	25, /*R*/
	26, /*S*/
	27, /*T*/
	28, /*U*/
	29, /*V*/
	32, /*W*/
	30, /*X*/
	31, /*Y*/
	33  /*Z*/
};

int main(int argc, char *argv[])
{
	char ch;
	int num;

	while (scanf("%c%d\n", &ch, &num) != EOF)
	{
		debug(printf("[DEBUG]%c%d\n", ch, num));
		debug(printf("[DEBUG]%c = %d\n", ch, VALUE[ch - 'A']));

		int i, cheak = VALUE[ch - 'A'] / 10 + (VALUE[ch - 'A'] % 10) * 9;
		cheak += num % 10;
		num /= 10;
		for (i = 1; i <= 8; i++)
		{
			cheak += (num % 10) * i;
			num /= 10;
		}
		debug(printf("[DEBUG]cheak = %d\n", cheak));

		printf("%s\n", (cheak % 10 == 0) ? "real" : "fake");
	}

	return 0;
}
