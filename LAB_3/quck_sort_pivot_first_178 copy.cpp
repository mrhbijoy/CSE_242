#include<bits/stdc++.h>
using namespace std;
void element_swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int Arr[], int l, int h){
    int pivot = Arr[l];
    int i = l, j = h;
    while(i < j){
        do{
            i++;
        }while(Arr[i] <= pivot);
        do{
            j--;
        }while(Arr[j] > pivot);
        if(i < j){
            element_swap(&Arr[i], &Arr[j]);
        }
    }
    element_swap(&Arr[l], &Arr[j]);
    return j;
}
void quick_sort(int Arr[], int l, int h){
    if(l < h){
        int pivot = partition(Arr, l, h);
        quick_sort(Arr, l, pivot);
        quick_sort(Arr, pivot+1, h);
    }
}

int main(){
    int n;
    cin>>n;
    int Arr[n+1];
    for (int i = 0; i < n; i++)
    {
        cin>>Arr[i];
    }
    quick_sort(Arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout<<Arr[i]<<" ";
    }
}