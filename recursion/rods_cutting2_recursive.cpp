#include <iostream>
#include <vector>
using namespace std;

class Solution {    
private:
    int n;
    vector<int> prices;

    int maxProfit_recursive(int n) {
        // base case
        if (n == 0) return 0;
        if (n < 0) return 0;

        // recursive case
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int current_ans = this->maxProfit_recursive(n-(i+1)) + this->prices[i];
            ans = max(current_ans, ans);
        }

        return ans;
    }

    // dynamic / memoisation top down
    int maxProfit2(int n, vector<int> &dp) {
        // base case
        if (n == 0) return 0;
        if (n < 0) return 0;
        if (dp[n] != 0) {
            return dp[n];
        }

        // recursive case
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int current_ans = this->maxProfit2(n-(i+1), dp) + this->prices[i];
            ans = max(current_ans, ans);
        }
        dp[n] = ans;
        return ans;
    }

    // dynamic / memoisation bottom up
    int maxProfit3(int n) {
        vector<int> dp(n+1, 0);

        for (int len = 1; len <= n; len++) {
            int ans = INT_MIN;
            for (int i = 0; i < len; i++) {
                int cut = i + 1;
                int current_ans = dp[len-cut] + this->prices[i];
                ans = max(current_ans, ans);
            }
            dp[len] = ans;
        }

        return dp[n];
    }


public:
    Solution() {
        this->prices = {1,5,8,9,10,17,17,20};
        this->n = this->prices.size();
    }

    int maxProfit() {
        return this->maxProfit_recursive(this->n);
    }

    int maxProfit_TD() {
        vector<int> dp(this->n, 0);
        return this->maxProfit2(this->n, dp);
    }

    int maxProfit_BU() {
        return this->maxProfit3(this->n);
    }
    
};




int main(void) {

    Solution s;

    cout << s.maxProfit_BU() << endl;

    return 0;
}