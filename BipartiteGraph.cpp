// Problem Id: https://practice.geeksforgeeks.org/problems/bipartite-graph/1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map < int , vector < int > > adj;
unordered_map < int , int > color;

bool isBipartite(int source){
    queue < int > q;
    color[source] = 1;
    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0 ; i < adj[u].size() ; i++){
            int v = adj[u][i];

            if(color[v] == 0){
                color[v] = (color[u] == 1)? 2 : 1;
                q.push(v);
            }

            else if(color[u] == color[v])
                return false;
        }
    }
    return true;
}
int main(){
    int i , j , x , y , n , m;
    bool ans = true;
    cin>>n>>m;

    for(i = 0 ; i < m ; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(i = 0 ; i < n ; i++){
        if(color[i] == 0 && !isBipartite(i)){
            ans = false;
            break;
        }
    }
    cout<<ans<<endl;

    return 0;
}