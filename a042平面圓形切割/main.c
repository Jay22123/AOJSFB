#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n", 2 + n * (n - 1));
	}

	return 0;
}
