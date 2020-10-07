#include "DiscMath/Disk.h"

vector<string> u, a, b, c, arr1, arr2, arr3;

vector<string>& ArraySelect();

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
		cout << "Выберите операцию, которую хотите провести над множеством:\n 1. Объединение множеств;\n 2. Пересечение множеств;\n 3. Разность множеств;\n 4. Симметрическая разность множест;\n 5. Инверсия множества\n 6. Буллеана множества\n 7. Мощность булеаны множества\n 8. Декартово произведение\n 9. Телепорты\n";
		int action = 0;
		cin >> action;
		switch (action) {
		case 0:
			cout << "Программа остановлена\n";
			return 0;
		case 1:
			system("cls");
			arr1 = ArraySelect();
			arr2 = ArraySelect();
			Unification(arr1, arr2);
			break;
		case 2:
			system("cls");
			arr1 = ArraySelect();
			arr2 = ArraySelect();
			Crossing(arr1, arr2);
			break;
		case 3:
			system("cls");
			arr1 = ArraySelect();
			arr2 = ArraySelect();
			Difference(arr1, arr2);
			break;
		case 4:
			system("cls");
			SymetricDifference(a, b);
			break;
		case 5:
			system("cls");
			arr1 = ArraySelect();
			Difference(u, arr1);
			break;
		case 6:
			arr1 = ArraySelect();
			BulenaOfArray(arr1);
			break;
		case 7:
			system("cls");
			arr1 = ArraySelect();
			cout << PowerOFBuleanaOfArray(arr1) << endl;
			system("pause");
			break;
		case 8:
			system("cls");
			arr1 = ArraySelect();
			arr2 = ArraySelect();
			CartesianProduct(arr1, arr2);
			system("pause");
			break;
		case 9:
			system("cls");
			Teleports(a, b, c);
			break;
		default:
			cout << "Ошибка ввода\n";
		}
	}
	return 0;
}

vector<string>& ArraySelect() {
	cout << "Выберите множество:\n 0 - Универсум\n 1 - A\n 2 - B\n 3 - C\n";
	while (1) {
		int choose = 0;
		cin >> choose;
		if (choose == 0) {
			return u;
		}
		else if (choose == 1) {
			return a;
		}
		else if (choose == 2) {
			return b;
		}
		else if (choose == 3) {
			return c;
		}
		else {
			cout << "Ошибка ввода\n";
		}
	}
}