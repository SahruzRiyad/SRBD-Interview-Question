/*
Solve the equation f(k) = a * k + b * k * log2(k) + c * k^3;
Input: a , b , c , x where x is the result of the equation i.e. f(k) = x
Output: find the value of k such that f(k) = x
[NOTE: All value will fit in 64 bit integer]

Sample input 1:
1 2 3 30
Sample input 2:
1 2 0 470000000

Sample output 1:
2
10^7
*/

#include <iostream>
#include <cmath>
using namespace std;

long long funOutput(long long a , long long b , long long c , long long k){
    long long ans = a * k + (b * k * log2(abs(k)));

    if(c != 0)
        ans = ans + c * (k * k * k);
        
    return ans;
}

long long binarySearch(long long a , long long b , long long c , long long x){
    long long low = 0 , high = x , mid , res;

    while(low <= high){
        mid = (low + high) >> 1;
        res = funOutput(a,b,c,mid);
        
        if(res == x)
            return mid;
        
        else if(res < x)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return low;
}
int main(){
    long long a , b , c , x;

    cin>>a>>b>>c>>x;
    cout<<binarySearch(a,b,c,x)<<endl;

    return 0;
}