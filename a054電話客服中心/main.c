#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

struct CharValue
{
	char ch;
	int value;
}const CHARVALUE[26] = {
	{ 'A' , 10 },/*台北市*/
	{ 'B' , 11 },/*台中市*/
	{ 'C' , 12 },/*基隆市*/
	{ 'D' , 13 },/*台南市*/
	{ 'E' , 14 },/*高雄市*/
	{ 'F' , 15 },/*台北縣*/
	{ 'G' , 16 },/*宜蘭縣*/
	{ 'H' , 17 },/*桃園縣*/
	{ 'I' , 34 },/*嘉義市*/
	{ 'J' , 18 },/*新竹縣*/
	{ 'K' , 19 },/*苗栗縣*/
	{ 'L' , 20 },/*台中縣*/
	{ 'M' , 21 },/*南投縣*/
	{ 'N' , 22 },/*彰化縣*/
	{ 'O' , 35 },/*新竹市*/
	{ 'P' , 23 },/*雲林縣*/
	{ 'Q' , 24 },/*嘉義縣*/
	{ 'R' , 25 },/*台南縣*/
	{ 'S' , 26 },/*高雄縣*/
	{ 'T' , 27 },/*屏東縣*/
	{ 'U' , 28 },/*花蓮縣*/
	{ 'V' , 29 },/*台東縣*/
	{ 'W' , 32 },/*金門縣*/
	{ 'X' , 30 },/*澎湖縣*/
	{ 'Y' , 31 },/*陽明山*/
	{ 'Z' , 33 } /*連江縣*/
};

void ID_char(int weightedSum, int cheakNum)
{
	int i;
	for (i = 0; i < 26; i++)
	{
		if (((CHARVALUE[i].value / 10
			+ (CHARVALUE[i].value % 10) * 9
			+ weightedSum + cheakNum) % 10) == 0)
			printf("%c", CHARVALUE[i].ch);
	}
}

int main(int argc, char *argv[])
{
	int input;
	while (scanf("%d", &input) != EOF)
	{
		int i, cheakNum, weightedSum = 0;
		for (i = 0; i < 9; i++)
		{
			if (i <= 0)
				cheakNum = input % 10;
			weightedSum += (input % 10) * i;
			input /= 10;
		}
		ID_char(weightedSum, cheakNum);
		printf("\n");
	}

	return 0;
}
