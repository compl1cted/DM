#include "set.h"

namespace set_methods {
    vector<string> getUnifiedSetOf(vector<string>& array1, vector<string>& array2) {
        vector<string> unitedArray;
        for (const auto & i : array1) {
            if (!isSameElement(unitedArray, i)) {
                unitedArray.push_back(i);
            }
        }

        for(const auto & i : array2) {
            if (!isSameElement(unitedArray, i)) {
                unitedArray.push_back(i);
            }
        }
        return unitedArray;
    }

    vector<string> getCrossedSetOf(vector<string>& array1, vector<string>& array2) {
        vector<string> crossingArray;
        for (const auto & i : array2) {
            if (isSameElement(array1, i)) {
                crossingArray.push_back(i);
            }
        }
        return crossingArray;
    }

    vector<string> getDifferenceSetOf(vector<string>& array1, vector<string>& array2) {
        vector<string> differenceOfArrays;
        for (const auto & i : array1) {
            if (!isSameElement(array2, i)) {
                differenceOfArrays.push_back(i);
            }
        }
        return differenceOfArrays;
    }

    vector<string> getSymmetricDifferenceSetOf(vector<string>& array1, vector<string>& array2) {
        vector<string> symmetricDiffArray;
        for (const auto & i : array1) {
            if (!isSameElement(array2, i)) {
                symmetricDiffArray.push_back(i);
            }
        }
        for (const auto & i : array2) {
            if (!isSameElement(array1, i)) {
                symmetricDiffArray.push_back(i);
            }
        }
        return symmetricDiffArray;
    }

    int getPowerSetSize(vector<string>& array) {
        return (int)pow(2, array.size());
    }

    vector<vector<string>> getPowerSet(vector<string>& set) {
        int p = getPowerSetSize(set);
        vector<vector<string>> powerSet = vector<vector<string>>();
        for (int i = 0; i < set.size(); i ++) {
            powerSet.emplace_back();
            for (int j = 0; j < set.size(); j++) {
                if (i & (1<<j)) {
                    powerSet.back().emplace_back(set[j]);
                }
            }
        }

        return powerSet;
    }

    vector<vector<string>> getCartesianProduct(vector<string>& array1, vector<string>& array2) {
        vector<vector<string>> cartesianProductArray;
        for (auto & i : array1) {
            for (auto & j : array2) {
                cartesianProductArray.push_back({i, j });
            }
        }
        return cartesianProductArray;
    }

    void teleports(vector<string>& array1, vector<string>& array2, vector<string>& array3) {
        int choose = 0;
        vector<vector<string>> R, S;

        vector<vector<string>> cartesianProduct1 = getCartesianProduct(array1, array2);
        vector<vector<string>> cartesianProduct2 = getCartesianProduct(array2, array3);

        cout << "Choose 5 pairs from the first cartesian set\n";
        for (int i = 0; i < 5; i++) {
            choose = selectPair(cartesianProduct1);
            R.push_back(cartesianProduct1[choose]);
        }

        cout << "Choose 5 pairs from the second cartesian set\n";
        for (int i = 0; i < 5; i++) {
            choose = selectPair(cartesianProduct2);
            S.push_back(cartesianProduct2[choose]);
        }

        displayArray(R);
        displayArray(S);

        vector<vector<string>> Matrix1 = fillMatrix(cartesianProduct1, R, array2);
        vector<vector<string>> Matrix2 = fillMatrix(cartesianProduct2, S, array3);

        displayMatrix(Matrix1, array1, array2);
        displayMatrix(Matrix2, array2, array3);

        //Creating and filling third matrix with zeroes
        vector<vector<string>> matrix3;
        for (int i = 0; i < Matrix2[0].size(); i++) {
            matrix3.emplace_back();
            for (int j = 0; j < Matrix1.size(); j++) {
                matrix3[i].emplace_back("0");
            }
        }

        for (int i = 0; i < Matrix1.size(); i++) {
            for (int j = 0; j < Matrix1[i].size(); j++) {
                if (Matrix1[i][j] == "1") {
                    for (int z = 0; z < Matrix2[0].size(); z++) {
                        if (Matrix2[j][z] == "1") {
                            matrix3[z][i] = "1";
                        }
                    }
                }
            }
        }
        displayMatrix(matrix3, array3, array1);

        cout << "Domain R:";
        displayArray(array1);
        cout << "Domain S:";
        displayArray(array2);

        cout << "Domain R:";
        displayArray(array2);
        cout << "Domain S:";
        displayArray(array3);
    }
}

void displayMatrix(vector<vector<string>>& Matrix, vector<string>& array1, vector<string>& array2) {
	for (const auto & i : array2) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < Matrix.size(); i++) {
		for (const auto & j : Matrix[i]) {
			cout << j << " ";
		}
		cout << array1[i] << endl;
	}
	cout << endl;
}

void displayPowerSet(vector<vector<string>>& powerSet) {
    for (int i = 0; i < powerSet.size(); i++) {
        cout << "{";
        for (int j = 0; j < powerSet[i].size(); j++) {
            if (i & (1<<j)) {
                cout << powerSet[i][j] << " ";
            }
        }
        cout << "}";
    }
}

vector<vector<string>> fillMatrix(vector<vector<string>>& CartesianProduct, vector<vector<string>>& PairArray, vector<string> &array1) {
	int count = 0;
	vector<vector<string>> Matrix;
	Matrix.emplace_back();
	for (auto & i : CartesianProduct) {
		if (count == array1.size()) {
			Matrix.emplace_back();
			count = 0;
		}
        Matrix.back().emplace_back(isSameElement(PairArray, i) ? "1" : " 0");
		count++;
	}
	return Matrix;
}

int selectPair(vector<vector<string>>& array) {
	int choose = 0;
	while (true) {
		cout << "Choose\n";
		cin >> choose;
		if (choose < 0 || choose >= array.size()) {
			cout << "Input error\n";
		}
		else {
			break;
		}
	}
	return choose;
}

bool isSameElement(vector<string>& array1, const string& element) {
	for (const auto & i : array1) {
		if (i == element) {
			return true;
		}
	}
	return false;
}

bool isSameElement(vector<vector<string>>& array1, vector<string>& element) {
	for (const auto & i : array1) {
		if (i == element) {
			return true;
		}
	}
	return false;
}

void displayArray(vector<string>& array) {
	cout << "{";
	for (const auto & i : array) {
		cout << i << ";";
	}
	cout << "}\n";
}

void displayArray(vector<vector<string>>& array) {
	cout << "{";
	for (int i = 0; i < array.size(); i++) {
		cout << i << " - {";
		for (const auto & j : array[i]) {
			cout << j << ";";
		}
		cout << "},\n";
	}
	cout << "}\n";
}

vector<string> arrayInput() {
	vector<string> array;
	string element;
	cout << "Enter ! to stop input\n";
	while (true) {
		std::cout << "Enter element:\n";
		std::cin >> element;
		if (element == "!") {
			break;
		}
		array.push_back(element);
	}
	return array;
}
