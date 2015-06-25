//LIST OR DOUBLY LINKED LIST
#include<stdio.h>
#include<list>
using namespace std;
int main()
{
    list<int> first;    //empty list
    list<int> second (4,10); //4 elements initalized to 10
    list<int>::iterator it,it1;
    second.push_front(30);
    for(it=second.begin();it!=second.end();it++)
    printf("%d ",*it);printf("\n");
 
 
    list<int> third(5); //list of 5 elements initialized to 0
    list<int>::reverse_iterator rit;
    for (int i=1; i<=5; ++i) 
    third.push_back(i); //adds the element i to the end of the list
 
    for(rit=third.rbegin();rit!=third.rend();rit++)
    printf("%d ",*rit);
 
    int sum=0;
    while(!third.empty())
    {
        sum+=third.front();
        third.pop_front();
    }
    printf("\n%d\n",sum);
 
    for (int j=1; j<=5; ++j) 
    first.push_back(j);
    it=first.begin();
    it++;   //iterator now points on the second element i.e in 1 2 3 4 5 list it is at 2
 
    first.insert(it,20);    //this will insert 20 just before 2 i.e 1 20 2 3 4 5 and it will still be on 2
    first.insert(it,3,30);  //this will insert 3 30s just before 2 i.e 1 20 30 30 30 2 3 4 5 and it will still be on 2
    for(it=first.begin();it!=first.end();it++)
    printf("%d ",*it);printf("\n");
 
    it1=first.begin();
    advance(it1,5); //this will sent iterator it1 3 places ahead of its initial position i.e at 2
    first.erase(it1);   //this will delete element at it1 i.e. 2
    for(it=first.begin();it!=first.end();it++)
    printf("%d ",*it);printf("\n");
 
    first.remove(5);    //this will remove element with value 5
    first.remove(20);
    for(it=first.begin();it!=first.end();it++)
    printf("%d ",*it);printf("\n");
 
    first.sort();   //sorts the list.ALso if the list is a string type the compares the character codes
    first.unique(); //removes the duplicate elements from the list
    for(it=first.begin();it!=first.end();it++)
    printf("%d ",*it);printf("\n");
 
return 0;
}
