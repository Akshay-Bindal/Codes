#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
//containers
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<string>
#include<stack>
#include<bitset>
//IOs
#include<iostream>
//algorithm & miscellaneous
#include<algorithm>
#include<utility>
#include<limits>
#include<locale>

using namespace std;

#define swap(x,y) x=x+y-(y=x)
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define s(a) scanf("%d",&a)
#define p(a) printf("%d",a)
#define ss(a) scanf("%s",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define nline printf("\n")
#define ff first
#define rep(i,a,b) for(i=a;i<b;i++)
 
void convert10tob(int N,int b)
{
     if (N==0)
        return;
      
     int x = N%b;
     N/=b;
     if (x<0)
        N+=1;
         
     convert10tob(N,b);
     printf("%d",x<0?x+(b*-1):x);
     return;
}
 
 
int main()
{
    int N,b;
    while (scanf("%d%d",&N,&b)==2)
    {
          if (N!=0)
          {
              convert10tob(N,b);
              printf("\n");
          }
          else
              printf("0\n");
    }
}

