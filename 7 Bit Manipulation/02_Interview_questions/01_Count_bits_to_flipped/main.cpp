#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

int countBitsToFlip(int start, int goal) {
  int cnt = 0;

  for (int i = 0; i <= 31; i++) {
    if ((goal & (1 << i)) != (start & (1 << i))) cnt++;
  }

  return cnt;
} 

int main() {

  ifstream infile("input.txt");
  if (!infile.is_open()) {
    cerr << "Failed to open input.txt file!";
    return 1;
  }

  streambuf* cinbuf = cin.rdbuf();
  cin.rdbuf(infile.rdbuf());

  ofstream outfile("output.txt");
  if (!outfile.is_open()) {
    cerr << "Failed to open output.txt file!";
    return 1;
  }

  streambuf* coutbuf = cout.rdbuf();
  cout.rdbuf(outfile.rdbuf());


  int start, goal;
  cin >> start >> goal;

  cout << countBitsToFlip(start, goal);
  
  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
