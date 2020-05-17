#include <stdio.h>

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    size_t read;

    fp = fopen("test.txt", "r");

    while ((read = getline(&line, &len, fp)) != -1)
    {
      if (read > 60)
      {
        printf("%s", line);
      }
      //printf("%s", line);
    }

    fclose(fp);
}
