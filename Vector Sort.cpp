//============================================================================
// Name        : VectorSort.cpp
// Author      : Aman Mishra
// Description : Sorting a vector using sort function from the algorithm library
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));
	int length=rand()%10+1;
	cout<<length<<endl;
	//Random length vector
	vector<int> myvect (length);

	//Fill in the vector with a random number at each position
	for(auto& x : myvect){
		x=rand();
	}
	//Print the vector
	for(auto i : myvect){
		cout<<i<<endl;
	}

	//A copy of myvect, used in sanity checking
	vector<int> myvect_copy (length);
	copy(myvect.begin(), myvect.end(), myvect_copy.begin());

	//Sort the vector, using the sort function from the algorithms library
	sort(myvect.begin(), myvect.end());

	//Print the sorted vector
	cout<<"Sorted myvect"<<endl;
	for(auto i:myvect){
		cout<<i<<endl;
	}

	/**Sanity checking, for each of the item in the vector copy, check if it is
	 * in the sorted vector. If the item is not present, print an error message.
	 */
	for(auto i:myvect_copy){
		if(!(binary_search(myvect.begin(), myvect.end(), i))){
			cout<<"Error item "<<i<<" not found"<<endl;

		}
	}
	//Sanity Check: Do the sizes of the vectors match
	if(myvect_copy.size()!=myvect.size()){
		cout<<"Error:Lengths do not match."<<endl;
	}


	return 0;
}
