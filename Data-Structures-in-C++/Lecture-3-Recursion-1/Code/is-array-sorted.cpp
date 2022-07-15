#include <iostream>
using namespace std;

// Time: - O(n) Space: - O(n)
bool is_sorted(int *a, int size)
{
    if (size == 0 || size == 1)
        return true;

    if (a[0] > a[1])
        return false;

    return is_sorted(a + 1, size - 1);
}

/* Alternative
Time: - O(n) Space: - O(n)
bool is_sorted(int *a, int size){
    if (size == 0 || size == 1)
        return true;
    bool smalleroutput = is_sorted(a + 1, size - 1);
    if (!smalleroutput)
        return false;
    if (a[0] > a[1])
        return false;
    return true;
}
*/

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    cout << is_sorted(a, 5);

    return 0;
}