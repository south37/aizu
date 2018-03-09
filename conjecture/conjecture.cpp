#include <iostream>
#include <map>

using namespace std;

map<int, int> memo;

bool is_prim(int n) {
  if (n == 1) return false;
  if (n == 2) return true;
  if ((n % 2) == 0) return false;

  // NOTE: Return cached result
  if (memo.find(n) != memo.end()) {
    return memo[n];
  }

  bool isPrime = true;

  for (int i = 3; i * i <= n; ++i) {
    // Check dividability
    if ((n % i) == 0) {
      isPrime = false;
      break;
    }
  }

  // NOTE: Cache result
  memo[n] = isPrime;

  return isPrime;
}

int count_prim(int n) {
  map<int, int> p;
  int r = 0;

  for(int i = 2; i <= n / 2; ++i) {
    // NOTE: only for debug
    // cout << i << ": " << is_prim(i) << endl;
    // cout << n - i << ": " << is_prim(n - i) << endl;
    if (is_prim(i) && is_prim(n - i)) {
      ++r;
    }
  }

  return r;
}

int main(int argc, char** argv) {
  int n;
  // NOTE: only for debug
  // cout << "is_prim(1): " << is_prim(1) << endl;
  // cout << "is_prim(2): " << is_prim(2) << endl;
  // cout << "is_prim(3): " << is_prim(3) << endl;
  // cout << "is_prim(4): " << is_prim(4) << endl;
  // cout << "is_prim(5): " << is_prim(5) << endl;
  // cout << "is_prim(6): " << is_prim(6) << endl;
  // cout << "is_prim(7): " << is_prim(7) << endl;
  // cout << "is_prim(8): " << is_prim(8) << endl;
  // cout << "is_prim(9): " << is_prim(9) << endl;
  // cout << "is_prim(10): " << is_prim(10) << endl;
  // cout << "is_prim(11): " << is_prim(11) << endl;
  // cout << "is_prim(12): " << is_prim(12) << endl;
  // cout << "is_prim(13): " << is_prim(13) << endl;
  // cout << "is_prim(14): " << is_prim(14) << endl;
  // cout << "is_prim(15): " << is_prim(15) << endl;
  // cout << "is_prim(16): " << is_prim(16) << endl;
  // cout << "is_prim(17): " << is_prim(17) << endl;
  // cout << "is_prim(18): " << is_prim(18) << endl;
  // cout << "is_prim(19): " << is_prim(19) << endl;
  // cout << "is_prim(20): " << is_prim(20) << endl;
  cin >> n;
  while (n != 0) {
    // Do here
    // cout << n << endl;
    int r = count_prim(n);
    cout << r << endl;

    cin >> n;
  }
  return 0;
}
