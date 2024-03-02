#include "set.h"

using namespace set_methods;

vector<string> u, a, b, c, arr1, arr2, result;
vector<vector<string>> powerSet, ct;

vector<string>& ArraySelect();

int main() {
    a.emplace_back("1");
    a.emplace_back("2");
    a.emplace_back("3");
    a.emplace_back("4");

    b.emplace_back("4");
    b.emplace_back("5");
    b.emplace_back("6");
    b.emplace_back("7");

    c.emplace_back("1");
    c.emplace_back("9");
    c.emplace_back("8");
    c.emplace_back("5");
//	cout << "Fill the universal set\n";
//	u = arrayInput();
//	cout << "Fill the set A\n";
//	a = arrayInput();
//	cout << "Fill the set B\n";
//	b = arrayInput();
//	cout << "Fill the set C\n";
//	c = arrayInput();
	while (true) {
		cout << "Choose an method for following set:\n 1. getUnifiedSetOf;\n 2. getCrossedSetOf;\n 3. Difference;\n 4. Symmetric getDifferenceSetOf;\n 5. Difference with universal set \n 6. Get Power Set\n 7. Get Power Set Size\n 8. Get Cartesian Product\n 9. Teleports\n";
		int action = 0;
		cin >> action;
        system("cls");
		switch (action) {
		case 0:
			cout << "Exiting...\n";
			return 0;
		case 1:
			arr1 = ArraySelect();
			arr2 = ArraySelect();
			result = getUnifiedSetOf(arr1, arr2);
			break;
		case 2:
			arr1 = ArraySelect();
			arr2 = ArraySelect();
            result = getCrossedSetOf(arr1, arr2);
			break;
		case 3:
			arr1 = ArraySelect();
			arr2 = ArraySelect();
            result = getDifferenceSetOf(arr1, arr2);
			break;
		case 4:
            result = getSymmetricDifferenceSetOf(a, b);
			break;
		case 5:
			arr1 = ArraySelect();
            result = getDifferenceSetOf(u, arr1);
			break;
		case 6:
			arr1 = ArraySelect();
            powerSet = getPowerSet(arr1);
            displayPowerSet(powerSet);
			break;
		case 7:
			arr1 = ArraySelect();
			cout << getPowerSetSize(arr1) << endl;
			break;
		case 8:
			arr1 = ArraySelect();
			arr2 = ArraySelect();
            ct = getCartesianProduct(arr1, arr2);
            displayArray(ct);
			break;
		case 9:
            teleports(a, b, c);
			break;
		default:
			cout << "Invalid input\n";
		}

        displayArray(result);
        cin.get();
	}
}

vector<string>& ArraySelect() {
	cout << "Select set:\n 0 - Universal Set\n 1 - A\n 2 - B\n 3 - C\n";
	while (true) {
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
			cout << "Invalid Input\n";
		}
	}
}