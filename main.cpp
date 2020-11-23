#include <iostream>
#include <iomanip>
#include <time.h>
#include <math.h>
#include "func.h"

using namespace std;

void Create(int* parr, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++)
        parr[i] = Low + rand() % (High - Low + 1);
}

void Print(int* parr, const int size) {
    for (int i = 0; i < size; i++)
        cout << setw(4) << parr[i];
    cout << endl;
}



int sum (int* parr,const int size){
    int j = 0;
    int two_elements_arr[2];
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if(j==2){
            break;
        }
        if (parr[i]<0){
            two_elements_arr[j]=i;
            j++;
        }

    }
    for(int i = two_elements_arr[0]; i <= two_elements_arr[1]; i++){
        sum += parr[i];
    }
    return sum;
}



void replace (int* parr, const int size){
    int rightSideCounter = 0;
    for(int i = 0; i < size; ++i) {
        if(abs(parr[i]) > 1) {
            ++rightSideCounter;
        }
    }

    for(int i = 0, temp; i < size - rightSideCounter; ++i) {
        if(abs(parr[i]) > 1) {
            bool isEnd = false;
            for(int j = 0; !isEnd; ++j) {
                if(abs(parr[size - 1 - j]) <= 1) {
                    temp = parr[size - 1 - j];
                    parr[size - 1 - j] = parr[i];
                    parr[i] = temp;
                    isEnd = true;
                }
            }
        }
    }

}

int main() {
    srand((unsigned)time(NULL));
    int SIZE;
    cout << "Number of elements = ";
    cin >> SIZE;
    int *parr = new int[SIZE];

    int Low = -15;
    int High = 70;

    Create(parr, SIZE, Low, High);
    Print(parr, SIZE);
    cout << "number of minimal element= "<< number_of_min_element(parr, SIZE) << endl;
    cout << "sum of array elements between two negative elements = " << sum(parr, SIZE)<< endl;
    replace(parr, SIZE);
    Print(parr, SIZE);

    return 0;
}