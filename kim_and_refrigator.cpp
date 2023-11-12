#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define pii pair<int,int>
using namespace std;

int main(){
    int t = 10 , x , y , n , res = INT_MAX;
    pii home , office;

    while(t--){
        cin>>n;
        vector < pii > customers;

        cin>>office.first>>office.second;
        cin>>home.first>>home.second;

        vector < int > tmp;
        int sum = 0;
        res = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            cin>>x>>y;
            customers.push_back({x,y});

            tmp.push_back(i);
        }

        do{
            pii prev = office;
            sum = 0;

            for(int i = 0 ; i < n ; i++){
                x = customers[tmp[i]].first;
                y = customers[tmp[i]].second;

                sum += abs(x-prev.first) + abs(y-prev.second);
                prev = {x,y};
            }

            sum += abs(home.first-prev.first) + abs(home.second-prev.second);
            res = min(res, sum);

        }while(next_permutation(tmp.begin(),tmp.begin()+n));

        cout<<"# "<<10-t<<' '<<res<<endl;
    }
    return 0;
}