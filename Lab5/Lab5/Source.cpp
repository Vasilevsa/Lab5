#include <iostream>
#include "Queue.h"
#include "Queue_int.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");

	cout << "Шаблонная очередь:" << endl << endl;

	Queue<int> z(5);

	z.Push(1);
	z.Push(2);
	z.Push(5);
	z.Push(6);
	z.Push(9);

	cout << z;

	z.Pop();
	cout << z;
	cout << "Число элементов в очереди: " <<z.GetSize() << endl;

	z.Push(7);
	cout << z;
	cout << "Число элементов в очереди: " << z.GetSize() << endl;

	cout << "Первый элемент в очереди: " << z.Peek() << endl;

	
	cout << endl << "Целочисленная очередь:" << endl << endl;

	Queue_int v(5);

	v.Push(1);
	v.Push(2);
	v.Push(5);
	v.Push(6);
	v.Push(9);

	cout << v;

	v.Pop();
	cout << v;
	cout << "Число элементов в очереди: " << v.GetSize() << endl;

	v.Push(7);
	cout << v;
	cout << "Число элементов в очереди: " << v.GetSize() << endl;

	cout << "Первый элемент в очереди: " << v.Peek() << endl;



	return 0;
}