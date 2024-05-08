#include <iostream>
using namespace std;

class Solution {
private:
    int dp[46] = {0};
public:
    int countWays(int n, int k) {
        if (n == 0) return 1; // 1 <= n <= 45
        if (n < 0) return 0;
        if (dp[n] != 0) return dp[n];

        int ans = 0;
        for (int jumps = 1; jumps <= k; jumps++) {
            ans += countWays(n-jumps, k);
        }

        dp[n] = ans;
        return dp[n];
    }
};


int main(void) {

    int steps, jumps;

    cout << "Enter steps and jumps: " << endl;
    cin >> steps >> jumps;
    
    Solution s;
    cout << s.countWays(steps, jumps) << endl;

    return 0;
}