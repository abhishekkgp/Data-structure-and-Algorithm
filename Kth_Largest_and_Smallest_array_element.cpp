/*

Problem: Given an integer array and an integer k, 
return the Kth smallest and kth largest element in the array.

Note that it is the kth largest element in the sorted order, 
not the kth distinct element.

*/

/*

Solution: Using QuickSort based method.
Space complexity: O(1)
Time complexity: O(n) in avg case and O(n2) in worse case(**very less chance of worse case here**), 
             because of randomisation array element chances of worse case here is 1/n! 
             hence this is good approach.
             Even in worse case as input gets randomised, so most of the time, time complexity becomes O(n) 
             Note: without randmosation of array, worse case complexity will always be O(n2)

*/

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int l, int r);
void randomize (vector<int> &arr,int n);


// This function returns k'th smallest element in arr
//using QuickSort based method.
int kthSmallest(vector<int> arr, int k)
{
	randomize(arr,arr.size());
    int left=0, right=arr.size()-1;
    while(left<=right)
    {
        // Partition the array around last element and get
        // position of pivot element in sorted array
        int pos = partition(arr, left , right);
        if(pos==k-1) break;
        else if(pos<k-1) left=pos+1;
        else right = pos-1;
        
    }
	return arr[k-1];
}


// This function returns k'th Largest element in arr
//using QuickSort based method.
int kthLargest(vector<int> arr,int k)
{
	randomize(arr,arr.size());
	
    int left=0, right=arr.size()-1;
    k=arr.size()-k+1;
    while(left<=right)
    {
        // Partition the array around last element and get
        // position of pivot element in sorted array
        int pos = partition(arr, left , right);
        if(pos==k-1) break;
        else if(pos<k-1) left=pos+1;
        else right = pos-1;
        
    }
	return arr[k-1];
}


// Standard partition process of QuickSort().  It considers the last
// element as pivot and moves all smaller element to left of it
// and greater elements to right
int partition(vector<int> &arr, int left, int right)
{
	int x = arr[right], temp = left;
	for (int j = left; j <= right - 1; j++) {
		if (arr[j] <= x) {
			swap(arr[temp], arr[j]);
			temp++;
		}
	}
	swap(arr[temp], arr[right]);
	return temp;
}


// A function to generate a random
// permutation of arr
void randomize(vector<int> &arr,int n)
{
    // Use a different seed value so that
    // we don't get same result each time
    // we run this program
    srand (time(NULL));
 
    for (int i = n - 1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i + 1);
 
        swap(arr[i], arr[j]);
    }
}


int main()
{
	vector<int> v;
	v.push_back(12);
	v.push_back(3);
	v.push_back(6);
	v.push_back(7);
	v.push_back(19);
	v.push_back(26);
	v.push_back(4);
	
	cout<<"Array element is: ";
	for(int i=0;i<v.size();i++)
	{
	    cout<<v[i]<<" ";
	}
	cout<<endl;
	
	int n =  v.size();
	cout <<6<< "th smallest element is " << kthSmallest(v,6)<<endl;
	cout <<2<< "th LARGEST element is " << kthLargest(v,2)<<endl;
	cout <<3<< "th smallest element is " << kthSmallest(v,3)<<endl;
	cout <<3<< "th LARGEST element is " << kthLargest(v,3)<<endl;
	return 0;
}
