#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector < int > adj[11] , parent(11,0) , vis(11,0) , inStack(11,0);
vector < int > ans , tmp , path;
int mx = INT_MAX;

void dfs(int s , int p){
    vis[s] = 1;
    parent[s] = p;

    for(int i = 0; i < adj[s].size() ; i++){
        int u = adj[s][i];

        if(vis[u] == 0)
            dfs(u,s);
        
        else{
            int v = s , sum = s;
            tmp.push_back(v);
            while(v != u && v > 0){
                v = parent[v] , tmp.push_back(v) , sum += v;
            }
          
            if(mx > sum){
                mx = sum;
                ans = tmp;
            }

            tmp.clear();
        }

    }
    vis[s] = 0;

}


int main(){
    // freopen("./input.txt","r",stdin);

    int n , i , m , j , x , y;

    cin>>n>>m;

    for(i = 0 ; i < m ; i++){
        cin>>x>>y;
        adj[x].push_back(y);
    }

    for(i = 1 ; i <= n ; i++){
        if(vis[i] == false)
            dfs(i,-1);
    }

    sort(ans.begin(),ans.end());

    for(auto &itr : ans)
        cout<<itr<<' ';
    cout<<endl;
    return 0;
}