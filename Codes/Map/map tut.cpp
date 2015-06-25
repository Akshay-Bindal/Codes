#include<map>
#include<stdio.h>
 
using namespace std;
 
int main()
{
    map<int,int> test;
    map<int,int> :: iterator it;
    test[8]=1008;
    test[7]=7231;
    test[6]=64214;
    test[5]=542;
    test[4]=4342;
    test[3]=35352234;
    for(it=test.begin();it!=test.end();it++)
    printf("first value = %d second value = %d\n",it->first,it->second);
return 0;
}
