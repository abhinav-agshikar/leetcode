#include <iostream>
#include <vector>

using namespace std;

int equaltoindex(vector <int> a)
{
	int left = 0, right = a.size() - 1;
	while(left <= right) {
		int mid = left + ((right-left)/2);
		int diff = a[mid] - mid;
		if (diff == 0) {
			return mid;
		} 
		else if (diff > 0 ) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}

	}
	return -1;
}

int main()
{
	vector <int> a;
	a.push_back(-2);
	a.push_back(0);
	a.push_back(2);
	a.push_back(3);
	a.push_back(6);
	a.push_back(7);
	a.push_back(9);
	cout << equaltoindex(a);
}