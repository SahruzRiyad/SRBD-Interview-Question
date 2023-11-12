#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int burst(vector<int> &a , int i , int j, int n, vector<vector<int>> &dp){
    if(i > j)
        return 0;

    if(dp[i][j] != INT_MIN)
        return dp[i][j];

    int mx = INT_MIN;
    for(int ind = i ; ind <= j ; ind++){
        int cost = burst(a,i,ind-1,n,dp) + burst(a,ind+1,j,n,dp);

        if(i == 1 && j == n)
            cost += a[ind];
        else 
            cost += a[i-1] * a[j + 1];

        mx = max(mx,cost);
    }
    return dp[i][j] = mx;
}
int main(){
    int n , i , sum = 0 , res = INT_MIN;

    cin>>n;

    vector < int > arr(n+2);
    vector < vector < int > > dp(n+2,vector<int>(n+2,INT_MIN));

    for(i = 1 ; i  <= n ; i++){
        cin>>arr[i];
    }

    arr[0] = arr[n+1] = 1;

    cout<<burst(arr,1,n,n,dp)<<endl;

    return 0;
}