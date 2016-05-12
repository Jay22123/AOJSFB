#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char s[1000] = { NULL };

	while (gets(s) != 0)
	{
		bool isWord = false;
		int i, word = 0;

		for (i = 0; i < strlen(s); i++)
		{
			if (isalpha(s[i]))
			{
				if (!isWord)
					++word;
				isWord = true;
				continue;
			}
			else if (s[i] == '\0')
				break;
			else
				isWord = false;
		}

		printf("%d\n", word);
	}

	return 0;
}
