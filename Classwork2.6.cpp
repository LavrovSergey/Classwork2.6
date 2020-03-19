#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "windows.h"
using namespace std;

struct Node {
	char eng[50];
	char ukr[50];
	Node* left;
	Node* right;
};


struct Tree {
	Node* root = NULL;
	Node* creat_leaf(char e[], char u[]) {
		Node* cur = new Node;
		strcpy(cur->eng,e);
		strcpy(cur->ukr, u);
		cur->left = NULL;
		cur->right = NULL;
		return cur;
	}
	void recursia1(char e[], char u[], Node* node) {
		if (root == NULL)
		{
			root = creat_leaf(e, u);
		}
		else if (e[0] <= node->eng[0])
		{
			if (node->left != NULL)
			{
				recursia1(e, u, node->left);
			}
			else 
			{
				node->left = creat_leaf(e, u);
			}
		}
		else if (e[0] > node->eng[0])
		{
			if (node->right != NULL)
			{
				recursia1(e, u, node->right);
			}
			else
			{
				node->right = creat_leaf(e, u);
			}
		}
	}
	void add_leaf() {
		char e[50], u[50];
		cout << "Введите английское слово" << endl;
		cin >> e;
		cout << "Введите украинский перевод" << endl;
		cin >> u;
		recursia1(e, u, root);
	}
	void recursia2(Node* node)
	{
		if (root != NULL)
		{
			if (node->left != NULL)
			{
				recursia2(node->left);
			}
			cout << node->eng << "-" << node->ukr << endl;
			if (node->right != NULL)
			{
				recursia2(node->right);
			}
			
		}
		else(cout << "Пусто" << endl);
	}

	void PrintInOrder() {
		recursia2(root);
		system("pause");
	}
	int recursia3(char e[], Node*node, int count)
	{
		if (node != NULL)
		{
			if (!strcmp(node->eng, e))
			{
				cout << node->ukr<< endl;
				count++;
			}
			if (strcmp(node->eng, e)|| !strcmp(node->eng, e))
			{
				if (e[0] <= node->eng[0])
				{
					recursia3(e, node->left, count);
				}
				else if (e[0] > node->eng[0])
				{
					recursia3(e, node->right, count);
				}
			}
		}
		else { return count; }
	}
	void find() {
		int count=0;
		char e[50];
		cout << "Введите слово, перевод которого хотите узнать" << endl;
		cin >> e;
		count=recursia3(e, root, count);
		if (count == 0) { cout << "Такого нема"; }
		system("pause");
	}
};
int menu_start() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 6) % 6;
		if (key == 0) cout << "-> Добавить слово" << endl;
		else  cout << "   Добавить слово" << endl;
		if (key == 1) cout << "-> Вывести словарь" << endl;
		else  cout << "   Вывести словарь" << endl;
		if (key == 2) cout << "-> Найти перевод слова" << endl;
		else  cout << "   Найти перевод слова" << endl;
		if (key == 3) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int main(bool isRunning)
{
	Tree tree;
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu_start();
		switch (answer)
		{
		case 0:tree.add_leaf(); break;
		case 1:tree.PrintInOrder(); break;
		case 2:tree.find(); break;
		case 3: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}
	return 0;
}