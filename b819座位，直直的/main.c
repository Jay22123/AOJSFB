#ifdef _DEBUG
#	define debug(function) function
#else
#	define debug(function)
#endif

#include <stdio.h>

typedef struct _Classmate
{
	float Ch, En, height;
	int *prev, *next;
}Classmate;

Classmate classmate[100000] = { -1 };
int headIndex, lastIndex;

enum CompareType
{
	LESS,
	MORE
};

int compare(const int aIndex, const int bIndex)
{
	int a = classmate[aIndex].Ch + classmate[aIndex].En,
		b = classmate[bIndex].Ch + classmate[bIndex].En;

	if (a == b)
	{
		if (classmate[aIndex].Ch == classmate[bIndex].Ch)
			return (classmate[aIndex].En < classmate[bIndex].En) ? LESS : MORE;

		return (classmate[aIndex].Ch < classmate[bIndex].Ch) ? LESS : MORE;
	}
	return (a < b) ? LESS : MORE;
}

void sort(int index)
{
	if (index == 0)
	{
		headIndex = lastIndex = 0;
	}
	else
	{
		if (compare(index, headIndex) == LESS)
		{// 最小插入
			classmate[index].prev = -1;
			classmate[index].next = headIndex;
			classmate[headIndex].prev = index;
			headIndex = index;
		}
		else if (compare(lastIndex, index) == LESS)
		{// 最大插入
			classmate[index].prev = lastIndex;
			classmate[index].next = -1;
			classmate[lastIndex].next = index;
			lastIndex = index;
		}
		else
		{// 其餘插入
			int currentIndex = headIndex;
			while (currentIndex >= 0)
			{
				if (compare(currentIndex, index) == MORE)
				{
					classmate[index].prev = classmate[currentIndex].prev;
					classmate[index].next = currentIndex;
					classmate[currentIndex].prev = index;
				}

				currentIndex = classmate[currentIndex].next;
			}
		}
	}
}

void printSort()
{
	int currentIndex = headIndex;
	while (currentIndex >= 0)
	{
		printf("%f %f %f\n",
			classmate[currentIndex].Ch,
			classmate[currentIndex].En,
			classmate[currentIndex].height
		);

		currentIndex = classmate[currentIndex].next;
	}
}


int main(int argc, char *argv[])
{
	int N = 0;

	while (scanf("%d", &N) != EOF)
	{
		headIndex = lastIndex = -1;
		debug(printf("[DEBUG] %d\n", N));

		Classmate *head = &classmate[0];
		int i;
		for (i = 0; i < N; i++)
		{
			scanf("%f %f %f",
				&classmate[i].Ch,
				&classmate[i].En,
				&classmate[i].height
			);
			debug(
				printf("[DEBUG] %f %f %f\n",
					classmate[i].Ch,
					classmate[i].En,
					classmate[i].height)
			);
			sort(i);
		}
		debug(
			printf("[DEBUG] printSort:\n"); printSort(); printf("\n");
		);

		int K = 0;

		printf("%d\n", K);
	}

	return 0;
}
