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
		if (n <= 10)
			printf("%d\n", 6 * n);
		else if (n <= 20)
			printf("%d\n", 2 * (n - 10) + 60);
		else if (n <= 40)
			printf("%d\n", (n - 20) + 80);
		else
			printf("100\n");
	}

	return 0;
}
