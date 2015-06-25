#include <stdio.h>
#include <string.h>
#include<iostream>

using namespace std;

const long maxn = 40;

long c[maxn];

long lowbit ( long x )
{
    return x & -x;
}


void update ( long x, long a )
{
    while ( x <= maxn )
    {
        c[x] += a;
        x += lowbit ( x );
    }
}


long read ( long x )
{
    long re = 0;
    while ( x > 0 )
    {
		cout<<x<<" ";
        re += c[x];
        x -= lowbit ( x );
    }
    cout<<endl;
    return re;
}

int main()
{
	int i,j,l,r,t;
	cin>>t;
	while(t--)
	{
		cin>>j>>l>>r;
		update(l,j);
		for(int k=0;k<maxn;k++)
		cout<<k<<"->"<<c[k]<<" ";
		cout<<endl;
		update(r+1,-j);
		for(int k=0;k<maxn;k++)
		cout<<k<<"->"<<c[k]<<" ";
		cout<<endl;
		int tem;
		cin>>tem;
		cout<<read(tem)<<endl;
	}
}
