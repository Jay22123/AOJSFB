#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int N, M;

	while (scanf("%d %d", &N, &M) != EOF)
	{
		debug(printf("[DEBUG] %d %d\n", N, M));

		printf("%d\n", (N == M) ? M : M + 1);
	}

	return 0;
}
