/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3

*/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    vector <int> v;
    int v_size, sum;
    MovingAverage(int size) {
        v_size = size;
        sum = 0;
    }
    
    double next(int val) {
        sum+=val;
        v.push_back(val);
        
        if(v.size() <= v_size)
        {
            return double(sum)/v.size();
        }
        else
        {
            sum-=v[0];
            v.erase(v.begin(),v.begin()+1);
            return double(sum)/v.size();
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
