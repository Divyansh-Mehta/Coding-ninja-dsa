#include <iostream>
using namespace std;

class fraction{
    private:
    int numerator;
    int denominator;

    public:
    fraction(){
    }
    fraction(int numerator, int denominator){
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    void print() const{
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

    /*
    this function will be called as f1.add(f2);
    void add(fraction const & f){
      int lcm = this -> denominator * f.denominator;
      this -> numerator = this -> numerator * f.denominator + f.numerator * this -> denominator;  
      this -> denominator = lcm;
      this -> simplify();  // we can also just write simplify();
    }
    */

    /* this function will be called as f3 = f1.add(f2);
    fraction add(fraction const & f){
        fraction fnew;
      int lcm = this -> denominator * f.denominator;
      fnew.numerator = this -> numerator * f.denominator + f.numerator * this -> denominator;  
      fnew.denominator = lcm;
      fnew.simplify();
      return fnew;  
    }
    */
   // this will be called as f3 = f1 + f2;
   fraction operator+(fraction const & f) const{
        fraction fnew;
      int lcm = this -> denominator * f.denominator;
      fnew.numerator = this -> numerator * f.denominator + f.numerator * this -> denominator;  
      fnew.denominator = lcm;
      fnew.simplify();
      return fnew;  
    }
    fraction operator*(fraction const &f) const{
        fraction fnew;
        fnew.numerator = this -> numerator * f.numerator;
        fnew.denominator = this -> denominator * f.denominator;
        fnew.simplify();
        return fnew;
    }
    // here if fraction is not simplefied it may give wrong result
    bool operator==(fraction const &f) const{
        
        if(this -> numerator == f.numerator && this -> denominator == f.denominator){
            return true;
        }
        return false;
    }

    // pre-increment 
    fraction & operator++(){
        this -> numerator = this -> numerator + this -> denominator;
        this -> simplify();
        return *this;
    }

    // post-increment
    fraction operator++(int){
        fraction fnew(this -> numerator, this -> denominator);
        this -> numerator = this -> denominator + this -> numerator;
        this -> simplify();
        fnew.simplify();
        return fnew;
    }

    fraction & operator+=(fraction f){
        int lcm = this -> denominator * f.denominator;
        this -> numerator = this -> numerator * f.denominator + f.numerator * this -> denominator;
        this -> denominator = lcm;
        this -> simplify();
        return *this;
    }
};

int main(){
    fraction f1(10, 2), f2(15, 4);
    (f1 += f2) += f2;
    f1.print();
    f2.print();

    return 0;
}