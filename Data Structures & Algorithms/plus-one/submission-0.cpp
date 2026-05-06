class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v;
        int carry = 1;
        for(int i=digits.size()-1;i>=0;i--){
            int num = digits[i] + carry;
            int rem = num%10;
            carry = num/10;
            v.push_back(rem);
        }

        if(carry != 0){
            v.push_back(carry);
        }

        reverse(v.begin(), v.end());
        return v;
    }
};
