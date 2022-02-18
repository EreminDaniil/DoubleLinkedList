#include <iostream>
#include "DoubleLinkedList.h"
#include <string>


UDoublyLinkedList::UDoublyLinkedList()
{
	Head = Tail = nullptr;
	Count = 0;
}

UDoublyLinkedList::~UDoublyLinkedList()
{
	while (Head)
	{
		FNode* Temp = Head;
		Head = Head->Next;
		delete Temp;
	}
}

UDoublyLinkedList::UDoublyLinkedList(const UDoublyLinkedList& other)
{
	FNode* NewNode = new FNode; 
	FNode* Current; 

	if (other.Head == 0) 
	{
		Head = nullptr;
		Count = 0;
	}
	else
	{
		Current = other.Head;
		Count = other.Count;
		Head->Data = Current->Data; 
		Head->Next = Current->Next; 
		Head->Tail = Current->Tail;
		Tail = Head; 
		Current = Current->Next;
		while (Current != nullptr)
		{
			NewNode = new FNode; 
			NewNode->Data = Current->Data;
			NewNode->Next = Current->Next;
			NewNode->Prev = Current->Prev;
			Tail->Next = NewNode;
			Tail = NewNode;
			Current = Current->Next;
		}
	}
}

UDoublyLinkedList& UDoublyLinkedList::operator=(const UDoublyLinkedList& other)
{
	if (this != &other.Head) //avoid self-copy
	{
		UDoublyLinkedList(other);
	}
	return *this;
}

bool UDoublyLinkedList::IsEmpty() const
{
	if (Count <= 0)
	{
		return true;
	}
	return false;
}

UDoublyLinkedList::UIterator Begin() const
{

}

UDoublyLinkedList::UIterator End() const
{

}

size_t UDoublyLinkedList::Count() const
{
	
}

void UDoublyLinkedList::InsertBack(const Elem& Value)
{
	FNode* NewNode = new FNode;
	NewNode->Value = Value;
	NewNode->Next = nullptr;
	NewNode->Prev = nullptr;

	if (NewNode == nullptr)
	{
		NewNode->Next = Head;
		Head->Prev = NewNode;
		Head = NewNode;
	}
}

void UDoublyLinkedList::InsertFront(const Elem& Value)
{
	FNode* NewNode = new FNode;
	NewNode->Value = Value;
	NewNode->Next = nullptr;
	NewNode->Prev = nullptr;
	if (NewNode == nullptr)
	{
		Tail->Next = NewNode;
		NewNode->Prev = Tail;
		Tail = NewNode;
	}
}

void UDoublyLinkedList::Insert(const UIterator& idx, const Elem& Value)
{
	if (idx == 0)
	{
		InsertFront(Value);
	}
	else if (idx == Count)
	{
		InsertBack(Value);
	}
	else
	{
		FNode* PrevNode = Head;
		int NodeCount = 0;
		while (NodeCount < (idx - 1))
		{
			PrevNode = PrevNode->Next;
			NodeCount++;
		}
		FNode* NextNode = PrevNode;
		while (NodeCount < idx)
		{
			NextNode = NextNode->Next;
			NodeCount++;
		}
		FNode* NewNode = new FNode;
		NewNode->Prev = PrevNode;
		NewNode->Next = NextNode;
		NodeCount++;
	}
}

void UDoublyLinkedList::EraseFront()
{
	if (!IsEmpty())
	{
		FNode* Temp = Head;
		if (Head == Tail)
		{
			Tail = nullptr;
		}
		Elem DelValue = Temp->Data;
		Head = Head->Next;
		delete Temp;
		Count--;
	}
}

void UDoublyLinkedList::EraseEnd()
{
	if (!IsEmpty())
	{
		FNode* Temp = Tail;
		if (Head == Tail)
		{
			Head = nullptr;
		}
		Elem DelValue = Temp->Data;
		Tail->Next = nullptr;
		Tail = Tail->Prev;
		delete Temp;
		Count--;
	}
}

void UDoublyLinkedList::Erase(const UIterator& idx)
{
	if (Count == 0)
	{
		return;
	}
	else
	{
		FNode* NodeDelete = Head;
		for (int i=0; i < idx; i++)
		{
			NodeDelete = NodeDelete->Next;
		}
		if (NodeDelete->Prev) 
		{ 
			NodeDelete->Prev->Next = NodeDelete->Next;
		}
		if (NodeDelete->Next)
		{
			NodeDelete->Next->Prev = NodeDelete->Prev;
		}
		if (Head == NodeDelete)
		{
			Head = NodeDelete->Next;
		}
		if (Tail == NodeDelete)
		{
			Tail = NodeDelete->Prev;
		}
		Count--;
		delete NodeDelete;
	}
}

int main() 
{

	UDoublyLinkedList List;

	
// 	List.Insert("2", 1);
// 	std::cout << "Insert 2" << std::endl;
 	List.PushFront("9");
 	std::cout << "Push front 9:" << std::endl;
 	List.PushBack("5");
 	std::cout << "Push back 5: " << std::endl;
 	List.PushBack("10");
 	std::cout << "Push back 10: " << std::endl;

	List.Size();
// 	List.PushBack("20");
// 	std::cout << "Push back 20: " << std::endl;
// 	List.Insert("5", List.Size());
// 	List.PushBack("200");
// 	std::cout << "Push back 200: " << std::endl;
// 	List.Delete(List.Size() - 2);
// 	List.PushBack("15");
// 	std::cout << "Push back 15: " << std::endl;
// 	List.PushBack("25");
// 	std::cout << "Push back 25: " << std::endl;
// 	List.Delete(List.Size());
// 	List.Delete(List.Size() - 1);
// 	List.PushFront(30);
// 	std::cout << "Push front: " << std::endl;
// 	List.PushFront(35);
// 	std::cout << "Push front: " << std::endl;
// 	List.PushFront(40);
// 	std::cout << "Push front: " << std::endl;
// 	List.PushFront(45);
// 	std::cout << "Push front: " << std::endl;
// 	List.Insert(200, List.Size());
// 	List.Delete(List.Size() - 1);
// 	List.Delete(List.Size());
// 
// 	List.Insert(300, List.Size());
// 	List.Insert(400, List.Size());

	return 0;
}