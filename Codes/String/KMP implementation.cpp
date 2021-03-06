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

 
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]
 
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    while(i < N)
    {
      if(pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
        printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
      }
 
      // mismatch after j matches
      else if(pat[j] != txt[i])
      {
      
	    if(j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps);
}
 
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;
 
    lps[0] = 0;
    i = 1;
 
    // the loop calculates lps[i] for i = 1 to M-1
    while(i < M)
    {
       if(pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if( len != 0 )
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
 .


          lps[i] = 0;
           i++;
         }
       }
    }
}
 
int main()
{
   char *txt = "ABABDABACDABABCABAB";
   char *pat = "ABABCABAB";
   KMPSearch(pat, txt);
   return 0;
}

