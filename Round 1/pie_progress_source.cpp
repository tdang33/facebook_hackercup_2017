#include <iostream>
#include <vector>
#include <unordered_set>
#include <math.h>

typedef long long ll;
#define C 10000000000

using namespace std;


void print(vector<vector<ll>> v) {
    for (auto i: v) {
        for (auto j: i) {
            cout << j <<" ";
        }
        cout <<endl;
    }
}

ll solve(vector<vector<ll>> & v) {
    for (int i = 0; i < v.size(); i++) {
        sort(v[i].begin(), v[i].end());
    }
    ll ans = 0; //TODO: change to max value
    vector<ll> pies(v.size());
    for (int i = 0; i < v.size(); i++) {
        ll new_ans = C; // TODO: change to max value
        int opt_index = 0;
        for (int j = 0; j <= i; j++) {
            if (pies[j] + 1 <= v[0].size()) {
                ll current_cost = ans + v[j][pies[j]] + 2*pies[j]+1;
                if (current_cost < new_ans) {
                    new_ans = min(new_ans, current_cost);
                    opt_index = j;
                }
            }
        }
        pies[opt_index]++;
        ans = new_ans;
    }
    // print(v);
    // cout << endl;
    return ans;
}

int main(){
    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        int N, M; cin >> N >> M;
        vector<vector<ll>> v (N, vector<ll> (M));
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> v[j][k];
            }
        }
        cout << "Case #" << i+1 << ": " << solve(v) <<endl;
        // print (v);
        // cout << endl;
    }
    // vector<vector<ll >> x = {{1}, {1, 2}};
    // cout << "test: "<< solve(x) <<endl;
    return 0;
}
