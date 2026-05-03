class Solution {
private:
    double rec(double x, int n){
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }

        double half = rec(x, n/2);

        return n%2 == 0 ? half*half: half*half*x;
    }
public:
    double myPow(double x, int n) {
        if(n < 0){
            x = (1/x);
            n*=-1;
        }

        if(n == 0){
            return 1;
        }

        double ans = 1;
        
        return rec(x, n);
    }
};
