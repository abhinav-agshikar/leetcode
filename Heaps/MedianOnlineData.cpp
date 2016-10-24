#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

void onlineMedian(vector <int> v)
{
    priority_queue<int, vector<int>, greater<int> > min_heap;
    priority_queue<int, vector<int>, less<int> > max_heap;

    int x;
    for (int i = 0 ; i < v.size() ; i++) {
        x = v[i];
        if (min_heap.empty()) {
            min_heap.push(x);
        } else {
            if (x >= min_heap.top()) {
                min_heap.push(x);
            }
            else {
                max_heap.push(x);
            }

        }
    }
    if(min_heap.size() > max_heap.size() + 1) {
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
    else {
        min_heap.push(max_heap.top());
        max_heap.pop();
    }

    cout << (min_heap.size() == max_heap.size() ? 0.5 * (min_heap.top() + max_heap.top()) : min_heap.top()) << endl;

}


int main()
{
    vector <int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(3);
    v.push_back(5);
    onlineMedian(v);
    v.push_back(2);
    v.push_back(0);
    v.push_back(1);
    //("1,0,3,5,2,0,1");
    onlineMedian(v);
    return 0;
}