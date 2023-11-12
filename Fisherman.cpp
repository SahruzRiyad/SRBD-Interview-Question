#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int calcDistance(int i, int j, int gPos){
    int ans = 0;
    for(int itr = i ; itr < j ; itr++){
        ans += abs(gPos-itr) + 1;
    }
    return ans;
}

int main(){
    // freopen("./input.txt","r",stdin);
    int n , i , g1 , g2 , g3 , res = INT_MAX , x , y , z;
    cin>>n;

    vector < int > gate_pos(3) , no_of_fisherman(3);

    for(i = 0 ; i < 3 ; i++)
        cin>>gate_pos[i];
    
    for(i = 0; i < 3 ; i++)
        cin>>no_of_fisherman[i];
    
    for(g1 = 1 ; g1 <= n - (no_of_fisherman[1] + no_of_fisherman[2]); g1++){

        x = calcDistance(g1,g1+no_of_fisherman[0],gate_pos[0]);

        for(g2 = g1 + no_of_fisherman[0]; g2 <= n - no_of_fisherman[2] ; g2++){

            y = calcDistance(g2,g2+no_of_fisherman[1],gate_pos[1]);

            for(g3 = g2 + no_of_fisherman[1]; g3 <= n; g3++){

                z = calcDistance(g3,g3+no_of_fisherman[2],gate_pos[2]);
                res = min(res,x+y+z);
            }
        }
    }

    cout<<res<<endl;

    return 0;
}