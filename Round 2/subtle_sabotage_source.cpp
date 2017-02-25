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

int solve(int N, int M , int K) {
    if (N >= M) {
        int temp = N;
        N = M; M = temp;
    }
    if (2*K + 3 > M || K + 1 > N) return -1;
    int w = min(N - K, 2*K + 2);
    return 1 + (w)/K + (w%K == 0 ? 0: 1);
}

int main(){
    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        int N, M, K; cin >> N >> M >> K;
        int a = N, b = M;

        cout << "Case #" << i+1 << ": " << solve(a, b, K) <<endl;

    }
    // cout << solve(7,7,2)<<endl;

    return 0;
}
