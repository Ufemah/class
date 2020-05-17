#include <stdio.h>
#include <stdlib.h>


int sum(int arr[100], int n);
int count(int arr[100], int n);
int last(int arr[100], int n);
int max(int arr[100], int n);


int main()
{
   int n;
   int arr[100];
   int i = 0;
   FILE *fptr;

   if ((fptr = fopen("test.bin", "rb")) == NULL){
       printf("Error! opening file");
       exit(1);
   }

   for(n = 1; n <= 5; ++n)
   {
     int get;
     fread(&get, sizeof(int), 1, fptr);
     printf("%d\t", get);
     arr[i] = get;
     i++;
   }
   fclose(fptr);

   printf("\n");
   printf("sum of members = %d\n", sum(arr, i));
   printf("count of members below zero = %d\n", count(arr, i));
   printf("last member = %d\n", last(arr, i));
   printf("max member = %d\n", max(arr, i));
   return 0;
}


int sum(int arr[100], int n)
{
  int res = 0;
  for (int i = 0; i < n; i++)
  {
    res += arr[i];
  }

  return res;
}


int count(int arr[100], int n)
{
  int res = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] < 0)
    {
      res += 1;
    }
  }

  return res;
}


int last(int arr[100], int n)
{
  return arr[n - 1];
}


int max(int arr[100], int n)
{
  int res = arr[0];
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > res)
    {
      res = arr[i];
    }
  }

  return res;
}
