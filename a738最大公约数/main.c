#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <math.h>

int EuclideanDivision(int a, int b)
{
	int max = (int)fmax(a, b), min = (int)fmin(a, b);
	debug(printf("[DEBUG] max = %d, min = %d\n", max, min));

	int remainder = max % min;

	return (remainder == 0) ? min : EuclideanDivision(min, remainder);
}

int main(int argc, char *argv[])
{
	int a, b;

	while (scanf("%d %d", &a, &b) != EOF)
	{
		debug(printf("[DEBUG] %d %d\n", a, b));

		printf("%d\n", EuclideanDivision(a, b));
	}

	return 0;
}
