#include <stdio.h>
#include <locale.h>
#include <malloc.h>


int main()
{
	setlocale(LC_ALL, "Russian");
	int n, c, i, j, co1 = 0, co2 = 0;
	char* arr;
	printf("Введите натуральное число n: ");

	while ((scanf_s("%d", &n) == 0))
	{
		printf("Введите верное числовое значение ещё раз: ");
		rewind(stdin);
	}
	rewind(stdin);

	if (!(arr = (char*)calloc(n + 1, sizeof(char))))
	{
		printf("Ошибка..."); return 0;
	}

	printf("\nВведите строку длиной не более n = %d символов: ", n);

	fgets(arr, n + 1, stdin);
	printf("\nИсходная строка: %s\n", arr);


	for (i = 0; i < n + 1; i++)
	{
		if (arr[i] == '#')
			co1++;
	}
	printf("Количество # равно %d\n", co1);

	for (i = 0; i<n+1 ; i++)
	{
		if (arr[i] != '#' && arr[i] != 0 && arr[i] != '\n')
		{
			co2++;
		}
			
	}
	printf("Количество символов равно %d\n\n", co2);


	if (co1 > co2)
	{
		printf("Количество решеток больше количества символов..\n");
		return 0;
	}

	c = n + 1;

	for (i = 0; i < n + 1; i++)
	{
		if (arr[i] == '#')
		{
			c = c - 2;
			for (j = i; j < c; j++)
			{
				arr[j - 1] = arr[j + 1];
				i = i - 2;
			}
		}
	}

	printf("\nИтоговая строка строка: %s\n", arr);
	free(arr);
	return 0;
}