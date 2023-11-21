#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 배열 요소를 교환하는 매크로
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
// 배열의 크기
#define MAX_SIZE 20

int com1 = 0, com2 = 0, com3 = 0;
int swap1 = 0, swap2 = 0, swap3 = 0;

// 선택정렬
static void selection_sort(int list[], int n, int t)
{
	int i, j, least, temp, k;
	int comparisons = 0, swaps = 0;

	if (t == 0)
	{
		printf("Selection Sort\n");
	}
	
	for (i = 0; i < n - 1; i++)
	{
		least = i;
		for (j = i + 1; j < n; j++)
		{
			comparisons++;
			if (list[j] < list[least])
			{
				least = j;
			}
		}

		SWAP(list[i], list[least], temp);
		swaps++;

		if (t == 0)
		{
			// 정렬 과정 출력
			for (k = 0; k < n; k++)
			{
				printf("%d ", list[k]);
			}
			printf("\n");
		}
	}

	if (t == 0)
	{
		printf("Compare Count: %d\n", comparisons);
		printf("Move Count: %d\n\n", swaps);
	}
	
}

// 삽입정렬
static void insertion_sort(int list[], int n, int t)
{
	int i, j, k, key, comparisons = 0, swaps = 0;

	if (t == 0)
	{
		printf("Insertion Sort:\n");
	}
	
	for (i = 1; i < n; i++)
	{
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
		{
			comparisons++;
			list[j + 1] = list[j];
			swaps++;
		}
		list[j + 1] = key;

		if (t == 0)
		{
			// 정렬 과정 출력
			for (k = 0; k < n; k++)
			{
				printf("%d ", list[k]);
			}
			printf("\n");
		}
	}

	if (t == 0)
	{
		printf("Compare Count: %d\n", comparisons);
		printf("Move Count: %d\n\n", swaps);
	}
	com2 = com2 + comparisons;
	swap2 = swap2 + swaps;
}

// 버블정렬
static void bubble_sort(int list[], int n, int t)
{
	int i, j, k, temp, comparisons = 0, swaps = 0;

	if (t == 0)
	{
		printf("Bubble Sort\n");
	}
	
	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			comparisons++;
			if (list[j] > list[j + 1])
			{
				SWAP(list[j], list[j + 1], temp);
				swaps++;
			}
		}

		if (t == 0)
		{
			// 정렬 과정 출력
			for (k = 0; k < MAX_SIZE; k++)
			{
				printf("%d ", list[k]);
			}
			printf("\n");
		}
	}

	if (t == 0)
	{
		printf("Compare Count: %d\n", comparisons);
		printf("Move Count: %d\n\n", swaps);
	}
	com3 = com3 + comparisons;
	swap3 = swap3 + swaps;
}

int main()
{
	int i, list[MAX_SIZE]{}, list2[MAX_SIZE]{}, list3[MAX_SIZE]{};
	int n = MAX_SIZE;
	srand(time(NULL));

	for (int j = 0; j < 19; j++)
	{
		for (i = 0; i < n; i++)
		{
			list[i] = rand() % 100;
			list2[i] = list[i];
			list3[i] = list[i];
		}

		if (j == 0)
		{
			// 원본 배열 출력
			printf("Original List\n");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", list[i]);
			}
			printf("\n\n");
		}

		// 각 정렬 알고리즘 적용 및 결과 출력
		selection_sort(list, n, j);
		insertion_sort(list2, n, j);
		bubble_sort(list3, n, j);
	}

	printf("\nselection sort, compare count average : %d, move count average : %d\n", com1 / 20, swap1 / 20);
	printf("insertion sort, compare count average : %d, move count average : %d\n ", com2 / 20, swap2 / 20);
	printf("bubble sort, compare count average : %d, move count average : %d\n", com3 / 20, swap3 / 20);

	return 0;
}