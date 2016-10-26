#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int mat2(int a, int b, int c, int d)
{
	return a * d - b * c;
}

int main(int argc, char *argv[])
{
	int a, b, c, d, e, f;

	while (scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f) != EOF)
	{
		debug(printf("[DEBUG] %d %d %d %d %d %d\n", a, b, c, d, e, f));

		double delta = mat2(a, b, d, e);
		if (delta == 0)
			if (c == f)
				printf("Too many\n");
			else
				printf("No answer\n");
		else
		{
			double delta_x = mat2(c, b, f, e),
				delta_y = mat2(a, c, d, f);

			debug(printf("[DEBUG] delta=%f, delta_x=%f, delta_y=%f\n",
				delta, delta_x, delta_y));

			printf("x=%0.2f\ny=%0.2f\n",
				delta_x / delta, delta_y / delta);
		}
	}

	return 0;
}
