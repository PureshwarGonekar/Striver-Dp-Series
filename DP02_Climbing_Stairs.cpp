#include<iostream>
using namespace std;

//Contraints
// 0 <= N <= 10^18
// con't run for loop
//We have to run Matrix Exponential -- O(logn)

int climbStairs(int n){
    //Base Case
    if(n==0){ 
        return 1;
    }
    if(n==1){
        return 0;
    }
    int a=climbStairs(n-1);
    int b=climbStairs(n-2);
    // int c=climbStairs(n-3);
    return a+b;
}


int climbStairs2(int n, int *ans){
    if(n==0){ 
        return 1;
    }
    if(n==1){
        return 0;
    }
    if(ans[n]!= -1){
        return ans[n];
    }
    int a = climbStairs2(n-1,ans);
    int b = climbStairs2(n-2,ans);
    ans[n]= a+b;
    return ans[n];
}
int climbStairs2(int n){
    int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return climbStairs2(n,ans);
}

// Tabular Method (DP) Time Complexity - O(n)  Space Complexity - O(n)
int climbStairs3(int n){
    int *ans = new int[n+1];
    ans[0]=1;
    ans[1]=0;
    for(int i=2;i<=n;i++){
        ans[i]= ans[i-1]+ans[i-2];
    }
    return ans[n];
}
int main(){
    cout<<climbStairs(5)<<endl;
    cout<<climbStairs2(5)<<endl;
    cout<<climbStairs3(5)<<endl;
    return 0;
}