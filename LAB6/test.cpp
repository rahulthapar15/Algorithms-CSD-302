#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

int count_stops(int D, const std::vector<int>& d) {
  if (d.size() < 2) { throw std::logic_error("Vector too small."); }

  auto p = std::begin(d);
  auto count = 0;

  while (p != --std::end(d)) {
    // Greedy: go as far as I can on this tank of gas.
    auto n = --std::find_if(p, std::end(d), [=](int x) {
      return *p + D < x; });
    // The specification says we do not need to worry about this...
    if (p == n) { throw std::logic_error("D too small."); }
    p = n;
    ++count; }

  return count; }


int main(int, char* []) {
  auto D = 100;
  auto d = std::vector<int> { 0, 5, 15, 30, 32, 33, 37, 49, 53, 59, 61 };

  std::cout << "stops: " << count_stops(D, d) << "\n";
  return 0; }