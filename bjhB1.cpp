// Ben Haase
// 9/27/15
// CS3130 part B#1 results of search algorithms on array of 100 random ints
 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int linearSearch(int *, int, int);
int binarySearch(int *, int, int);
void run100();
int * randomArrGen(int);
void viewArray(int *, int);
void cocktailSortSwCt(int *, int);
int main(int argc, char * argv[])
{
	srand(time(NULL));
	run100();

	return 0;
}

//Linear Search function
int linearSearch(int * a, int s, int key){
	for (int i = 0; i < s; i++){
		if (a[i] == key) return i;
	}
	return -1;
}

//Binary Search function
int binarySearch(int * a, int s, int key){
	int min = 0;
	int max = s - 1;
	int mid;
	while (min <= max){
		mid = (min + max) / 2;
		if (a[mid] == key) return mid;
		else if (a[mid] < key) min = mid + 1;
		else max = mid - 1;
	}
	return -1;
}

//function to run search algorithms for a sorted array of 100 random ints
void run100(){
	int s = 100;
	int * a = randomArrGen(s);
	cocktailSortSwCt(a, s);
	int key = rand() % s;
	int lin;
	int bin;
	viewArray(a, s);
	cout << endl << "Search Value: " << a[key] << endl;
	lin = linearSearch(a, s, a[key]);
	bin = binarySearch(a, s, a[key]);
	cout << "Linear Search: " << lin << " (" << a[lin] << ")" << endl;
	cout << "Binary Search: " << bin << " (" << a[bin] << ")" << endl;
	delete[] a;

	return;
}

//function to generate an array of random ints
int * randomArrGen(int s){
	int * a = new int[s];
	for (int i = 0; i < s; i++){
		a[i] = rand() % 9000 + 1000;
	}
	return a;
}

//function to print an array
void viewArray(int * a, int s){
	for (int i = 0; i < s; i++){
		if (i % 10 == 0 && i > 0) cout << endl;
		cout << a[i] << " ";
	}
	cout << endl;
}

//Cocktail Sort function to sort array
void cocktailSortSwCt(int * a, int s){
	int swaps = 1;
	int temp;
	while (swaps > 0){
		swaps = 0;
		for (int i = 0; i < s - 1; i++){
			if (a[i] > a[i + 1]){
				temp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = temp;
				swaps++;
			}
		}
		if (swaps = 0) return;
		swaps = 0;
		for (int i = s - 1; i > -1; i--){
			if (a[i] < a[i - 1]){
				temp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = temp;
				swaps++;
			}
		}
	}
	return;
}
