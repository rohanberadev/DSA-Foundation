#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;
long long sumOfAllSmallestSubArray(vector<int> arr, int n) {
  function<vector<int>()> find_nse = [&]() -> vector<int> {
    vector<int> nse(n);
    stack<int> st;

    for (int i = n-1; i >= 0; i--) {
      while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
      if (st.empty()) nse[i] = n;
      else nse[i] = st.top();

      st.push(i);
    }
    return nse;
  };

  function<vector<int>()> find_pse = [&]() -> vector<int> {
    vector<int> pse(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
      while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
      if (st.empty()) pse[i] = -1;
      else pse[i] = st.top();

      st.push(i);
    }
    return pse;
  };
  
  long long sum = 0;
  
  vector<int> nse = find_nse();
  vector<int> pse = find_pse();

  for (int i = 0; i < n; i++) {
    int left = i - pse[i];
    int right = nse[i] - i;
    sum += 1ll * left * right * arr[i];  
  }

  return sum;
}

long long sumOfAllLargestSubArray(vector<int> arr, int n) {
  function<vector<int>()> find_nge = [&]() -> vector<int> {
    vector<int> nge(n);
    stack<int> st;

    for (int i = n-1; i >= 0; i--) {
      while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
      if (st.empty()) nge[i] = n;
      else nge[i] = st.top();

      st.push(i);
    }
    return nge;
  };

  function<vector<int>()> find_pge = [&]() -> vector<int> {
    vector<int> pge(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
      while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
      if (st.empty()) pge[i] = -1;
      else pge[i] = st.top();

      st.push(i);
    }
    return pge;
  };

  vector<int> nge = find_nge();
  vector<int> pge = find_pge();
  
  long long sum = 0;

  for (int i = 0; i < n; i++) {
    int left = i - pge[i];
    int right = nge[i] - i;
    sum += 1ll * left * right * arr[i];
  }
  return sum;
}


long long sumOfAllRanges(vector<int> nums) {
  int n = nums.size();
  long long largest = sumOfAllLargestSubArray(nums, n);
  long long smallest = sumOfAllSmallestSubArray(nums, n);
  return largest - smallest;
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

  int n;
  cin >> n;
  
  vector<int> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  
  cout << sumOfAllRanges(nums);
    
  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
