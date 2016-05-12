#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int t, time, num[4];

	scanf("%d", &t);
	for (time = 0; time < t; time++)
	{
		scanf("%d %d %d %d", &num[0], &num[1], &num[2], &num[3]);
		printf("%d %d %d %d ", num[0], num[1], num[2], num[3]);

		if (num[2] == num[1] + (num[1] - num[0]))
		{
			debug(printf("[DEBUG]¤½®t:%d\n", num[1] - num[0]));
			printf("%d\n", num[3] + (num[1] - num[0]));
		}
		else
		{
			debug(printf("[DEBUG]¤½¤ñ:%d\n", num[1] / num[0]));
			printf("%d\n", num[3] * (num[1] / num[0]));
		}
	}
	return 0;
}
