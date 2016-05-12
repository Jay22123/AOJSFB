#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	long long a, b;

	while (scanf("%lld %lld", &a, &b) != EOF)
	{
		printf("%lld\n", llabs(a - b));
	}

	return 0;
}
