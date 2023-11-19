// Problem Link:https://www.geeksforgeeks.org/samsung-interview-experience-on-campus-2019-for-samsung-research-institute-noida/
/*
Input: Test case , N x N grid , no_of_rareElements followed by
location of rareElements and the grid;
Index of matrix started from (1,1) and end at (N,N);

7
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1

8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1

15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1

20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0

5 2
2 1
3 5
1 0 1 1 1
1 1 1 0 1
0 1 1 0 1
0 1 0 1 1
1 1 1 0 1

3 2
1 1
3 3
1 1 1
1 1 1
1 1 1

Output:
#1: 1
#2: 2
#3: 2
#4: 12
#5: 15
#6: 4
#7: 2
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <climits>
#define pii pair<int,int>
using namespace std;

int n ,mx , cnt , c;
unordered_map < int , vector < int > > adj;
vector < pii > rareElements;
int vis[21][21];

int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};

bool valid(int x , int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool isRareElements(int x , int y){
    for(auto &itr : rareElements){
        if(itr.first == x && itr.second == y)
            return true;
    }

    return false;
}

void bfs(int x, int y){

    vis[x][y] = 1;
    queue < pii > q;
    q.push({x,y});

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            x = u.first + fx[i];
            y = u.second + fy[i];

            if(valid(x,y) && adj[x][y] != 0 && vis[x][y] == 0 && cnt < c){
                vis[x][y] = vis[u.first][u.second] + 1;
                q.push({x,y});

                if(adj[x][y] == 2)
                    mx = max(mx,vis[x][y]),cnt++;
            }
        }
    }
    
}

int findLongestDist(int x, int y){
    cnt = mx = 0;
    memset(vis,0,sizeof(vis));
  
    bfs(x,y);

    return (cnt < c)? INT_MAX : mx - 1;
}

void clearArrays(){
    rareElements.clear();

    for(int i = 0 ; i < n; i++)
        adj[i].clear();
}

int main(){
    freopen("./input.txt","r",stdin);

    int i , j , tc, x, y , ans = INT_MAX , cs = 1;
    cin>>tc;

    while(tc--){
        cin>>n>>c;

        ans = INT_MAX;
        for(i = 0 ; i < c; i++){
            cin>>x>>y;
            x--,y--;
            rareElements.push_back({x,y});
        }

        for(i = 0 ; i < n; i++){
            for(j = 0 ; j < n ; j++){
                cin>>x;

                if(isRareElements(i,j))
                    x = 2;

                adj[i].push_back(x);
            }
        }

        for(i = 0 ; i < n ; i++){
            for(j = 0 ; j < n ; j++){
                if(adj[i][j] != 0){
                    ans = min(ans,findLongestDist(i,j));
                }
            }
       }

       cout<<'#'<<cs++<<": "<<ans<<endl;

       clearArrays();

    }
    return 0;
}