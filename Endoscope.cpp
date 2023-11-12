#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int row , col , x, y , L , ans;
unordered_map < int , vector < int > > mat , vis;

bool valid(int x , int y){
    return x >= 0 && x < row && y >= 0 && y < col && mat[x][y] != 0 && vis[x][y] == 0;
}

bool left(int x, int y){
    return mat[x][y] == 1 || mat[x][y] == 3 || mat[x][y] == 6 || mat[x][y] == 7;
}

bool right(int x, int y){
    return mat[x][y] == 1 || mat[x][y] == 3 || mat[x][y] == 4 || mat[x][y] == 5;
}

bool up(int x, int y){
    return mat[x][y] == 1 || mat[x][y] == 2 || mat[x][y] == 4 || mat[x][y] == 7;
}

bool down(int x, int y){
    return mat[x][y] == 1 || mat[x][y] == 2 || mat[x][y] == 5 || mat[x][y] == 6;
}

void bfs(){
    vis[x][y] = 1;
    queue < pair < int , int > > q;
    q.push({x,y});

    while(!q.empty()){

        int u = q.front().first , v = q.front().second;
        q.pop();

        if(mat[u][v] == 0 || vis[u][v] > L)
            continue;
        
        ans++;

        if(valid(u,v-1) && left(u,v) && right(u,v-1))
            vis[u][v-1] = vis[u][v] + 1 , q.push({u,v-1});

        if(valid(u,v+1) && right(u,v) && left(u,v+1))
            vis[u][v+1] = vis[u][v] + 1 , q.push({u,v+1});

        if(valid(u-1,v) && up(u,v) && down(u-1,v))
            vis[u-1][v] = vis[u][v] + 1 , q.push({u-1,v});

        if(valid(u+1,v) && down(u,v) && up(u+1,v))
            vis[u+1][v] = vis[u][v] + 1 , q.push({u+1,v});  
        
    }
}
int main(){
    // freopen("./input.txt","r",stdin);

    int t , i , j , val;

    cin>>t;

    while(t--){
        cin>>row>>col>>x>>y>>L;

        for(i = 0 ; i < row ; i++){
            vis[i].clear() , mat[i].clear();
            for(j = 0 ; j < col ; j++){
                cin>>val;
                mat[i].push_back(val);
                vis[i].push_back(0);
            }
        }

        bfs();
        cout<<ans<<endl;
        ans = 0;
    }
    return 0;
}