#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned long long ull;
const ull B = 100000007;

string T;
string P;

int main(int argc, char** argv) {
  cin >> T;
  cin >> P;

  int ts = T.size();
  int ps = P.size();
  // NOTE: Early return
  if (ps > ts) return 0;

  // NOTE: calculate t = B ^ ps
  ull t = 1;
  for (int i = 0; i < ps; ++i) {
    t *= B;
  }

  ull th = 0;
  ull ph = 0;
  // NOTE: calculate for fist ps
  for (int i = 0; i < ps; ++i) {
    th = th * B + T[i];
  }
  for (int i = 0; i < ps; ++i) {
    ph = ph * B + P[i];
  }

  // NOTE: calculate result
  vector<int> r;
  for (int i = 0; i + ps <= ts; ++i) {
    if (ph == th) {  // NOTE: match `b[i] .. b[i + ps - 1]`
      r.push_back(i);
    }
    if (i + ps < ts) {
      th = th * B + T[i + ps] - T[i] * t;
    }
  }

  for (int i = 0; i < r.size(); ++i) {
    cout << r[i] << endl;
  }

  // NOTE: Only for debug
  // cout << T << endl;
  // cout << P << endl;
  return 0;
}
