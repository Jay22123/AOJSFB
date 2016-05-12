#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char str[1000];

	while (scanf("%s", &str) != EOF)
	{
		const int strLen = strlen(str);

		bool palindrome = true;
		int i;
		for (i = 0;
			i < (strLen - 1) - i;
			i++)
		{
			if (str[i] != str[(strLen - 1) - i])
			{
				palindrome = false;
				break;
			}
		}
		printf("%s\n", palindrome ? "yes" : "no");
	}

	return 0;
}
