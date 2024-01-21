#include<bits/stdc++.h>
using namespace std;


void bubble_sort(int arr[],int n){
    int counter=1;
    while(counter<n){
        for(int i=0;i<n-counter;i++){
            if(arr[i]>arr[i+1]){
                arr[i]=arr[i]+arr[i+1];
                arr[i+1]=arr[i]-arr[i+1];
                arr[i]=arr[i]-arr[i+1];
                
            }
        }
        counter++;
    }

    

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
     bubble_sort(arr,n);
    
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}