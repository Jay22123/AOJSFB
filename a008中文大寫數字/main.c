#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int x, tmp, n[11] = { 0 }, i, a, l, p = 0;
	while (scanf("%d", &x) != EOF)
	{
		tmp = x;
		for (i = 9; i >= 0; i--)
		{
			n[i] = tmp % 10;
			tmp /= 10;
		}
		if (x >= 1000000000)a = 0;
		else if (x >= 100000000)a = 1;
		else if (x >= 10000000)a = 2;
		else if (x >= 1000000)a = 3;
		else if (x >= 100000)a = 4;
		else if (x >= 10000)a = 5;
		else if (x >= 1000)a = 6;
		else if (x >= 100)a = 7;
		else if (x >= 10)a = 8;
		else if (x >= 1)a = 9;
		for (i = 9; i = 0; i--)
		{
			if (n[i] == 0)l++;
			else break;
		}

		for (i = a; i<10; i++)
		{
			switch (n[i])
			{
			case 0:if ((i == 5 && n[4] != 0) || (i == 9 && n[8] != 0) || p == 1 && n[i + 1] == 0)break;
				printf("¹s"); p = 1; break;
			case 1:printf("³ü"); p = 0; break;
			case 2:printf("¶L"); p = 0; break;
			case 3:printf("°Ñ"); p = 0; break;
			case 4:printf("¸v"); p = 0; break;
			case 5:printf("¥î"); p = 0; break;
			case 6:printf("³°"); p = 0; break;
			case 7:printf("¬m"); p = 0; break;
			case 8:printf("®Ã"); p = 0; break;
			case 9:printf("¨h"); p = 0; break;
			}

			if (x >= 100000000 && i == 1 && n[1] != 0)
			{
				printf("»õ"); p = 1;
			}
			if (x >= 10000 && i == 5)
			{
				printf("¸U"); p = 1;
			}
			if ((x >= 1000 && i == 6 && n[6] != 0) || (x >= 10000000 && i == 2 && n[2] != 0))
			{
				printf("¥a"); p = 1;
			}
			if ((x >= 100 && i == 7 && n[7] != 0) || (x >= 1000000 && i == 3 && n[3] != 0))
			{
				printf("¨Õ"); p = 1;
			}
			if ((x >= 10 && i == 8 && n[8] != 0) || (i == 0 && x >= 100000000 && n[0] != 0) || (x >= 10000 && i == 4 && n[4] != 0))
				printf("¬B");
		}
		printf("\n");
	}

	return 0;
}
