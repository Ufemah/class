#include <stdio.h>
#include <string.h>


void code(char arr[], int i, int key)
{
  for(int r = 0; r < i - 1; r++)
  {
    int num = (int) arr[r];

    if ((num >= 65) && (num <= 90))
    {
      num += key;
      while (num > 90)
      {
        num -= 26;
      }
    }

    if ((num >= 97) && (num <= 122))
    {
      num += key;
      while (num > 122)
      {
        num -= 26;
      }
    }

    arr[r] = (char)num;
  }
}


void decode(char arr[], int i, int key)
{
  for(int r = 0; r < i - 1; r++)
  {
    int num = (int) arr[r];

    if ((num >= 65) && (num <= 90))
    {
      num -= key;
      while (num < 65)
      {
        num += 26;
      }
    }

    if ((num >= 97) && (num <= 122))
    {
      num -= key;
      while (num < 97)
      {
        num += 26;
      }
    }

    arr[r] = (char)num;
  }
}



int main()
{
   unsigned int key = 2;
   //scanf("%d", &key);

   char ch;
   char file_name[100] = "F.txt";
   char aim_file[100] = "G.txt";
   char arr[] = {};
   int i = 0;
   FILE *fp;
   FILE *gp;

   fp = fopen(file_name, "r");

   while((ch = fgetc(fp)) != EOF)
      {
        arr[i] = ch;
        i++;
      }
    fclose(fp);

   code(arr, i, key);
   //decode(arr, i, key);

   gp = fopen("G.txt","w");
   for (int r = 0; r < i; r++)
   {
     fprintf(gp,"%c", arr[r]);
   }
   fclose(gp);

   printf("done\n");
   return 0;
}
