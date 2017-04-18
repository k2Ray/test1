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
	Element* get_head();
	Element* get_tail();
	void set_head(Element* );
	void set_tail(Element* );
	void print();
};

//Queue class inheret from List class
class Queue : public List
{
private:
public:
	Queue();
	void enqueue(int val);
	Element* dequeue();
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

Queue::Queue()
{
  //head & tail are set in List Constructor
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

Element* List::get_head()
{
	return head;
}

void List::set_head(Element* x)
{
	head = x;
	if(head) {
		head->set_prev(nullptr);
	} 
}

Element* List::get_tail()
{
	return tail;
}

void List::set_tail(Element* tail_in)
{
	tail = tail_in;
	if (tail_in) {
		tail_in->set_next(nullptr);
	}
}

Element* Queue::dequeue()
{
	Element* currTail;
	currTail = get_tail();
	//updating the linked list to change return the current head in the pop
	//& update the next to head element as new head
	if(currTail)
	{
		set_tail(currTail->get_prev());
		if (get_tail() == nullptr) {
			set_head(nullptr);
		}
		return currTail;
	} 
	std::cout << "no elements left to dequeue \n";
	return nullptr;
}

void Queue::enqueue(int val)
{
	add_element(val);
}

int main()
{
	int x;
	Queue testLink;
	Element* temp;

	while (1)
	{
		std::cin >> x;
		if (x == 0) 
		{ 
			break; 
		}
		else
		{
			testLink.enqueue(x);
			testLink.print();
		}
	}

	temp = testLink.dequeue();
	if (temp) {
		std::cout << "testLink.dequeue(); value = " << temp->get_value();
		delete(temp);
	}

	temp = testLink.dequeue();
	if (temp) {
		std::cout << "testLink.dequeue(); value = " << temp->get_value();
		delete(temp);
	}

	temp = testLink.dequeue();
	if (temp) {
		std::cout << "testLink.dequeue(); value = " << temp->get_value();
		delete(temp);
	}

	temp = testLink.dequeue();
	if (temp) {
		std::cout << "testLink.dequeue(); value = " << temp->get_value();
		delete(temp);
	}

	temp = testLink.dequeue();
	if (temp) {
		std::cout << "testLink.dequeue(); value = " << temp->get_value();
		delete(temp);
	}

	testLink.print();

	std::cin >> x;


	return 0;
}