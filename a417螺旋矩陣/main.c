#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int T = 0;

	while (scanf("%d", &T) != EOF)
	{
		debug(printf("[DEBUG] %d\n", T));

		int t;
		for (t = 0; t < T; t++)
		{
			int N, M;
			scanf("%d %d", &N, &M);
			debug(printf("[DEBUG] %d %d\n", N, M));
		}
	}

	return 0;
}
