/*
4) Визначити типи запису для зображення таких понять:
г) адреса (місто, вулиця, будинок, квартира);
*/
#include <stdio.h>


typedef struct {
  char*         city;
  char*         street;
  unsigned int  house;
  unsigned int  flat;
} Address;



int main()
{
  Address Petya;
  Petya.city = "Kyiv";
  Petya.street = "Lomosova";
  Petya.house = 3;
  Petya.flat = 87;
  printf("%s\n", Petya.city);
  printf("%s\n", Petya.street);
  printf("%d\n", Petya.house);
  printf("%d\n", Petya.flat);
  return 0;
}
