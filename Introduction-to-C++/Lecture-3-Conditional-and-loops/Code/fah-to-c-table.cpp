#include <iostream>
using namespace std;

int main()
{

    int s, e, w;
    int c;
    cin >> s >> e >> w;
    while (s <= e)
    {
        c = (5.0 / 9) * (s - 32);
        cout << s << "\t" << c << endl;
        s = s + w;
    }

    return 0;
}