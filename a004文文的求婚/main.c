#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int year;
	while (scanf("%d", &year) != EOF)
	{
		if ((year % 400 == 0) 
			|| (year % 4 == 0 && year % 100 != 0))
			printf("¶|¦~\n");
		else
			printf("¥­¦~\n");
	}

	return 0;
}
