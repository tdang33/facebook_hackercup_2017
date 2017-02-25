#include <iostream>
#include <vector>
#include <unordered_set>
#include <math.h>

using namespace std;
#define PI 3.14159265358979323846

void solve (int i, int p, int x, int y) {
    double dist = sqrt((x-50)*(x-50) + (y-50)*(y-50));
    if (dist > 50.0 || p == 0) {
        cout << "Case #" << i << ": white" <<endl;
        return;
    }
    if (dist == 0.0 || p == 100) {
        cout << "Case #" << i << ": black" <<endl;
        return;
    }

    double cover_angel = p/100.0*360*PI/180;
    // cout << p/100.0*360 <<endl;
    double num = (y-50)*50;
    double den = 50*dist;
    double cos_given_angle = num/den;
    double given_angle = acos(cos_given_angle);
    if (x < 50) given_angle = 2*PI - given_angle;
    // cout << given_angle*180/PI <<endl;
    if (given_angle <= cover_angel) {
        cout << "Case #" << i << ": black" << endl;
    } else {
        cout << "Case #" << i<< ": white" << endl;
    }

}

int main(){
    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        int p,x,y;cin >>p >> x >> y;
        solve(i+1, p,x,y);
    }
    // solve(1, 50, 45 , 51);

    return 0;
}
