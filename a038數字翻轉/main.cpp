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
	/* 2^31���|�W�X10���*/
	char num[11] = { NULL };

	while (scanf("%s", &num) != EOF)
	{
		bool valid = false;
		int i;
		for (i = strlen(num) - 1; i >= 0; i--)
		{
			if (num[i] != '0')
				valid = true;

			if(valid)
				printf("%1c", num[i]);
		}
		/* �p�G�Ʀr�� 0 �h������X */
		if (!valid)
			printf("0");

		printf("\n");
	}

	return 0;
}
