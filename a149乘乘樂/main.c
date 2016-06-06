#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int T;
	scanf("%d", &T);
	debug(printf("[DEBUG] T=%d\n", T));

	int i;
	for (i = 0; i < T; i++)
	{
		int n = 0;
		scanf("%d", &n);
		debug(printf("[DEBUG] n=%d\n", n));

		int result = 1;
		if (n > 0)
			for (; n > 0; n /= 10)
			{
				result *= (n % 10);
				debug(printf("[DEBUG] %d\n", result));
			}
		else
			result = 0;

		printf("%d\n", result);
	}

	return 0;
}
