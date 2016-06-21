#include<iostream>
using namespace std;
class Node{
	friend class List;
public:
	Node()
	{
		next = NULL;
	}
	Node(int input)
	{
		data = input;
		next = NULL;
	}
private:
	int data;
	Node *next;
};
class List{
public:
	List()
	{
		head = NULL;
	}

	void insert(Node *data);
	void insert(Node *data, int pos);
	void del(int data);
	void print();
private:
	Node *head;
};
void List::insert(Node *data)
{
	if (head == NULL)
	{
		head = data;
		return;
	}

	Node *ptr;
	for (ptr = head; ptr->next != NULL; ptr = ptr->next);
	ptr->next = data;
}
void List::insert(Node *data, int pos)
{
	if (head == NULL)
	{
		head = data;
		return;
	}
	else if (pos == 1)
	{
		data->next = head;
		head = data;
		return;
	}

	Node *ptr;
	int idx;
	for (ptr = head, idx = 1; (idx != pos - 1) && (ptr->next != NULL); ptr = ptr->next, idx++);

	if (idx + 1 < pos)
	{
		cout << "overflow..." << endl;
		getchar();
		getchar();
	}
	else if (ptr->next == NULL)
		ptr->next = data;
	else
	{
		Node *new_next = ptr->next;
		ptr->next = data;
		data->next = new_next;
	}

}
void List::del(int data)
{
	if (head == NULL)
	{
		cout << "List is empty..." << endl;
		return;
	}

	Node *ptr, *prev = head;
	for (ptr = head; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->data == data)
		{
			if (ptr == head)
			{
				head = ptr->next;
				delete ptr;
				return;
			}
			else if (ptr->next == NULL)
			{
				prev->next = NULL;
				delete ptr;
				return;
			}
			else
			{
				prev->next = ptr->next;
				delete ptr;
				return;
			}
		}
		prev = ptr;
	}
	cout << "No data..." << endl;
	getchar(); getchar();
}
void List::print()
{
	if (head == NULL)
	{
		cout << "List is empty..." << endl;
		return;
	}

	Node *ptr;
	for (ptr = head; ptr != NULL; ptr = ptr->next)
		cout << ptr->data << ' ';
	cout << endl;
}
int main()
{
	//List *lst=new List();
	List lst;
	while (1)
	{
		cout << "-------------------------------------------------" << endl;
		cout << "-    1. insert 2. delete, 3. print, 4. exit     -" << endl;
		cout << "-------------------------------------------------" << endl;
		cout << endl << "select menu -> ";
		int menu; cin >> menu;
		if (menu == 1)
		{
			int data, pos, type;
			cout << "1. input data 2.input data and position " << endl;
			cout << "select type -> ";
			cin >> type;
			if (type == 1)
			{
				cout << "input data -> ";
				cin >> data;
				Node *new_node = new Node(data);
				//lst->insert(new_node);
				lst.insert(new_node);
				system("cls");
			}
			else if (type == 2)
			{
				cout << "input data and pos -> ";
				cin >> data >> pos;
				Node *new_node = new Node(data);
				//lst->insert(new_node, pos);
				lst.insert(new_node, pos);
				system("cls");
			}
			else continue;
		}
		else if (menu == 2)
		{
			int data;
			cout << "input data for delete -> ";
			cin >> data;
			lst.del(data);
			system("cls");
		}
		else if (menu == 3)
		{
			//lst->print();
			lst.print();
			cout << "press enter key...";
			getchar();
			getchar();
			system("cls");
		}
		else if (menu == 4)
		{
			cout << "Bye~ Bye~" << endl;
			break;
		}
		else
		{
			cout << "What are you doing???" << endl;
			getchar();
			system("cls");
		}
	}

	return 0;
}