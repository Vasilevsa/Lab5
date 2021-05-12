#pragma once
#include <iostream>

template<typename T>
class Queue{
private:

	T* arr;

	int size, head, tail, count;

public:

	Queue(const int size); // Инициализация

	Queue(const Queue& other); // Копирование

	Queue(Queue&& other); // Перемещение

	Queue& operator=(const Queue& other); // Присваивание

	Queue& operator=(Queue&& other); // Присваивание с перемещением

	~Queue(); // Деструктор

	int GetSize() const;

	void Push(const T& element); // Вставка элемента

	T Pop(); // Удаление элемента

	T Peek() const; // Просмотр элемента
	
	template<typename T>
	friend std::ostream& operator <<(std::ostream& os, const Queue<T>& obj); // Вывод
};

template<typename T>
Queue<T>::Queue(const int size): size(size), arr(new T[size]), head(0), tail(0), count(0) { }

template<typename T>
Queue<T>::Queue(const Queue& other) : size(other.size), arr(new T[other.size]), head(other.head), tail(other.tail), count(other.count)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
}

template<typename T>
Queue<T>::Queue(Queue&& other) : size(other.size), count(other.count), head(other.head), tail(other.tail), arr(other.arr)
{
	other.arr = nullptr;
	other.size = NULL;
	other.count = NULL;
	other.head = NULL;
	other.tail = NULL;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] arr;

	size = other.size;
	arr = new T[other.size];

	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue&& other)
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

template<typename T>
Queue<T>::~Queue()
{
	delete[] arr;
	arr = nullptr;
	size = NULL;
	count = NULL;
	head = NULL;
	tail = NULL;
}

template<typename T>
int Queue<T>::GetSize() const
{
	return this->count;
}

template<typename T>
void Queue<T>::Push(const T &element)
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

template<typename T>
T Queue<T>::Pop()
{
	if (count > 0)
	{
		T element = arr[head];
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

template<typename T>
T Queue<T>::Peek() const
{
	return arr[head];
}

template<typename T>
std::ostream& operator << (std::ostream& os, const Queue<T>& obj)
{
	Queue<T> temp = obj;

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