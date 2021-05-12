#include "Queue_int.h"

Queue_int::Queue_int(const int size) : size(size), arr(new int[size]), head(0), tail(0), count(0) { }

Queue_int::~Queue_int()
{
	delete[] arr;
	arr = nullptr;
	size = NULL;
	count = NULL;
	head = NULL;
	tail = NULL;
}

Queue_int::Queue_int(const Queue_int& other) : size(other.size), arr(new int[other.size]), head(other.head), tail(other.tail), count(other.count)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
}

Queue_int::Queue_int(Queue_int&& other) : size(other.size), count(other.count), head(other.head), tail(other.tail), arr(other.arr)
{
	other.arr = nullptr;
	other.size = NULL;
	other.count = NULL;
	other.head = NULL;
	other.tail = NULL;
}

Queue_int& Queue_int::operator=(const Queue_int& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] arr;

	size = other.size;
	arr = new int[other.size];

	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
}

Queue_int& Queue_int::operator=(Queue_int&& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] arr;

	size = other.size;
	count = other.count;
	head = other.head;
	tail = other.tail;
	arr = other.arr;

	other.arr = nullptr;
	other.size = NULL;
	other.count = NULL;
	other.head = NULL;
	other.tail = NULL;
}


int Queue_int::GetSize() const
{
	return this->count;
}

void Queue_int::Push(const int& element)
{
	if (count < size)
	{
		arr[tail] = element;

		tail = (tail + 1) % size;

		count++;
	}
	else
	{
		std::cout << "Очередь переполнена! Аварийное завершение программы!" << "\n";
		abort();
	}
}

int Queue_int::Pop()
{
	if (count > 0)
	{
		int element = arr[head];
		head = (head + 1) % size;
		count--;

		return element;
	}
	else
	{
		std::cout << "Очередь пуста! Аварийное завершение программы!" << "\n";
		abort();
	}
}

int Queue_int::Peek() const
{
	return arr[head];
}


std::ostream& operator << (std::ostream& os, const Queue_int& obj)
{
	Queue_int temp = obj;

	os << "Текущая очередь => ";

	for (int i = 0; i < temp.size; i++)
	{
		if (temp.count > 0)
		{
			os << temp.arr[temp.head] << " ";
			temp.head = (temp.head + 1) % temp.size;
			temp.count--;
		}
	}

	os << "\n";

	return os;
}