#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int num;

	while (scanf("%d", &num) != EOF)
	{
		int bit;
		for (bit = (int)log2(num);
			bit >= 0;
			bit--)
		{
			int pow2X = (int)pow(2, bit);
			printf("%1d", (num / pow2X));
			num %= pow2X;
		}
		printf("\n");
	}

	return 0;
}
