#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#define pii pair<int,int>
using namespace std;

unordered_map < int , vector < int > > adj;
unordered_map < int , bool > mark;
int ans = INT_MAX;

void dks(int s , int d, int val, int n){
    vector < int > dist(n,INT_MAX);

    dist[s] = 0;
    priority_queue < pii , vector < pii > , greater < pii > > pq;
    pq.push({0,s});

    while(!pq.empty()){
        pii tmp = pq.top();
        pq.pop();

        for(int i = 0 ; i < n ; i++){
            int x = adj[tmp.second][i];

            if(dist[tmp.second] + x < dist[i]){
                dist[i] = dist[tmp.second] + x;
                pq.push({dist[i],i});
            }
        }
    }

    ans = dist[n-1];

}
int main(){
    int t , i , j, n , res , val;
    pii source , dest;
    freopen("./input.txt","r",stdin);
    cin>>t;

    while(t--){
        cin>>n;
        int lim = (n + 1) * 2;
        int x[lim] , y[lim] , c[n] , cInd = 0;

        cin>>x[0]>>y[0]>>x[lim-1]>>y[lim-1];

        for(i = 1 , j = 0 ; i < lim - 1; i += 2, j++)
            cin>>x[i]>>y[i]>>x[i+1]>>y[i+1]>>c[j];
        
        for(i = 0 ; i < lim ; i++){
            int val1 = abs(x[0]-x[i]) + abs(y[0]-y[i]);
            int val2 = abs(x[lim-1]-x[i]) + abs(y[lim-1]-y[i]);

            adj[0].push_back(val1);
            adj[lim-1].push_back(val2);
        }

        for(i = 1 ; i < lim - 1 ; i++){

            for(j = 0 ; j < lim ; j++){
                if(i == j)
                    adj[i].push_back(0);
                else{
                    if(i & 1)
                        val = abs(x[j]-x[i+1]) + abs(y[j]-y[i+1]) + c[cInd];
                    else 
                        val = abs(x[j]-x[i-1]) + abs(y[j]-y[i-1]) + c[cInd];

                    adj[i].push_back(val);
                }
                
            }

            if(!(i & 1))
                cInd++;
        }

        // for(i = 0 ; i < lim ; i++){
        //     for(j = 0 ; j < lim ; j++)
        //         cout<<adj[i][j]<<' ';
        //     cout<<endl;
        // }
       dks(0,lim-1,0,lim);
       cout<<ans<<endl;

       adj.clear();
       mark.clear();

    }
    return 0;
}