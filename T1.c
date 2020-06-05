#include <stdio.h>
#define SIZE 10


void transpose(int matrix[SIZE][SIZE], int r, int c);
int check(int array[SIZE], int len);
void change(int matrix[SIZE][SIZE], int r, int c, int first, int second);
void show(int matrix[SIZE][SIZE], int r, int c);


int main() {
    int a[SIZE][SIZE], res[SIZE][SIZE], r, c, i, j, min, max;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("\nEnter matrix elements:\n");
    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }

    printf("\nEntered matrix: \n");
    show(a, r, c);

    transpose(a, r, c);


    for (i = 0; i < c; i++)
    {
      if (check(a[i], c) == 1)
      {
        max = i;
      }
    }

    for (i = c; i >= 0; i--)
    {
      if (check(a[i], c) == 1)
      {
        min = i;
      }
    }

    if (min < 0 || max > r)
    {
      printf("error\n");
      return 1;
    }
    change(a, r, c, min, max);
    transpose(a, c, r);

    printf("\nChanged matrix:\n");
    show(a, r, c);

    return 0;
}


void show(int matrix[SIZE][SIZE], int r, int c)
{
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) {
        printf("%d  ", matrix[i][j]);
        if (j == c - 1)
            printf("\n");
    }
}


int check(int array[SIZE], int len)
{
  int k = 1;
  for (int i = 0; i < len; i++)
  {
    if (array[i] < 0)
    {
      k = 0;
    }
  }
  return k;
}


void transpose(int matrix[SIZE][SIZE], int r, int c)
{
  int transposed[SIZE][SIZE];
  for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
          transposed[j][i] = matrix[i][j];
      }

  for (int i = 0; i < c; ++i)
      for (int j = 0; j < r; ++j) {
          matrix[i][j] = transposed[i][j];
      }
}


void change(int matrix[SIZE][SIZE], int r, int c, int first, int second)
{
  int changed[SIZE][SIZE];
  printf("tyt\n" );
  for (int i = 0; i < c; ++i)
      for (int j = 0; j < r; ++j) {
          changed[i][j] = matrix[i][j];
          if (i == first)
          {
            changed[i][j] = matrix[second][j];
          }
          if (i == second)
          {
            changed[i][j] = matrix[first][j];
          }

      }
  for (int i = 0; i < c; ++i)
      for (int j = 0; j < r; ++j) {
          matrix[i][j] = changed[i][j];
      }
}
