#include <vector>
#include <iostream>

using namespace std;

int char_to_int(char digit) {
	return  (int) digit -  (int) '0';
}

int max_(int n1, int n2) {
	if (n2 > n1)
	{
		return n2;
	}
	return n1;
}

int get_max(vector<string> brojevi, int index) {
	if (brojevi.empty())
	{
		return 0;
	}
	else {
		int broj = char_to_int(brojevi[0][index]);
		if (index == 0)
		{
			brojevi.erase(brojevi.begin());
			return broj + get_max(brojevi, index + 1);
		}
		else if (index >= brojevi[0].size() - 1) {
			brojevi.erase(brojevi.begin());
			return broj + get_max(brojevi, index - 1);
		}
		else {
			brojevi.erase(brojevi.begin());
			return broj + max_(get_max(brojevi, index + 1), get_max(brojevi, index - 1));
		}
	}
}

int main(void) {
	int broj_rijeci;
	vector<string> rijeci = {};
	scanf_s("%d", &broj_rijeci);

	for (int i = 0; i < broj_rijeci; i++)
	{
		string rijec;
		cin >> rijec;
		rijeci.push_back(rijec);
	}

	int max_zbroj = 0;

	for (int i = 0; i < rijeci[0].size(); i++)
	{
		int zbroj = get_max(rijeci, i);
		if (zbroj > max_zbroj)
		{
			max_zbroj = zbroj;
		}
	}
	
	cout << max_zbroj;
}