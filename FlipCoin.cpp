#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unordered_map < int , vector < bool > > table;

int countRows(int n , int m, vector < bool > &mark){
    int res = 0 , i , j;

    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < m ; j++){
            if(mark[j] == table[i][j])
                break;
        }
        if(j == m)
            res++;
    }
    // cout<<res<<endl;
    return res;
}
int main() {
    int t , i , n , m , k , j , tmp , ans = 0;
    bool x;
    t = 1;

    while(t--){
        cin>>n>>m>>k;


        for(i = 0 ; i < n ; i++){
            for(j = 0 ; j < m ; j++){
                cin>>x;
                table[i].push_back(x);
            }
        }
        
        for(i = 0 ; i < n ; i++){
            tmp = k;
            vector < bool > mark(m,0);
        
            for(j = 0 ; j < m ; j++){
                if(table[i][j] == 1)
                    continue;

                else if(table[i][j] == 0 and tmp)
                    mark[j] = 1 , tmp--;

                else
                    break;
            }
            if(j != m || (tmp >= 0 && tmp&1))
                continue;
            else{
                tmp = countRows(n,m,mark);
                ans = max(ans,tmp);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
