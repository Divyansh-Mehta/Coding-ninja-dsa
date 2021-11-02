#include <iostream>
using namespace std;

class fraction{
    private:
    int numerator;
    int denominator;

    public:
    fraction(int numerator, int denominator){
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    void print(){
        cout << this -> numerator << "/" << this -> denominator << endl;
    }
      void simplify(){
          int gcd = 1;
          int j = (this -> numerator, this -> denominator);
          for (int i = 1; i <= j; i++){
              if (this -> numerator % i == 0 && this -> denominator % i == 0){
                  gcd = i;
              }
          }
          this -> numerator /= gcd;
          this -> denominator /= gcd;
      }
    // add and update in calling object
    /*
    copy constructor is called here
    void add(fraction f){    
      int lcm = this -> denominator * f.denominator;
      this -> numerator = this -> numerator * f.denominator + f.numerator * this -> denominator;  
      this -> denominator = lcm;
      this -> simplify();  // we can also just write simplify();
    }
    
    here changes in f will refect in main
    void add(fraction& f){
      int lcm = this -> denominator * f.denominator;
      this -> numerator = this -> numerator * f.denominator + f.numerator * this -> denominator;  
      this -> denominator = lcm;
      this -> simplify();  // we can also just write simplify();
    }
    */
   // here if we try to make changes in f error will be shown, so to be more careful we do this.
    void add(fraction const & f){
      int lcm = this -> denominator * f.denominator;
      this -> numerator = this -> numerator * f.denominator + f.numerator * this -> denominator;  
      this -> denominator = lcm;
      this -> simplify();  // we can also just write simplify();
    }

    void multiply(fraction const &f){
        this -> numerator = this -> numerator * f.numerator;
        this -> denominator = this -> denominator * f.denominator;
        this -> simplify();
    }



};