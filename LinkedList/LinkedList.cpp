#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node* previous;
};

class linkedListCirc
{
private:
	node* tail;
	int size = 0;
public:
	linkedListCirc()
	{
		tail = nullptr;
	}
	void addNodeEnd(int value)
	{
		node* temp = new node;
		temp->data = value;
		if (tail == nullptr)
		{
			temp->next = temp;
			temp->previous = temp;
			tail = temp;

		}
		else {
			temp->next = tail->next;
			temp->previous = tail;
			tail->next->previous = temp;
			tail->next = temp;
			tail = temp;
		}
		size++;
	}
	void display() {
		if (tail == nullptr) {
			cout << "Sarasas tuscias" << endl;
			return;
		}

		node* current = tail->next;
		current = tail->next;

		do {
			cout << current->data << " ";
			current = current->next;
		} while (current != tail->next);
	}
	void addNodeStart(int value)
	{
		node* temp = new node;
		temp->data = value;
		if (tail != nullptr) {
			temp->previous = tail;
			temp->next = tail->next;
			tail->next->previous = temp;
			tail->next = temp;
		}
		else {
			temp->next = temp;
			temp->previous = temp;
			tail = temp;
		}
		size++;
	}
	void addNodePos(int pos, int value) {
		if (pos < 0)
		{
			cout << "Position is incorrectly specified" << endl;
			return;
		}
		node* temp = new node;
		temp->data = value;
		if (tail == nullptr) {
			temp->next = temp;
			temp->previous = temp;
			tail = temp;
			size++;
			return;
		}
		int fullCicles = pos / size;
		int FromHead = pos % size;
		int FromTail = size - (pos % size);
		node* current = tail;
		if (FromTail < FromHead) {
			FromTail = size * fullCicles + FromTail;
			cout << "TAIL " << pos << " " << FromTail << endl;
			for (int i = 0; i < FromTail; i++) {
				current = current->previous;
			}
			temp->previous = current;
			temp->next = current->next;
			current->next->previous = temp;
			current->next = temp;
		}
		else {
			cout << "Head " << pos << endl;
			for (int i = 0; i < pos + 1; i++) {
				current = current->next;
			}
			cout << current->data << endl;
			temp->next = current;
			temp->previous = current->previous;
			current->previous->next = temp;
			current->previous = temp;
		}
		size++;
	}
	void deleteNodeStart() {
		if (tail != nullptr)
		{
			node* temp = tail->next;
			if (temp != tail) {
				tail->next = temp->next;
				temp->next->previous = tail;
				delete temp;
			}
			else if (temp == tail) {
				delete temp;
				tail = nullptr;
			}
			size--;
		}
		else {
			cout << "You can't delete items from an empty list";
		}
	}
	void deleteNodeEnd() {
		if (tail != nullptr) {
			if (tail->next != tail) {
				node* temp = tail->previous;
				temp->next = tail->next;
				tail->next->previous = temp;
				tail = temp;
			}
			else {
				delete tail;
				tail = nullptr;
			}
			size--;
		}
		else if (tail == nullptr) {
			cout << "You can't delete items from an empty list";
		}
	}
};

int main()
{
	linkedListCirc list;
	list.addNodeEnd(1);
	list.addNodeEnd(2);
	list.addNodeEnd(3);
	list.addNodeEnd(4);
	list.addNodeEnd(5);
	list.addNodeEnd(6);
	list.addNodeEnd(7);
	list.addNodeEnd(8);
	list.addNodeEnd(9);
	list.addNodeEnd(10);
	list.addNodePos(20, 99);
	list.display();
	return 0;
}
