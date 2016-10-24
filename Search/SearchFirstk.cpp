#include <iostream>
#include <vector>

using namespace std;

int SearchFirstofK(vector <int> a, int k)
{
	int left = 0, right = a.size() - 1;
	int result = -1;
	while(left <= right) {
		int mid = left + ((right-left)/2);
		if (a[mid] == k) {
			result = mid;
			right = mid - 1;
		} 
		else if (a[mid] > k ) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}

	}
	return result;
}

int main()
{
	vector <int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(5);
	a.push_back(10);
	a.push_back(10);
	a.push_back(10);
	a.push_back(19);
	cout << SearchFirstofK(a,10);
}