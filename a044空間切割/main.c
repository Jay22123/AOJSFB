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
		int ans = ((n + 1) * (n*n - n + 6)) / 6;
		printf("%d\n", ans);
	}

	return 0;
}
