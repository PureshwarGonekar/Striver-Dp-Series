#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    cout<<"before n"<<n<<endl;
    int N = abs(n);
    cout<<"after n"<<n<<endl;
    double ans[N+1];
    ans[0]=1;
    if(n > 0){
        cout<<"inside if n"<<n<<endl;
        ans[1]=x;
    } 
    else if( n < 0){
        cout<<"inside else n"<<n<<endl;
        ans[1] = 1/x;
        cout <<" ans[1]" <<ans[1]<<endl;
    }

    for(int i=2; i<=N; i++){
        int half1= i/2;
        int half2 = i-half1;
        ans[i] = ans[half1] * ans[half2];
    }
    return ans[N];
}
int main(){
    cout<<myPow(2.00000, -2)<<endl;
    return 0;
}