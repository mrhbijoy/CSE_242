#include<bits/stdc++.h>
using namespace std;

void Marge(int Arr[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1],R[n2+1];
    for(int i=0;i<n1;i++){
        L[i]=Arr[p+i];
    }
        for(int i=0;i<n2;i++){
        R[i]=Arr[q+i+1];
    }
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    int i=0,j=0;
    for(int k=p;k<=r;k++){
        if(L[i]<=R[j]){
            Arr[k]=L[i];
            i++;
        }
        else{
            Arr[k]=R[j];
            j++;
        }
    }
}
int Marge_sort(int Arr[],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        Marge_sort(Arr,p,q);
        Marge_sort(Arr,q+1,r);
        Marge(Arr,p,q,r);
    }
}

int main(){
    int n;
    cin>>n;
    int Arr[n];
    for(int i=0;i<n;i++)cin>>Arr[i];
    
    Marge_sort(Arr,0,n-1);
    cout<<"After Marge Sort:"<<endl;
    for(int i=0;i<n;i++)cout<<Arr[i]<<" ";
}