#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		/*
			f(n)=(n)+(n-1)+...+1, f(1)=1
			f(n)=(n+1)*n/2

			g(n)=f(n)+g(n-1), g(1)=1
			=>g(n)=f(n)+f(n-1)+g(n-1)
			=>g(n)=f(n)+f(n-1)+f(n-2)+...+f(2)+g(1)
			=>g(n)=f(n)+f(n-1)+f(n-2)+...+f(2)+f(1)
			=>		[(n+1)*n/2]
					+[((n-1)+1)*(n-1)/2]
					+[((n-2)+1)*(n-2)/2]
					+...
					+[(2+1)*(2)/2]
					+[(1+1)*(1)/2]
			=>	{	[(n+1)*n]
					+[((n)*(n-1)]
					+[((n-1)*(n-2)]
					+...
					+[(3)*(2)]
					+[(2)*(1)]
				}/2
			=>g(n)={[n]sigma[x=1] ((x+1)*x)/2}
			=>g(n)={[n]sigma[x=1] ((x+1)*x)}/2
			=>g(n)={n*(n+1)*(n+2)/3}/2
			=>g(n)=n*(n+1)*(n+2)/6
		*/
		printf("%lld %lld\n", 
			(long long int)(n + 1) * n / 2,
			(long long int)n * (n + 1) * (n + 2) / 6
		);
	}

	return 0;
}
