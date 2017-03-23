#include <iostream>

class List
{
private:
	List *prev;
	List *next;
	int value;
	//static members exist even if no objects of the class have been instantiated!
	//Much like global variables, they are created when the program starts, and destroyed when the program ends.
	//declaring the head & tail points of List type class as there is only 1 head & tail of this liked list
	//and a new instaantiated object can be added to the link list
	static List* head;
	static List* tail;

public:
	List(int);
	void print();
	static List* add(int val);
	void remove(int val);
	static void print_static();
};

// static member variables hav eto be initialized before being used 
List* List::head = 0;
List* List::tail = 0;

List::List(int x)
{
	if(head)
	{
		head->prev = this;
		this->next = head;
		head = this;
	}
	else
	{
		head = this;
		tail = this;
		next = nullptr;
		prev = nullptr;
	}
	this->value = x;
}

void List::print()
{
	List * temp;
	List * temprev;

	temp = this->head;
	if (temp == nullptr) return; 
	while (temp)
	{
		std::cout << temp->value << "\n"; 
		temp = temp->next;
	}
	std::cout << "end of the list from head" << "\n";

	/*
	temprev = this->tail;
	if (temprev == nullptr) return;
	while (temprev)
	{
		std::cout << temprev->value << "\n";
		temprev = temprev->prev;
	}
	std::cout << "end of the list from tail" << "\n";
	*/
}

void List::print_static()
{
	List * temp;

	temp = List::head;
	if (temp == nullptr) return;
	while (temp)
	{
		std::cout << temp->value << "\n";
		temp = temp->next;
	}
	std::cout << "end of the list from head" << "\n";
}

// allocates memory by calling: operator new (sizeof(List))
// and then constructs an object at the newly allocated space
List* List::add(int val)
{
	List* x = new List(val);
	return (x);
}

void List::remove(int val)
{

	List * temp;
	temp = this->head;
	if (temp == nullptr) return;
	while (temp)
	{
		if (temp->value == val)
		{
			if (temp->next == nullptr)
			{
				//It is the tail element that needs to be removed
				tail = temp->prev;
				tail->next = nullptr;
				return;
			} else if(temp->prev == nullptr)
			{
				//It is the head element that needs to be removed
				head = temp->next;
				head->prev = nullptr;
				return;
			}
			else
			{
				//some element in the list
				(temp->prev)->next = temp->next;
				(temp->next)->prev = temp->prev;
				return;
			}
		}
		else {
			temp = temp->next;
		}
	}

	std::cout << " No list element contains the value \n";
	
}

int main()
{
	int x;
	List link1(2);
	List* test;
	while (1)
	{
		std::cin >> x;
		if (x == 0) 
		{ 
			break; 
		}
		else
		{
			test = List::add(x);
			//test->value won't work as private variables cannot be accessed without
			//unless inside member functions  & this code is in main
			std::cout << "test value \n";
			test->print();
		}
	}
	//link1.remove(2);

	link1.print();
	List::print_static();

	std::cin >> x;


	return 0;
}