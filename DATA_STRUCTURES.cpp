#include <iostream>
using namespace std;

#define DATA_TYPE int
#define MAX_SIZE 10

class Node {
	public:
		DATA_TYPE data;
		Node* next;
	Node (DATA_TYPE d) {
		data = d;
	}
};
class LinkedList {
	public:
void set_Node(Node& node) {
	cin >> node.data;
}
//--------------------------------------------------------------
		Node* head;
		Node* tail;
		int size;
		LinkedList (DATA_TYPE data) {
			Node first_node (data);
			head = &first_node;
			tail = &first_node;
			size = 1;
		} //constructor
		
		void print() {
			Node* node = head;
			while (1) {
				if (node->next == NULL) {
					cout << node->data << " -> ";
					break;
				}
				cout << node->data << " -> ";
				node = node->next;
			}
		}
		void add(DATA_TYPE data) {
			Node node (data);
			tail->next = &node;
			tail = &node;
			size++;
		}
		void add_front(DATA_TYPE data) {
			Node node (data);
			node.next = head;
			head = &node;
			size++;
		}
		int find(DATA_TYPE d) {
			Node node = *head;
			for (int i=0; i<size; i++) {
				if (node.data == d)
					return i;
				node = *node.next;
			}
			return -1;
		} //takes data and returns it's index position
		DATA_TYPE lookup(int idx) {
			Node node = *head;
			for (int i=0; i<=idx; i++) 
				node = *node.next;
			return node.data;

		} //takes index and returns the data
};
//========================================================================

class Stack {	// using array
	DATA_TYPE list[MAX_SIZE];
	int idx = 0;

	void push(DATA_TYPE x) {
		list[idx] = x;
		idx++;		
	}
	int top() {
		return list[idx];
	}
	int pop() {
		idx--;
		return list[idx+1];
	}	
	void get_input() {
		int x;
		cin >> x;
		push(x);
	}
};
int main ()
{	freopen("in1.txt", "r", stdin);

	LinkedList list (10);
	list.add(20);
	list.add(30);
	list.add(40);
	//cout << list.size;

	list.print();
	return 0;
}