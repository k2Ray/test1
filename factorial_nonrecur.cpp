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

int Factorial::calc_fact(int idx) {
	int temp;

	if (idx == 0) return 0;
	if (idx == 1) return 1;
	else {
		int* ptr = new int[idx + 1];
		*(ptr + 0) = 0;
		*(ptr + 1) = 1;
		for (int i = 2; i < (idx + 1); i++) {
			*(ptr + i) = i * *(ptr + (i - 1));
		}
		temp = *(ptr + idx);
		delete[] ptr;
	}
	return (temp);
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
