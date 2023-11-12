#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define pii pair<int,int>
using namespace std;

int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};

vector < int > adj[10];
map < pii, bool > mark;

int ans = 500;
bool valid(int x , int y , int n, int m){
    return x >= 0 && x < n && y >=0 && y < m; 
}

void solve(int x, int y, pii dest, int difficulty,int n , int m){
    if(!valid(x,y,n,m))
        return;
    if(dest.first == x && dest.second == y){
        ans = min(ans,difficulty);
        return;
    }

    mark[{x,y}] = true;
    int up = x - 1;
    while(up >= 0 && adj[up][y] == 0)
        up--;
    
    if(up >= 0 && mark[{up,y}] == false)
        solve(up,y,dest,max(difficulty,x-up),n,m);
    
    int down = x + 1;
    while(down < n && adj[down][y] == 0)
        down++;
    
    if(down < n && mark[{down,y}] == false)
        solve(down,y,dest,max(difficulty,down-x),n,m);
    
    if(y + 1 < m && adj[x][y+1] != 0 && mark[{x,y+1}] == false)
        solve(x,y+1,dest,difficulty,n,m);
    
    if(y - 1 >= 0 && adj[x][y-1] != 0 && mark[{x,y-1}] == false)
        solve(x,y-1,dest,difficulty,n,m);
    
    mark[{x,y}] = false;
    
}
int main(){
    freopen("./input.txt","r",stdin);

    int n , m , i , j , x;
    pii dest;
    cin>>n>>m;

    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            cin>>x;
            adj[i].push_back(x);
            if(x == 3)
                dest = {i,j};
        }
    }

    solve(n-1,0,dest,0,n,m);
    cout<<ans<<endl;

    return 0;
}