#include <iostream>
using namespace std;

int main()
{
    // DECLARING 2-D ARRAY
    int b[100][100]; 
    
    // INPUTING ROWS AND COLUMN
    int n, m;
    cin >> n >> m;

    // INPUT 2-D ARRAY
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }

    // PRINT 2-D ARRAY
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    // PRINT 2-D ARRAY COLUMN WISE
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << b[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}