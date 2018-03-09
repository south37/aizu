#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int Rank[1000005];
int Tmp[1000005];
int sa[1000005];
int kc, len;

bool compare_sa(int i, int j) {
  return Rank[i] != Rank[j] ?
    Rank[i] < Rank[j] :
    (i + kc <= len ? Rank[i + kc] : -1) < (j + kc <= len ? Rank[j + kc] : -1);
}

void construct_sa(string& T) {
  len = T.size();
  for (int i = 0; i <= len; ++i) {
    sa[i] = i;
    Rank[i] = (i < len) ? T[i] : -1;
  }

  // NOTE: only for debug
  // cout << "sa: " << endl;
  // for (int i = 0; i < len + 1; ++i) {
  //   cout << sa[i] << ": " << T.c_str() + sa[i] << endl;
  // }

  for (kc = 1; kc <= len; kc *= 2) {
    sort(sa, sa + len + 1, compare_sa);

    // NOTE: only for debug
    // cout << "sa: " << endl;
    // for (int i = 0; i < len + 1; ++i) {
    //   cout << sa[i] << ": " << T.c_str() + sa[i] << endl;
    // }

    Tmp[sa[0]] = 0;
    for (int i = 1; i <= len; ++i) {
      Tmp[sa[i]] = Tmp[sa[i-1]] + compare_sa(sa[i-1], sa[i]);
    }
    for (int i = 0; i <= len; ++i) {
      Rank[i] = Tmp[i];
    }

    // cout << "kc: " << kc << endl;
    // cout << "Rank: " << endl;
    // for (int i = 0; i < len + 1; ++i) {
    //   cout << "Rank[" << i << "]" << ": " << Rank[i] << endl;
    // }
  }

  // NOTE: only for debug
  // cout << "sa: " << endl;
  // for (int i = 0; i < len; ++i) {
  //   cout << sa[i] << endl;
  // }
}

int main(int argc, char** argv) {
  string T;
  cin >> T;
  int n = T.size();
  construct_sa(T);
  // NOTE: only for debug
  // cout << "sa: " << endl;
  // for (int i = 0; i < n; ++i) {
  //   cout << sa[i] << ": " << T.c_str() + sa[i] << endl;
  // }

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    string P;
    cin >> P;

    // NOTE: do this
    // cout << P << endl;
    int k = P.size();
    int l = 1;
    int r = n;
    int m;
    int success = false;
    while (l <= r) {
      m = (l + r) / 2;
      int cmp = strncmp(T.c_str() + sa[m], P.c_str(), k);
      // NOTE: only for debug
      // cout << "m: " << m << ", sa[m]: " << sa[m] << ", T.c_str() + sa[m]: " << T.c_str() + sa[m] << endl;
      // cout << "cmp: " << cmp << endl;

      if (cmp == 0) {
        // NOTE: success
        success = true;
        break;
      } else if (cmp > 0) { // P is small
        r = m - 1;
      } else {  // cmp < 0, P is large
        l = m + 1;
      }
    }

    if (success) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}
