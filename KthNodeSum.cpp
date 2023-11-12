#include <iostream>
using namespace std;

int solve(int k , string &str){
    int i , ans = 0 , n = str.size() , lvl = -1 , x = 0;

    for(i = 0; i < n ;i++){
        if(str[i] == '(')
            lvl++;
        else if(str[i] == ')')
            lvl--;
        
        if(lvl == k && str[i] != '(' && str[i] != ')'){
            x = 0;
            while(i < n && str[i] >= '0' && str[i] <= '9')
                x = x * 10 + (str[i]-'0') , i++;
            i--;
            // cout<<x<<endl;
            ans += x;
        }
        
    }
    return ans;
}
int main(){
    freopen("./input.txt","r",stdin);

    int k;
    string str;

    cin>>k;
    cin>>str;

    cout<<solve(k,str)<<endl;;
}