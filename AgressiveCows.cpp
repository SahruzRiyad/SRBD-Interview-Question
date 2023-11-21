// Problem id: https://www.spoj.com/problems/AGGRCOW/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isFit(vector < long long > &x , int c , int n , int mid){
    int cnt = 1 , j = 0;
    for(int i = 1 ; i < n ; i++){
        if(x[i] - x[j] >= mid)
            cnt++ , j = i;
    }
    return cnt >= c;
}

long long binarySearch(vector < long long > &x , int c , int n){
    long long i , low = 1 , high = x[n-1] , mid;
    
    while(low <= high){
        mid = (low + high) >> 1;

        if(isFit(x,c,n,mid))
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return high;
}
int main(){
    // freopen("./input.txt","r",stdin);
    int tc , i , j , n , c;
    cin>>tc;

    while(tc--){
        cin>>n>>c;

        vector < long long > stalls(n);

        for(i = 0 ; i < n ; i++){
            cin>>stalls[i];
        }

        sort(stalls.begin(),stalls.end());

        cout<<binarySearch(stalls,c,n)<<endl;
    }
}