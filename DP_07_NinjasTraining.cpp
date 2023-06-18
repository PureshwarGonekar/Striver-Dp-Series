#include <bits/stdc++.h> 
int ninjaTraining(int day,int last,vector<vector<int>> &points){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi= max(maxi,points[day][i]);
            }
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int point = points[day][i] + ninjaTraining(day-1,i,points);
            maxi = max(maxi,point);
        }  
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points,int last=3)
{
    // Write your code here.
    return ninjaTraining(n-1,3,points);
}


// Memorization
int ninjaTraining(int day,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi= max(maxi,points[day][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!= -1) return dp[day][last];

    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int point = points[day][i] + ninjaTraining(day-1,i,points,dp);
            maxi = max(maxi,point);
        }  
    }
    return dp[day][last]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points,int last=3)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return ninjaTraining(n-1,3,points,dp);
}

// Tabulation 
int ninjaTraining(int n,vector<vector<int>> &points){
    vector<vector<int>> dp(n,vector<int>(4,0));

    dp[0][0]= max(points[0][1], points[0][2]);
    dp[0][1]= max(points[1][0], points[1][2]);
    dp[0][2]= max(points[2][0], points[2][1]);
    dp[0][3]= max(points[3][0], max(points[3][1],points[3][2]));

    for(int day=0;day<n;day++){
        for(int last=0;last<4; last++){
            dp[day][last]= 0;
            for(int task=0 ; task<3;task++){
                if(task!=last){
                    int point = points[day][i] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }
            }
         
        }
        
    }
    return dp[n-1][3];
}

//Space Optimization T.C. => O(n*4*3) S.C O(4)
int ninjaTraining(int n,vector<vector<int>> &points){
    vector<int> prev(4,0);

    prev[0]= max(points[0][1], points[0][2]);
    prev[1]= max(points[0][0], points[0][2]);
    prev[2]= max(points[0][0], points[0][1]);
    prev[3]= max(points[0][0], max(points[0][1],points[0][2]));

    for(int day=1; day<n; day++){
        vector<int> temp(4,0);
        for(int last=0;last<4; last++){

            temp[last]= 0;
            

            for(int task=0 ; task<3; task++){
                if(task!=last){
                    temp[last] = max(temp[last],points[day][task] + prev[task]);
        
                }
            }
         
        }
        prev=temp;
        
    }
    return prev[3];
}