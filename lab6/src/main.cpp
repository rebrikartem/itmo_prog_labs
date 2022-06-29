#include "Polynom.h"


using namespace std;


int main()
{   
    constexpr static int arr[] = {1, 2, 1};
    constexpr int m = compile_time_calc(1, arr, 3);
    static_assert(m == 4);
    array<int, m> megaabobus;

    constexpr static int a[] = {1,2,1,0,1};
    constexpr Polynom p(a, 5);
    constexpr int lol = p.get_value(1);
    static_assert(lol == 5);

    cout << p << endl;

    return 0;
}
