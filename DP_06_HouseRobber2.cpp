#include <bits/stdc++.h> 
long long int maximumNonAdjacentSum(vector<int> &nums){
    long long int prev2= 0;
    long long int prev1= nums[0];

    for(int i=1;i<nums.size();i++){
        long long int pick = nums[i];
        if  (i>1) pick += prev2;
        long long int not_pick= prev1;
        long long int ans = max(pick,not_pick);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse,int i=0)
{
    // Write your code here.
    int n=valueInHouse.size();
    if(n==1) return valueInHouse[0];

    vector<int> temp1, temp2;
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));

}