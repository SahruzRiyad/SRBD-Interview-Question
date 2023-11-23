#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int burst(vector<int>&a , int i , int j , int n , vector<vector<int>> &dp){
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int mx = INT_MIN;
    for(int ind = i ; ind <= j ; ind++){
        int cost = burst(a,i,ind-1,n,dp) + burst(a,ind+1,j,n,dp);

        cost += a[i-1] * a[ind] * a[j+1];
        mx = max(mx,cost);
    }
    return dp[i][j] = mx;
}

int maxCoins(vector<int>&nums){
    int n = nums.size();
    vector < int > tmp(n+2);

    tmp[0] = tmp[n+1] = 1;

    for(int i = 1 ; i <= n ; i++)
        tmp[i] = nums[i-1];
    
    vector < vector < int > > dp(n+2,vector<int>(n+2,-1));
    
    return burst(tmp,1,n,n,dp);
}

int main(){
    // freopen("./input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n , i;
    cin>> n;

    vector < int > nums(n);

    for(i = 0 ; i < n ; i++){
        cin>>nums[i];
    }

    cout<<maxCoins(nums)<<endl;
}