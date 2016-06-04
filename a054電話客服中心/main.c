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
	{ 'A' , 10 },/*�x�_��*/
	{ 'B' , 11 },/*�x����*/
	{ 'C' , 12 },/*�򶩥�*/
	{ 'D' , 13 },/*�x�n��*/
	{ 'E' , 14 },/*������*/
	{ 'F' , 15 },/*�x�_��*/
	{ 'G' , 16 },/*�y����*/
	{ 'H' , 17 },/*��鿤*/
	{ 'I' , 34 },/*�Ÿq��*/
	{ 'J' , 18 },/*�s�˿�*/
	{ 'K' , 19 },/*�]�߿�*/
	{ 'L' , 20 },/*�x����*/
	{ 'M' , 21 },/*�n�뿤*/
	{ 'N' , 22 },/*���ƿ�*/
	{ 'O' , 35 },/*�s�˥�*/
	{ 'P' , 23 },/*���L��*/
	{ 'Q' , 24 },/*�Ÿq��*/
	{ 'R' , 25 },/*�x�n��*/
	{ 'S' , 26 },/*������*/
	{ 'T' , 27 },/*�̪F��*/
	{ 'U' , 28 },/*�Ὤ��*/
	{ 'V' , 29 },/*�x�F��*/
	{ 'W' , 32 },/*������*/
	{ 'X' , 30 },/*���*/
	{ 'Y' , 31 },/*�����s*/
	{ 'Z' , 33 } /*�s����*/
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
