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
    int i =0;
    while (fin >> mark && i < all50_records.size()) {
        // extract the mark from the file and place them into the all50 array
        all50_records.at(i) = mark;
        i++;
    }
    
    for (double score: top15_records){
        cout << score <<endl; // we can see the original 15 elements are all 0
    }

    for (double score: all50_records){
        cout << score <<endl; // we can see what's in the all50_records array now. (all elements from the 2020top50 file)
    }


    cout << "Then, sort the 50 records and add the top15 into our top15_records array." <<endl;
    sort(all50_records.begin(), all50_records.end());// sort the top 50 scores
    for (int i = 0; i < 15; i++){
        top15_records.at(i) = all50_records.at(i);
    }
    cout << "Up to the year 2000, the top 15 all-time performances in the 100m race are as follows: " <<endl;
    for (double score: top15_records){
        cout << score <<" ";
    }
    cout <<endl;

    
    
	return 0;
}

