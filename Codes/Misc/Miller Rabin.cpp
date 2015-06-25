#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//random number generator
//generate a random between m and n.
long long random(long long m,long long n)
{
     srand((long long)time(NULL));
     return (long long)(m+rand()%n);
 }
//power mod function
//return X^Y mod N
long long PowMod(long long x,long long y,long long n)
{
     long long s, t, u;
    s=1; t=x; u=y;
    while(u){
        if(u&1)s=(s*t)%n;
         u>>=1;
         t=(t*t)%n;
     }
     return s;
 }
 //Rabin-Miller prime test, 1 for true, 0 for false.
 //n is the prime to be tested
 //Warning: Passing the test does not garrentee it is a prime. The chance for a non-prime to pass the test is 1/4.
 int RabinMillerKnl(long long n)
 {
     long long b, m=n-1, j=0, v, i;
     //Firstly , compute the m and j, satisfy n-1=m*2^j, in which m is a positive odd and j is a non-negtive integer.
     while(!(m & 1)){
         ++j;
         m>>=1;
     }
     b=random(2,m);
    v=PowMod(b, m, n);
     if(v == 1)
         return 1;
     i=1;
    while(v != n - 1){     
         if(i == j)
            return 0;
         v=PowMod(v, 2, n);
         i++;
     }
     return 1;
 }
 int PrimeTest(long long int p)
 {
     int TestNum=18;
     int count=0;
     for(int temp=0; temp < TestNum; temp++)
    {
         if (p%2==0)
         {
            if (p==2)
                count=TestNum;
             break;
         }
         if(RabinMillerKnl(p))
             count++;
         else
            break;
    }
     if(count==TestNum)
         cout<<"Passed all test, Prime!"<<endl;
     else
        cout<<"Not Prime"<<endl;
    return 0;
 }
 int main()
 {
    long long int p;
     int t,count=0;
    cin>>t;
	while(t--){
     cout<<"Enter positive integer:"<<endl;
    cin>>p;
     PrimeTest(p);}
    return 0;
    getch();
 }

