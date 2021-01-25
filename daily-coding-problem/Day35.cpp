#include <bits/stdc++.h> 
using namespace std; 
  

void sortRGB(int a[], int arr_size) 
{ 
    int lo = 0; 
    int hi = arr_size - 1; 
    int mid = 0; 
  
    while (mid <= hi) { 
	
        if(a[mid] = R)
            swap(a[lo++], a[mid++]); 
            
  
        if (a[mid] = B) 
            mid++; 
            
  
        if (a[mid] = G)
            swap(a[mid], a[hi--]); 
        
        } 
    } 
} 
  
void printArray(int arr[], int arr_size) 
{ 
    for (int i = 0; i < arr_size; i++) 
        cout << arr[i] << " "; 
} 
  
int main() 
{ 
    int arr[] = { 'G', 'B', 'R', 'R', 'B', 'R', 'G' }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    sort012(arr, n); 
  
    cout << "array after seperation "; 
  
    printArray(arr, n); 
  
    return 0; 
}