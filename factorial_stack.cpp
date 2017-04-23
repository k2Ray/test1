#include <iostream>

class Factorial {
private:
	int value;

public:
	Factorial(int i);
	int calc_fact(int a);
	void print();
};

Factorial::Factorial(int i) {
	value = calc_fact(i);
}

int Factorial::calc_fact(int a) {
	int temp;

	if (a == 0) return 1;

	temp = a*calc_fact(a - 1);
	return temp;
}

void Factorial::print() {
	std::cout << value << "\n";
}

int main() {
	int x;

	std::cout << "enter value you want factorial for" << std::endl;
	std::cin >> x;

	while (x != 0) {
		Factorial *fibNum = new Factorial(x);
		fibNum->print();
		delete[] fibNum;
		std::cout << "enter value you want factorial for" << std::endl;
		std::cin >> x;
	}
	
	std::cin >> x;

	return 0;

}
