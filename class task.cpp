#include <iostream>
#include <string>
#include <cctype>

using namespace std;


string task1b(string& str)
{
  string res;
  if (str.length()>=1)
  {
    res.push_back(str[0]);
  }

  for (size_t i = 1; i < str.length(); i++)
  {
    if (!(str[i]=='b' && str[i-1]=='c'))
    {
      res.push_back(str[i]);
    }
  }
  return res;
}


void task1b2(string str)
{
  string pr = "cb";

  int m = str.find(pr);
  printf("%d\n", m);

  while (m!=string::npos)
  {
    str = str.substr(0, m) + str.substr(m + 2, str.length());

    m = str.find(pr, m + 1);
  }
}

void repl(string& s)
{
  int m = s.find("ph");

  while (m!=string::npos)
  {
    s.replace(m, 2, "f");
    m = s.find("ph", m + 1);
  }
}


int main(){

   string s;
   getline(cin, s);

   string s2 = task1b(s);
//   task1b2(s);
   //cout << s2 <<endl;
   cout << repl(s);
}
