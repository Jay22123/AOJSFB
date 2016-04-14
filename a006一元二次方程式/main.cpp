#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int a, b, c, i, D;
	while (scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		D = b * b - 4 * a * c;
		debug(printf("§PÂ_¦¡D=%d\n", D));
		if (D > 0)
		{
			D = sqrt(D);
			int x1 = (-b + D) / (2 * a),
				x2 = (-b - D) / (2 * a);

			printf("Two different roots x1=%d , x2=%d\n"
				, (int)fmax(x1, x2), (int)fmin(x1, x2));
		}
		else if (D == 0)
		{
			int x = (-b) / (2 * a);
			printf("Two same roots x=%d\n", x);
		}
		else
			printf("No real root\n");
	}
	return 0;
}
