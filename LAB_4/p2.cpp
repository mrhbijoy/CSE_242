/*2:Write a program to implement fractional knapsack using the given
weights and values of n items, where we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Complete the function fractional Knapsack() that receives maximum capacity , array of structure/class and size n and returns a double value representing the maximum value in knapsack.

Note: The details of structure/class are defined in the comments above the given function.
Sample Input: Items as (value, weight) pairs
arr[] = {{60, 10}, {100, 20}, {120, 30}}
Knapsack Capacity, W = 50;
Sample Output: Maximum possible value = 240 by taking items of weight 10 and 20 kg and 2/3
fraction of 30 kg. Hence total price will be 60+100+(2/3) (120) = 24
*/
#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value, weight;
};
void fractional_Knapsack(float W, Item arr[], int n)
{
    // sort(arr, arr + n, [](Item a, Item b) {
    //     return (a.value / a.weight) > (b.value / b.weight);
    // });

    
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            Item temp = arr[i];
            int j;
            for (j = i; j >= gap && (arr[j - gap].value / arr[j - gap].weight) < (temp.value / temp.weight); j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }






    float res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= W)
        {
            res += arr[i].value;
            W -= arr[i].weight;
        }
        else
        {
            res += arr[i].value * (W / arr[i].weight);
            break;
        }
    }
    cout << "Maximum possible value = " << res << endl;

}
int main()
{
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    float W = 50;
    fractional_Knapsack(W, arr, n);
    return 0;
}