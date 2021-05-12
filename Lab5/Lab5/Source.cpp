#include <iostream>
#include "Queue.h"
#include "Queue_int.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");

	cout << "��������� �������:" << endl << endl;

	Queue<int> z(5);

	z.Push(1);
	z.Push(2);
	z.Push(5);
	z.Push(6);
	z.Push(9);

	cout << z;

	z.Pop();
	cout << z;
	cout << "����� ��������� � �������: " <<z.GetSize() << endl;

	z.Push(7);
	cout << z;
	cout << "����� ��������� � �������: " << z.GetSize() << endl;

	cout << "������ ������� � �������: " << z.Peek() << endl;

	
	cout << endl << "������������� �������:" << endl << endl;

	Queue_int v(5);

	v.Push(1);
	v.Push(2);
	v.Push(5);
	v.Push(6);
	v.Push(9);

	cout << v;

	v.Pop();
	cout << v;
	cout << "����� ��������� � �������: " << v.GetSize() << endl;

	v.Push(7);
	cout << v;
	cout << "����� ��������� � �������: " << v.GetSize() << endl;

	cout << "������ ������� � �������: " << v.Peek() << endl;



	return 0;
}