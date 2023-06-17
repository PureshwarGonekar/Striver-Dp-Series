#include<iostream>
using namespace std;
// Normal Approch Time Complexity - O(2^n) Space Complexity - O(n)[function stack]
int fibo1(int n){
    if(n<=1){
        return n;
    }
    int a = fibo1(n-1);
    int b = fibo1(n-2);
    return a+b;
}

//Memorization Time Complexity - O(n)  Space Complexity - O(n)[function stack]+ O(n)[array of size n+1]
int fibo2(int n, int *ans){
    if(n<=1){
        return n;
    }
    if(ans[n]!= -1){
        return ans[n];
    }
    int a = fibo2(n-1,ans);
    int b = fibo2(n-2,ans);
    ans[n]= a+b;
    return ans[n];
}
int fibo2(int n){
    int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return fibo2(n,ans);
}

// Tabular Method (DP) Time Complexity - O(n)  Space Complexity - O(n)
int fibo3(int n){
    int *ans = new int[n+1];
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        ans[i]= ans[i-1]+ans[i-2];
    }
    return ans[n];
}
int main(){
    cout<<fibo1(10)<<endl;
    cout<<fibo2(20)<<endl;
    cout<<fibo3(30)<<endl;

    return 0;
}