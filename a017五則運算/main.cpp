#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int getLine(char *strBuf)
{
	char input;

	int isEOF = 0, seek = ftell(stdin);
	while (true)
	{
		isEOF = fscanf(stdin, "%c", &input);
		if (input == '\n')
			break;
		if (isEOF == EOF)
		{
			if (seek + 1 < ftell(stdin))
			{
				fseek(stdin, -1, SEEK_CUR);
				isEOF = 1;
			}
			break;
		}
		*(strBuf++) = input;
	}
	*(strBuf++) = '\0';

	return isEOF;
}

int main(int argc, char *argv[])
{
	char str[1000] = { NULL };

	while (getLine(str) != EOF)
	{
		printf("%s\n", str);
	}

	return 0;
}
