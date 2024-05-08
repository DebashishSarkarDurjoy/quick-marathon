#include <iostream>
using namespace std;

class Solution {
private:
    int dp[46] = {0};
public:
    int countWays_BU(int n, int k) {
        this->dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) this->dp[i] += this->dp[i - j];
            }
        }
        return this->dp[n];
    }
};


int main(void) {

    int steps, jumps;

    cout << "Enter steps and jumps: " << endl;
    cin >> steps >> jumps;
    
    Solution s;
    cout << s.countWays_BU(steps, jumps) << endl;

    return 0;
}