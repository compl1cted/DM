#include "Disk.h"

void Unification(vector<string>& array1, vector<string>& array2) {
	vector<string> United_Array;
	for (int i = 0; i < array1.size(); i++) {
		if (!IsSameElement(United_Array, array1[i])) {
			United_Array.push_back(array1[i]);
		}
	}
	for (int i = 0; i < array2.size(); i++) {
		if (!IsSameElement(United_Array, array2[i])) {
			United_Array.push_back(array2[i]);
		}
	}
	DisplayAnArray(United_Array);
	system("pause");
}

void Crossing(vector<string>& array1, vector<string>& array2) {
	vector<string> Crossing_Array;
	for (int i = 0; i < array2.size(); i++) {
		if (IsSameElement(array1, array2[i])) {
			Crossing_Array.push_back(array2[i]);
		}
	}
	DisplayAnArray(Crossing_Array);
	system("pause");
}

void Difference(vector<string>& array1, vector<string>& array2) {
	vector<string> DifferenceOfArrays;
	for (int i = 0; i < array1.size(); i++) {
		if (!IsSameElement(array2, array1[i])) {
			DifferenceOfArrays.push_back(array1[i]);
		}
	}
	DisplayAnArray(DifferenceOfArrays);
	system("pause");
}

void SymetricDifference(vector<string>& array1, vector<string>& array2) {
	vector<string> Symetric_Diff_Array;
	for (int i = 0; i < array1.size(); i++) {
		if (!IsSameElement(array2, array1[i])) {
			Symetric_Diff_Array.push_back(array1[i]);
		}
	}
	for (int i = 0; i < array2.size(); i++) {
		if (!IsSameElement(array1, array2[i])) {
			Symetric_Diff_Array.push_back(array2[i]);
		}
	}
	DisplayAnArray(Symetric_Diff_Array);
	system("pause");
}

void BulenaOfArray(vector<string>& array) {
	int BuleanaSize = PowerOFBuleanaOfArray(array);
	for (int i = 0; i < BuleanaSize; i ++) {
		cout << "{";
		for (int j = 0; j < array.size(); j++) {
			if (i & (1<<j)) {
				cout << array[j] << " ";
			}
		}
		cout << "}";
	}
	system("pause");
}

int PowerOFBuleanaOfArray(vector<string>& array) {
	int POB = pow(2, array.size());
	return POB;
}

vector<vector<string>> CartesianProduct(vector<string>& array1, vector<string>& array2) {
	vector<vector<string>> CartesianProductArray;
	for (int i = 0; i < array1.size(); i++) {
		for (int j = 0; j < array2.size(); j++) {
			CartesianProductArray.push_back({ array1[i], array2[j] });
		}
	}
	DisplayAnArray(CartesianProductArray);
	return CartesianProductArray;
}

void Teleports(vector<string>& array1, vector<string>& array2, vector<string>& array3) {
	int choose = 0;
	vector<vector<string>> R, S;

	vector<vector<string>> CartesianProduct1 = CartesianProduct(array1, array2);

	cout << "Выберите 5 пар из первого декартового множества\n";
	for (int i = 0; i < 5; i++) {
		choose = SelectAPair(CartesianProduct1);
		R.push_back(CartesianProduct1[choose]);
	}
	vector<vector<string>> CartesianProduct2 = CartesianProduct(array2, array3);

	cout << "Выберите 5 пар из второго декартового множества\n";
	for (int i = 0; i < 5; i++) {
		choose = SelectAPair(CartesianProduct2);
		S.push_back(CartesianProduct2[choose]);
	}
	//system("cls");
	DisplayAnArray(R);
	DisplayAnArray(S);

	vector<vector<string>> Matrix1 = FillMatrix(CartesianProduct1, R, array2);
	vector<vector<string>> Matrix2 = FillMatrix(CartesianProduct2, S, array3);

	DisplayMatrix(Matrix1, array1, array2);
	DisplayMatrix(Matrix2, array2, array3);

	//Создание третьей матрицы  и заполнение ее нулями
	vector<vector<string>> Matrix3;
	for (int i = 0; i < Matrix2[0].size(); i++) {
		Matrix3.push_back(vector<string>());
		for (int j = 0; j < Matrix1.size(); j++) {
			Matrix3[i].push_back("0");
		}
	}

	for (int i = 0; i < Matrix1.size(); i++) {
		for (int j = 0; j < Matrix1[i].size(); j++) {
			if (Matrix1[i][j] == "1") {
				for (int z = 0; z < Matrix2[0].size(); z++) {
					if (Matrix2[j][z] == "1") {
						Matrix3[z][i] = "1";
					}
				}
			}
		}
	}
	DisplayMatrix(Matrix3, array3, array1);

	cout << "Область определения R:";
	DisplayAnArray(array1);
	cout << "Область определения S:";
	DisplayAnArray(array2);

	cout << "Область значения R:";
	DisplayAnArray(array2); 
	cout << "Область значения S:";
	DisplayAnArray(array3);

	system("pause");
}

void DisplayMatrix(vector<vector<string>>& Matrix, vector<string>& array1, vector<string>& array2) {
	for (int i = 0; i < array2.size(); i++) {
		cout << array2[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < Matrix.size(); i++) {
		for (int j = 0; j < Matrix[i].size(); j++) {
			cout << Matrix[i][j] << " ";
		}
		cout << array1[i] << endl;
	}
	cout << endl;
}

vector<vector<string>> FillMatrix(vector<vector<string>>& CartesianProduct, vector<vector<string>>& PairArray, vector<string> &array1) {
	int count = 0;
	vector<vector<string>> Matrix;
	Matrix.push_back(vector<string>());
	for (int i = 0; i < CartesianProduct.size(); i++) {
		if (count == array1.size()) {
			Matrix.push_back(vector<string>());
			count = 0;
		}
		if (IsSameElement(PairArray, CartesianProduct[i])) {
			Matrix.back().push_back("1");
		}
		else {
			Matrix.back().push_back("0");
		}
		count++;
	}
	return Matrix;
}

int SelectAPair(vector<vector<string>>& array) {
	int choose = 0;
	while (1) {
		cout << "Выберите\n";
		cin >> choose;
		if (choose < 0 || choose >= array.size()) {
			cout << "Ошибка ввода\n";
		}
		else {
			break;
		}
	}
	return choose;
}

bool IsSameElement(vector<string>& array1, string element) {
	for (int i = 0; i < array1.size(); i++) {
		if (array1[i] == element) {
			return true;
		}
	}
	return false;
}

bool IsSameElement(vector<vector<string>>& array1, vector<string>& element) {
	for (int i = 0; i < array1.size(); i++) {
		if (array1[i] == element) {
			return true;
		}
	}
	return false;
}

void DisplayAnArray(vector<string>& array) {
	cout << "{";
	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << ";";
	}
	cout << "}\n";
}

void DisplayAnArray(vector<vector<string>>& array) {
	cout << "{";
	for (int i = 0; i < array.size(); i++) {
		cout << i << " - {";
		for (int j = 0; j < array[i].size(); j++) {
			cout << array[i][j] << ";";
		}
		cout << "},\n";
	}
	cout << "}\n";
}
vector<string> ArrayInput() {
	vector<string> array;
	string element;
	cout << "Введите ! для окончания ввода\n";
	while (1) {
		std::cout << "Введите элемент:\n";
		std::cin >> element;
		if (element == "!") {
			break;
		}
		array.push_back(element);
	}
	return array;
}
