#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max(int arr[] , int n){
    
    int maxi = arr[0]; 
    
    int sum = 0;
    
    for (int i = 0; i<n; i++){
        
        sum = sum +arr[i];
        
        maxi = max (maxi, sum);
        
        if(sum < 0){
            
            sum = 0;
        }
        
    }
    
    return maxi;
}


int main() {
    
        
    int n;
    
    cin>>n;
    
    int arr[n];
    
    for (int i = 0; i<n; i++){
        
        cin>>arr[i];
        
    }

    int maxsum = max(arr,n);
    
    cout<<maxsum;
    
    
    
    
    
    return 0;
}