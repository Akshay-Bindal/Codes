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

#define swap(x,y) x=x+y-(y=x)
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define mk(x,y) make_pair(x,y)
#define s(a) scanf("%d",&a)
#define p(a) printf("%d",a)
#define ss(a) scanf("%s",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define nline printf("\n")
#define ff first
//#define ss second
#define rep(i,a,b) for(i=a;i<b;i++)
#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int i,t,x,y;
	scanf("%d",&t);
	
	set<pair<int, int> >s;
	set<pair<int, int> >:: iterator it;
	
	rep(i,0,t)
	{
		scanf("%d %d",&x,&y);
		s.insert(mk(x,y));
	}
	
	for(it=s.begin();it!=s.end();it++)
	printf("%d %d\n",it->first,it->second);

return 0;
}

