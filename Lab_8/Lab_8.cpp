#include <stdio.h>
#include <locale.h>
#include <malloc.h>


int main()
{
	setlocale(LC_ALL, "Russian");
	int n, c, i, j, co1 = 0, co2 = 0;
	char* arr;
	printf("������� ����������� ����� n: ");

	while ((scanf_s("%d", &n) == 0))
	{
		printf("������� ������ �������� �������� ��� ���: ");
		rewind(stdin);
	}
	rewind(stdin);

	if (!(arr = (char*)calloc(n + 1, sizeof(char))))
	{
		printf("������..."); return 0;
	}

	printf("\n������� ������ ������ �� ����� n = %d ��������: ", n);

	fgets(arr, n + 1, stdin);
	printf("\n�������� ������: %s\n", arr);


	for (i = 0; i < n + 1; i++)
	{
		if (arr[i] == '#')
			co1++;
	}
	printf("���������� # ����� %d\n", co1);

	for (i = 0; i<n+1 ; i++)
	{
		if (arr[i] != '#' && arr[i] != 0 && arr[i] != '\n')
		{
			co2++;
		}
			
	}
	printf("���������� �������� ����� %d\n\n", co2);


	if (co1 > co2)
	{
		printf("���������� ������� ������ ���������� ��������..\n");
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

	printf("\n�������� ������ ������: %s\n", arr);
	free(arr);
	return 0;
}