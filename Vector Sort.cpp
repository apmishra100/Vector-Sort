// Copyright 2015 Aman Mishra
// ============================================================================
// Name        : VectorSort.cpp
// Author      : Aman Mishra
// Description : Sorting a vector using sort function from the algorithm library
// ============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main() {
  unsigned int seed = time(NULL);
  int length = rand_r(&seed)%10+1;
  std::cout << length << std::endl;
  // Random length vector
  std::vector<int> myvect(length);

  // Fill in the vector with a random number at each position
  for (auto& x : myvect) {
    x = rand_r(&seed);
  }
  // Print the vector
  for (auto i : myvect) {
    std::cout << i << std::endl;
  }

  // A copy of myvect, used in sanity checking
  std::vector<int> myvect_copy(length);
  copy(myvect.begin(), myvect.end(), myvect_copy.begin());

  // Sort the vector, using the sort function from the algorithms library
  sort(myvect.begin(), myvect.end());

  // Print the sorted vector
  std::cout << "Sorted myvect" << std::endl;
  for (auto i : myvect) {
    std::cout << i << std::endl;
  }

  /**Sanity checking, for each of the item in the vector copy, check if it is
	 * in the sorted vector. If the item is not present, print an error message.
	 */
  for (auto i : myvect_copy) {
    if (!(binary_search(myvect.begin(), myvect.end(), i))) {
      std::cout << "Error item " << i << " not found" << std::endl;
    }
  }
  // Sanity Check: Do the sizes of the vectors match
  if (myvect_copy.size() != myvect.size()) {
    std::cout << "Error:Lengths do not match." << std::endl;
  }

  return 0;
}
