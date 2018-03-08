#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MAX_N 100000
typedef pair<char, int> card;
card A[MAX_N];

// NOTE: used for storing order of card.
map<int, vector<char> > orders;
map<int, int> indices;

#define SWAP(X, Y) do { \
  card tmp = X;         \
  X = Y;                \
  Y = tmp;              \
} while(0)

int Partition(int p, int r) {
  card x = A[r];
  int i = p - 1;
  for (int j = p; j < r; ++j) {
    if (A[j].second <= x.second) {
      i = i + 1;
      SWAP(A[i], A[j]);
    }
  }
  SWAP(A[i+1], A[r]);
  return i + 1;
}

void Quicksort(int p, int r) {
  if (p < r) {
    int q = Partition(p, r);
    Quicksort(p, q - 1);
    Quicksort(q + 1, r);
  }
}

int main(int argc, char** argv) {
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> A[i].first;
    cin >> A[i].second;

    int n = A[i].second;
    orders[n].push_back(A[i].first);
    indices[n] = 0;
  }

  Quicksort(0, n - 1);

  int stable = true;
  for(int i = 0; i < n; ++i) {
    int n = A[i].second;
    if (orders[n][indices[n]] != A[i].first) {
      stable = false;
    }
    indices[n] += 1;
  }

  if (stable) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }
  for(int i = 0; i < n; ++i) {
    cout << A[i].first << " " << A[i].second << endl;
  }

  return 0;
}
