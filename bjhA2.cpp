// Ben Haase
// 9/27/15
// CS3130 part A#2 run time of sorting algorithms

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

void bubbleSortSwCt(int *, int);
void cocktailSortSwCt(int *, int);
void shellSort1(int *, int);
void shellSort2(int *, int);
int * randomArrGen(int);
void viewArray(int *, int);
int * copyArray(int *, int s);
void resetArr(int ***, int ***, int *);
void avgRunTime();
int main(int argc, char * argv[])
{
	srand(time(NULL));
	avgRunTime();

	return 0;
}

//Bubble Sort with swaps counting
void bubbleSortSwCt(int * a, int s){
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
	}
	return;
}

//Cocktail Sort with swaps counting
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

// Shell Sort using gap starting at n/2 and dividing gap by 2 each iteration
void shellSort1(int * a, int s){
	int temp;
	int gap = s;
	int k;
	do{
		gap /= 2;
		for (int i = 0; i<(s / gap); i++){
			for (int j = i; j<s; j += gap){
				k = j;
				temp = a[k];
				while (temp < a[k - gap] && k - gap > -1){
					a[k] = a[k - gap];
					k -= gap;
				}
				a[k] = temp;
			}
		}
	} while (gap > 1);
}

// Shell Sort using gap starting at n/2.2 and dividing gap by 2.2 each iteration adding one if gap is even
void shellSort2(int * a, int s){
	int temp;
	int gap = s;
	int k;
	do{
		gap /= 2.2;
		if (gap % 2 == 0) gap++;
		for (int i = 0; i<(s / gap); i++){
			for (int j = i; j<s; j += gap){
				k = j;
				temp = a[k];
				while (temp < a[k - gap] && k - gap > -1){
					a[k] = a[k - gap];
					k -= gap;
				}
				a[k] = temp;
			}
		}
	} while (gap > 1);
}

//function to generate an array of random numbers
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
		cout << a[i] << " ";
	}
	cout << endl;
}

//function to copy an array
int * copyArray(int * a, int s){
	int * b = new int[s];
	for (int i = 0; i < s; i++) b[i] = a[i];
	return b;
}

//function to reset sorted array to original unsorted array
void resetArr(int *** a, int *** b, int * s){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 10; j++){
			delete[] b[i][j];
			b[i][j] = copyArray(a[i][j], s[i]);
		}
	}
}

//function to measure the runtime of sorting algorithms for various input sizes
void avgRunTime(){
	clock_t start;
	clock_t end;
	double elapsed;
	int s[] = { 500, 1000, 2500, 5000 };
	int ** a[4];
	int ** b[4];
	double * at[4];
	for (int i = 0; i < 4; i++){
		a[i] = new int *[10];
		b[i] = new int *[10];
		at[i] = new double[4];
		for (int k = 0; k < 4; k++) at[i][k] = 0;
		for (int j = 0; j < 10; j++){
			a[i][j] = randomArrGen(s[i]);
			b[i][j] = copyArray(a[i][j], s[i]);
		}
	}

	for (int j = 0; j < 4; j++){
		for (int k = 0; k < 10; k++){
			start = clock();
			bubbleSortSwCt(b[j][k], s[j]);
			end = clock();
			elapsed = double(end - start) / CLOCKS_PER_SEC;
			at[0][j] = at[0][j] + elapsed;
		}
		at[0][j] = at[0][j] / 10;
	}
	resetArr(a, b, s);
	for (int j = 0; j < 4; j++){
		for (int k = 0; k < 10; k++){
			start = clock();
			cocktailSortSwCt(b[j][k], s[j]);
			end = clock();
			elapsed = double(end - start) / CLOCKS_PER_SEC;
			at[1][j] = at[1][j] + elapsed;
		}
		at[1][j] = at[1][j] / 10;
	}
	resetArr(a, b, s);
	for (int j = 0; j < 4; j++){
		for (int k = 0; k < 10; k++){
			start = clock();
			shellSort1(b[j][k], s[j]);
			end = clock();
			elapsed = double(end - start) / CLOCKS_PER_SEC;
			at[2][j] = at[2][j] + elapsed;
		}
		at[2][j] = at[2][j] / 10;
	}
	resetArr(a, b, s);
	for (int j = 0; j < 4; j++){
		for (int k = 0; k < 10; k++){
			start = clock();
			bubbleSortSwCt(b[j][k], s[j]);
			end = clock();
			elapsed = double(end - start) / CLOCKS_PER_SEC;
			at[3][j] = at[3][j] + elapsed;
		}
		at[3][j] = at[3][j] / 10;
	}
	for (int i = 0; i < 4; i++){
		if (i == 0) cout << "Bubble" << endl;
		if (i == 1) cout << endl << "Cocktail" << endl;
		if (i == 2) cout << endl << "Shell n/2" << endl;
		if (i == 3) cout << endl << "Shell n/2.2 odd" << endl;
		for (int j = 0; j < 4; j++){
			cout << s[j];
			if(s[j]==500) cout << " ";	
			cout << ": " << at[i][j] << endl;
		}
	}
}
