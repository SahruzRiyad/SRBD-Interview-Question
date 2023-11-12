#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;

int ans;

bool checkGrid(pii x , pii r){
    return r.first <= x.first && x.first <= r.second;
}

void dfs(vector<vector<int>> mat, int n, int coins, pii s , pii r){
    if(s.first < 0 || s.first >= n || s.second < 0 || s.second >= 5){
        ans = max(ans,coins);
        return;
    }

    if(mat[s.first][s.second] == 2 && !checkGrid(s,r)){
        ans = max(ans,coins);
        return;
    }
        
    if(mat[s.first][s.second] == 1)
        coins++;
    
    dfs(mat,n,coins,{s.first-1,s.second},r);
    dfs(mat,n,coins,{s.first-1,s.second-1},r);
    dfs(mat,n,coins,{s.first-1,s.second+1},r);
    
}

void callDfs(vector<vector<int>> &mat,int n,int i){
    dfs(mat,n,0,{n-1,1},{i-5,i-1});
    dfs(mat,n,0,{n-1,2},{i-5,i-1});
    dfs(mat,n,0,{n-1,3},{i-5,i-1});
}

int main(){
    // freopen("./input.txt","r",stdin);

    int t , i , j , n , x , tc = 1;
    cin>>t;

    while(t--){
        cin>>n;

        vector < vector < int >  > mat(n);

        for(i = 0; i < n ; i++){
            for(j = 0; j < 5 ; j++){
                cin>>x;
                mat[i].push_back(x);
            }
        }

        if(n <= 5){
            callDfs(mat,n,5);
        }

        else{
            for(i = 5 ; i <= n ; i++){
                callDfs(mat,n,i);
            }
        }

        cout<<"#"<<tc++<<' '<<ans<<endl;
        ans = 0;
    }
    return 0;
}