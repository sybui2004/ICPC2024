#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define EPS 1e-6

struct Seed {
    int x, y, c;
};

// Hàm tính khoảng cách Euclid
double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// Hàm kiểm tra nếu thời gian T là đủ để nảy mầm ít nhất K hạt giống
bool canGrowInTime(double T, const vector<Seed>& seeds, int K) {
    int N = seeds.size();
    for (int i = 0; i < N; ++i) {
        vector<double> times;
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                double timeToGrow = dist(seeds[i].x, seeds[i].y, seeds[j].x, seeds[j].y) / seeds[j].c;
                if (timeToGrow <= T) {
                    times.push_back(timeToGrow);
                }
            }
        }
        sort(times.begin(), times.end());
        if (times.size() >= K - 1) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    vector<Seed> seeds(N);
    for (int i = 0; i < N; ++i) {
        cin >> seeds[i].x >> seeds[i].y >> seeds[i].c;
    }

    double low = 0, high = 1e6;
    while (high - low > EPS) {
        double mid = (low + high) / 2.0;
        if (canGrowInTime(mid, seeds, K)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << fixed << setprecision(6) << low << endl;
    
    return 0;
}
