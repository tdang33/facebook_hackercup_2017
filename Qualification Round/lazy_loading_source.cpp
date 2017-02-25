#include <iostream>
#include <vector>

using namespace std;

void solve (int c, vector<int> & v, int size) {
    sort(v.begin(), v.end());
    int rem = size, i = size - 1, ans = 0;
    while (i >= 0 && rem >= 0) {
        if (v[i] >= 50) {
            ans++; i--;rem--;
        } else {
            int need = 50/v[i] + (50%v[i]? 1 : 0);
            if (need <= rem ) {
                ans++;
            }
            rem -= need;
            i--;
        }
    }
    cout << "Case #" << c << ": " << ans << endl;
}

int main(){
    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        int N; cin >> N;
        vector<int> v(N);
        for (int k = 0; k < N; k++) {
            cin >> v[k];
        }
        solve(i+1, v, N);
    }
    // int N = 4;
    // vector<int> v = {30,30,1,1};
    // int N = 3;
    // vector<int> v = {20,20,20};
    // int N = 11;
    // vector<int> v = {1,2,3,4,5,6,7,8,9,10,11};
    // int N = 6;
    // vector<int> v = {9,19,29,39,49,59};
    // int N = 10;
    // vector<int> v = {32,56,76,8,44,60,47,85,71,91};
    // int N  = 1;
    // vector<int> v = {1};
    // solve(1, v, N);

    return 0;
}
