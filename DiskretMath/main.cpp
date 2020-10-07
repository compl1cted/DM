#include "DiscMath/Disk.h"

vector<string> u, a, b, c;

int main() {
	SetConsoleCP(1251);			// Исправление ошибки
	SetConsoleOutputCP(1251);	// кодировки в консоли
	cout << "Введите елементы универсума\n";
	u = ArrayInput();
	cout << "Введите елементы множества A\n";
	a = ArrayInput();
	cout << "Введите елементы множества B\n";
	b = ArrayInput();
	cout << "Введите елементы множества C\n";
	c = ArrayInput();
	while (1) {
		system("cls");
		cout << "Выберите операцию, которую хотите провести над множеством:\n 1. Объединение множеств A и B;\n 2. Пересечение множест A и B;\n 3. Разность множест A и B;\n 4. Разность множест B и A;\n 5. Симметрическая разность множест A и B;\n 6. Инверсия множества A\n 7. Инверсия множества A\n 8. Мощность булеаны множества A\n 9. Мощность булеаны множества B\n 10. Декартово произведение\n 11. Построение матриц\n";
		int action = 0;
		cin >> action;
		switch (action) {
		case 0:
			cout << "Программа остановлена\n";
			return 0;
		case 1:
			system("cls");
			Unification(a, b);
			break;
		case 2:
			system("cls");
			Crossing(a, b);
			break;
		case 3:
			system("cls");
			Difference(a, b);
			break;
		case 4:
			system("cls");
			Difference(b, a);
			break;
		case 5:
			system("cls");
			SymetricDifference(a, b);
			break;
		case 6:
			system("cls");
			Difference(u, a);
			break;
		case 7:
			system("cls");
			Difference(u, b);
			break;
		case 8:
			system("cls");
			PowerOFBuleanaOfArray(a);
			break;
		case 9:
			system("cls");
			PowerOFBuleanaOfArray(b);
			break;
		case 10:
			system("cls");
			CartesianProduct(a, b);
			system("pause");
			break;
		case 11:
			system("cls");
			Teleports(a, b, c);
		default:
			cout << "Ошибка ввода\n";
		}
	}
	return 0;
}