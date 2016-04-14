#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int M, D, S;

	while (scanf("%d %d", &M, &D) != EOF)
	{
		S = (M * 2 + D) % 3;
		debug(printf("[DEBUG]M = %d, D = %d, S = %d\n", M, D, S));

		switch (S)
		{
		case 1:
			printf("¦N\n");
			break;
		case 2:
			printf("¤j¦N\n");
			break;
		default:
			printf("´¶³q\n");
			break;
		}
	}

	return 0;
}
