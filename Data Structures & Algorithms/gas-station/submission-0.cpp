class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int net = 0;
        for(int i=0;i<gas.size();i++){
            net += (gas[i] - cost[i]);
        }

        if(net < 0){
            return -1;
        }

        for(int i=0;i<gas.size();i++){
            if(net < 2*(gas[i] - cost[i])){
                return i;
            }
        }
        
        return -1;
    }
};
