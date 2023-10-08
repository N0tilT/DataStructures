#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Queue
{
	//Очередь
	int* Data;
	//Максимальный размер очереди
	int MaxQueueLength;
	//Текущий размер очереди
	int QueueLength;
public:
	//Конструктор
	Queue(int m);
	//Деструктор
	~Queue();
	//Добавление элемента
	void Enqueue(int c);
	//Извлечение элемента
	int Dequeue();
	//Очистка очереди
	void Clear();
	//Проверка существования элементов в очереди
	bool IsEmpty();
	//Проверка на переполнение очереди
	bool IsFull();
	//Количество элементов в очереди
	int GetCount();
	//демонстрация очереди
	void Show();
};
void Queue::Show() {
	cout << "\n-----------------------------------\n";
	for (int i = 0; i < QueueLength; i++) {
		cout << Data[i] << " ";
	}
	cout << "\n-----------------------------------\n";
}
Queue::~Queue()
{
	delete[]Data;
}
Queue::Queue(int m)
{
	MaxQueueLength = m;
	Data = new int[MaxQueueLength];
	QueueLength = 0;
}
void Queue::Clear()
{
	QueueLength = 0;
}
bool Queue::IsEmpty()
{
	return QueueLength == 0;
}
bool Queue::IsFull()
{
	return QueueLength == MaxQueueLength;
}
int Queue::GetCount()
{
	return QueueLength;
}
void Queue::Enqueue(int c)
{
	if (!IsFull())
		Data[QueueLength++] = c;
}
int Queue::Dequeue()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь
	if (!IsEmpty()) {

		//запомнить первый
		int temp = Data[0];

		//сдвинуть все элементы
		for (int i = 1; i < QueueLength; i++)
			Data[i - 1] = Data[i];
		QueueLength--;

		//вернуть первый(нулевой)
		return temp;
	}
	else
		return -1;
}


void main()
{
	srand(time(0));
	//создание очереди
	Queue queue(25);

	for (int i = 0; i < 5; i++) {
		queue.Enqueue(rand() % 50);
	}

	queue.Show();
	queue.Dequeue();
	queue.Show();
}