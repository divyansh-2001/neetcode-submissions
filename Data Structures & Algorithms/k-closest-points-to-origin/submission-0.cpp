class Solution {
private:
    double calculateDistance(vector<int>& a){
        int x = a[0];
        int y = a[1];

        return sqrt((x*x)+(y*y));
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>, vector<pair<double,int>>> pq;

        int i = 0;
        for(;i<k;i++){
            pq.push({calculateDistance(points[i]), i});
        }

        while(i < points.size()){
            pq.push({calculateDistance(points[i]), i});
            pq.pop();
            i++;
        }

        vector<vector<int>> ans;

        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }   
};
