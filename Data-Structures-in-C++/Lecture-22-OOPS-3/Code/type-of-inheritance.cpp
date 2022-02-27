#include <iostream>
using namespace std;

//Single inheritance
class A{

};

class B : A{

};

//Multilevel inheritance
class X{

};

class Y : X{

};

class Z : Y{

};

//Hierarchical inheritance
class P{

};

class Q : P{

};

class R : P{

};

//Multiple inheritance
class H{

};

class I{

};

class J : public H, public I{

};