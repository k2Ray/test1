#include <iostream>

class Fibonacci
{
private:
	int index;
	int value;

public:
	Fibonacci(int);
	void setIndex(int);
	int getIndex();
	void setValue(int);
	int getValue();
	int sumCalc(int idx);
	int sumCalc_memonize(int i, int* ptr_in);
	// incr the index on usage of this operator on an object  
	void operator++() { value = sumCalc(index + 1); index++; return; };
	Fibonacci operator++(int idx);
	Fibonacci& operator+=(Fibonacci& a) { index = index + a.index; value = sumCalc(index); return *this; };
	void print();
};

Fibonacci& operator+(const Fibonacci& a, const Fibonacci& b);

Fibonacci::Fibonacci(int idx)
{
	index = idx;
	value = sumCalc(idx);
}

void Fibonacci::setIndex(int idx)
{
	index = idx;
}

void Fibonacci::setValue(int val)
{
	value = val;
}

int Fibonacci::getIndex()
{
	return index;
}

int Fibonacci::getValue()
{
	return value;
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


Fibonacci& operator+(Fibonacci& a, Fibonacci& b)
{
	int temp = a.getIndex() + b.getIndex();
	Fibonacci fibS(temp);
	return fibS;
}

Fibonacci Fibonacci::operator++(int idx) 
{
	Fibonacci temp(index); 
	++(*this); 
	return temp; 
}


void Fibonacci::print()
{
	std::cout << "index = " << index << " value =" << value << std::endl;
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
		std::cin >> x;
		Fibonacci* fibNum1 = new Fibonacci(x - 1);
		fibNum1->print();
		//*fibNum += *fibNum1;
		Fibonacci test = (*fibNum1)++;
		std::cout << "printing test \n";
		test.print();
		std::cout << "printing fibNum1 after increment \n";
		fibNum1->print();
		
		Fibonacci fibSum = (*fibNum+*fibNum1);
		std::cout << "\n";
		std::cout << "fibSum =" << "\n";
		fibSum.print();
		std::cout << "\n";
		//similar to int x++ incr value in x 
		//*fibNum++ wont work -----------------------
		++(*fibNum);  //You had (*fibNum)++ that was wrong the overlaoded operator is ++(*fibNum)
		std::cout << "++fibSum =" << "\n";
		fibNum->print();
		std::cout << "\n";
		Fibonacci x(4);
		//x++ wont work ----------------------------------------------------------
		++x;  //You had x++ that was wrong the overlaoded operator is ++x
		x.print();
		std::cout << "x" << "\n";
		
//		delete fibNum;

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
		delete fibNumPtr[i];
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