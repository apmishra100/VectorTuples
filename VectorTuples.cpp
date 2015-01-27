// Copyright 2015 Aman Mishra
// ============================================================================
// Name        : VectorTuples.cpp
// Author      : Aman Mishra
// Description : Modifying the vector class to behave as a priority queue
// of tuples.
// ============================================================================

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <tuple>
#include <ctime>

class Comp{
 public:
  bool operator() (const std::tuple<int, int>& a,
                      const std::tuple<int, int>& b) {
    return (std::get<0> (a)) < (std::get<0> (b));
  }
};

int main() {
  std::vector<std::tuple<int, int>> myvect;
  unsigned int seed = time(NULL);

  // Tuples of form (weight, vertex number)
  for (int i = 0; i < 10; i++) {
     auto a = std::make_tuple(rand_r(&seed) % 10, i);
     myvect.push_back(a);
  }

  // Printing the current elements in the vector
  for (auto a : myvect) {
    std::cout << "Vertex " << std::get<1> (a) << ' ';
    std::cout << "Weight " << std::get<0> (a) << std::endl;
  }

  // Treating the vector as a priority queue
  std::sort_heap(myvect.begin(), myvect.end(), Comp());

  std::cout << "The sorted vector " << std::endl;

  for (auto a : myvect) {
    std::cout << "Vertex " << std::get<1> (a) << ' ';
    std::cout << "Weight " << std::get<0> (a) << std::endl;
  }

  // Generating and printing the delta array
  int delta_arr[10];
  for (auto &x : delta_arr) {
    x = rand_r(&seed) % 10;
  }
  std::cout << "The delta array " << std::endl;
  for (auto x : delta_arr) {
    std::cout << x << std::endl;
  }

  /*
   * The benefits of using the vector versus the priority queue
   * is that we can always access the individual elements of the vector
   * and not just the element that is at the front. Unlike the priority queue
   * however, the compare function had to be implemented its own class (although the
   * PQueueTuples.cpp could be modified to use the same thing).
   */
  while (myvect.size() != 0) {
    std::sort_heap(myvect.begin(), myvect.end(), Comp());
    std::tuple<int, int> temp = myvect.front();
    myvect.erase(myvect.begin());
    if (delta_arr[std::get<1> (temp)] == 0) {
      std::cout << "Vertex " << std::get<1> (temp) << ' ';
      std::cout << "Weight " << std::get<0> (temp) << std::endl;
    } else {
      auto a = std::make_tuple(std::get<0> (temp) + delta_arr[std::get<1> (temp)], std::get<1> (temp));
      delta_arr[std::get<1> (temp)] = 0;
      myvect.push_back(a);
    }
  }
  return 0;
}



