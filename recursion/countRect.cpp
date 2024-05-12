#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point(int a, int b) {
        this->x = a;
        this->y = b;
    }
};

class Compare {
public:
    bool operator()(const Point p1, const Point p2) {
        if (p1.x == p2.x) return p1.y < p2.y;
        else return p1.x < p2.x;
    }
};

int countRectangles(set<Point, Compare> s) {
    int total = 0;

    for (auto it = s.begin(); it != prev(s.end()); it++) {
        Point p1 = *it;
        for (auto jt = next(it); jt != s.end(); jt++) {
            Point p2 = *jt;

            if (p1.x == p2.x || p1.y == p2.y) continue;

            Point p3 = Point(p2.x, p1.y);
            Point p4 = Point(p1.x, p2.y);

            if ( s.find(p3) != s.end() && s.find(p4) != s.end() ) total++;
        }
    }

    return total / 2;
}

int main(void) {
    set<Point, Compare> s;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        Point p(x, y);
        s.insert(p);
    }

    cout << "No. of rectangles: " << countRectangles(s) << endl;

    return 0;
}