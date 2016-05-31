// Ben Haase
// 9/27/15
// CS3130 part B#2 running time of search algorithms on array of random sorted integers

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;

int linearSearch(int *, int, int);
int binarySearch(int *, int, int);
void avgRunTimes();
int * randomArrGen(int);
void cocktailSortSwCt(int *, int);
int main(int argc, char * argv[])
{
	srand(time(NULL));
	avgRunTimes();

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

//Function to determine the average run times for search algorithms
void avgRunTimes(){
	clock_t start;
	clock_t end;
	double elapsed;
	int s[] = { 500, 1000, 2500, 5000 };
	int ** a[4];
	double * at[2];
	int key[4][10];
	for (int i = 0; i < 4; i++){
		a[i] = new int *[10];
		if (i < 2){
			at[i] = new double[4];
			for (int k = 0; k < 4; k++) at[i][k] = 0;
		}
		for (int j = 0; j < 10; j++){
			a[i][j] = randomArrGen(s[i]);
			cocktailSortSwCt(a[i][j], s[i]);
			key[i][j] = rand() % s[i];
		}
	}

	for (int j = 0; j < 4; j++){
		for (int k = 0; k < 10; k++){
			start = clock();
			for(int x = 0; x < 50000; x++)linearSearch(a[j][k], s[j], a[j][k][key[j][k]]);
			end = clock();
			elapsed = double(end - start) / CLOCKS_PER_SEC;
			at[0][j] = at[0][j] + elapsed;
			start = clock();
			for(int x = 0; x < 50000; x++)binarySearch(a[j][k], s[j], a[j][k][key[j][k]]);
			end = clock();
			elapsed = double(end - start) / CLOCKS_PER_SEC;
			at[1][j] = at[1][j] + elapsed;
		}
		at[0][j] = (at[0][j] / 10) / 50000;
		at[1][j] = (at[1][j] / 10) / 50000;
	}

	for (int i = 0; i < 2; i++){
		if (i == 0) cout << "Linear Search:" << endl;
		if (i == 1) cout << endl << "Binary Search:" << endl;
		for (int j = 0; j < 4; j++){
			cout << s[j] << ": ";
			if (s[j] == 500) cout << " ";
			cout << at[i][j] << endl;
		}
	}

	return;
}

//function to generate arrays of random ints
int * randomArrGen(int s){
	int * a = new int[s];
	for (int i = 0; i < s; i++){
		a[i] = rand() % 9000 + 1000;
	}
	return a;
}

//Cocktail Sort function
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
