/*
Given a 2 D matrix where 1 represent the places where the frog can jump and 0 represent the empty spaces,
the frog can move freely in horizontal direction (on 1’s only) without incurring any cost (jump). 
A vertical jump from a given point of the matrix to other point on the matrix can be taken (on 1’s only) 
with cost as the number of jumps taken.
Given a source and destination, the frog has to reach the destination minimizing the cost (jump).

Input: t = test case , n  = number of rows , m = number of coloums followed by the 2D matrix
and source and destination.

Output: Minimum cost of jump to reach source to destination;

Sample Input:
1
5 5
1 0 0 1 1
1 1 1 0 0
0 1 1 1 0
1 1 1 1 0
1 1 1 1 1
0 0 
4 4

Sample Output:
4
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#define pii pair<int,int>
using namespace std;

unordered_map < int , vector < bool > > mat;
map < pii , int > lvl;
int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};
int n , m;

bool valid(int x , int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs(pii source , pii dest){
    queue < pii > q;
    q.push(source);
    lvl[source] = 1;

    while(!q.empty()){
        pii u = q.front();
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int x = u.first + fx[i];
            int y = u.second + fy[i]; 

            if(valid(x,y) && mat[x][y] == 1 && lvl[{x,y}] == 0){
                lvl[{x,y}] = lvl[u];

                if(i >= 2)
                    lvl[{x,y}] += 1;
                
                q.push({x,y});
            }
        }
    }
    return lvl[dest] - 1;

}

int main(){
    // freopen("./input.txt","r",stdin);
    int i , j , tc;
    bool x;
    pii source , dest;
    cin>>tc;

    while(tc--){
        cin>>n>>m;

        for(i = 0 ; i < n ; i++){
            for(j = 0 ; j < m ; j++){
                cin>>x;
                mat[i].push_back(x);
            }
        }

        cin>>source.first>>source.second;
        cin>>dest.first>>dest.second;

        cout<<bfs(source,dest)<<endl;
    }
    return 0;
}