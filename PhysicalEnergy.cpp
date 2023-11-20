/*
Initially you have H amount of energy and D distance to travel. You may travel
with any of the given 5 speeds. But you may only travel in units of 1 km. For 
each km distance traveled, you will spend corresponding amount of energy.
e.g. the given speeds are:

Required energy to travel 1 km: [4, 5, 2, 3, 6]
Required time  to travel 1 km: [200, 210, 230, 235, 215]

Input: test case t, H = total amount of energy , D = total distance need to travel
and Five inputs of energy and time required to travel 1 km.

Output:
Find minimum time required to cover total D km with remaining H >= 0

Sample Input:
6
13 4
4 5 2 3 6
200 210 230 235 215
14 4
4 5 2 3 6
200 210 230 235 215
15 4
4 5 2 3 6
200 210 230 235 215
16 4
4 5 2 3 6
200 210 230 235 215
16 1
4 5 2 3 6
200 210 230 235 215
10 2
4 5 2 3 6
200 210 230 235 215

Sample Output:
#1: 860
#2: 830
#3: 830
#4: 800
#5: 200
#6: 400

Constraint:
1 <= H <= 4000
1 <= D <= 1000
*/

#include <iostream>
#include <vector>
#include <cstring>
#define INF 2e9
using namespace std;

vector < int > reqire_energy(5) , require_time(5);
int dp[4001][1001][5];

int getMinTime(int h , int d , int itr){
    if(h < 0 || itr < 0)
        return INF;
    if(d == 0)
        return 0;
    if(dp[h][d][itr] != -1)
        return dp[h][d][itr];
    
    return dp[h][d][itr] = min(getMinTime(h,d,itr-1), require_time[itr] + getMinTime(h-reqire_energy[itr],d-1,itr));

}

int main(){
    freopen("./input.txt","r",stdin);
    int i , j , n , tc = 1 , t , h , d;
    cin>>t;

    while(t--){
        cin>>h>>d;

        for(i = 0 ; i < 5 ; i++)
            cin>>reqire_energy[i]; 
        
        for(i = 0 ; i < 5 ; i++)
            cin>>require_time[i];
        
        memset(dp,-1,sizeof(dp));
        cout<<"#"<<tc++<<": "<<getMinTime(h,d,4)<<endl;
    }
    return 0;
}