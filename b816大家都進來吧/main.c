#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int n = 0;

	/*
		i < j < k, a_i <= a_j <= a_k，並最大化(a_j - a_i) * (a_k - a_j)
		保證存在一組i, j, k使得i < j < k且a_i <= a_j <= a_k。
	*/

	while (scanf("%d", &n) != EOF)
	{
		int i, a_n = -1, a_i = -1, a_j = -1, a_k = -1, maxNum = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a_n);

			if (a_i < a_n)
			{
				a_i = (int)fmin(a_n, a_i);
				a_k = (int)fmax(a_n, a_k);

				if (a_n < a_k)
					a_j = a_n;
				else
					a_j = -1;

				maxNum = (int)fmax((a_j - a_i) * (a_k - a_j), maxNum);
			}
			else
			{
				a_i = 500000;
				a_j = -1;
				a_k = 0;
			}
		}
		/*debug(
			printf("[DEBUG] maxIndex=%d, minIndex=%d\n"
				, maxIndex, minIndex)
		);*/

		printf("%d\n", maxNum);
	}

	return 0;
}
