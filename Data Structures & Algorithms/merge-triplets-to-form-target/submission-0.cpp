class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> ignored;
        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]){
                ignored.insert(i);
            }
        }

        int amax = INT_MIN;
        int bmax = INT_MIN;
        int cmax = INT_MIN;

        for(int i=0;i<triplets.size();i++){
            if(ignored.find(i) != ignored.end()){
                continue;
            }

            amax = max(amax, triplets[i][0]);
            bmax = max(bmax, triplets[i][1]);
            cmax = max(cmax, triplets[i][2]);
        }
        
        return target[0] == amax && target[1] == bmax && target[2] == cmax;
    }
};
