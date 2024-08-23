#include <bits/stdc++.h>
using namespace std;

double minimiseMaxDistance(vector<int> &arr, int k) {
  int n = arr.size();

  vector<int> stations(n - 1, 0);

  for (int st = 1; st <= k; st++) {
    double maxDist = 0;
    int ind = -1;

    for (int i = 0; i < n - 1; i++) {
      double dist = double(arr[i + 1] - arr[i]) / double(stations[i] + 1);

      if (dist > maxDist) {
        maxDist = dist;
        ind = i;
      }
    }

    stations[ind] += 1;
  }

  double ans = 0;

  for (int i = 0; i < n - 1; i++) {
    double dist = double(arr[i + 1] - arr[i]) / double(stations[i] + 1);
    ans = max(dist, ans);
  }

  return ans;
}