class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> net(gas.size(), 0);
        for(int i=0;i<gas.size();i++){
            net[i] = gas[i] - cost[i];
        }

        if(accumulate(net.begin(), net.end(), 0) < 0){
            return -1;
        }

        int tempSum = 0;
        int si = 0;

        for(int i=0;i<net.size();i++){
            tempSum += net[i];
            if(tempSum < 0){
                si = i+1;
                tempSum = 0;
            }
        }

        return si;
    }
};
