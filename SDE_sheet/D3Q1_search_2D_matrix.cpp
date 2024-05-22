class Solution {
public:
    double myPow(double x, int n) {
        // Handle the case when n is INT_MIN
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double ans = 1;
        double current_product = x;
        
        while (N > 0) {
            if (N % 2 == 1) {
                ans *= current_product;
            }
            current_product *= current_product;
            N /= 2;
        }
        
        return ans;
    }
};
// class Solution {
// public:
//     double myPow(double x, int n) {
//         long N = (long) abs(n);
//         double ans[N+1];
//         ans[0]=1;
//         if(n > 0){
//             ans[1]=x;
//         } 
//         else if( n < 0){
//             ans[1] = 1/x;
//         }

//         for(long i=2; i<=N; i++){
//             int half1= i/2;
//             int half2 = i-half1;
//             ans[i] = ans[half1] * ans[half2];
//         }
//         return ans[N];
//     }
// };