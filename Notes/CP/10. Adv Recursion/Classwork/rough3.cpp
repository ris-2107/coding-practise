#include<bits/stdc++.h>
using namespace std;
#define inpt freopen("input.txt", "r", stdin);
#define otpt freopen("output.txt", "w", stdout);



void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}




int partition(int arr[], int low, int high ){

	//create pivot:
	int pivot = arr[high];
	int i=low-1;

	for(int j=low; j<high; j++){
		if(arr[j]<=pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}

swap(arr[i],arr[high]);
return i+1;
}



void quickSort(int array[], int low, int high) {
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}



int subs(string input , string output[]){
	
if(input.empty()){
	output[0]="";
	return 1;
}


string smallString= input.substr();
int smallOp=subs(smallString, output);

for(int i =0; i<smallOp;i++){
output[i+smallOp]= input[0]+output[i];
}


}

void merge(int array[], int left, int mid, int right){

	//declare sizes:
	int subArrayOne=mid-left+1,subArrayTwo=right-mid;

	//declare temporary Arrays:
	int *leftSubArray= new int [subArrayOne], *rightSubArray= new int [subArrayTwo];

	//Fill in the Temporary Arrays:

	for(int i=0;i<subArrayOne;i++){
		leftSubArray[i]=array[left+i];
	}
	for(int i=0; i<subArrayTwo;i++){
		rightSubArray[i]=array[mid+i+1];
	}

	//declare the iterator variables for the arrays:

	int leftSubArrayIndex=0, rightSubArrayIndex=0, mergedArrayIndex=left;


	//Merge and compare logic:

	while(leftSubArrayIndex<subArrayOne && rightSubArrayIndex<subArrayTwo){
		if(leftSubArray[leftSubArrayIndex]<=rightSubArray[rightSubArrayIndex]){
			array[mergedArrayIndex]=leftSubArray[leftSubArrayIndex];
			leftSubArrayIndex++;
		}else{
			array[mergedArrayIndex]=rightSubArray[rightSubArrayIndex];
			rightSubArrayIndex++;
		}
		mergedArrayIndex++;
	} 

	//Fill in the rest of the array:

	while(leftSubArrayIndex<subArrayOne){
		array[mergedArrayIndex]=leftSubArray[leftSubArrayIndex];
		leftSubArrayIndex++;mergedArrayIndex++;

	}
	while(rightSubArrayIndex < subArrayTwo){
		array[mergedArrayIndex]= rightSubArray[rightSubArrayIndex];
		mergedArrayIndex++; rightSubArrayIndex++;
	}
}


void mergeSort(int array[], int begin , int end){
	if(begin>=end)
		return;

	int mid= begin+(end-begin)/2;

	mergeSort(array, begin, mid);
	mergeSort(array, mid+1, end);
	merge(array,begin, mid, end);
}


int main() {
  int data[] = {8, 7, 6, 1, 0, 9, 2};
  int n = sizeof(data) / sizeof(data[0]);
  
  cout << "Unsorted Array: \n";
  printArray(data, n);
  
  // perform quicksort on data
  quickSort(data, 0, n - 1);
  cout << "QS done"<<endl;

  //Merge Sort:
  //cout << "MS done"<<endl;
  //mergeSort(data,0,n-1 );
  
  cout << "Sorted array in ascending order: \n";
  printArray(data, n);

}