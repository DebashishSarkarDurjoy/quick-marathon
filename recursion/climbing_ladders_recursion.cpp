#include <iostream>
using namespace std;

int countWays(int n, int k) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    int ans = 0;
    for (int jumps = 1; jumps <= k; jumps++) {
        ans += countWays(n-jumps, k);
    } 

    return ans;
}

int main(void) {
    int steps, jumps;
    cout << "Enter steps and jumps: " << endl;
    cin >> steps >> jumps;

    cout << countWays(steps, jumps) << endl;

    return 0;
}