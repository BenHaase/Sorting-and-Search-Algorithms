// Ben Haase
// 9/27/15
// CS3130 part A#1 implementation of sorting algorithms on array of 100 random ints

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

void bubbleSortSwCt(int *, int);
void cocktailSortSwCt(int *, int);
void shellSort1(int *, int);
void shellSort2(int *, int);
int * randomArrGen(int);
void viewArray(int *, int);
int * copyArray(int *, int s);
void run100();
int main(int argc, char * argv[])
{
	srand(time(NULL));
	run100();

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
		if(i%10==0 && i>0) cout << endl;
		cout << a[i] << " ";
	}
	cout << endl << endl;
}

//function to copy an array
int * copyArray(int * a, int s){
	int * b = new int[s];
	for (int i = 0; i < s; i++) b[i] = a[i];
	return b;
}

//function to run each sorting algorithm for an array of 100 random ints
void run100(){
	int s = 100;
	int * a = randomArrGen(s);
	int * bubble = copyArray(a, s);
	int * cocktail = copyArray(a, s);
	int * shell1 = copyArray(a, s);
	int * shell2 = copyArray(a, s);
	bubbleSortSwCt(bubble, s);
	cocktailSortSwCt(cocktail, s);
	shellSort1(shell1, s);
	shellSort2(shell2, s);
	cout << "Bubble Sort" << endl;
	viewArray(a, s);
	viewArray(bubble, s);
	cout << endl << "Cocktail Sort" << endl;
	viewArray(a, s);
	viewArray(cocktail, s);
	cout << endl << "Shell Sort n/2" << endl;
	viewArray(a, s);
	viewArray(shell1, s);
	cout << endl << "Shell Sort n/2.2 odd" << endl;
	viewArray(a, s);
	viewArray(shell2, s);
}
