/*
14) Задано масив Р, компонентами якого є записи, що містять дані про людину
на ім'я i з указаного списку. Кожне дане складається зі статі людини та
її зросту. Визначити підпрограми для:
в) перевірки, чи є дві людини, однакові на зріст.
*/

#include <stdio.h>
#include <stdbool.h>
#define N 3


typedef struct
{
  const char*     name;
  unsigned int    gender;
  int    height;
}Person;


bool test_unique( unsigned int* arr)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (arr[i] == arr[j] && i != j)
      {
        return 1;
      }
    }
  }
  return 0;
}


int main()
{
  unsigned int *talls;
  Person data[N] = {
      { "Petya", 1, 180},
      { "Tolik", 1, 175},
      { "Inga" , 0, 180}
  };

  for (int i = 0; i < N; i++)
  {
    talls[i] = data[i].height;
  }

  if (test_unique(talls) == 0 )
  {
    printf("%s\n", "all heights are unique");
  }
  else
  {
    printf("%s\n", "not all heights are unique");
  }

  return 0;
}
