#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <math.h>

enum
{
	BB = 0, /* -1 玂癳     */
	K = 1,  /*  0 Ы     */
	B1 = 2, /*  1 耂ゴ */
	B2 = 3, /*  2 耂ゴ */
	B3 = 4, /*  3 耂ゴ */
	HR = 5  /*  4 耂ゴ   */
};


int main(int argc, char *argv[])
{
	int input = 0, num[6] = { 0 };
	while (scanf("%d", &input) != EOF)
	{
		debug(printf("[DEBUG] %d\n", input));
		num[input + 1]++;
	}

	/* ゴゴ计 = 耂ゴ + 耂ゴ + 耂ゴ + 耂ゴ */
	int H = num[B1] + num[B2] + num[B3] + num[HR];
	/* 羆ゴ阑计 = ゴゴ计 + Ы + 玂癳*/
	int sumBatting = H + num[K] + num[BB];

	/*ゴ阑瞯∽ゴゴ计〓羆ゴ阑计 - 玂癳Ω计*/
	float AVG = 0.0f;
	if (H > 0)
	{
		AVG = (float)H / (sumBatting - num[BB]);
		AVG = roundf(AVG * 100) / 100;
	}

	/* 耂瞯∽ゴゴ计∠玂癳Ω计〓羆ゴ阑计 */
	float OBP = 0.0f;
	if (H > 0)
	{
		OBP = (float)(H + num[BB]) / sumBatting;
		OBP = roundf(OBP * 100) / 100;
	}

	/*
	ゴ瞯ゴゴ耂羆㎝〓羆ゴ阑计 - 玂癳Ω计
	狦ゴ耂ゴ衡ゴ瞯耂羆㎝碞穦+4
	狦ゴ耂ゴ衡ゴ瞯耂羆㎝碞穦+3
	狦ゴ耂ゴ衡ゴ瞯耂羆㎝碞穦+2
	狦ゴ耂ゴ衡ゴ瞯耂羆㎝碞穦+1
	狦⊿Τゴ玥0
	*/
	float SLG = 0.0f;
	if (H > 0)
	{
		SLG = (float)(num[HR] * 4 + num[B3] * 3 + num[B2] * 2 + num[B1])
			/ (sumBatting - num[BB]);
		SLG = roundf(SLG * 100) / 100;
	}

	printf("%0.2f %0.2f %0.2f\n", AVG, OBP, SLG);


	return 0;
}
