#include <iostream>
#include <queue>

using namespace std;

int maxL = 100;
//int arrayToSort[100];


void merge(int arrayToSort[], int low, int middle, int high){
	queue<int> buffer1, buffer2; 
	cout<<"before merge:" <<low<<" "<<middle<<" "<<high<<endl;
	for( int i=low; i<high; i++){
		cout<<arrayToSort[i]<<" ";
	}
	cout<<endl;
	for( int i=low; i<= middle; i++){
		buffer1.push( arrayToSort[i] );
	}
	for( int i=middle+1; i<=high; i++){
		buffer2.push( arrayToSort[i] );
	}
	
	int i= low;
	while( ! (buffer1.empty() || buffer2.empty() )){
		if( buffer1.front() <= buffer2.front()){
			
			arrayToSort[i++] = buffer1.front();
			buffer1.pop();
		}else{
			arrayToSort[i++] = buffer2.front();
			buffer2.pop();
		}
	}
	while( ! buffer1.empty()){ 
		arrayToSort[i++] = buffer1.front(); 
		buffer1.pop(); 
	}
	while( ! buffer2.empty()){ 
		arrayToSort[i++] = buffer2.front(); 
		buffer2.pop(); 
	}
	for( int i=low; i<high; i++){
		cout<<arrayToSort[i]<<" ";
	}
	cout<<endl;
	
}


void mergeSort(int arrayToSort[], int low, int high){
	int middle = (low + high) / 2;
	if( low < high) {
		mergeSort( arrayToSort, low, middle);
		mergeSort( arrayToSort, middle+1, high);
		merge( arrayToSort, low, middle, high);
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
	
	mergeSort(arrayToSort,0, 8);
	
	for( int i=0; i<9; i++){
		cout<< arrayToSort[i]<<" ";
	}
	cout<<endl;
	return 0;
}
