#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int quickSelect(int a[], int lo, int hi, int k) {
    // use quick sort's idea
    // put nums that are <= pivot to the left
    // put nums that are  > pivot to the right
    int i = lo, j = hi, pivot = a[hi];
    while (i < j) {
      if (a[i++] > pivot) swap(a[--i], a[--j]);
    }
    swap(a[i], a[hi]);
    
    // count the nums that are <= pivot from lo
    int m = i - lo + 1;
    
    // pivot is the one!
    if (m == k)     return i;
    // pivot is too big, so it must be on the left
    else if (m > k) return quickSelect(a, lo, i - 1, k);
    // pivot is too small, so it must be on the right
    else            return quickSelect(a, i + 1, hi, k - m);
  }

int findKthLargest(int a[], int k) {
    int n = 7;
    int p = quickSelect(a, 0, n - 1, n - k + 1);
    return a[p];
  }
  
  // return the index of the kth smallest number
  

int main()
{
    int v [] =  {14,0,3,5,2,10,1};
   //cout << "Largest:" << v[kthlargest(0,6,0,&v)] << endl;
    //cout << "Smallest:" << v[kthlargest(0,6,1,&v)] << endl;
    for(int i = 0 ; i < 7; i++)
        cout << findKthLargest(v, i) << endl;
    return 0;
}