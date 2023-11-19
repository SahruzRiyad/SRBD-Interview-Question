/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/
https://www.careercup.com/page?pid=samsung-interview-questions

A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and 
the edge weights are the probabilities of the doctor going from that division to other connected division but the 
doctor stays 10mins at each division now there will be given time and had to find the division in which he will be 
staying by that time and is determined by finding division which has high probability.

Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division 
in which he will be there, the edges starting point, end point, probability.

Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling 
time is not considered and during that 10min at 10th min he will be in next division, so be careful

2
6 10 40 
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 10 10 
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5

6 0.774000  
3 0.700000
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <iomanip>
#define pd pair<int,double>
using namespace std;

unordered_map < int , bool > vis;
unordered_map < int , double > probablility;

double maxProb;
int node;
vector < pd > adj[100];

void bfs(int s , int duration){
    vis[s] = 1;
    queue < int > q;
    q.push(s);
    vis.clear();
    probablility.clear();

    probablility[s] = 1;

    while(!q.empty()){
        
        int sz = q.size();

        maxProb = 0;

        while(sz--){
            int u = q.front();
            q.pop();

            for(int i = 0 ; i <  adj[u].size(); i++){
                int v = adj[u][i].first;
                double w = adj[u][i].second;

                if(u == v)
                    continue;

                if(vis[v] == 0)
                    q.push(v) , vis[v] = 1;

                probablility[v] = probablility[v] + w * probablility[u];
                if(maxProb < probablility[v])
                    maxProb = probablility[v] , node = v;

            }
        }

        duration -= 10;

        if(duration <= 0)
            break;
    }
}

int main(){
    freopen("./input.txt","r",stdin);

    int i , j , n , t , e , duration , x , y;
    double prob;
    cin>>t;

    while(t--){
        cin>>n>>e>>duration;

        for(i = 0; i < e ; i++){
            cin>>x>>y>>prob;
            adj[x].push_back({y,prob});
        }

        bfs(1,duration);

        for(i = 1 ; i <= n ; i++){
            adj[i].clear();
        }
        
        cout<<node<<' '<<setprecision(6)<<fixed<<maxProb<<endl;

    }
    return 0;
}