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
		int i, x[3] = { 0 };
		for (i = 0; i < n; i++)
		{
			int num;
			scanf("%d", &num);
			switch (num % 3)
			{
			case 0: x[0]++; break;
			case 1: x[1]++; break;
			case 2: x[2]++; break;
			default: break;
			}
		}
		printf("%d %d %d\n", x[0], x[1], x[2]);
	}

	return 0;
}
