#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char x[500];
	int i, temp, n, p;

	while (gets(x) != 0)
	{

		for (i = 0, temp = 0, n = 0; i <= strlen(x); i++)
		{
			p = n;
			if (x[i] > 64 && x[i] < 91 ||
				x[i] > 96 && x[i] < 123)
				n = 1;
			else if (x[i] == '\0')
				break;
			else
				n = 0;

			if (p == 0 && n == 1)
				temp++;
		}
		printf("%d\n", temp);
	}

	return 0;
}
