#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100000

typedef struct
{
	int index;
	int length;
} Length;

int main(int argc, char *argv[])
{
	char input, cheakInput;
	Length mat[N] = { 0 };

	int cheakInputIndex,
		indexLenCount,
		isContinuou,
		T,
		day,
		*l = NULL,
		*r = NULL,
		i,
		*sum = NULL;

	while (scanf("%c", &input) != EOF)
	{
		memset(mat, 0, sizeof(Length) * N);
		debug(printf("[DEBUG] %c", input));

		cheakInputIndex = 1;
		indexLenCount = 0;
		isContinuou = 0;

		while (1)
		{
			scanf("%c", &cheakInput);
			debug(printf("%c", cheakInput));

			if (input == cheakInput)
			{
				if (isContinuou == 0)
					mat[indexLenCount].index = cheakInputIndex;
				isContinuou++;
			}
			else if (isContinuou > 0)
			{
				mat[indexLenCount++].length = isContinuou;
				isContinuou = 0;
			}

			if (cheakInput == '\n')
				break;

			input = cheakInput;
			cheakInputIndex++;
		}
		debug(printf("\n"));

		T = 0;
		scanf("%d", &T);
		debug(printf("[DEBUG] %d\n", T));

		l = malloc(T * sizeof(int));
		r = malloc(T * sizeof(int));
		for (day = 0; day < T; day++)
		{
			scanf("%d %d", (l + day), (r + day));
			debug(printf("[DEBUG] [%d,%d)\n",
				*(l + day), *(r + day)));

			/*--(*(l + day));
			--(*(r + day));*/
		}

		sum = malloc(T * sizeof(int));
		memset(sum, 0, T * sizeof(int));
		for (i = 0; i < indexLenCount; i++)
		{
			for (day = 0; day < T; day++)
			{
				if (*(l + day) <= mat[i].index + mat[i].length &&
					mat[i].index < *(r + day))
				{
					(*(sum + day)) += mat[i].length;

					if (mat[i].index < *(l + day))
						(*(sum + day)) -= *(l + day) - mat[i].index;

					if (mat[i].index + mat[i].length > *(r + day))
						(*(sum + day)) -=
						((mat[i].index + mat[i].length) - *(r + day));
					// 終點位址=起始位址+長度
				}
			}
		}

		for (day = 0; day < T; day++)
		{
			printf("%d\n", *(sum + day));
		}

		free(l);
		free(r);
		free(sum);
	}

	return 0;
}
