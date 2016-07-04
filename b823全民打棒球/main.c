#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <math.h>

enum
{
	BB = 0, /* -1 �N��O�e     */
	K = 1,  /*  0 �N��X��     */
	B1 = 2, /*  1 �N��@�S�w�� */
	B2 = 3, /*  2 �N��G�S�w�� */
	B3 = 4, /*  3 �N��T�S�w�� */
	HR = 5  /*  4 �N����S��   */
};


int main(int argc, char *argv[])
{
	int input = 0, num[6] = { 0 };
	while (scanf("%d", &input) != EOF)
	{
		debug(printf("[DEBUG] %d\n", input));
		num[input + 1]++;
	}

	/* ���X�w���� = �@�S�w�� + �G�S�w�� + �T�S�w�� + ���S�� */
	int H = num[B1] + num[B2] + num[B3] + num[HR];
	/* �`������ = ���X�w���� + �X�� + �O�e*/
	int sumBatting = H + num[K] + num[BB];

	/*�����v�ץ��X�w���ơ��]�`������ - �O�e���ơ^*/
	float AVG = 0.0f;
	if (H > 0)
	{
		AVG = (float)H / (sumBatting - num[BB]);
		AVG = roundf(AVG * 100) / 100;
	}

	/* �W�S�v�ס]���X�w���ơϫO�e���ơ^���`������ */
	float OBP = 0.0f;
	if (H > 0)
	{
		OBP = (float)(H + num[BB]) / sumBatting;
		OBP = roundf(OBP * 100) / 100;
	}

	/*
	�����v�G�]���X�w�����S�]�`�M�^���]�`������ - �O�e���ơ^
	�p�G�A���X���S���A�A�b������v�ɧA���S�]�`�M�N�|+4
	�p�G�A���X�T�S���A�A�b������v�ɧA���S�]�`�M�N�|+3
	�p�G�A���X�G�S���A�A�b������v�ɧA���S�]�`�M�N�|+2
	�p�G�A���X�@�S���A�A�b������v�ɧA���S�]�`�M�N�|+1
	�p�G�S���w���h��0
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
