// main.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include "p1_library.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;
int main() {

  cout << "enter a filename" << endl;
  string file;
  cin >> file;

  string col;
  cout << "enter a column name" << endl;
  cin >> col;

  cout << "reading column " << col << " from " << file << endl;

  vector<double> data = extract_column(file, col);

  vector < vector<double> > summary = summarize(data);
  
  cout << "Summary (value: frequency)" << endl;
  for (size_t i = 0; i < summary.size(); ++i) {
    for (size_t j = 0; j < (summary[i].size() - 1); ++j) {
      cout << summary[i][j] << ": " << summary[i][j+1] << endl;
    }
  }
  cout << "\n";
  
  int ct = count(data);
  cout << "count = " << ct << endl;

  double sm = sum(data);
  cout << "sum = " << sm << endl;

  double mn = mean(data);
  cout << "mean = " << mn << endl;

  double sd = stdev(data);
  cout << "stdev = " << sd << endl;

  double mdn = median(data);
  cout << "median = " << mdn << endl;

  double mo = mode(data);
  cout << "mode = " << mo << endl;

  double mi = min(data);
  cout << "min = " << mi << endl;

  double ma = max(data);
  cout << "max = " << ma << endl;

  double P1 = percentile(data, 0.0);
  double P2 = percentile(data, 0.25);
  double P3 = percentile(data, 0.50);
  double P4 = percentile(data, 0.75);
  double P5 = percentile(data, 1.0);

  cout << "  0th percentile = " << P1 << endl;
  cout << " 25th percentile = " << P2 << endl;
  cout << " 50th percentile = " << P3 << endl;
  cout << " 75th percentile = " << P4 << endl;
  cout << "100th percentile = " << P5 << endl;


}