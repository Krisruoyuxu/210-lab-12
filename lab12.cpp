#include <iostream>
#include <algorithm>  // for sort(), find()
#include <numeric>    // for accumulate()
#include <array>
#include <fstream>
using namespace std;

const int top15_size = 15; // our array only stores the top15 athletes in the 100m race

int main() {
	
    array<double, top15_size> top15_records{}; // we use this array to store the final top15 records
    array<double, 50> all50_records{};

    ifstream fin("2000top50.txt");
    double mark;
    while (fin >> mark) {
        // extract the mark from the file and place them into the all50 array
        
    }
    
    for (double score: top15_records){
        cout << score <<endl; // we can see the original 15 elements are all 0
    }

	return 0;
}

