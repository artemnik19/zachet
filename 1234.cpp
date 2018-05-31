#include <stdio.h>
#include <stdlib.h>

int main()
{
  int SIZE;//
  scanf("%d", &SIZE);//
  int a[SIZE][SIZE]; // ������� ������
  int d[SIZE]; // ����������� ����������
  int v[SIZE]; // ���������� �������
  int temp,s;
  scanf("%d", &s);
  if(s>SIZE)
    return 0;
  int minindex, min;

  // ������������� ������� ������
  for (int i = 0; i<SIZE; i++)
  {
    a[i][i] = 0;
    for (int j = i + 1; j<SIZE; j++) {
      printf("Distanse %d - %d: ", i + 1, j + 1);
      scanf("%d", &temp);
      a[i][j] = temp;
      a[j][i] = temp;
    }
  }
  // ����� ������� ������
  for (int i = 0; i<SIZE; i++)
  {
    for (int j = 0; j<SIZE; j++)
      printf("%5d ", a[i][j]);
    printf("\n");
  }
  //������������� ������ � ����������
  for (int i = 0; i<SIZE; i++)
  {
    d[i] = 10000;
    v[i] = 1;
  }
  d[s-1] = 0;
  // ��� ���������
  do {
    minindex = 10000;
    min = 10000;
    for (int i = 0; i<SIZE; i++)
    { // ���� ������� ��� �� ������ � ��� ������ min
      if ((v[i] == 1) && (d[i]<min))
      { // ��������������� ��������
        min = d[i];
        minindex = i;
      }
    }
    // ��������� ��������� ����������� ���
    // � �������� ���� �������
    // � ���������� � ������� ����������� ����� �������
    if (minindex != 10000)
    {
      for (int i = 0; i<SIZE; i++)
      {
        if (a[minindex][i] > 0)
        {
          temp = min + a[minindex][i];
          if (temp < d[i])
          {
            d[i] = temp;
          }
        }
      }
      v[minindex] = 0;
    }
  } while (minindex < 10000);
  // ����� ���������� ���������� �� ������
  printf("\nDistanse: \n");
  for (int i = 0; i<SIZE; i++)
    printf("%5d ", d[i]);



}
