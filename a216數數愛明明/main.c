#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

#define MAX_G_DATA 30000

typedef long long int lli;

lli f(int n)
{
	/* 上底+下底*高/2 */
	debug(
		printf("[DEBUG] f(%d)=%lld\n",
			n, ((1 + (lli)n) * n) >> 1)
	);
	return ((1 + n) * n) >> 1;
}

lli gData[MAX_G_DATA] = { 0 };

lli g(int n)
{
	/* 可等價成g(n)=f(n)+f(n-1)+...+f(1) */

	if (n <= MAX_G_DATA)
	{
		if (gData[n] == 0)
		{
			debug(
				printf("[DEBUG] g(%d)=%lld\n",
					n, gData[n])
			);
			return gData[n] = (n > 1) ? f(n) + g(n - 1) : n;
		}
		return gData[n];
	}

	return (n > 1) ? f(n) + g(n - 1) : n;
}

int main(int argc, char *argv[])
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%lld %lld\n", f(n), g(n));
	}

	return 0;
}
