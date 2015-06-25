//how to construct a vector
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    int i;
    vector<int>::iterator it;
 
    vector<int> first;
    vector<int> second (4,0);
    vector<int> third (second.begin(),second.end());
    vector<int> myvector (10);   // 10 zero-initialized elements
 
    int myints[] = {16,2,77,29};
    vector<int> fourth (myints,myints+sizeof(myints)/sizeof(int));
 
    for(it=fourth.begin();it!=fourth.end();it++)
    printf("%d ",*it);printf("\n");
 
    for (int i=0; i<10; i++) first.push_back(i);    //push_back() adds element at the end
    cout << "1. size: " << first.size() << '\n';
 
    first.insert (first.end(),10,100);      //insert(pos, begin, end)
    cout << "2. size: " << first.size() << '\n';
 
    //step 29 to 41 to use vector as an array we use the 29th step
    std::vector<int>::size_type sz = myvector.size();
 
    // assign some values:
    for (unsigned i=0; i<sz; i++) myvector[i]=i;
 
    // reverse vector using operator[]:
    for (unsigned i=0; i<sz/2; i++)
    {
        int temp;
        temp = myvector[sz-1-i];
        myvector[sz-1-i]=myvector[i];
        myvector[i]=temp;
    }
 
    //step 43 to 50 at() make it easier to access a vector element
    for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;
 
    std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';
 
    //step 53 to 63 to access vector with a pointer
    int* p = myvector.data();
 
  *p = 10;
  ++p;
  *p = 20;
  p[2] = 100;
 
  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
 
 
return 0;
}
