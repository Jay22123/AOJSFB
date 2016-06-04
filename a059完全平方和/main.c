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
		int i;
		for (i = 0; i < n; i++)
		{
			int j, a, b, sum = 0;
			scanf("%d", &a);
			scanf("%d", &b);

			for (j = sqrt(a); j * j <= b; j++)
			{
				if (j * j >= a)
					sum += j * j;
			}
			printf("Case %d: %d\n", i + 1, sum);
		}
	}

	return 0;
}
