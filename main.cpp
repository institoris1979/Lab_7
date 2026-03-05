#include <iostream>

using namespace std;
const int M = 20,
	N = 20;
void task1();
void task2();
void get_matr(int in_matr[M][N], int & in_m, int & in_n);
void show_matr(const int out_matr[M][N],
	const int m,
		const int n,
			const char * title = "Матриця:\n");
void print_max_cols(const int matr[M][N],
	const int m,
		const int n);
void change_matr(int matr[M][N],
	const int m,
		const int n);
int main() {
	setlocale(LC_ALL, "");
	int num;
	do {
		cout << "---------------------------------\n";
		cout << "1 - Matrix 24\n";
		cout << "2 - Matrix 53\n";
		cout << "0 - Вихід\n";
		cout << "Ваш вибір -> ";
		cin >> num;
		switch(num) {
			case 0:
				cout << "Вихід...\n";
				break;
			case 1:
				task1();
				break;
			case 2:
				task2();
				break;
			default:
				cout << "Невірний номер!\n";
		}
	} while(num != 0);
}
void get_matr(int in_matr[M][N], int & in_m, int & in_n) {
	do {
		cout << "Рядки (2-20): ";
		cin >> in_m;
		cout << "Стовпці (2-20): ";
		cin >> in_n;
	} while(in_n < 2 || in_n > N || in_m < 2 || in_m > M);
	cout << "Введіть " << in_m * in_n << " елементів:\n";
	for(int i = 0; i < in_m; i++) {
		for(int j = 0; j < in_n; j++) {
			cin >> in_matr[i][j];
			// Ігноруємо коми та пробіли, якщо введення йде в рядок
			while(cin.peek() == ',' || cin.peek() == ' ') cin.ignore();
		}
	}
	// Очищаємо буфер від сміття до кінця рядка
	while(cin.peek() != '\n' && cin.peek() != EOF) cin.ignore();
}
void show_matr(const int out_matr[M][N],
	const int m,
		const int n,
			const char * title) {
	cout << title;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) cout << out_matr[i][j] << "\t";
		cout << endl;
	}
}
void print_max_cols(const int matr[M][N],
	const int m,
		const int n) {
	cout << "Максимуми по стовпцях:\n";
	for(int j = 0; j < n; j++) {
		int mx = matr[0][j];
		for(int i = 1; i < m; i++)
			if(matr[i][j] > mx) mx = matr[i][j];
		cout << mx << "\t";
	}
	cout << endl;
}
void change_matr(int matr[M][N],
	const int m,
		const int n) {
	for(int j = n - 1; j >= 0; j--) {
		bool pos = true;
		for(int i = 0; i < m; i++)
			if(matr[i][j] <= 0) pos = false;
		if(pos) {
			for(int i = 0; i < m; i++) {
				int temp = matr[i][0];
				matr[i][0] = matr[i][j];
				matr[i][j] = temp;
			}
			break;
		}
	}
}
void task1() {
	int matr[M][N], row, col;
	get_matr(matr, row, col);
	show_matr(matr, row, col);
	print_max_cols(matr, row, col);
}
void task2() {
	int matr[M][N], row, col;
	get_matr(matr, row, col);
	show_matr(matr, row, col);
	change_matr(matr, row, col);
	show_matr(matr, row, col, "Перероблена матриця:\n");
}