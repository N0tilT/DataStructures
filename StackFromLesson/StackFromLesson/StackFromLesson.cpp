#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Stack
{
	//Нижняя и верхняя границы стека
	enum { EMPTY = -1, FULL = 20 };

	//Массив для хранения данных
	char st[FULL + 1];

	//индекс определяющий вершину стека
	int top;

public:

	//Конструктор
	Stack();

	//Добавление элемента
	void Push(char c);

	//Извлечение элемента
	char Pop();

	//Очистка стека
	void Clear();

	//Проверка существования элементов в стеке
	bool IsEmpty();

	//Проверка на переполнение стека
	bool IsFull();

	//Количество элементов в стеке
	int GetCount();
};

Stack::Stack()
{
	//Изначально стек пуст
	top = EMPTY;
}

void Stack::Clear()
{
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	return top == EMPTY;
}

bool Stack::IsFull()
{
	return top == FULL;
}

int Stack::GetCount()
{
	return top + 1;
}

void Stack::Push(char c)
{
	if (!IsFull())
	{
		st[++top] = c;
	}
}


char Stack::Pop()
{
	if (!IsEmpty())
		return st[top--];
	else
		return 0;
}


void main()
{
	srand(time(0));
	
	Stack ST;
	char c;
	//пока стек не заполнится
	while (!ST.IsFull()) {
		c = rand() % 4 + 2;
		ST.Push(c);
	}

	ST.Push('a');
	//пока стек не освободится
	while (c = ST.Pop()) {
		cout << c << " ";
	}
	cout << "\n\n";
}