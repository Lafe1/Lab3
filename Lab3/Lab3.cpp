//14. Построить класс для работы с бинарным деревом, узлы которого
//содержат действительные числа.Создать дерево для заданной
//последовательности чисел.Используя его, упорядочить
//последовательность по возрастанию, убыванию.
#include "pch.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include <ctime>
#include <windows.h>

using namespace std;

struct node
{
	float n; //информационное поле узла дерева
	int count;

	node*left, *right;
};
class Tree
{
public:
	node*root;
	Tree() { root = 0; }
	Tree(const Tree&ob); //конструктор копирования
	//	Рекурсивная функция, используемая в деструкторе (освобождение памяти) void DelTree(node *wer);
	~Tree() { DelTree(root); }
	void Push(node*&wer, float data);// Вставка элемента в дерево
	void Look(node*wer);	// Вывод дерева на экран
	void DelTree(node *wer);
	void increase(node*wer);
	void descending(node*wer);
};

void Tree::increase(node*wer)
{

	if (wer != NULL)
	{
		increase(wer->left);
		cout << " " << wer->n << " ";
		increase(wer->right);
	}

}

void Tree::descending(node*wer)
{

	if (wer != NULL)
	{
		descending(wer->right);
		cout << " " << wer->n << " ";
		descending(wer->left);
	}

}

Tree::Tree(const Tree&ob)
{
	if (ob.root == 0)root = 0;
	else {
		root = new node;
		root->n = ob.root->n;
		root->count = 1;
		root->left = 0;
		root->right = 0;
	}
}

void Tree::DelTree(node *wer)

{
	if (wer->left != 0)DelTree(wer->left);
	if (wer->right != 0)DelTree(wer->right);
	delete wer;
}
void Tree::Push(node*&wer, float data)
{
	if (wer == 0)

	{
		wer = new node;
		wer->n = data;
		wer->left = 0; wer->right = 0;
		wer->count = 1;
	}
	else if (data < wer->n)Push(wer->left, data);
	else if (data > wer->n)Push(wer->right, data);
	else wer->count++;
}
void Tree::Look(node*wer)
{
	if (wer != 0)
	{
		Look(wer->left);
		cout << " Число: " << wer->n << " - " << wer->count; cout << " штук" << endl; Look(wer->right);
	}
}


int main(int argc, char* argv[])
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Tree tr;
	cout << "**************************** BOOL TREE *********************************\n"
		<< "========================================================================\n"
		<< "||  Данная программа строит бинарное дерево с действительными числами  ||\n"
		<< "|| и упорядочивает последовательность по возрастанию или убыванию      ||\n"
		<< "========================================================================\n\n";
	while (1) {
		int select;
		cout << "  Выберете, что необходимо сделать:\n"
			<< " 1. Ввести дерево\n"
			<< " 2. Показать дерево\n"
			<< " 3. Вывести дерево по возрастанию\n"
			<< " 4. Вывести дерево по убыванию\n"
			<< " 5. Выход\n";
		cout << " Выбрать: ";
		cin >> select;
		switch (select)
		{
		case 1: {
			int n;
			cout << " Введите кол-во элементов в дереве: ";
			cin >> n;
			float *data = new float[n];
			for (int i = 0; i < n; i++)
			{
				cout << " Введите число №" << i + 1 << ": ";
				cin >> data[i];
				tr.Push(tr.root, data[i]);
			}
			cout << endl;
			break;

		}
		case 2: {
			if (tr.root == 0)cout << " Дерево пустое";
			else
			{
				cout << " Наше дерево:" << endl;
				tr.Look(tr.root);
			}
			cout << endl;
			while (!_kbhit());
			break;
		}
		case 3: {
			cout << " Вывод: " << endl;
			tr.increase(tr.root);
			cout << endl;
			cout << endl;
			while (!_kbhit());
			break;
		}
		case 4: {
			cout << " Вывод: " << endl;
			tr.descending(tr.root);
			cout << endl;
			cout << endl;
			while (!_kbhit());
			break;
		}
		case 5: {
			exit(0);
		}
		}

	}
	return 0;
}
