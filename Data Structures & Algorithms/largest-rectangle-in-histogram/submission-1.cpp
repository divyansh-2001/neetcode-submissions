class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int ans = 0;

        for(int i=0;i<heights.size();i++){
            if(s.empty() || heights[s.top()] <= heights[i]){
                s.push(i);
                continue;
            }

            while(!s.empty() && heights[s.top()] > heights[i]){
                int val = s.top();
                s.pop();
                int area = s.empty() ? (val+1)*heights[val] : (i - s.top() - 1)*heights[val];
                ans = max(ans, area);
            }

            s.push(i);
        }

        while(!s.empty()){
            int curr = s.top();
            s.pop();

            int area = s.empty() ? heights.size() * heights[curr] : (heights.size() - s.top() - 1)*heights[curr];
            ans = max(ans, area);
        }

        return ans;
    }
};
