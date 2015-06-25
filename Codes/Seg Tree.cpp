// Segment trees

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
#define reprev(i,a,b) for(i=a;i>b;i--)
#define mk(x,y) make_pair(x,y)

int getMid(int s, int e) {  return s + (e -s)/2;  }

void updateValueUtil(int *st, int l, int r, int i, int diff, int index)
{
    // Base Case: If the input index lies outside the range of this segment
    if (i < l || i > r)
        return;
 
    // If the input index is in range of this node, then update the value
    // of the node and its children
    st[index] = st[index] + diff;
    if (r != l)
    {
        int mid = getMid(l, r);
        updateValueUtil(st, l, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, r, i, diff, 2*index + 2);
    }
}

void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }
 
    // Get the difference between new value and old value
    int diff = new_val - arr[i];
 
    // Update the value in array
    arr[i] = new_val;
 
    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}

int getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part of given range, then return the 
    // sum of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);	//"+" sign for adding
}

int getSum(int *st, int n, int l, int r)
{
    // Check for erroneous input values
    if (l < 0 || r > n-1 || l > r)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(st, 0, n-1, l, r, 0);
}

int constructSTUtil(int arr[], int l, int r, int *st, int curr)
{
	if (l == r)
    {
        st[curr] = arr[l];
        return arr[l];
    }
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(l, r);
    st[curr] =  constructSTUtil(arr, l, mid, st, curr*2+1) +
              constructSTUtil(arr, mid+1, r, st, curr*2+2);	//"+" was used to store te sum of the child nodes
    
    return st[curr];
}

int *constructST(int arr[], int n)
{
	// Allocate memory for segment tree
    int x = (int)(ceil(log2(n))); 	//Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; 	//Maximum size of segment tree
    int *st = new int[max_size];
    
    constructSTUtil(arr, 0, n-1, st, 0);
    
	return st;	
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n,i,arr[100005]={0};
	s(n);
	rep(i,0,n)
	s(arr[i]);
	
	// Build segment tree from given array
    int *st = constructST(arr, n); 	//st = pointer to the root of the tree
	
	// Print sum of values in array from index 1 to 3
	printf("Sum of values in given range = %d\n", getSum(st, n, 1, 7));
	
	// Update: set arr[1] = 10 and update corresponding segment
    // tree nodes
    updateValue(arr, st, n, 4, 10);
    
    // Find sum after the value is updated
    printf("Updated sum of values in given range = %d\n",getSum(st, n, 1, 7));
 
return 0;
}

