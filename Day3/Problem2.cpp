// Pow(x,n)
class Solution {
public:
    
    double binaryExpo(double num, long long pow){
        double res = 1.0;
        while(pow > 0){
            if(pow&1){
                res = res*num;
            }
            num = num*num;
            pow >>= 1;
        }
        return res;
    }
    
    double myPow(double x, int n) {
        bool isNegativePow = (n<0);
        
        if(n==0) return 1;
        
        double result = binaryExpo(x,abs(n));
        
        return isNegativePow ? (double)(1.0) / (double)result : result;
    }
};