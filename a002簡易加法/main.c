#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int a, b;

	while (scanf("%d %d", &a, &b) != EOF)
	{
		debug(printf("[DEBUG]a = %d, b = %d\n", a, b));
		printf("%d\n", a + b);
	}

	return 0;
}
