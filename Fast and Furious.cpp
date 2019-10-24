#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, T;
  while (cin >> N >> T) {
    double mn = -1e9, mx = 1e9;     //mn -min limit  mx -max limit
    vector<double> D(N), S(N);      //array for distance and speed
    for (int i = 0; i < N; i++) {
      cin >> D[i] >> S[i];
      mn = max(mn, -S[i]);          //finding out lower limit
    }

    while (mx-mn > 1e-9) {
      double c = (mx+mn)/2, t = 0.0;
      for (int i = 0; i < N; i++) t += D[i] / (S[i] + c);   //t - estimated time    T - actual time
      if (t > T) mn = c; else mx = c;                       //estimated time > actual time increase lower limit else decrease upper limit
    }

    printf("%.9lf\n", (mx+mn)/2);
  }
}
