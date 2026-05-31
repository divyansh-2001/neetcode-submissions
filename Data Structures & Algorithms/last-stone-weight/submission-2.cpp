class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() < 2){
            return stones[0];
        }

        priority_queue<int, vector<int>> pq;

        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(!pq.empty()){
            int top1 = pq.top();
            pq.pop();

            if(pq.empty()){
                return top1;
            }

            int top2 = pq.top();
            pq.pop();

            int diff = abs(top1-top2);
            if(diff == 0){
                continue;
            }

            pq.push(diff);
        }

        return pq.empty() ? 0 : pq.top();
    }
};
