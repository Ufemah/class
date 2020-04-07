/*
1.	Вводиться рядки S1 та рядки S2 та натуральне число k.
Створіть дві функції: перша створює новий рядок який отримується додаванням
рядку S2 в рядок S1 на позицію k-го символу, друга робить теж саме,
але при цьому модифікує безпосередньо рядок S1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100


char* create(char* s1, char* s2, int k)
{
  int r = 0;
  char* res = malloc(sizeof(char) * 2 * N);
  int le = strlen(s2);

  for (int i = 0; i <= strlen(s1) + strlen(s2); i++)
  {
    if (i < k)
    {
      res[i] = s1[i];
      r = i;
    }

    if (i <= r + le && i >= k)
    {
      res[i] = s2[i - k];
    }

    if (i > r + le)
    {
      res[i] = s1[i - le];
    }
  }
  return res;
}


void edit(char* s1, char* s2, int k)
{
  char* temp = malloc(sizeof(char) * N);

  for (int i = k; i <= strlen(s1); i++)
  {
    temp[i - k] = s1[i];
  }

  for (int j = k; j <= strlen(s1) - k + strlen(s2); j++)
  {
    s1[j] = s2[j - k];
  }

  for (int i = strlen(s2) + k; i <= strlen(s1) + strlen(s2); i++)
  {
    s1[i] = temp[i - strlen(s2) - k];
  }
}


int main()
{
  char* s1 = malloc(sizeof(char) * N);
  char* s2 = malloc(sizeof(char) * N);
  int k;

  printf("type s1: ");
  gets(s1);

  printf("type s2: ");
  gets(s2);

  printf("type k: ");
  scanf("%d", &k);

  if (strlen(s1) >= k)
  {
  char* s_result = create(s1, s2, k);
  printf("%s\n", s_result);

  edit(s1, s2, k);
  printf("%s\n", s1);
  }
  else
  {
    printf("k is too larger\n");
  }
  return 0;
}
