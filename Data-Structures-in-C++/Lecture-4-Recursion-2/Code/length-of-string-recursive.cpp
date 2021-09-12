#include <iostream>
using namespace std;

int length(char str[]){
    if (str[0] == '\0')
    return 0;

    return length(str + 1) + 1;
}

int main(){
    char str[100];
    cin.getline(str,100);

    cout << length(str);

    return 0;
}