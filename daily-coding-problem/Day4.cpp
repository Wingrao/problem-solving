#include <iostream>
#include <unordered_map>
using namespace std;


int FindNumber(int a[], int n)
{
    
    unordered_map<int, int> map;

    
    for (int i = 0; i < n; i++) {
        if (a[i] > 0)
            map[a[i]]++;
    }


    int index = 1;


    while (1) {
        if (map.find(index) == map.end()) {
            return index;
        }

        index++;
    }
}


int main()
{
    int a[] = { 3, 4, -1, 1 };
    int size = sizeof(a) / sizeof(a[0]);

    cout << "Smallest number is " << FindNumber(a, size) << endl;

    return 0;
}
