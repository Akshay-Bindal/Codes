#include<stdio.h>
#include<algorithm>
#include<set>
#include<math.h>
#include<stdlib.h>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<climits>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<clocale>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>

//containers
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<complex>
#include<string>
#include<stack>
#include<bitset>
#include<istream>
#include<valarray>

//IOs
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<exception>
#include<ios>
#include<iosfwd>
#include<ostream>
#include<iterator>
#include<stdexcept>
#include<streambuf>


//algorithm & miscellaneous
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<limits>
#include<locale>
#include<memory>
#include<new>



using namespace std;

struct test{
	int a,b,c;
};

bool comp(const test d,const test e)
{
	if(d.a==e.a)
	return d.b>e.b;	//Decreasing
	else
	return d.a<e.a;	//Increasing
}

int main()
{
		struct test arr[20]={0};
 		int i,m,r,t;
 		scanf("%d",&t);
 		
		 for(i=0;i<t;i++)
			scanf("%d %d %d",&arr[i].a,&arr[i].b,&arr[i].c);
		
		for(int i=0;i<t;i++)
			printf("%d %d %d\n",arr[i].a,arr[i].b,arr[i].c);
		
		sort(arr,arr+t,comp);
		
		printf("\n\n");
		
		for(int i=0;i<t;i++)
			printf("%d %d %d\n",arr[i].a,arr[i].b,arr[i].c);
		
return 0;		
}

