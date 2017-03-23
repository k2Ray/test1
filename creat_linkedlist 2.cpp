#include <iostream>

class Element
{
private:
	Element *prev;
	Element *next;
	int value;

public:
	Element(int);
	void print();
	void set_prev(Element *);
	void set_next(Element *);
	Element* get_next();
	Element* get_prev();
	int get_value();
};

class List
{
private:
	Element* head;
	Element* tail;

public:
	List();
	void add_element(int val);
	void remove_element(int val);
	void print();
};

Element::Element(int x)
{
	value = x;
	next = nullptr;
	prev = nullptr;
}

List::List()
{
	head = nullptr;
	tail = nullptr;
}


void Element::set_prev(Element* linkptr)
{
	prev = linkptr;
}

void Element::set_next(Element* linkptr)
{
	next = linkptr;
}

void Element::print()
{
	std::cout << value << " ";
}

int Element::get_value()
{
	return(value);
}

Element* Element::get_next()
{
	return(next);
}

Element* Element::get_prev()
{
	return(prev);
}

void List::print()
{
	Element * temp;

	temp = head;
	if (temp == nullptr) return;

	while (temp)
	{
		temp->print();
		temp = temp->get_next();
	}

	std::cout << "end of the list from head \n";
}

void List::add_element(int val)
{
	// allocates memory by calling: operator new (sizeof(List))
	// and then constructs an object at the newly allocated space
	Element* x = new Element(val);
	if (head)
	{
		head->set_prev(x);
		x->set_next(head);
		head = x;
	}
	else
	{
		head = x;
		tail = x;
	}
}

void List::remove_element(int val)
{

	Element * temp, *temp1;
	temp = head;
	if (temp == nullptr) return;
	while (temp)
	{
		if (temp->get_value() == val)
		{
			if (temp->get_next() == nullptr)
			{
				//It is the tail element that needs to be removed
				tail = temp->get_prev();
				tail->set_next(nullptr);
				break;
			} else if(temp->get_prev() == nullptr)
			{
				//It is the head element that needs to be removed
				head = temp->get_next();
				head->set_prev(nullptr);
				break;
			}
			else
			{
				//some element in the list
				//(temp->prev)->next = temp->next;
				//(temp->next)->prev = temp->prev;
				temp1 = temp->get_prev();
				temp1->set_next(temp->get_next());

				//(temp->get_prev())->set_next(temp->get_next());
				temp1 = temp->get_next();
				temp1->set_prev(temp->get_prev());
				//(temp->get_next())->set_prev(temp->get_prev());
				break;
			}
		}
		else 
		{
			temp = temp->get_next();
		}
	}

	if (temp) 
	{ 
		delete(temp);
	}
	
}

int main()
{
	int x;
	List testLink;

	while (1)
	{
		std::cin >> x;
		if (x == 0) 
		{ 
			break; 
		}
		else
		{
			testLink.add_element(x);
			testLink.print();
		}
	}

	testLink.remove_element(43);

	testLink.remove_element(50);

	testLink.print();

	std::cin >> x;


	return 0;
}