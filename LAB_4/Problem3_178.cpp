#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};
bool activityCompare(Activity s1, Activity s2) {
    return (s1.finish < s2.finish);
}

void activity_selection(Activity arr[], int n) {
    sort(arr, arr+n, activityCompare);
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << "(" << arr[j].start << ", " << arr[j].finish << "), ";
            i = j;
        }
    }
}

int main() {
    Activity arr[10000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].finish;
    }
     cout << "Following activities are selected: \n";
    activity_selection(arr, n);
    return 0;
}