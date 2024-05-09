#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int *prices, int n, vector<int> &dp) {
    // base case
    if (n == 0) return 0;
    if (n < 0) return 0;
    if (dp[n] != 0) return dp[n];

    // recursive case
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cut = i + 1;
        int current_ans = maxProfit(prices, n-cut, dp) + prices[i];
        ans = max(current_ans, ans);
    }
    dp[n] = ans;

    return dp[n];
}


int main(void) {
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices) / sizeof(int);

    vector<int> dp(n+1, 0);
    cout << maxProfit(prices, n, dp) << endl;

    return 0;
}