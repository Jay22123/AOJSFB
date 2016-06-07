#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_NUM 1000

int main(int argc, char *argv[])
{
	char str[MAX_INPUT_NUM + 1];

	while (scanf("%s", &str) != EOF)
	{
		int i, ascII[127] = { 0 }, odd = 0;
		for (i = 0; i < strlen(str); i++)
		{
			if (isalpha(str[i]))
			{
				ascII[toupper(str[i])]++;
			}
		}

		for (i = 0; i < 127 & odd < 2; i++)
		{
			if (ascII[i] % 2 > 0)
			{
				odd++;
			}
		}
		printf("%s\n", (odd < 2)?"yes !":"no...");
	}

	return 0;
}
