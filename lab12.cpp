#include <iostream>
#include <algorithm>  // for sort(), find()
#include <numeric>    // for accumulate()
#include <array>
#include <fstream>
using namespace std;

const int top15_size = 15; // our array only stores the top15 athletes in the 100m race
const int top50_size  = 50; // create another one to store the data from external files

void readFile(const string& filename, array<double, top50_size >& all50_records); // create a function to read the external file and move the data in it into the array
void extractTop15(const array<double, top50_size >& all50_records, array<double, top15_size>& top15_records); 
void print_top15(const array<double, top15_size>& top15_records);

int main() {
	
    array<double, top15_size> top15_records{}; // we use this array to store the final top15 records
    array<double, top50_size > all50_records{};
    array<double, top15_size> temp_top15_records{};

    // ---- 2000 ----
    readFile("2000top50.txt", all50_records);

    for (double score: top15_records){
        cout << score <<endl; // we can see the original 15 elements are all 0
    }

    for (double score: all50_records){
        cout << score <<endl; // we can see what's in the all50_records array now. (all elements from the 2020top50 file)
    }

    cout << "Then, sort the 50 records and add the top15 into our top15_records array." << endl;
    extractTop15(all50_records, top15_records);

    cout << "Up to the year 2000, the top 15 all-time performances in the 100m race are as follows: " <<endl;
    for (double score: top15_records){
        cout << score <<" ";
    }
    cout <<endl;

    // ---- 2010 ----
    readFile("2010top50.txt", all50_records);
    extractTop15(all50_records, top15_records);

    cout << "So up to the year 2010, the new top 15 all-time performances in the 100m race are as follows: ";
    print_top15(top15_records);

    // ---- 2020 -----
    readFile("2020top50.txt", all50_records);
    extractTop15(all50_records, top15_records);

    cout << "Finally up to the year 2010, the new top 15 all-time performances in the 100m race are as follows: ";
    print_top15(top15_records);
    cout << "The top 1's record in this world is: " << top15_records.front() <<endl;
    cout << "The top 15's record in this world is: " << top15_records.back() <<endl;

    temp_top15_records.swap(top15_records);

	return 0;
}

void readFile(const string& filename, array<double, top50_size >& all50_records){ 
    ifstream fin(filename); // this function reads 50 marks from a text file into all50_records
    double mark;
    int i = 0;
    while (fin >> mark && i < static_cast<int>(all50_records.size())) {
        all50_records.at(i) = mark;  // bounds-checked
        i++;
    }
    fin.close();
}

// This function sorts the copy of the 50 marks and copy the first 15 (fastest) into top15_records
void extractTop15(const array<double, top50_size>& all50_records, array<double, top15_size>& top15_records) {
    array<double, top50_size> temp = all50_records;   // copy the all50_records
    sort(temp.begin(), temp.end());                   
    for (int i = 0; i < top15_size; i++) {
        top15_records.at(i) = temp.at(i);
    }
}

void print_top15(const array<double, top15_size>& top15_records){
    for (int i = 0; i < top15_size; ++i) {
    cout << (i+1) << ". " << top15_records[i] <<endl;
}
    cout <<endl;
}