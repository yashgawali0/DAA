#include <iostream>
#include <string>
using namespace std;

bool check_two_strings(string str1, string str2)
{
	bool solution[str1.length() + 1][str2.length() + 1];
	for (int i = 0; i <= str1.length(); i++) {
		for (int j = 0; j <= str2.length(); j++) {
			solution[i][j] = false;
		}
	}
	solution[0][0] = true;

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j <= str2.length(); j++) {

			if (solution[i][j]) {

				// if upper_case(s1[i])==s2[j]
				if (j < str2.length() && 
					(toupper(str1[i]) == str2[j]))
					solution[i + 1][j + 1] = true;

				// if not upper then deletion is possible
				if (!isupper(str1[i]))
					solution[i + 1][j] = true;
			}
		}
	}

	return (solution[str1.length()][str2.length()]);
}

int main()
{
	if (check_two_strings("daBd","ABC"))
		cout << "YES";
	else
		cout << "NO";
    cout<<endl;
	return 0;
}
