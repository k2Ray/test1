#include <iostream>

class Fibonacci
{
private:
	int index;
	int value;

public:
	Fibonacci(int);
	int sumCalc(int idx);
	int sumCalc_memonize(int i, int* ptr_in);
	void print();
};

Fibonacci::Fibonacci(int idx)
{
	index = idx;
	value = sumCalc(idx);
}

int Fibonacci::sumCalc(int idx)
{
	int* ptr = new int[idx + 1];
	int temp;

	std::fill_n(ptr, (idx + 1), 0);

	temp = sumCalc_memonize(idx, ptr);

	delete[] ptr;
	return temp;
}

int Fibonacci::sumCalc_memonize(int i, int* ptr_in)
{	
	if(i == 0) {
		*(ptr_in + 0) = 0;
		return 0;
	}
	if (i == 1) {
		*(ptr_in + 1) = 1;
		return 1;
	}
	if (*(ptr_in + i) == 0) {		
		*(ptr_in + i) = sumCalc_memonize(i - 1, ptr_in) + sumCalc_memonize(i - 2, ptr_in);
	}
	return *(ptr_in + i);
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
		delete fibNum;

		//fibNum++;
		//std::cout << "AFTER fIB++\n"
		//fibNum->print();
		//std::cout << "\n";
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
	delete[] fibNumPtr;
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