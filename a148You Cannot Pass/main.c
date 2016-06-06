#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int i, x;
		float sum = 0;
		for (i = 0; i < n; i++)
		{
			scanf(" %d", &x);
			sum += x;
		}
		debug(printf("[DEBUG] %f\n", round(sum / n)));
		printf("%s\n", (round(sum / n) < 60) ? "yes" : "no");
	}

	return 0;
}
