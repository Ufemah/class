/*
9.	Побудувати рядок S з рядків S1, S2 так, щоб у S входили
а) ті символи S1, які не входять у S2;
б) всі символи S1, які не входять у S2, та всі символи S2, які не входять у S1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100


char* fun1(char* s1, char* s2)
{
  char* res = malloc(sizeof(char) * N);
  int j = 0;

  for (int i = 0; i < strlen(s1); i++)
  {
    if (strchr(s2, s1[i]) == NULL)
    {
      res[j] = s1[i];
      j++;
    }
  }
  res[j] = '\0';
  return res;
}


char* fun2(char* s1, char* s2)
{
  char* res = malloc(sizeof(char) * N);
  int j = 0;

  for (int i = 0; i < strlen(s1); i++)
  {
    if (strchr(s2, s1[i]) == NULL)
    {
      res[j] = s1[i];
      j++;
    }
  }

  for (int i = 0; i < strlen(s2); i++)
  {
    if (strchr(s1, s2[i]) == NULL)
    {
      res[j] = s2[i];
      j++;
    }
  }
  res[j] = '\0';
  return res;
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

  char* s_res1 = fun1(s1, s2);
  printf("%s\n", s_res1);

  char* s_res2 = fun2(s1, s2);
  printf("%s\n", s_res2);

  return 0;
}
