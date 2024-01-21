#include<bits/stdc++.h>
using namespace std;
int pivot_last_element(int arr[],int s,int e){
    int pivot=arr[e];
    int i=s-1;
    for(int j=s;j<e;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}
int pivot_first_element(int arr[],int s,int e){
    int pivot=arr[s];
    int i=s+1;
    for(int j=s+1;j<=e;j++){
        if(arr[j]<pivot){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[s],arr[i-1]);
    return i-1;
}
int quick_sort(int arr[],int s,int e){
    if(s>=e){
        return 0;
    }
    int p=pivot_first_element(arr,s,e);
    quick_sort(arr,s,p-1);
    quick_sort(arr,p+1,e);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
     quick_sort(arr,0,n-1);
    
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
