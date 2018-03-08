#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string T;
string P;

bool isEqual(int s1, int l1, int s2, int l2) {
  // Check length;
  if ((l2 - s2) > (l1 - s1)) {
    return false;
  }
  while (s2 <= l2) {
    if (T[s1] != P[s2]) {
      return false;
    }
    ++s1;
    ++s2;
  }
  return true;
}

int main(int argc, char** argv) {
  cin >> T;
  cin >> P;

  vector<int> r;
  int i = 0;
  for(int i = 0; i < T.size(); ++i) {
    if (isEqual(i, T.size() - 1, 0, P.size() - 1)) {
      r.push_back(i);
    }
  }

  for(auto it = r.begin(); it != r.end(); ++it) {
    cout << *it << endl;
  }

  // NOTE: Only for debug
  // cout << T << endl;
  // cout << P << endl;
  return 0;
}
