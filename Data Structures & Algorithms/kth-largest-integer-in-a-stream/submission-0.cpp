class KthLargest {
private:
    priority_queue<int,vector<int>,greater<>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        // pq.erase();
        this->k = k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        while(pq.size() > k){
            pq.pop();
        }

        if(pq.size() == k){
            if(pq.top() < val){
                pq.pop();
            }
        }

        pq.push(val);
        return pq.top();
    }
};
