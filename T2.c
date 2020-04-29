#include <stdio.h>


typedef struct {
  unsigned int day;
  unsigned int month;
  unsigned int year;
} Date;


Date prev(Date d)
{
  Date y;
  y.year = d.year;
  if (d.day == 1)
  {
    if (d.month == 1)
      {y.day = 0;
      y.month = 0;}
    if (d.month == 2)
      {y.day = 31;
      y.month = 1;}
    if (d.month == 3)
      {y.day = 28;
      y.month = 2;}
    if (d.month == 4)
      {y.day = 31;
      y.month = 3;}
    if (d.month == 5)
      {y.day = 30;
      y.month = 4;}
    if (d.month == 6)
      {y.day = 31;
      y.month = 5;}
    if (d.month == 7)
      {y.day = 30;
      y.month = 6;}
    if (d.month == 8)
      {y.day = 31;
      y.month = 7;}
    if (d.month == 9)
      {y.day = 31;
      y.month = 8;}
    if (d.month == 10)
      {y.day = 30;
      y.month = 9;}
    if (d.month == 11)
      {y.day = 31;
      y.month = 10;}
    if (d.month == 12)
      {y.day = 30;
      y.month = 11;}
  }
  else
  {
    y.day = d.day - 1;
    y.month = d.month;
  }
  return y;
}


int what_day(Date d)
{
  int days = d.day;
  if (d.month == 2)
    {days += 31;}
  if (d.month == 3)
    {days += 31+28;}
  if (d.month == 4)
    {days += 31+28+31;}
  if (d.month == 5)
    {days += 31+28+31+30;}
  if (d.month == 6)
    {days += 31+28+31+30+31;}
  if (d.month == 7)
    {days += 31+28+31+30+31+30;}
  if (d.month == 8)
    {days += 31+28+31+30+31+30+31;}
  if (d.month == 9)
    {days += 31+28+31+30+31+30+31+31;}
  if (d.month == 10)
    {days += 31+28+31+30+31+30+31+31+30;}
  if (d.month == 11)
    {days += 31+28+31+30+31+30+31+31+30+31;}
  if (d.month == 12)
    {days += 31+28+31+30+31+30+31+31+30+31+30;}

    int res = (days - (days/7)*7 + 3);  // +3 поправка на 01.01.20 - среду
    if (res > 7)
    {res -= 7;}
  return res;
}


void show_date(Date d)
{
  printf("%d/%d/%d\n", d.day, d.month, d.year);
}


int main()
{
  Date today;
  today.day = 27;
  today.month = 4;
  today.year = 2020;

  show_date(today);

  Date yesterday;
  yesterday = prev(today);
  show_date(yesterday);

  int n;
  n = what_day(today);
  printf("%d\n", n);

  return 0;
}
