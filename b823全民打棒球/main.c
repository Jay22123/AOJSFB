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
		棒球統計 : https://zh.wikipedia.org/wiki/%E6%A3%92%E7%90%83%E7%B5%B1%E8%A8%88#.E6.8A.95.E6.89.8B.E6.95.B8.E6.93.9A

		4代表全壘打
		3代表三壘安打
		2代表二壘安打
		1代表一壘安打
		0代表出局
		-1代表保送
	*/
	while (scanf("%d", &input) != EOF)
	{
		debug(printf("[DEBUG] %d\n", input));
		num[input + 1]++;
	}

	//打擊率，上壘率，長打率
	float AVG = 0, OBP = 0, SLG = 0;


	return 0;
}
