#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int maxProfit(int *prices, int n, vector<int> &dp) {
    // base case
    if (n == 0) return 0;
    if (n < 0) return 0;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int current_ans = maxProfit(prices, n-i, dp) + prices[i-1];
        ans = max(current_ans, ans);
    }

    return ans;
}


int main(void) {
    int prices[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = sizeof(prices)/sizeof(int);
    // cout << "Enter length: " << endl;
    // cin >> n;

    vector<int> dp(n+1, 0);
    cout << maxProfit(prices, n, dp) << endl;

    return 0;
}