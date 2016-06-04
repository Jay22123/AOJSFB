#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char *argv[])
{
	unsigned int a = 0, b = 0;

	while (scanf("%d %d", &a, &b) != EOF)
	{
		debug(printf("%d %d\n", a, b));

		int number, count = 0;
		for (number = (a % 2 == 0) ? (a + 1) : a;
			number <= b;
			number += 2)
		{
			bool flag = true;
			int x;
			for (x = 3; x <= sqrt(number); x += 2)
			{
				if ((number % x) == 0)
				{
					flag = false;
					break;
				}
			}
			//1不為質數
			if (flag && (number != 1))
			{
				++count;
				debug(printf("[%d]=%d\n", count, number));
			}
		}
		//如果範圍有包含2，則補回
		if (a <= 2 && b >= 2)
			++count;

		printf("%d\n", count);
	}

	return 0;
}
