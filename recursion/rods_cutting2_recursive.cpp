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

    // dynamic / memoisation
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

public:
    Solution() {
        this->prices = {1,5,8,9,10,17,17,20};
        this->n = this->prices.size();
    }

    int maxProfit() {
        return maxProfit_recursive(this->n);
    }

    int maxProfit_TD() {
        vector<int> dp(this->n, 0);
        return maxProfit2(this->n, dp);
    }
    
};




int main(void) {

    Solution s;

    cout << s.maxProfit_TD() << endl;

    return 0;
}