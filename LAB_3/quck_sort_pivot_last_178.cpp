#include<bits/stdc++.h>
using namespace std;
void element_swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int pertition(int Arr[], int l, int h){
    int pivot = Arr[h];
    int i = l-1;
    for (int j = l; j < h; j++)
    {
        if(Arr[j] < pivot){
            i++;
            element_swap(&Arr[i], &Arr[j]);
        }
    }
    element_swap(&Arr[i+1], &Arr[h]);
    return i+1;
}

void quick_sort(int Arr[], int l, int h){
    if(l < h){
        int pivot = pertition(Arr, l, h);
        quick_sort(Arr, l, pivot-1);
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
    quick_sort(Arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<Arr[i]<<" ";
    }
}
