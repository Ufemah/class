#include <stdio.h>

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    size_t read;
    size_t leng = 0;
    int emp = 0;

    fp = fopen("test.txt", "r");

    while ((read = getline(&line, &len, fp)) != -1)
    {
        if (read > leng)
        {
          leng = read;
        }

        if (line[0] == '\n')
        {
          emp++;
        }
    }

    fclose(fp);

    printf("max len = %zu\n", leng);
    printf("empty strings = %d\n", emp);
}
