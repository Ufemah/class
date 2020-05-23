#include <iostream>
#include <string>

using namespace std;

string check(string inp)
{
  int temp1 = 0;
  int temp2 = 0;
  string::size_type npos1 = 0;
  string::size_type npos2 = 0;
  string target1 = "<td>";
  string target2 = "</td>";

  while ((npos1 = inp.find(target1, npos1 )) != string::npos) {
         ++ temp1;
         npos1 += target1.length();
  }

  while ((npos2 = inp.find(target2, npos2 )) != string::npos) {
         ++ temp2;
         npos2 += target2.length();
  }


  if (temp1 == temp2)
  {
    return "ok";
  }
  else
  {
    return "not ok";
  }
}


int main()
{
  string inp1 = "<td> it's ok </td>";
  string inp2 = "<td> it's not ok";
  string inp3 = "it's not ok too </td>";
  string inp4 = "ok";

  cout << inp1 << "   -   is "<< check(inp1) << endl;
  cout << inp2 << "   -   is "<< check(inp2) << endl;
  cout << inp3 << "   -   is "<< check(inp3) << endl;
  cout << inp4 << "   -   is "<< check(inp4) << endl;
  return 0;
}
