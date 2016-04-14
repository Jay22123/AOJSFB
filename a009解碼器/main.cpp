#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	char ch;

	while (scanf("%c", &ch) != EOF)
	{
		if (ch != '\n')
			printf("%c", ch - 7);
		else
			printf("\n");
	}
	return 0;
}
