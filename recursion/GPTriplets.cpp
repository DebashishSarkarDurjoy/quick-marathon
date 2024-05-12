#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int count_triplets(vector<int> arr, int r) {
    unordered_map<int,int> left;
    unordered_map<int,int> right;

    for (int i: arr) {
        left[i] = 0;
        right[i]++;
    }

    int ans = 0;
    for (int i: arr) {
        if (i % r == 0) {
            int prev = i / r;
            int current = i;
            int next = i * r;

            ans += left[prev] * right[next];
        }

        right[i]--;
        left[i]++;
    }

    return ans;
}


int main(void) {
    vector<int> arr = { 1, 16, 4, 16, 64, 16 };

    cout << count_triplets(arr, 4) << endl;

    return 0;
}