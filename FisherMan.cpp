#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int gate[3] , people[3];
vector < int > order;

int findCost(int i , int pos){
    int pp = people[pos] , ans = 0;

    while(pp--){
        ans += abs(i-gate[pos]) + 1;
        i++;
    }
    return ans;
}

int solve(){

    int ans = INT_MAX;

    do{

        for(int i = 1 ; i <= n - (people[order[1]] + people[order[2]]) ; i++){
            int x = findCost(i,order[0]);

            for(int j = i + people[order[0]] ; j <= n - people[order[2]] ; j++){
                int y = findCost(j,order[1]);

                for(int k = j + people[order[1]] ; k <= n ; k++){
                    int z = findCost(k,order[2]);

                    ans = min(ans,x+y+z);
                }
            }
        }
    }while(next_permutation(order.begin(),order.begin()+3));

    return ans;
}

int main(){
    freopen("./input.txt","r",stdin);
    int i;
    cin>>n;

    for(i = 0 ; i < 3 ; i++)
        cin>>gate[i];
    
    for(i = 0 ; i < 3 ; i++)
        cin>>people[i] , order.push_back(i);
    
    cout<<solve()<<endl;
}