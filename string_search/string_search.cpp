#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string T;
string P;

#define MAX_DIS 256
int dis[MAX_DIS];

int bm(int i) {
  for (int j = 0; j < P.size(); ++j) {
    // NOTE: for debug
    // cout << "compare " << T[i - j] << " and " << P[P.size() - 1 - j] << endl;

    if (T[i - j] != P[P.size() - 1 - j]) {
      // NOTE: update i
      return max(dis[T[i - j]] - j, 1);
    }
  }
  return 0;  // means `find`
}

int main(int argc, char** argv) {
  cin >> T;
  cin >> P;

  for (int i = 0; i < MAX_DIS; ++i) {
    dis[i] = P.size();
  }
  for (int i = 0; i < P.size(); ++i) {
    dis[P[i]] = P.size() - 1 - i;
  }
  // NOTE: for debug
  // cout << "dis['a']=" << dis['a'] << endl;
  // cout << "dis['b']=" << dis['b'] << endl;

  vector<int> r;
  int i = P.size() - 1;
  while (i < T.size()) {
    // NOTE: for debug
    // cout << "try " << i << endl;

    int d = bm(i);
    if (d == 0) { // find
      r.push_back(i - (P.size() - 1));
      ++i;
    } else {
      i += d;
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
