#include <iostream>

class Fibonacci
{
private:
	int index;
	int value;

public:
	Fibonacci(int);
	int sumCalc(int idx);
	void print();
};

Fibonacci::Fibonacci(int idx)
{
	index = idx;
	value = sumCalc(idx);
}

int Fibonacci::sumCalc(int idx)
{
	if (idx == 0) return 0;
	else if (idx == 1) return 1;
	else {
		return (sumCalc(idx - 1) + sumCalc(idx - 2));
	}
	return 0;
}

void Fibonacci::print()
{
	std::cout << "index = " << index << " value =" << value;
}

int main()
{
	int x;
	std::cin >> x;

	//declaring object of type Fibonnaci from heap
	//1-0, 2-1, 3-1, 4-2, 5-3, 6-5, 7-8, 8-13,....... 
	if( (x > 0) && (x <10) ) {
		Fibonacci *fibNum = new Fibonacci(x - 1);
		fibNum->print();
		std::cout << "\n";
	}

	Fibonacci *fibNumPtr[10];
	for (int i = 0; i < x; i++) {
		fibNumPtr[i] = new Fibonacci(i);
	}

	for (int i = 0; i < x; i++) {
		fibNumPtr[i]->print();
		std::cout << "\n";
	}
	
	std::cin >> x;
	return 0;
}


#if 0

typedef struct xyz {
	int c;
	int z;
} XYZ;

XYZ test[10];
XYZ* ptr_arr[10];
XYZ vc;
XYZ *ptr_struct;
#endif