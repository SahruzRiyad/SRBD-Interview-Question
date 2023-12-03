#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#define pii pair<int,int>
using namespace std;

unordered_map < int , vector < int > > adj;


int dijkstra(int x , int N){
    priority_queue < pii , vector < pii > , greater <pii> > pq;
    pq.push({0,x});
    vector < int > dist(N,INT_MAX);
    dist[x] = 0;

    while(!pq.empty()){
        pii u = pq.top();
        pq.pop();

        for(int i = 0 ; i < adj[u.second].size() ; i++){
            x = adj[u.second][i];

            if(dist[i] > dist[u.second] + x){
                dist[i] = dist[u.second] + x;
                pq.push({dist[i],i});
            }
        }
    }
    return dist[N-1];
}

void init(int n){
    for(int i = 0 ; i < n ; i++)
        adj[i].clear();
}

int main(){
    //freopen("./input.txt","r",stdin);
    int t , i , j , n , x , N , val;
    cin>>t;
    while(t--){
        cin>>n;

        N = (n + 1) * 2;
        int x[N] , y[N] , cost[N];
        j = 1;
        init(N);

        cin>>x[0]>>y[0]>>x[N-1]>>y[N-1];

        for(i = 1 ; i <= n ; i++){
            cin>>x[j]>>y[j];
            cin>>x[j+1]>>y[j+1];
            cin>>cost[j];
            cost[j+1] = cost[j];

            j += 2;
        }

        for(i = 0; i < N ; i++){
            int dis1 = abs(x[0]-x[i]) + abs(y[0]-y[i]);
            int dis2 = abs(x[N-1] - x[i]) + abs(y[N-1] - y[i]);

            adj[0].push_back(dis1);
            adj[N-1].push_back(dis2);
        }

        for(i = 1 ; i < N - 1 ; i++){

            for(j = 0 ; j < N ; j++){
                if(i == j)
                    adj[i].push_back(0);
                else{
                    if(i & 1)
                        val = abs(x[j]-x[i+1]) + abs(y[j]-y[i+1]) + cost[i];
                    else 
                        val = abs(x[j]-x[i-1]) + abs(y[j]-y[i-1]) + cost[i];

                    adj[i].push_back(val);    
                }
            }
        }

        cout<<dijkstra(0,N)<<endl;
    }
    return 0;
}
