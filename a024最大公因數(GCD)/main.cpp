#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <math.h>

int GCD(int a, int b)
{
	int max = (int)fmax(a, b),
		min = (int)fmin(a, b);

	if (max % min != 0)
		return GCD(min, max % min);
	else
		return min;
}

int main(int argc, char *argv[])
{
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		printf("%d\n", (a == b) ? a : GCD(a, b));
	}

	return 0;
}
