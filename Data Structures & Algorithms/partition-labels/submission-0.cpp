class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;     // stores last index of char c in s

        for(int i=0;i<s.size();i++){
            m[s[i]] = i;
        }

        vector<int> ans;
        // int start = 0;
        // int end = m[s[start]];
        int l = 0;
        int r = m[s[l]];

        while(r < s.size()){
            for(int i=l;i<=r;i++){
                r = max(r, m[s[i]]);
            }

            ans.push_back(r-l+1);
            l = r + 1;
            if(l >= s.size()){
                break;
            }
            
            r = m[s[l]];
        }

        return ans;
    }
};
