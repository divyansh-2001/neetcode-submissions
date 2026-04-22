#include <bits/stdc++.h>
#include <string>

class Solution {
private:
    bool isOperator(string a){
        return a == "+" || a == "-" || a == "*" || a == "/";
    }

    int evaluate(int a, int b, string oper){
        if(oper == "+"){
            return a+b;
        } else if (oper == "-") {
            return b-a;
        } else if ( oper == "*") {
            return a*b;
        }

        return b/a;
    }

    int getInt(string num){
        return stoi(num);
    }

    string getString(int val){
        return to_string(val);
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(int i=0;i<tokens.size();i++){
            if(isOperator(tokens[i])){
                int a = getInt(st.top());
                st.pop();
                int b = getInt(st.top());
                st.pop();

                int val = evaluate(a, b, tokens[i]);
                st.push(getString(val));
            } else {
                st.push(tokens[i]);
            }
        }

        return getInt(st.top());
    }
};
