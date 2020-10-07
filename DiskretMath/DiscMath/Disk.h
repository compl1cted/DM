
#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <windows.h> // Подключена тольк для исправления кодировки в консоли

using namespace std;

//Основные функции
void Unification(vector<string>& array1, vector<string>& array2); // Объединение
void Crossing(vector<string>& array1, vector<string>& array2); // Пересечение
void Difference(vector<string>& array1, vector<string>& array2); // Разность
void SymetricDifference(vector<string>& array1, vector<string>& array2); // Симетрическая разность
void BulenaOfArray(vector<string>& array);
void PowerOFBuleanaOfArray(vector<string>& array); // Мощность булеаны
vector<vector<string>> CartesianProduct(vector<string>& array1, vector<string>& array2); // Декартовое произведние
void Teleports(vector<string>& array1, vector<string>& array2, vector<string>& array3); // Телепорты

//Вспомогательные
void DisplayMatrix(vector<vector<string>>& Matrix, vector<string>& array1, vector<string>& array2);
vector<vector<string>> FillMatrix(vector<vector<string>> &CartesianProduct, vector<vector<string>>& PairArray, vector<string>& array1);
int SelectAPair(vector<vector<string>>& array);
bool IsSameElement(vector<string>& array1, std::string element); // Проверка на одинаковый елемент
bool IsSameElement(vector<vector<string>>& array1, vector<string>& element);
void DisplayAnArray(vector<string>& array); // Вывод массива
void DisplayAnArray(vector<vector<string>>& array); // Вывод двумерного массива
vector<string> ArrayInput();