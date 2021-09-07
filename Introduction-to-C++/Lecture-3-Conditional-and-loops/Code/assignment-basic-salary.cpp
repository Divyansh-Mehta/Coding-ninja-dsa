#include<iostream>
#include<math.h>
using namespace std;

int main() {
	// Write your code here
    long int basic, allow;
    char grade;
    double hra, da, pf, ts;
    
    cin >> basic >> grade;
    
    if (grade == 'A'){
        allow = 1700;
    }
    else if (grade == 'B'){
        allow = 1500;
    }
    else{
        allow = 1300;
    }
  
    
    hra = (basic * 20) / 100.0;
    da = (basic * 50) / 100.0;
    pf = (basic * 11) / 100.0;
        
    ts = basic + hra + da + allow - pf;
    int final = round(ts);
    cout << final;
    
    return 0;
	
}
