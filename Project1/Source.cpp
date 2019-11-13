#include <iostream>
#include <cstdlib>
#include <stdlib.h>

class inside1 {
public:
	inside1() { std::cout << "inside1 constructor" << std::endl; }
	~inside1() { std::cout << "inside1 DESTRUCTOR" << std::endl; }
};

class inside2 {
public:
	inside2() { std::cout << "inside2 constructor" << std::endl; }
	~inside2() { std::cout << "inside2 DESTRUCTOR" << std::endl; }
};

class B {
public:
	B() { std::cout << "B constructor" << std::endl; }
	~B() { std::cout << "B DESTRUCTOR" << std::endl; }
};


class A : B {

	inside1 X;
	inside2 Y;
public:
	A() { std::cout << "A constructor" << std::endl; }
	~A() { std::cout << "A DESTRUCTOR" << std::endl; }

};

int main() {

	//case 1:
	//A tmp = A();
	/*OUTPUT:
		B constructor
		inside1 constructor
		inside2 constructor
		A constructor
		A DESTRUCTOR
		inside2 DESTRUCTOR
		inside1 DESTRUCTOR
		B DESTRUCTOR*/

	//case 2:
	A * tmp = new A;
	delete tmp;

	/*OUTPUT WITHOUT DELETE:
		B constructor
		inside1 constructor
		inside2 constructor
		A constructor*/

	/*OUTPUT WITH DELETE:
		B constructor
		inside1 constructor
		inside2 constructor
		A constructor
		A DESTRUCTOR
		inside2 DESTRUCTOR
		inside1 DESTRUCTOR
		B DESTRUCTOR*/


	return 0;
}