#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countTriangles(vector<pair<int,int>> points) {
    unordered_map<int,int> freq_x;
    unordered_map<int,int> freq_y;
    for (pair<int,int> point: points) {
        freq_x[point.first]++;
        freq_y[point.second]++;
    }

    int total = 0;
    for (auto point: points) {
        int count_x = freq_x[point.first];
        int count_y = freq_y[point.second];

        total += (count_x - 1) * (count_y - 1);
    }

    return total;
}

int main(void) {
    vector<pair<int,int>> points;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    cout << "No. of triangles: " << countTriangles(points) << endl;

    return 0;
}