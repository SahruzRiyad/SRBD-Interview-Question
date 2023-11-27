#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector < int > people(4) , gate(4) , vis(100);
int n , ans = INT_MAX;


int findEmptyPlaceLeft(int index){
    for(int i = index - 1 ; i > 0 ; i--){
        if(vis[i] == 0)
            return i;
    }
    return INT_MAX;
}

int findEmptyPlaceRight(int index){
    for(int i = index ; i <= n ; i++){
        if(vis[i] == 0)
            return i;
    }
    return INT_MAX;
}

void solve(int x, int y , int z , int g , int cost){
    if(cost > ans)
        return;
    
    if(people[g] == 0){ // Change gate as all people are placed for this gate.
        if(g == x)
            g = y;
        else if(g == y)
            g = z;
        else{
            ans = min(ans,cost);
            return;
        }
    }

    int leftPos = findEmptyPlaceLeft(gate[g]);
    int rightPos = findEmptyPlaceRight(gate[g]);

    int leftDist = abs(gate[g] - leftPos) + 1;
    int rightDist = abs(gate[g] - rightPos) + 1;

    int minPos , minDist;
    
    if (leftDist <= rightDist)
        minPos = leftPos , minDist = leftDist;
    else 
        minPos = rightPos , minDist = rightDist; 

    // For the last people, if the distance from left and right are 
    // same then consider both of them to find optimal result

    if(people[g] == 1 && leftDist == rightDist){
        vis[leftPos] = true;
        people[g]--;
        solve(x,y,z,g,cost+leftDist);

        vis[leftPos] = false; // Backtracking
        people[g]++;

        vis[rightPos] = true;
        people[g]--;
        solve(x,y,z,g,cost+rightDist);

        vis[rightPos] = false;
        people[g]++;
    }
    else{
        vis[minPos] = true;
        people[g]--;
        solve(x,y,z,g,cost+minDist);

        vis[minPos] = false;
        people[g]++;
    }

}

void init(){
    for(int i = 1 ; i <= n ; i++)
        vis[i] = false; 
}

void findMinDist(int x , int y , int z , int g){
    init();
    solve(x,y,z,g,0);
}

int main(){
    // freopen("./input.txt","r",stdin);
    int t = 1;

    while(t--){
        cin>>n;

        ans = INT_MAX;

        for(int i = 1 ; i <= 3 ; i++)
            cin>>gate[i];
        
        for(int i = 1 ; i <= 3 ; i++)
            cin>>people[i];
        
        findMinDist(1,2,3,1);
        findMinDist(1,3,2,1);
        findMinDist(2,1,3,2);
        findMinDist(2,3,1,2);
        findMinDist(3,1,2,3);
        findMinDist(3,2,1,3);

        cout<<ans<<endl;
    }
    return 0;
}