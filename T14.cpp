#include<iostream>
#include <algorithm>


using namespace std;

main()
{
   string inp = "Awdgt**";
   string res;

   inp.erase(remove(inp.begin(), inp.end(), '*'), inp.end());

   size_t size = inp.size();

   for (size_t i = 0; i < size; ++i)
   {
       res.push_back( inp[i] );
       res.push_back( inp[i] );
   }

   cout << res;

   return 0;
}
