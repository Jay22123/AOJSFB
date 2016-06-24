#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	char s[1000] = { NULL };

	while (scanf("%s", &s) != EOF)
	{
		printf("hello, %s\n", s);
	}

	return 0;
}
