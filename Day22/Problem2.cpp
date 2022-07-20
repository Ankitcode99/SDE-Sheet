//Kth Largest Element in a Stream
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minpq;
    int cap;
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for(int x:nums){
            if(minpq.size()<k){
                minpq.push(x);
            }else{
                if(minpq.top() < x){
                    minpq.pop();
                    minpq.push(x);
                }
            }
        }
    }
    
    int add(int val) {
        if(minpq.size() == cap && minpq.top() < val){
            minpq.pop();
            minpq.push(val);
        }
        if(minpq.size()<cap){
            minpq.push(val);
        }
        return minpq.top();
    }
};