#include <bits/stdc++.h>
using namespace std;

int ax, ay, bx, by, cx, cy, dx, dy;

int main() {
    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;

    // 방향 벡터
    double mx = bx - ax, my = by - ay;
    double gx = dx - cx, gy = dy - cy;

    // 벡터의 길이
    double m_len = sqrt(mx * mx + my * my);
    double g_len = sqrt(gx * gx + gy * gy);

    // 단위 방향 벡터
    double mdx = mx / m_len, mdy = my / m_len;
    double gdx = gx / g_len, gdy = gy / g_len;

    double start = 0, end = 1; 
    double answer = 1000000;

    for (int i = 0; i < 100; i++) {
        double t1 = (2 * start + end) / 3;
        double t2 = (start + 2 * end) / 3;

        double m1x = ax + mdx * t1 * m_len;
        double m1y = ay + mdy * t1 * m_len;
        double g1x = cx + gdx * t1 * g_len;
        double g1y = cy + gdy * t1 * g_len;
        double dist1 = sqrt(pow(m1x - g1x, 2) + pow(m1y - g1y, 2));

        double m2x = ax + mdx * t2 * m_len;
        double m2y = ay + mdy * t2 * m_len;
        double g2x = cx + gdx * t2 * g_len;
        double g2y = cy + gdy * t2 * g_len;
        double dist2 = sqrt(pow(m2x - g2x, 2) + pow(m2y - g2y, 2));

        if (dist1 > dist2) start = t1;
        else end = t2;

        answer = min(answer, min(dist1, dist2));
    }

    cout << fixed << setprecision(10) << answer << "\n";
}
