#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Toy
{
  char name[100];
  int value;
  int age_from;
  int age_to;
};


int main()
{
   FILE *fptr;
   if ((fptr = fopen("test.bin","wb")) == NULL)
   {
       printf("Error! opening file");
       exit(1);
   }

   struct Toy doll;
   struct Toy ball;
   struct Toy car;
   struct Toy surprise;

   strcpy(doll.name, "doll");
   doll.value = 60;
   doll.age_from = 2;
   doll.age_to = 8;
   fwrite(&doll, sizeof(struct Toy), 1, fptr);

   strcpy(ball.name, "ball");
   ball.value = 10;
   ball.age_from = 2;
   ball.age_to = 18;
   fwrite(&ball, sizeof(struct Toy), 1, fptr);

   strcpy(car.name, "car");
   car.value = 100;
   car.age_from = 5;
   car.age_to = 12;
   fwrite(&car, sizeof(struct Toy), 1, fptr);

   strcpy(surprise.name, "surprise");
   surprise.value = 8;
   surprise.age_from = 2;
   surprise.age_to = 5;
   fwrite(&surprise, sizeof(struct Toy), 1, fptr);


   fclose(fptr);

   return 0;
}
