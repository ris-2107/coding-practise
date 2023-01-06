#include<bits/stdc++.h>
using namespace std;
#define inpt freopen("input.txt", "r", stdin);
#define otpt freopen("output.txt", "w", stdout);


//First Subarray is arr[left.. mid]
//Second subarray is arr[mid+1... right]

void merge(int array[], int const left, int const mid, int const right ){


// create the limit variables:
int subArrayOne=mid-left+1, subArrayTwo=right-mid;

// create the Arrays:

int *subArrayLeft= new int [subArrayOne], *subArrayRight=new int [subArrayTwo];

//fill the temporary arrays:
for(int i=0; i<subArrayOne;i++){
subArrayLeft[i]=array[left+i];

}
for(int i=0; i<subArrayOne;i++){

subArrayRight[i]= array[mid+i+1];
}

// declare the array index variables:
int leftArrayIndex=0, rightArrayIndex=0, mergedArrayIndex=left;


//Sorting Logic starts:

while(leftArrayIndex < subArrayOne && rightArrayIndex < subArrayTwo){

if(subArrayLeft[leftArrayIndex]<= subArrayRight[rightArrayIndex] )
{
 array[mergedArrayIndex]=subArrayLeft[leftArrayIndex];
 leftArrayIndex++;

}
else{
	array[mergedArrayIndex]=subArrayRight[rightArrayIndex];
	rightArrayIndex++;
}
mergedArrayIndex++;
}


// Now fill In the Left over Array Positions:

while(leftArrayIndex < subArrayOne){
	
	array[mergedArrayIndex]= subArrayLeft[leftArrayIndex];
	mergedArrayIndex++;leftArrayIndex++;

}


while(rightArrayIndex < subArrayTwo){
	
	array[mergedArrayIndex]= subArrayRight[rightArrayIndex];
	mergedArrayIndex++;rightArrayIndex++;

}
}

// mergeSort Function:


void mergeSort(int array[], int begin, int end ){

if(begin >= end){

return;
}

int mid= begin +(end - begin)/2;

mergeSort(array, begin, mid );
mergeSort(array, mid+1, end );
merge(array, begin,mid, end);

}




//MergeSort Caller Function:


// Function to print an array

void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}



// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}



//Driver Code:


