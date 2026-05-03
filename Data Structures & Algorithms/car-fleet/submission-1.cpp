class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i=0;i<position.size();i++){
            v.push_back({position[i], speed[i]});
        }

        sort(v.begin(), v.end());

        vector<double> tRem;
        for(int i=0;i<v.size();i++){
            cout<<v[i].first<<" "<<v[i].second<<endl;
            double val = (double)(target-v[i].first)/v[i].second;
            cout<<val<<endl;
            tRem.push_back(val);
        }

        int fleet = 1;
        double curr = tRem[tRem.size()-1];

        for(int i=tRem.size()-2;i>=0;i--){
            if(curr >= tRem[i]){

            } else {
                fleet++;
                curr = tRem[i];
            }
        }

        return fleet;
    }
};


// 0, 1, 4, 7
// 1, 2, 2, 1


// 10, 4.5, 3, 3

