// Program for range minimum query using segment tree

#include <stdio.h>
#include <math.h>
#include <limits.h>
 
int minVal(int x, int y) { return (x < y)? x: y; }
 
int getMid(int s, int e) {  return s + (e -s)/2;  }
 
int RMQUtil(int *st, int l, int r, int qs, int qe, int index)
{
    // If segment of this node is a part of given range, then return the
    // min of the segment
    if (qs <= l && qe >= r)
        return st[index];
 
    // If segment of this node is outside the given range
    if (r < qs || l > qe)
        return INT_MAX;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(l, r);
    return min(RMQUtil(st, l, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, r, qs, qe, 2*index+2));
}
 
// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
int RMQ(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return RMQUtil(st, 0, n-1, qs, qe, 0);
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
    st[curr] =  min(constructSTUtil(arr, l, mid, st, curr*2+1),
              constructSTUtil(arr, mid+1, r, st, curr*2+2));	//"+" was used to store te sum of the child nodes
    
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
    int arr[] = {1, 3, 2, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // Build segment tree from given array
    int *st = constructST(arr, n);
 
    int qs = 1;  // Starting index of query range
    int qe = 5;  // Ending index of query range
 
    // Print minimum value in arr[qs..qe]
    printf("Minimum of values in range [%d, %d] is = %d\n",
                           qs, qe, RMQ(st, n, qs, qe));
 
    return 0;
}
