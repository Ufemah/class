#include <stdio.h>
#include <string.h>

//new


int main()
{
   char ch;
   char file_name[100] = "F.txt";
   char aim_file[100] = "G.txt";
   char arr[] = {};
   int i = 0;
   FILE *fp;
   FILE *gp;

   fp = fopen(file_name, "r"); // read mode

   while((ch = fgetc(fp)) != EOF)
      {
        arr[i] = ch;
        i++;
      }
    fclose(fp);

   gp = fopen("G.txt","w");
   for (int r = i; r > 0; r--)
   {
     fprintf(gp,"%c", arr[r]);
   }
   fclose(gp);

   printf("done\n");
   return 0;
}
