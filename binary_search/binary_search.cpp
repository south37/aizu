#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

#define MAX_N 100000
#define MAX_Q 50000
int S[MAX_N];
int T[MAX_Q];

int main(int argc, char** argv) {
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> S[i];
  }

  int q;
  cin >> q;
  for(int i = 0; i < q; ++i) {
    cin >> T[i];
  }

  set<int> s;
  for(int i = 0; i < n; ++i) {
    s.insert(S[i]);
  }

  int r = 0;
  for(int i = 0; i < q; ++i) {
    if (s.find(T[i]) != s.end()) {
      r += 1;
    }
  }
  cout << r << endl;

  // NOTE: for debug
  // cout << "n: " << n << endl;
  // cout << "S: ";
  // for(int i = 0; i < n; ++i) {
  //   cout << S[i] << " ";
  // }
  // cout << endl;

  // BinSearch b0;
  // int ans = b0.bin_search;
  // cout << ans << endl;
  return 0;
}
