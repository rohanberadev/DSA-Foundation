#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int> asteroids) {
  int n = asteroids.size();
  vector<int> stack;
  
  for (int i = 0; i < n; i++) {
    if (asteroids[i] > 0) stack.push_back(asteroids[i]);
    else {
      while (!stack.empty() && stack.back() > 0 && stack.back() < -asteroids[i]) stack.push_back(asteroids[i]);
      if (stack.empty() || stack.back() < 0) stack.push_back(asteroids[i]);
      else if (!stack.empty() && stack.back() == -asteroids[i]) stack.pop_back();
    }
  }
  return stack;
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

  vector<int> asteroids(n);
  for (int i = 0; i < n; i++) cin >> asteroids[i];
  
  vector<int> colliosions = asteroidCollision(asteroids);

  for (auto it : colliosions) cout << it << " ";

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
