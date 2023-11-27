#include <iostream>
#include <vector>
using namespace std;

vector < int > mat[105];
int n , ans = 0;

bool valid(int x , int y){
    return x >= 0 && x < n && y >= 0 && y < 5;
}

void dfs(int x , int y , int coin , bool boomUsed , int isRowSafe){
    if(!valid(x,y)){
        ans = max(ans,coin);
        return;
    }

    if(mat[x][y] != 2){

        if(boomUsed)
            isRowSafe--;
        
        if(mat[x][y] == 1)
            coin++;
        
        dfs(x-1,y-1,coin,boomUsed,isRowSafe);
        dfs(x-1,y,coin,boomUsed,isRowSafe);
        dfs(x-1,y+1,coin,boomUsed,isRowSafe);

    }
    else{
        if(boomUsed && isRowSafe <= 0){
            ans = max(ans,coin);
            return;
        }
        else if(boomUsed && isRowSafe > 0){
            isRowSafe--;

            dfs(x-1,y-1,coin,boomUsed,isRowSafe);
            dfs(x-1,y,coin,boomUsed,isRowSafe);
            dfs(x-1,y+1,coin,boomUsed,isRowSafe);
        }
        else{
            boomUsed = true;
            isRowSafe = 4;

            dfs(x-1,y-1,coin,boomUsed,isRowSafe);
            dfs(x-1,y,coin,boomUsed,isRowSafe);
            dfs(x-1,y+1,coin,boomUsed,isRowSafe);
        }
    }
}

void init(int n){
    for(int i = 0 ; i < n ; i++)
        mat[i].clear();

    ans = 0;
}
int main(){
    // freopen("./input.txt","r",stdin);

    int t , tc = 1 , j , i , x;
    cin>>t;

    while(t--){
        cin>>n;

        init(n);

        for(i = 0 ; i < n ; i++){
          
            for(j = 0 ; j < 5 ; j++){
                cin>>x;
                mat[i].push_back(x);
            }
        }

        dfs(n-1,1,0,0,0);
        dfs(n-1,2,0,0,0);
        dfs(n-1,3,0,0,0);

        cout<<"#"<<tc++<<' '<<ans<<endl;
    }
    return 0;
}