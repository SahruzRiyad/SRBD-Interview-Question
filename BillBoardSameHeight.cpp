/*
Problem Id: https://www.geeksforgeeks.org/samsung-r-d-noida-question-september-2018/
Problem Id: https://leetcode.com/problems/tallest-billboard/description/
*/

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#define offset 5000
using namespace std;

int dp[21][2*offset+1];

int solve(vector<int>&rods , int i , int diff){
    if(i == rods.size()){
        if(diff == 0)
            return 0;

        return INT_MIN;
    }

    if(dp[i][diff+offset] != -1)
        return dp[i][diff+offset];
    
    int opt1 = solve(rods,i+1,diff);
    int opt2 = rods[i] + solve(rods,i+1,diff+rods[i]);
    int opt3 = solve(rods,i+1,diff-rods[i]);

    return dp[i][diff+offset] = max(opt1,max(opt2,opt3));
}
int tallestBillboard(vector<int>& rods) {
    memset(dp,-1,sizeof(dp));
    int ans = max(0,solve(rods,0,0));

    return ans;
}

int main(){
    // freopen("./input.txt","r",stdin);
    int n , i;

    cin>>n;
    vector < int > rods(n);

    for(i = 0 ; i < n ; i++)
        cin>>rods[i];
    
    cout<<tallestBillboard(rods)<<endl;
}