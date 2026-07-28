class KthLargest {
public:
    priority_queue<int, vector<int>, greater<> > heap;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(auto num : nums){
            heap.push(num);
        }
    }
    
    int add(int val) {
        heap.push(val);
        while (heap.size() > kth){
            heap.pop();
        }
        return heap.top();
    }
};