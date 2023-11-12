#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() { 
    int t , n , i , j , val , res = INT_MAX , sum;
    cin>>t;
    
    while(t--){
        cin>>n;
        
        vector < vector < int > > x;
        vector < int > tmp;
        res = INT_MAX , sum = 0;
        
        for(i = 0 ; i < n ; i++){
            for(j = 0 ; j < n ; j++){
                cin>>val;
                tmp.push_back(val); 
            }
            x.push_back(tmp);
            tmp.clear();
        }
        
        for(i = 0 ; i < n ; i++){
            tmp[i]  = i;
          
        }
        
        do{
            sum = 0;
            for(i = 0 ; i + 1 < n ; i++)
                sum += x[tmp[i]][tmp[i+1]];
            
            sum += x[tmp[n-1]][0];
            res = min(res,sum);
        
        }while(next_permutation(tmp.begin()+1,tmp.begin()+n));
        
        cout<<res<<endl;
    }
    return 0;
}
