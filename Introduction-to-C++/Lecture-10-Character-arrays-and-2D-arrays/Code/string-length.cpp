#include <iostream>
using namespace std;

int length(char input[]){
    int i = 0;
    while (input[i] != '\0'){
        i++;
    }

    return i;
}

int main(){
    char name[100];
    cin >> name;
    cout << length(name);

    return 0;
}