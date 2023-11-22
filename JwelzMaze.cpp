// Problem Id: https://blog.csdn.net/lihenair/article/details/17227667
/*
Sample Input:
2
5
0 0 0 2 0
2 1 0 1 2
0 0 2 2 0
0 1 0 1 2
2 0 0 0 0
6
0 1 2 1 0 0
0 1 0 0 0 0
0 1 2 1 2 1
0 2 0 1 0 2
0 1 0 1 0 1
2 0 2 1 0 0

Sample Output:
# 1: 6
3 0 3 3 3 
3 1 3 1 3 
3 0 3 2 3 
3 1 3 1 3 
3 3 3 0 3 
# 2: 4
3 1 2 1 0 0 
3 1 3 3 3 0 
3 1 3 1 3 1 
3 2 3 1 3 2 
3 1 3 1 3 1 
3 3 3 1 3 3 
*/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#define pii pair<int,int>
using namespace std;

unordered_map < int , vector < int > > adj , path;
map < pii , bool > vis;
int ans , n;
int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};

bool valid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int x , int y , int val){
    if(x == n - 1 && y == n - 1){
        if(val > ans){
            ans = val;
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(vis[{i,j}])
                        path[i][j] = 3;
                    else 
                        path[i][j] = adj[i][j];
                }
            }
        }
        return;
    }
    

    for(int i = 0 ; i < 4 ; i++){
        int u = x + fx[i];
        int v = y + fy[i];

        if(valid(u,v) && vis[{u,v}] == 0 && adj[u][v] != 1){
            vis[{u,v}] = 1;
            bool jewel = (adj[u][v] == 2);
            dfs(u,v,val+jewel);
            vis[{u,v}] = 0;
        }
    }
}

void init(int n){
    for(int i = 0 ; i < n ; i++)
        adj[i].clear();

    vis.clear();
    ans = 0;
}
int main(){
    freopen("./input.txt","r",stdin);
    int i , j , tc , cs = 1 , x;

    cin>>tc;

    while(tc--){
        cin>>n;

        init(n);

        for(i = 0 ; i < n ; i++){
            for(j = 0 ; j < n ; j++){
                cin>>x;
                adj[i].push_back(x);
                path[i].push_back(x);
            }
        }

        ans = (adj[0][0] == 2)? 1 : 0;
        vis[{0,0}] = 1;

        dfs(0,0,ans);
        cout<<"# "<<cs++<<": "<<ans<<endl;
        for(i = 0 ; i < n ; i++){
            for(j  = 0 ; j < n ; j++){
                cout<<path[i][j]<<' ';
            }
            cout<<endl;
        }

    }
    return 0;
}