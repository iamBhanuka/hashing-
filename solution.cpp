#include <bits/stdc++.h>
#include <fstream>

#define SIZE 1000

using namespace std;

vector<int> numbers;
vector<int> hashTable[SIZE];

// Method to check whether number is in the hash table
bool checkHash(int v) {
  for (int i : hashTable[v % SIZE]) {
    // cout << "\t\tChecking " << v << " against " << i << endl;
    if (i == v)
      return true;
  }
  return false;
}

// Method to print the hash table
void print() {
  cout << endl;
  int a = 0;
  for (vector<int> bulk : hashTable) {
    cout << a << ": ";
    // for (vector<int>::const_iterator i = bulk.begin(); i != bulk.end(); ++i) {
    //   cout << *i << " -> ";
    // }

    for (int i : bulk) {
      cout << i << " -> ";
    }

    ++a;
    cout << endl;
  }
  cout << endl;
}

// Method to add numbers to hash table
void add(int v) {
  hashTable[v % SIZE].push_back(v);
}

// Method to update numbers from numbers vector to hash table
void updateHash() {
  // for (vector<int>::const_iterator i = numbers.begin(); i != numbers.end(); ++i) {
  //   add(*i);
  // }

  for (int i : numbers) {
    add(i);
  }
}

// Driver class
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ifstream infile("data");

  while (!infile.eof()) {
    int x;
    infile >> x;
    numbers.push_back(x);
  }

  updateHash();

  // print();

  // Numbers to be checked
  int toCheck[9] = {231552, 234756, 596873, 648219, 726312, 981237,
                    988331, 1277361, 1283379};

  string solution = "";

  bool skip = false;

  for (int check : toCheck) {
    // cout << "Checking " << check << endl;
    for (int number : numbers) {
      // cout << "\tProcessing " << number << ". Check hash for " << check - number << endl;
      if (check > number) {
        if (checkHash(check - number)) {
          solution += "1";
          skip = true;
          break;
        }
        // cout << "\tPassing " << number << endl;
      } else {
        // cout << "Skipping " << number << endl;
      }
    }
    if (!skip)
      solution += "0";

    skip = false;

    // cout << "Current solution: " << solution << endl;
  }

  cout << solution << endl;

  return 0;
}