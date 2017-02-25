#include <iostream>
#include <vector>
#include <unordered_set>
#include <math.h>
#include <iomanip>

using namespace std;

template <typename T>
void print(vector<vector<T>> & v) {
    for (auto i: v) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout <<endl;
    }

}

vector<vector<double>> num_sol(int x, int y) {
    int max_value = x*y;
    vector<vector<double>> dp (x, vector<double>(max_value+1));
    for (int i = 1 ; i <= y; i++) {
        dp[0][i] = 1.0/y;
    }

    for (int i = 1; i < x; i++) {
        for (int j = 1; j <= (i+1)*y; j++) {
            int k = 1;
            while (k <= y && j - k >= 0) {
                dp[i][j] += dp[i-1][j-k]/y;
                k++;
            }
        }
    }
    // print(dp);
    return dp;
}


//return prob
double solve (int c, int h, int x, int y) {
    vector<vector<double>> dp = num_sol(x, y);
    double num = 0.0;
    int i = max(h, 0);
    for (; i <= x*y; i++) {
        num += dp[x-1][i];
    }
    return num;
}



int main(){
    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        int h,s; cin >> h >> s;
        double ans = 0.0;

        for (int j = 0; j < s; j++) {
            string ss;
            cin >> ss;
            int x, y, z = 0, sign = 1;
            auto it1 = find(ss.begin(), ss.end(),'d');
            auto it2 = find(ss.begin(), ss.end(), '+');
            auto it3 = find(ss.begin(), ss.end(), '-');
            auto it4 = it2;
            if (it3 != ss.end()) {
                it4 = it3;
                sign = -1;
            }
            x = stoi(ss.substr(0, it1 - ss.begin()));
            y = stoi(ss.substr(it1 - ss.begin() + 1, it4 - it1 - 1));

            if (it4 != ss.end()) {
                z = sign*stoi(ss.substr(it4 - ss.begin() + 1, ss.end() - it4 - 1));

            }
            double temp = solve(i+1, h - z, x, y);
            ans = ans < temp ? temp: ans;
        }

        cout <<fixed<< "Case #" << i+1<< ": " << ans << endl;
    }

    return 0;
}
