#include "DiscMath/Disk.h"

vector<string> u, a, b, c;

int main() {
	SetConsoleCP(1251);			// ����������� ������
	SetConsoleOutputCP(1251);	// ��������� � �������
	cout << "������� �������� ����������\n";
	u = ArrayInput();
	cout << "������� �������� ��������� A\n";
	a = ArrayInput();
	cout << "������� �������� ��������� B\n";
	b = ArrayInput();
	cout << "������� �������� ��������� C\n";
	c = ArrayInput();
	while (1) {
		system("cls");
		cout << "�������� ��������, ������� ������ �������� ��� ����������:\n 1. ����������� �������� A � B;\n 2. ����������� ������� A � B;\n 3. �������� ������� A � B;\n 4. �������� ������� B � A;\n 5. �������������� �������� ������� A � B;\n 6. �������� ��������� A\n 7. �������� ��������� A\n 8. �������� ������� ��������� A\n 9. �������� ������� ��������� B\n 10. ��������� ������������\n 11. ���������� ������\n";
		int action = 0;
		cin >> action;
		switch (action) {
		case 0:
			cout << "��������� �����������\n";
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
			cout << "������ �����\n";
		}
	}
	return 0;
}