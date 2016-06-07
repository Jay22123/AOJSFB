#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, num;

	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		long long int a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		switch (a)
		{
		case 1:
			printf("%lld\n", b + c);
			break;
		case 2:
			printf("%lld\n", b - c);
			break;
		case 3:
			printf("%lld\n", b * c);
			break;
		case 4:
			if (c == 0)
				printf("err!\n");
			else
				printf("%lld\n", b / c);
			break;
		}
	}

	return 0;
}
