/*
Here the last one Ballon that is left after bursting all others
will left as it is. It will not add up with maximum score.
Sample Input 1:
3
1 2 3
Sample Input 2:
2
1 5
Sample Input 3:
4
3 1 5 8

Sample Output 1: 9
Sample Output 2: 5
Sample Output 3: 159

*/
#include <iostream>
#include <vector>
using namespace std;

int burst(vector<int>&a , int i , int j , int n , vector<vector<int>>&dp){
    if(i > j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int mx = 0;
    for(int ind = i ; ind <= j ; ind++){
        int cost = burst(a,i,ind-1,n,dp) + burst(a,ind+1,j,n,dp);

        if(i == 1 && j == n)
            mx = max(mx,cost);

        else{
            cost += a[i-1] * a[ind] * a[j+1];
            mx = max(mx,cost);    
        }
    }

    return dp[i][j] = mx;
}

int maxCoins(vector<int>&nums , int n){
    vector < vector < int > > dp(n+2,vector<int>(n+2,-1));
    return burst(nums,1,n,n,dp);
}
int main(){
    // freopen("./input.txt","r",stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n , i;
    cin>>n;

    vector < int > arr(n+2);

    for(i = 1 ; i <= n ; i++){
        cin>>arr[i];
    }

    arr[0] = arr[n+1] = 1;

    cout<<maxCoins(arr,n)<<endl;

    return 0;
}