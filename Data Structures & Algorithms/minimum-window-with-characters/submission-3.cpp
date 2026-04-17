class Solution {
private:
    int getIdx(char c){
        if(c >= 'a' && c <= 'z'){
            return c-'a';
        }

        return c-'A'+26;
    }

    bool isEqual(vector<int>& a, vector<int>& b){
        for(int i=0;i<52;i++){
            if(a[i] < b[i]){
                return false;
            }
        }

        return true;
    }
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }

        vector<int> sot(52, 0);
        for(int i=0;i<t.size();i++){
            sot[getIdx(t[i])]++;
        }

        int l = 0;
        int r = 0;

        while(r < s.size() && sot[getIdx(s[r])] == 0 ){
            r++;
        }

        if(r == s.size() || (s.size() - r) < t.size() ){
            return "";
        }

        string ans = "";
        int minLength = INT_MAX;

        l = r;

        vector<int> curr(52, 0);

        while(r < s.size()){
            char c = s[r];
            int pos = getIdx(c);

            if(sot[pos] == 0){
                r++;
                continue;
            }

            curr[pos]++;

            if(curr[pos] == sot[pos]){
                if(isEqual(curr, sot)){

                    while(l <= r && isEqual(curr, sot)){
                        if( (r-l+1) < minLength){
                            minLength = r-l+1;
                            ans = s.substr(l, minLength);
                        }

                        curr[getIdx(s[l])] = max(0, curr[getIdx(s[l])]-1);
                        l++;
                    }

                    while(l <= r && sot[getIdx(s[l])] == 0 ){
                        l++;
                    }
                }
            }

            // while(l < r && curr[pos] > sot[pos]){
            //     curr[getIdx(s[l])] = max(0, curr[getIdx(s[l])]-1);
            //     l++;
            // }

            r++;
        }

        return ans;

    }
};
