#pragma once
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

namespace set_methods {
    vector<string> getUnifiedSetOf(vector<string>& array1, vector<string>& array2);
    vector<string> getCrossedSetOf(vector<string>& array1, vector<string>& array2);
    vector<string> getDifferenceSetOf(vector<string>& array1, vector<string>& array2);
    vector<string> getSymmetricDifferenceSetOf(vector<string>& array1, vector<string>& array2);
    int getPowerSetSize(vector<string>& array);
    vector<vector<string>> getPowerSet(vector<string>& set);
    vector<vector<string>> getCartesianProduct(vector<string>& array1, vector<string>& array2); // Cartesian product
    void teleports(vector<string>& array1, vector<string>& array2, vector<string>& array3); // teleports
}

void displayMatrix(vector<vector<string>>& matrix, vector<string>& array1, vector<string>& array2);
void displayPowerSet(vector<vector<string>>& powerSet);
vector<vector<string>> fillMatrix(vector<vector<string>> &cartesianProduct, vector<vector<string>>& pairArray, vector<string>& array1);
int selectPair(vector<vector<string>>& array);
bool isSameElement(vector<string>& array1, const std::string& element);
bool isSameElement(vector<vector<string>>& array1, vector<string>& element);
void displayArray(vector<string>& array);
void displayArray(vector<vector<string>>& array);
//vector<string> arrayInput();