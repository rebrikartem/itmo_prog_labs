#include <iostream>
// #include "CircularBuffer.h"
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4};
    auto it = v.end();
    cout << *it << endl;

    return 0;
}