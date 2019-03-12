

#include <conio.h>
#include <string.h>
#include "iostream"

using namespace std;
char bufRus[256];

char*Rus(const char*text) {

	CharToOem(text, bufRus);
	return bufRus;
}
struct node
{
	int n; //информационное поле узла дерева
	int count;

	node*left, *right;
};
class Tree
{
public:
	node*root;
	Tree() { root = 0; }
	Tree(int t); // Формирование дерева из t случайных чисел void CopyTree(node*&rootnew,node*rootold);

	/* Копирует дерево с корнем rootold в дерево с корнем rootnew. В результате деревья находятся в различных динамических участках памяти.*/
	Tree(const Tree&ob); //конструктор копирования
	//	Рекурсивная функция, используемая в деструкторе (освобождение памяти) void DelTree(node *wer);
	~Tree() { DelTree(root); }
	void Push(node*&wer, int data);// Вставка элемента в дерево
	void Look(node*wer);	//- Вывод дерева на экран
	node*Find(node*wer, int key); // Поиск по ключу
	void PrintLeaves(node *wer); // Вывод листьев дерева на экран
};
//********************** Tree::Tree(int t) *******************
Tree::Tree(int t)
{
	root = 0;
	for (int i = 0; i < t; i++)
		Push(root, random(10) - 5);
}
void Tree::CopyTree(node*&rootnew, node*rootold)
{
	if (rootold->left != 0)
	{
		Push(rootnew, (rootold->left)->n); CopyTree(rootnew, rootold->left);
	}
	if (rootold->right != 0)
	{
		Push(rootnew, (rootold->right)->n); CopyTree(rootnew, rootold->right);
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
		CopyTree(root, ob.root);
	}
}


void Tree::DelTree(node *wer)

{
	if (wer->left != 0)DelTree(wer->left);
	if (wer->right != 0)DelTree(wer->right);
	delete wer;
}
void Tree::Push(node*&wer, int data)
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
		cout << Rus(" Число: ") << wer->n << " - " << wer->count; cout << Rus(" штук") << endl; Look(wer->right);
	}
}
node* Tree::Find(node*wer, int key)
{
	if (wer == 0) return 0;
	else if (key < wer->n) return Find(wer->left, key); else if (key > wer->n) return Find(wer->right, key);
	else return wer;
}
void Tree::PrintLeaves(node *wer)
{
	if (wer == 0)return;
	else if ((wer->left == 0) && (wer->right == 0)) {
		cout << Rus(“Число: “) << wer->n << ” - “ << wer->count; cout << Rus(“штук”) << endl;
	}
	else
	{
		PrintLeaves(wer->left);
		PrintLeaves(wer->right);
	}

}
//-------------------------------- MAIN ----------------------------------------
int main(int argc, char* argv[])
{
	Tree tr;
	node *u;
	int k = 0, max, kol;
	cout << "**************************** BOOL TREE *********************************\n"
		<< "========================================================================\n"
		<< "||  Данная программа строит бинарное дерево с действительными числами  ||\n"
		<< "|| и упорядочивает последовательность по возрастанию или убыванию      ||\n"
		<< "========================================================================\n\n";
	while (1) {
		cout<<"Выберите, что нужно сделать"
		switch (mmm(kol, menu, max, k))
		{
		case 0: {
			int data;
			cout << Rus("Введите число:");
			cin >> data;
			tr.Push(tr.root, data);
			k = 0; break;
		}
		case 1: {
			if (tr.root == 0)cout << Rus("Дерево пустое");
			else
			{
				cout << Rus("Наше дерево:") << endl;
				tr.Look(tr.root);
			}
			while (!kbhit());
			k = 1; break;
		}
		case 2: {
			if (tr.root == 0)cout << Rus("Дерево пустое");
			else
			{
				int key;
				cout << Rus("Введите искомое число:");
				cin >> key;
				if ((u = tr.Find(tr.root, key)) != 0) {
					cout << Rus("Элементов: ");
					cout << key;
					cout << Rus(" найдено ");
					cout << u->count << Rus(" штук");

				}

				else cout << Rus("Таких элементов нет!");
			}
			while (!kbhit());
			k = 2; break;
		}
		case 3: {
			if (tr.root == 0)cout << Rus("Дерево пустое");
			else {

				cout << Rus("Листья:") << endl;
				tr.PrintLeaves(tr.root);
			}
			while (!kbhit());
			k = 3; break;
		}
		case 4: {
			exit(0);
		}
		}
	}
	return 0;
}
