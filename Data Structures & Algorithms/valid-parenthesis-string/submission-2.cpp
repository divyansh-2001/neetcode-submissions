class Solution {
public:
    bool checkValidString(string s) {
        int openCount = 0;
        int closeCount = 0;

        int dummyOpen = 0;
        int dummyClose = 0;

        int totalOpen = count(s.begin(), s.end(), '(');
        int totalClose = count(s.begin(), s.end(), ')');

        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                openCount++;
                dummyOpen++;
                continue;
            }
            
            if(s[i] == ')'){
                if(dummyClose > dummyOpen){
                    return false;
                }

                closeCount++;
                dummyClose++;
                continue;
            }

            int remOpen = totalOpen - openCount;
            int remClose = totalClose - closeCount;
            int net = dummyOpen - dummyClose;

            if(remOpen - remClose + net == 0){
                continue;
            }

            if(remOpen + net - remClose > 0){
                dummyClose++;
            } else {
                dummyOpen++;
            }
        }

        return dummyOpen == dummyClose;
    }
};
