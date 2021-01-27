#include <iostream>
#include <map>

using namespace std;

struct Point
{
    int coordinates[4];  // x1, y1, x2, y2
};

int Point_Crossing (int, int, int, int, int, int, int, int);

int main()
{
  int n;
  int j, d;
  int res = 2147483646;
  map<int,Point> segments;
  cout << "Input count of segments: ";
  cin >> n;

  if (n <= 0)
  {
    exit(-1);
  }
  else
  {
    for (int i = 0; i < n; i++)
    {
      int m[4];
      Point dot;
      cout << "format x1 y1 x2 y2" << endl;
      cout << "Input point " << i + 1 << " coordinates: ";
      cin >> dot.coordinates[0] >> dot.coordinates[1] >> dot.coordinates[2] >>
      dot.coordinates[3];

      segments.insert(pair<int,Point>(i,dot));
      cout << endl;
    }

    map<int,Point>::iterator itr;
    map<int,Point>::iterator itr2;

      for (itr = segments.begin(); itr != segments.end(); ++itr)
      {
        for (itr2 = segments.begin(); itr2 != segments.end(); ++itr2)
        {
          if (itr2->first != itr->first)
          {
          //x1, y1, x2, y2
          int h = Point_Crossing(itr->second.coordinates[0],
                                 itr->second.coordinates[2],
                                 itr2->second.coordinates[0],
                                 itr2->second.coordinates[2],
                                 itr->second.coordinates[1],
                                 itr->second.coordinates[3],
                                 itr2->second.coordinates[1],
                                 itr2->second.coordinates[3]);
          if (h < res)
          {
            res = h;
          }
        }
      }
    }
  cout << "result point abscissa: " << res << endl;
  return 0;
}
}

int Point_Crossing (int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4)
{
    if (((y1-y2)*(x4-x3)-(y3-y4)*(x2-x1)) == 0)
    {
      return 2147483646;
    }
    else
    {
      float x = -(((x1*y2-x2*y1)*(x4-x3)-(x3*y4-x4*y3)*(x2-x1))/((y1-y2)*(x4-x3)-(y3-y4)*(x2-x1)));
    return x;
    }
}
