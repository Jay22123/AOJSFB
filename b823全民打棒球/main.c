#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

int main(int argc, char *argv[])
{
	int input = 0, num[6] = { 0 };
	/*
		�βy�έp : https://zh.wikipedia.org/wiki/%E6%A3%92%E7%90%83%E7%B5%B1%E8%A8%88#.E6.8A.95.E6.89.8B.E6.95.B8.E6.93.9A

		4�N����S��
		3�N��T�S�w��
		2�N��G�S�w��
		1�N��@�S�w��
		0�N��X��
		-1�N��O�e
	*/
	while (scanf("%d", &input) != EOF)
	{
		debug(printf("[DEBUG] %d\n", input));
		num[input + 1]++;
	}

	//�����v�A�W�S�v�A�����v
	float AVG = 0, OBP = 0, SLG = 0;


	return 0;
}
