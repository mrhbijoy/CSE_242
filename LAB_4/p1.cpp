#include <bits/stdc++.h>
using namespace std;
int arr[1000000];
 void my_sort(int *arr, int *arr_end){
    int n = arr_end - arr;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}
void my_sort_2(int *arr, int *arr_end){
    
    int n = arr_end - arr;
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > temp; j--)
            arr[j] = arr[j - 1];
        arr[j] = temp;

    }

}

int main()
{
    int n;
    int i = 0;
    while (1)
    {
        cin >> n;
        if (n == 0){
            for (int j = 0; j < i; j++)
                cout << arr[j] << " ";
            cout << endl;
            return 0;
            
        }
            
        if (n == -1)
        {
            my_sort(arr, arr + i);
            if (i % 2 == 0){
                cout << arr[i / 2 - 1] << " ";
                for (int j = i / 2-1; j < i - 1; j++)
                arr[j] = arr[j + 1];

            }
            else {
                cout << arr[i / 2] << " ";
                for (int j = i / 2; j < i - 1; j++)
                arr[j] = arr[j + 1];
                }
            
            i--;
        }
        else
        {
            arr[i] = n;
            i++;
        }
    }
    return 0;
}

/*
here I have used shell sort
shell sort is a variation of insertion sort that is designed to work more efficiently on large lists.
The idea is to rearrange the list of elements so that the list is sorted in increasing order.
The algorithm works by comparing each element with the elements that are a certain distance apart.
The distance between the elements is called the gap.
The gap starts as half the length of the list of elements, and the algorithm reduces the gap by half each time it goes through the list of elements.
The algorithm continues to compare elements that are a certain distance apart until the gap is 1.
At this point, the algorithm is essentially an insertion sort, but the list of elements has been partially sorted by the previous passes of the algorithm.
The algorithm is efficient because it reduces the number of comparisons that need to be made to sort the list of elements.
The algorithm is also stable, meaning that it preserves the relative order of equal elements.

*/
