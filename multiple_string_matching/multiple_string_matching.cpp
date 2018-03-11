#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>

#define MAX_LEN 1000005

int sa[MAX_LEN];
int Rank[MAX_LEN];
int Tmp[MAX_LEN];
int k, len;

bool compare_sa(int i, int j) {
  return Rank[i] != Rank[j] ?
    Rank[i] < Rank[j] :
    (i + k <= len ? Rank[i + k] : -1) < (j + k <= len ? Rank[j + k] : -1);
}

void construct_sa(std::string& T) {
  len = T.size();
  for (int i = 0; i <= len; ++i) {
    sa[i] = i;
    Rank[i] = (i < len) ? T[i] : -1;
  }
  for (k = 1; k <= len; k *= 2) {
    std::sort(sa, sa + len + 1, compare_sa);
    Tmp[sa[0]] = 0;
    for (int i = 1; i <= len; ++i) {
      Tmp[sa[i]] = Tmp[sa[i - 1]] + compare_sa(sa[i - 1], sa[i]);
    }
    for (int i = 0; i <= len; ++i) {
      Rank[i] = Tmp[i];
    }
  }
}

int main(int argc, char** argv) {
  std::string T;
  std::cin >> T;
  int n = T.size();
  construct_sa(T);

  // NOTE: only for debug
  // for (int i = 0; i <= n; ++i) {
  //   std::cout << "sa[" << i << "]: " << sa[i] << ", T.c_str() + sa[i]: " << T.c_str() + sa[i] << std::endl;
  // }

  int Q;
  std::cin >> Q;
  for (int i = 0; i < Q; ++i) {
    std::string P;
    std::cin >> P;

    // NOTE: do this
    bool success = false;
    int l = 1;
    int r = n;
    while (l <= r) {
      int m = (l+r)/2;
      int cmp = std::strncmp(T.c_str() + sa[m], P.c_str(), P.size());
      if (cmp == 0) {
        success = true;
        break;
      } else if (cmp > 0) { // positive means P is small than T[sa[m]..sa[m]+P.size]
        r = m - 1;
      } else {  // cmp < 0
        l = m + 1;
      }
    }

    if (success) {
      std::cout << 1 << std::endl;
    } else {
      std::cout << 0 << std::endl;
    }
  }

  return 0;
}
