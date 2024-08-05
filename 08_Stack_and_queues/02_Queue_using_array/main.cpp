#include <bits/stdc++.h>
#include <fstream>
#include <streambuf>
using namespace std;

class Queue {
  private:
    int* ds;
    int start;
    int end;
    int maxSize;
    int currSize;
  
  public:
    Queue(int s) {
      maxSize = s;
      start = -1;
      end = 0;
      currSize = 0;

      ds = new int[maxSize];
    }

    bool empty() {
      return start == -1 || start == end;
    }

    void push(int x) {
      if (start == -1) start++;
      ds[end++] = x;
      currSize++;
    }

    void pop() {
      if (empty()) {
        cerr << "Queue is empty. Nothing to pop!";
        exit(1);
      }
      
      start++;
      currSize--;
    }

    int peek() {
      if (empty()) {
        cerr << "Queue is empty. Nothing to peek!";
        exit(1);
      }
      return ds[start];
    }

    int size() {
      return currSize;
    }
};

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
  
  Queue q(1000);
    
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    q.push(x);
  }

  while(!q.empty()) {
    cout << "element: " << q.peek() << " " << "current size: " << q.size() << endl;
    q.pop();
  }

  cin.rdbuf(cinbuf);
  cout.rdbuf(coutbuf);

  infile.close();
  outfile.close();

  return 0;
}
