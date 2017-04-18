#include <iostream>

class Fibonacci
{
private:
	int index;
	int value;

public:
	Fibonacci(int);
	int sum_calc(int idx);
};

Fibonacci::Fibonacci(int idx)
{
	index = idx;
	value = sum_calc(idx);
}

int Fibonacci::sum_calc(int idx)
{
	int value;
	if (idx == 0) return 0;
	else (idx == 1) return 1;
	else {
		value = sum_calc(idx - 1) + sum_calc(idx - 2);
		return value;
	}

}