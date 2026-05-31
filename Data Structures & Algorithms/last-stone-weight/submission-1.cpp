class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() < 2){
            return stones[0];
        }

        priority_queue<int, vector<int>> pq;
        pq.push(stones[0]);

        for(int i=1;i<stones.size();i++){
            pq.push(stones[i]);

            int top1 = pq.top();
            pq.pop();

            if(pq.empty()){
                pq.push(top1);
                continue;
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
