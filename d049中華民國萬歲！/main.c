#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int y;

	while (scanf("%d", &y) != EOF)
	{
		printf("%d\n", y - 1911);
	}

	return 0;
}
