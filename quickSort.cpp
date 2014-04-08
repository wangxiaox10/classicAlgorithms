#include <iostream>
using namespace std;

int partition(int arrayToSort[], int l, int h){
	int p;
	int firstHigh;
	
	p = h;
	firstHigh = l;
	for( int i=l; i<h; i++){
		if( arrayToSort[i] < arrayToSort[p]){
			//swap s[i] and s[firstHigh]
			int t = arrayToSort[i]; 
			arrayToSort[i] = arrayToSort[firstHigh];
			arrayToSort[firstHigh] = t;
			firstHigh ++; 
		}
	}
	
	int t = arrayToSort[p];
	arrayToSort[p] = arrayToSort[firstHigh]; 
	arrayToSort[firstHigh] = t;
	
	return firstHigh;
}

void quickSort(int arrayToSort[], int l, int h){
	if( h>l){
		cout<<"quickSort..."<<l<<" "<<h<<endl;
		int p = partition( arrayToSort, l, h);
		cout<<p<<endl;
		quickSort( arrayToSort, l, p-1);
		quickSort( arrayToSort, p+1, h);
	}
}

int main(){
	int arrayToSort[100];
	arrayToSort[0] = 0;
	arrayToSort[1] = 2;
	arrayToSort[2] = 3;
	arrayToSort[3] = 1;
	arrayToSort[4] = -1;
	arrayToSort[5] = 4;
	arrayToSort[6] = 11;
	arrayToSort[7] = 15;
	arrayToSort[8] = -11; 
	
	quickSort(arrayToSort,0, 8);
	
	for( int i=0; i<9; i++){
		cout<< arrayToSort[i]<<" ";
	}
	cout<<endl;
	return 0;
}

