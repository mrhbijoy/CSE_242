#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value, weight;
};
void fractional_Knapsack(float W, Item arr[], int n)
{
    
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
    Item arr[10000] ;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }
    
    float W ;
    cin >> W;
    fractional_Knapsack(W, arr, n);
    return 0;
}