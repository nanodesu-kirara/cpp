/**
 * 最近点问题
 * 分治法
 */
#include<math.h>
#include<vector>
#include<algorithm>

using std::vector, std::pair;

static const double invalid = -1;

struct Point {
    double x;
    double y;

    Point(double x, double y): x { x }, y { y } {}
    Point(const Point& p): x { p.x }, y { p.y } {}

};

double distance(pair<Point, Point> p) {
    return sqrt( pow((p.first.x - p.second.x), 2) + pow((p.first.y - p.second.y), 2) );
}

const Point& compareX(const Point& a, const Point& b) {
    return a.x < b.x ? a : b;
}

void sortByX(vector<Point>& points) {
    std::sort(points.begin(), points.end(), compareX);
}

void sortByY(const vector<Point>& points);

pair<Point, Point> addition(vector<Point> points);

pair<Point, Point> addition(vector<Point> points, pair<Point, Point> couple, double limit);
/**
 * 接受按x有序的点集
 */
pair<Point, Point> findMin(vector<Point> points) {
    auto division = points.begin() + points.size()/2;
    vector<Point> left { points.begin(), division };
    vector<Point> right { division, points.end() };

    if (left.size() > 1 and right.size() > 1) {
        pair<Point, Point> lp = findMin(left);
        double dl = distance(lp);

        pair<Point, Point> rp = findMin(right);
        double dr = distance(rp);

        return addition(points, dl < dr ? lp : rp, dl < dr ? dl : dr );
    } else if (left.size() > 1 and right.size() < 2) {
        pair<Point, Point> lp = findMin(left);
        double dl = distance(lp);

        return addition(points, lp, dl);
    } else if (left.size() < 2 and right.size() > 1) {
        pair<Point, Point> rp = findMin(right);
        double dr = distance(rp);

        return addition(points, rp, dr);
    } else if (left.size() < 2 and right.size() < 2) {
        return addition(points);
    } else ; // should not happen

}


