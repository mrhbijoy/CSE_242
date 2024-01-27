
 #include<bits/stdc++.h>
using namespace std;
void Merge(int arr[],int l,int mid,int h){
    int n1=mid-l+1;
    int n2=h-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        b[j]=arr[mid+1+j];
    }
    a[n1]=INT_MAX;
    b[n2]=INT_MAX;
    int i=0,j=0;
    for(int k=l;k<=h;k++){
        if(a[i]<=b[j]){
            arr[k]=a[i];
            i++;
        }
        else{
            arr[k]=b[j];
            j++;
        }
    }
}
void mergesort(int arr[],int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        Merge(arr,l,mid,h);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}