class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> m;
        for(int h: hand){
            m[h]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;

        for(auto i=m.begin();i!=m.end();i++){
            pq.push({i->first, i->second});
        }

        while(!pq.empty()){
            int minVal = -1;
            int freq = -1;
            stack<pair<int,int>> s;
            for(int i=0;i<groupSize;i++){
                if(pq.empty()){
                    return false;
                }

                auto top = pq.top();
                pq.pop();

                if(minVal == -1){
                    minVal = top.first;
                    freq = top.second;
                } else {
                    if(top.first != minVal + i){
                        // cout<<"A"<<endl;
                        // cout<<top.first<<" "<<minVal<<" "<<i<<endl;
                        return false;
                    }

                    if(top.second < freq){
                        // cout<<"B"<<endl;
                        // cout<<top.second<<" "<<freq<<endl;
                        // cout<<top.first<<" "<<minVal<<endl;
                        return false;
                    }

                    if(top.second > freq){
                        s.push({top.first, top.second-freq});
                    }
                }
            }

            minVal = -1;
            freq = -1;

            while(!s.empty()){
                pq.push(s.top());
                s.pop();
            }
        }

        return true;
    }
};
