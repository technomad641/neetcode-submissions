class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) return 1.00000/ myPow(x, -n);
        if(n==0) return 1.0000000;
        if(n%2==0){
             double P = myPow(x, n/2);
             return P*P;
        }else {
            return x* myPow(x, n-1);
        }
    }
};
