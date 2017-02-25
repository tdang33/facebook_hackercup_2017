#include <iostream>
#include <vector>
#include <unordered_set>
#include <math.h>
#include <iomanip>

typedef long long ll;
#define C 10000000000
using namespace std;
//
template <typename T>
void print(vector<vector<T>> & v) {
    for (auto i: v) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout <<endl;
    }

}
template <typename T>
void print(vector<pair<T, T>> & v) {
    for (auto i: v) {
        cout << i.first <<" "<<i.second;
        cout <<endl;
    }
}


ll solve (vector<vector<ll>> g, vector<pair<int, int>> families, int N, int M, int K) {
    for (int i = 0; i < K; i++) {
        if (g[families[i].first][families[i].second] == C || g[0][families[i].first] == C || g[0][families[i].second] == C) {
            return -1;
        }
    }

    if (K == 1) {
        return g[0][families[0].first] + g[families[0].first][families[0].second];
    }
    vector<vector<ll>> costs(K-1, vector<ll>(2, 0));
    costs[0][0] = g[0][families[0].first] + g[families[0].first][families[1].first] + g[families[1].first][families[0].second];
    costs[0][1] = g[0][families[0].first] + g[families[0].first][families[0].second] + g[families[0].second][families[1].first];
    for (int i = 1; i < K-1; i++) {
        costs[i][0] = min(costs[i-1][0] + g[families[i-1].second][families[i+1].first],
            costs[i-1][1] + g[families[i].first][families[i+1].first]) + g[families[i+1].first][families[i].second];
        costs[i][1] = min(costs[i-1][0] + g[families[i-1].second][families[i].second],
            costs[i-1][1] + g[families[i].first][families[i].second]) + g[families[i].second][families[i+1].first];
    }

    return min(costs[K-2][0] + g[families[K-2].second][families[K-1].second], costs[K-2][1] + g[families[K-1].first][families[K-1].second]);
}



int main(){
    int T; cin >> T;

    for (int _case = 0; _case < T; _case++) {

        int N, M, K; cin >> N >> M >> K;
        vector<vector<ll>> g(N, vector<ll>(N, C));
        for (int i = 0; i < N ; i++) {
            g[i][i] = 0;
        }
        for (int i = 0; i < M; i++) {
            int x, y; cin >> x >> y;
            ll z; cin >> z;
            if (z < g[x-1][y-1]) {
                g[x-1][y-1] = z;
                g[y-1][x-1] = z;
            }
        }
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        vector<pair<int, int>> families(K);
        for (int i = 0; i < K; i++) {
            int x, y; cin >> x >> y;
            families[i] = make_pair(x-1,y-1);
        }
        // print(g);
        // cout << endl;
        // print(families);
        cout << "Case #" << _case + 1<< ": " << solve(g, families, N, M, K)<< endl;
    }




    //
    // vector<vector<ll>> v(3000, vector<ll>(3000, C));
    // print(v);


    return 0;
}
