#include <iostream>
#include <climits>
using namespace std;

int n;
int gate[3];
int people[3];
int sum;

int ans = INT_MAX;
const int MAX_N = 105; // Define the maximum value of n
const int MAX_VAL = 105; // Define the maximum value of val
const int MAX_COUNT = 305; // Define the maximum value of count

int dp[MAX_N][MAX_VAL][MAX_COUNT]; // Memoization table initialized with -1

int abs(int a) {
    return a >= 0 ? a : -a;
}

int solve(int index, int val, int count) {
    if (count == sum) {
        return val;
    }
    if (index == n + 1) {
        return INT_MAX;
    }
    if (dp[index][val][count] != -1) {
        return dp[index][val][count];
    }

    int minCost = INT_MAX;
    for (int i = 0; i < 3; i++) {
        if (people[i] > 0) {
            people[i]--;
            minCost = min(minCost, solve(index + 1, val + abs(gate[i] - index) + 1, count + 1));
            people[i]++;
        }
    }
    minCost = min(minCost, solve(index + 1, val, count));

    return dp[index][val][count] = minCost;
}

int main() {
    freopen("./input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> gate[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> people[i];
        sum += people[i];
    }

    // Initialize memoization table with -1
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_VAL; j++) {
            for (int k = 0; k < MAX_COUNT; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    int result = solve(1, 0, 0);
    if (result == INT_MAX) {
        cout << "No possible solution\n";
    } else {
        cout << result << endl;
    }
    return 0;
}
