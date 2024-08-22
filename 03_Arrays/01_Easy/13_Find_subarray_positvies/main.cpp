#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

// Time :- O(N ^ 3)
// Space :- O(1)
int subArray_brute(vector<int> arr, int target) {
  int n = arr.size();
  int maxi = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int sum = 0;
      for (int k = i; k <= j; k++) {
        sum += arr[k];
      }
      if (sum == target) maxi = max(maxi, j-i+1);  
    }
  }
  return maxi;
}

// Time :- O(N ^ 2)
// Space :- O(1)
int subArray_better(vector<int> arr, int target) {
  int n = arr.size();
  int maxi = 0;

  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += arr[j];
      if (sum == target) maxi = max(maxi, j-i+1);
    }
  }
  return maxi;
}

// Time :- O(N)
// Space :- O(N)
int subArray_hashing(vector<int> arr, int target) {
  int n = arr.size();
  map<long long, int> preSumMap;
  
  int len = 0;
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    sum += arr[i];  
    
    if (sum == target) len = i+1;
    
    long long rem = sum - target;

    if (preSumMap.find(rem) != preSumMap.end()) {
      len = max(len, i - preSumMap[rem]);
    }

    if (preSumMap.find(rem) == preSumMap.end()) {
      preSumMap[sum] = i;
    }
  }
  return len;
}

// Works for positive array only.
// Time :- O(N)
// Space :- O(1)
int subArray_optimal(vector<int> arr, int target) {
  int n = arr.size();
  int len = 0;

  int sum = arr[0];
  int i = 0;
  int j = 0;

  while (j < n) {
    if (sum > target) {
      while (i <= j && sum > target) {
        sum -= arr[i];
        i++;
      }
    }

    if (sum == target) len = max(len, j-i+1);

    j++;
    if (j < n) sum += arr[j];
  }
  return len;
}

int main() {
  ifstream infile("input.txt");
  if (!infile.is_open()) {
    cerr << "Failed to open input file.";
    return 1;
  } 

  streambuf* cinbuf = cin.rdbuf();
  cin.rdbuf(infile.rdbuf());

  ofstream outfile("output.txt");
  if (!outfile.is_open()) {
    cerr << "Failed to open output file.";
    return 1;
  }
  
  streambuf* coutbuf = cout.rdbuf();
  cout.rdbuf(outfile.rdbuf());
  
  int size, k;
  cin >> size >> k;
  
  vector<int> arr(size);
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  cout << "Brute: " << subArray_brute(arr, k) << endl;
  cout << "Better: " << subArray_better(arr, k) << endl;
  cout << "Hashing: " << subArray_hashing(arr, k) << endl;
  cout << "Optimal: " << subArray_optimal(arr, k) << endl;

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
