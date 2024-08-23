#include <bits/stdc++.h>
using namespace std;

double minimiseMaxDistance(vector<int> &arr, int k) {
  int n = arr.size();

  vector<int> stations(n - 1, 0);
  priority_queue<pair<double, int>> pq;

  for (int i = 0; i < n - 1; i++) {
    double dist = double(arr[i + 1] - arr[i]);
    pq.push({dist, i});
  }

  for (int st = 1; st <= k; st++) {
    pair<int, int> tp = pq.top();
    pq.pop();

    int ind = tp.second;
    stations[ind] += 1;

    double initDiff = arr[ind + 1] - arr[ind];
    double newDist = initDiff / double(stations[ind] + 1);

    pq.push({newDist, ind});
  }

  return pq.top().first;
}

// Link -
// https://www.naukri.com/code360/problems/minimise-max-distance_7541449?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTabValue=PROBLEM