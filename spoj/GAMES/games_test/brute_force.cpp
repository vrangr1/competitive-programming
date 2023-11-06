#if 0
    me=`basename $0 .cpp`
    rm -f $me $me.out
    only_compile=${1:-0}
    if [ $only_compile == compile ]; then
        g++ -std=c++20 $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
        exit
    fi
    g++ -std=c++20 -DLOCAL $me.cpp -o $me -Wall -O2 -Wextra -Wno-sign-conversion -Wshadow
    if test -f $me; then
	    ./$me > $me.out
        echo "\noutput begins now:"
        cat $me.out
    	rm $me $me.out
    fi
    exit
#endif
/***************************************************
* AUTHOR : Ankit Rawat
* Nick   : acodebreaker2 (on CodeChef)
****************************************************/

#include <stdio.h>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
long gcd(long a,long b)
{
 return b==0?a:gcd(b,a%b);
}
int main()
{
 int t,count,i,flage;
 scanf("%d",&t);
 while(t--)
 {
  string s;
  cin>>s;
  long number=1,frac;
  count=0;
  flage=0;
  for(i=s.size()-1;i>=0;i--)
  {
   if(s[i]=='.')
   {
    flage=1;
    break;
   }
   else
    count++;
  }
  for(i=0;i<(int)s.size();i++)
  {
   if(s[i]!='.')
   {
    number=number*10 + (s[i]-48);
   }
  }
  frac=1;
  if(flage)
   frac=pow(10,count);
  printf("%ld\n",frac/gcd(number,frac));
 }
 return 0;
}