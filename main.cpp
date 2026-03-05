#include <iostream>

#include <clocale> // Стандартна бібліотека для мовних налаштувань

using namespace std;
const int M = 50,
	N = 50;
// Прототипи функцій
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
// Головна функція з меню
int main() {
	setlocale(LC_ALL, "");
	int num; // Змінна для вибору пункту меню
	do {
		cout << "---------------------------------\n";
		cout << "1 - Matrix 24 (Максимуми по стовпцях)\n";
		cout << "2 - Matrix 53 (Заміна стовпців)\n";
		cout << "0 - Вихід\n";
		cout << "Ваш вибір -> ";
		cin >> num;
		// Виклик відповідної функції залежно від вибору
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
	} while(num != 0); // Цикл працює, поки не введено 0
	return 0;
}
// Функція введення розмірів та елементів матриці з перевіркою
void get_matr(int in_matr[M][N], int & in_m, int & in_n) {
	// Перевірка даних на коректність (від 2 до 50)
	do {
		cout << "Рядки (2-50): ";
		cin >> in_m;
		cout << "Стовпці (2-50): ";
		cin >> in_n;
	} while(in_n < 2 || in_n > N || in_m < 2 || in_m > M);
	cout << "Введіть " << in_m * in_n << " елементів:\n";
	// Цикл введення елементів
	for(int i = 0; i < in_m; i++) {
		for(int j = 0; j < in_n; j++) {
			cin >> in_matr[i][j];
			// Ігноруємо коми та пробіли, якщо користувач вводить в один рядок
			while(cin.peek() == ',' || cin.peek() == ' ') cin.ignore();
		}
	}
	// Очищення буфера вводу від зайвих символів
	while(cin.peek() != '\n' && cin.peek() != EOF) cin.ignore();
}
// Функція виведення матриці на екран
void show_matr(const int out_matr[M][N],
	const int m,
		const int n,
			const char * title) {
	cout << title;
	// Прохід по всіх елементах та їх виведення через табуляцію
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) cout << out_matr[i][j] << "\t";
		cout << endl;
	}
}
// Завдання 1 (Matrix 24): Пошук максимального елемента у кожному стовпці
void print_max_cols(const int matr[M][N],
	const int m,
		const int n) {
	cout << "Максимуми по стовпцях:\n";
	// Зовнішній цикл по стовпцях (j)
	for(int j = 0; j < n; j++) {
		int mx = matr[0][j]; // Приймаємо перший елемент стовпця за максимум
		// Внутрішній цикл по рядках (i)
		for(int i = 1; i < m; i++)
			if(matr[i][j] > mx) mx = matr[i][j]; // Оновлюємо максимум
		cout << mx << "\t"; // Виводимо знайдений максимум
	}
	cout << endl;
}
// Завдання 2 (Matrix 53): Перетворення матриці (обмін стовпців)
void change_matr(int matr[M][N],
	const int m,
		const int n) {
	// Шукаємо з кінця (справа наліво)
	for(int j = n - 1; j >= 0; j--) {
		bool pos = true; // Прапорець: чи всі елементи стовпця додатні
		for(int i = 0; i < m; i++) {
			if(matr[i][j] <= 0) { // Якщо знайдено недодатний елемент
				pos = false;
				break; // Переходимо до наступного стовпця
			}
		}
		// Якщо знайдено стовпець, де всі елементи додатні
		if(pos) {
			// Міняємо місцями знайдений стовпець (j) і перший стовпець (0)
			for(int i = 0; i < m; i++) {
				int temp = matr[i][0];
				matr[i][0] = matr[i][j];
				matr[i][j] = temp;
			}
			break; // Робимо заміну тільки для одного (останнього) стовпця і виходимо
		}
	}
}
void task1() {
	int matr[M][N], row, col;
	get_matr(matr, row, col); // Введення
	show_matr(matr, row, col); // Виведення початкової
	print_max_cols(matr, row, col); // Аналіз і виведення результату
}
void task2() {
	int matr[M][N], row, col;
	get_matr(matr, row, col); // Введення
	show_matr(matr, row, col, "Початкова матриця:\n"); // Виведення початкової
	change_matr(matr, row, col); // Перетворення
	show_matr(matr, row, col, "Перероблена матриця:\n"); // Виведення переробленої
}