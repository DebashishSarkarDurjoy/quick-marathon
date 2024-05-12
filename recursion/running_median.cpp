#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main(void) {
    priority_queue<int> left_heap;
    priority_queue<int, vector<int>, greater<int>> right_heap;
    vector<float> med;

    vector<int> stream = {10, 5, 2, 3, 0, 12, 18, 20, 22, -1};

    int d = stream[0];
    left_heap.push(d);

    med.push_back(d);
    float median = d;

    d = stream[1];
    int i = 2;
    while (d != -1) {
        if (left_heap.size() > right_heap.size()) {
            if (d < median) {
                right_heap.push(left_heap.top());
                left_heap.pop();
                left_heap.push(d);
            }
            else right_heap.push(d);

            med.push_back( (left_heap.top() + right_heap.top()) / 2.0 );
            median = med[med.size() - 1];
        }
        else if (left_heap.size() < right_heap.size()) {
            if (d < median) {
                left_heap.push(d);
            }
            else {
                left_heap.push(right_heap.top());
                right_heap.pop();
                right_heap.push(d);
            }

            med.push_back( (left_heap.top() + right_heap.top()) / 2.0 );
            median = med[med.size() - 1];
        }
        else {
            if (d < median) {
                left_heap.push(d);
                median = left_heap.top();
            }
            else {
                right_heap.push(d);
                median = right_heap.top();
            }
            med.push_back(median);
        }

        if (stream[i] == -1) d = -1;
        else d = stream[i];

        i++;
    }

    for (float i: med) {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}