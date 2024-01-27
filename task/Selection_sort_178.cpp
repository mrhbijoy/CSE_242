#include<bits/stdc++.h>
using namespace std;

int selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    
    selection_sort(arr,n);
    cout<<"After Selection Sort:"<<endl;
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}