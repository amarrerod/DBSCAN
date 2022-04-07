#ifndef DBSCAN_H
#define DBSCAN_H

#include <iostream>
#include <utility>
#include <vector>

#define UNCLASSIFIED -1
#define CORE_POINT 1
#define BORDER_POINT 2
#define NOISE -2
#define SUCCESS 0
#define FAILURE -3

using namespace std;

using coords = std::pair<float, float>;

typedef struct Point_ {
    float x, y;     // X, Y position
    int clusterID;  // clustered ID
    Point_(const float& _x, const float& _y, const int& _c)
        : x(_x), y(_y), clusterID(_c) {}

    friend ostream& operator<<(std::ostream& os, const Point_& p) {
        return os << "(" << p.x << ", " << p.y << ") - " << p.clusterID;
    }
} Point;

class DBSCAN {
   public:
    DBSCAN() = delete;
    DBSCAN(const unsigned int& minPts, const float& eps,
           const vector<coords>& coordinates);
    DBSCAN(const unsigned int& minPts, const float& eps,
           const vector<Point>& points);
    ~DBSCAN() = default;

    int run();
    vector<int> calculateCluster(Point point);
    int expandCluster(Point point, int clusterID);
    inline double calculateDistance(const Point& pointCore,
                                    const Point& pointTarget);

    int getTotalPointSize() { return m_pointSize; }
    int getMinimumClusterSize() { return m_minPoints; }
    int getEpsilonSize() { return m_epsilon; }
    const vector<Point>& getPoints() { return m_points; }
    const unsigned int getNClusters() { return nClusters; }

   private:
    unsigned int nClusters;
    unsigned int m_minPoints;
    float m_epsilon;
    unsigned int m_pointSize;
    vector<Point> m_points;
};

#endif  // DBSCAN_H
