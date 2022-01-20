#include <iostream>
#include <string>

typedef std::string Elem;

struct Node { Node *Next; Node *Prev; Elem Value; };

class DoublyLinkedList
{
public:

	DoublyLinkedList()
	{
		Head = nullptr;
		Tail = nullptr;
	}

	~DoublyLinkedList()
	{
		while (Head)
		{
			Node* Temp = Head;
			Head = Head->Next;
			delete Temp;
			NodeCount--;
		}
	}

	int Size() const
	{
		return NodeCount;
	}

	void PushBack(Elem Value)
	{

		if (!Head)
		{
			Node* Tail = new Node;
			Head = Tail;
			NodeCount++;
		}
		else
		{
			Node* NewTail = new Node;
			Tail->Next = NewTail;
			Tail = NewTail;
			NewTail->Prev = Tail;
			NodeCount++;
		}
	}

	void PushFront(Elem Value)
	{
		if (!Tail)
		{
			Node* Head = new Node;
			Tail = Head;
			NodeCount++;
		}
		else
		{
			Node* NewHead = new Node;
			NewHead->Next = Head;
			Head->Prev = NewHead;
			Head = NewHead;
			NodeCount++;
		}

	}

	void Insert(Elem AddValue, int idx)
	{
		Node* PrevNode{ Head };
		int NodeCount{};
		while (NodeCount < (idx - 1))
		{
			PrevNode = PrevNode->Next;
			NodeCount++;
		}
		Node* NextNode{ PrevNode };
		while (NodeCount < idx)
		{
			NextNode = NextNode->Next;
			NodeCount++;
		}
		Node* NewNode = new Node;
		NewNode->Prev = PrevNode;
		NewNode->Next = NextNode;
		NodeCount++;
	}

	void Delete(int idx)
	{
		if (idx == 0)
		{
			Node* Temp{ Head };
			Head = Head->Next;
			Head->Prev = nullptr;
			NodeCount--;
			delete Temp;
		}
		else if (idx == NodeCount)
		{
			Node* Temp{ Tail };
			Tail = Tail->Prev;
			Tail->Next = nullptr;
			delete Temp;
			NodeCount--;
		}
		else if (idx == (NodeCount - 1))
		{
			Node* PrevNode{ Head };
			int Count{};
			while (Count < (idx-2))
			{
				PrevNode = PrevNode->Next;
				Count++;
			}
			Node* Temp{ PrevNode };
			while (Count < idx)
			{
				Temp = Temp->Next;
				Count++;
			}
			PrevNode->Next = Tail;
			Tail->Prev = PrevNode;
			delete Temp;
			NodeCount--;
		}
		else
		{
			Node* PrevNode{ Head };
			int Count{};
			while (Count < (idx - 1))
			{
				PrevNode = PrevNode->Next;
				Count++;
			}
			Node* Temp{ PrevNode };
			while (Count < idx)
			{
				Temp = Temp->Next;
				Count++;
			}
			Node* NextNode{ Temp };
			while (Count < (idx+1))
			{
				NextNode = NextNode->Next;
				Count++;
			}
			PrevNode->Next = NextNode;
			NextNode->Prev = PrevNode;
			delete Temp;
			NodeCount--;
		}
	}

private:
	Node* Head;
	Node* Tail;
	int NodeCount{};
};

int main() 
{

	DoublyLinkedList List;

	List.Size();
	List.PushBack(5);
	std::cout << "Push back 5: " << std::endl;
	List.PushBack(10);
	std::cout << "Push back 10: " << std::endl;
	List.PushBack(20);
	std::cout << "Push back 20: " << std::endl;
	List.Insert(100, List.Size());
	List.PushBack(200);
	std::cout << "Push back 200: " << std::endl;
	List.Delete(List.Size() - 2);
	List.PushBack(15);
	std::cout << "Push back 15: " << std::endl;
	List.PushBack(25);
	std::cout << "Push back 25: " << std::endl;
	List.Delete(List.Size());
	List.Delete(List.Size() - 1);
	List.PushFront(30);
	std::cout << "Push front: " << std::endl;
	List.PushFront(35);
	std::cout << "Push front: " << std::endl;
	List.PushFront(40);
	std::cout << "Push front: " << std::endl;
	List.PushFront(45);
	std::cout << "Push front: " << std::endl;
	List.Insert(200, List.Size());
	List.Delete(List.Size() - 1);
	List.Delete(List.Size());

	List.Insert(300, List.Size());
	List.Insert(400, List.Size());

	return 0;
}