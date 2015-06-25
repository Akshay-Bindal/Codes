#include<stdio.h>
#include<set>
#include<utility>

using namespace std;

int main()
{
	int i,t,j,k;
	set<int>rl,rr;
	set< pair<int,int> >r;
	for(i=0;i<8;i++)
	{
		scanf("%d %d",&j,&k);
		r.insert(make_pair(j, k ));
		rl.insert(j);rr.insert(k);
	}
	set<int>:: iterator lt,rt;
	set<pair<int ,int> >::iterator it;
	lt = rl.begin();rt = rr.begin();
	lt++;rt++;
	if(rl.size()==3 && rr.size()==3 && r.find(make_pair(*lt,*rt))==r.end())
		printf("respectable");
	else
		printf("ugly");
	
	for(it=r.begin();it!=r.end();it++)
		printf("%d %d\n",it->first,it->second);	
}
