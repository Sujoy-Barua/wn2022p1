// stats.cpp
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

vector<vector<double> > summarize(vector<double> v) {

  sort(v); //sorting the input vector

  int freq = 0; //to count the times a number is occurring
  double currentN = 0;
  double prevN = v[0];
  vector <vector <double> > summary;
  vector<double> pair;

  for (size_t i = 0; i < (v.size()+1); ++i) {

    if (i < v.size()) {
      currentN = v[i];

      if (currentN == prevN) {
        freq += 1;
      }

      else {
        pair.push_back(v[i-1]);
        pair.push_back(freq);
        summary.push_back(pair);
        pair.clear();
        prevN = currentN;
        freq = 1;
      }
    }
    else {
      pair.push_back(v[i-1]);
      pair.push_back(freq);
      summary.push_back(pair);
      pair.clear();
    }
  }
  return summary;
}

int count(vector<double> v) { 
  //v empty case to be considered
 int c = v.size();
 return c;
}

double sum(vector<double> v) {
  double s = 0.0; //sum

  for (size_t i = 0; i < v.size(); ++i) {
    s += v[i];
  }

  return s;
}

double mean(vector<double> v) {
  double m = 0.0; //mean
  double s = 0.0; //sum

  for (size_t i = 0; i < v.size(); ++i) {
    s += v[i];
  }

  m = s/v.size();
  return m; 
}

double median(vector<double> v) {
  double m;  //median
  sort(v);

  if (v.size() % 2 == 0) {  //if the size of the vector is an even number
    m = (v[(v.size() - 1) / 2] + v[((v.size() - 1) / 2) + 1]) / 2; //add both left middle and right middle numbers, then divide by 2
    }

  else {                    //if the size of the vector is not an even number ( an odd number )
    m = v[v.size() / 2];    //take the number in the middle of the vector
  }

  return m;
}

double mode(vector<double> v) {
  int mFreq = 0;  //max frequency
  int cFreq = 0;  //current frequency
  double currentN = 0.0; //current number
  double prevN = 0.0; //previous number
  double m = 0.0;   //mode

  sort(v);

  for (size_t i = 0; i < v.size(); ++i) {

    currentN = v[i];

    if (currentN == prevN) {
      cFreq += 1;
    }
    else {
      cFreq = 1;
      prevN = currentN;
    }

    if (cFreq > mFreq) {
      mFreq = cFreq;
      m = v[i];
    }

  }
  return m;
}

double min(vector<double> v) {
  sort(v);
  double m = v[0];
  return m;
}

double max(vector<double> v) {
  sort(v);
  double m = v[v.size() - 1];
  return m;
}

double stdev(vector<double> v) {
  double mean = 0.0;
  double sum = 0.0;
  double sd = 0.0;
  double n = v.size();

  for (size_t i = 0; i < v.size(); ++i) {
    sum += v[i];
  }

  mean = sum/v.size();

  //splitting the corrected SD formula into separate parts
  //corrected sd formula = sqrt(1/(N - 1) * summation (x_i - mean)^2)
  //x = 1 / (N-1)
  //y = (x - mean)^2
  //sumN = summation of (x_i - mean)^2 from i = 0 to N.
  double x = 1.0/(n-1.0);
  double y = 0.0;
  double sumN = 0.0;

  for (size_t j = 0; j < v.size(); ++j) {
    y = pow((v[j] - mean), 2);
    sumN += y;
  }

  sd = sqrt(x * sumN);

  return sd;
}

double percentile(vector<double> v, double p) {

  assert(!v.empty());
  assert(p >= 0 && p <= 1);
  
  sort(v); 
  double N = double(v.size());
  double n = ((p/1.0) * (N-1.0)) + 1.0;
  double nInt = 0;
  double nDec = 0.0;
  double P;
  nDec = modf(n , &nInt);

  if (nInt == 0) {
    P = (nDec * v[nInt]);
  }

  else if (nInt == N) {
    P = v[nInt-1];
  }

  else if (nInt < N) {
    P = v[nInt-1] + (nDec * (v[nInt] - v[nInt-1]));
  }

  return P;

}