#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <math.h>

#define STR_LEN 7

int main(int argc, char *argv[])
{
	char key[STR_LEN + 1]; // str(7) + '\0'
	while (scanf("%s", &key) != EOF)
	{
		int i;
		for (i = 1; i < STR_LEN; i++)
		{
			printf("%d", abs(key[i - 1] - key[i]));
		}
		printf("\n");
	}

	return 0;
}
