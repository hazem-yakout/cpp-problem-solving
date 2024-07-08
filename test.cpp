// c++ course [study it well!]...
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
string canreach(long long n) {
	if (n == 1)return"yes";
	else if (n < 1) return "no";
	if (n % 10 == 0 && canreach(n / 10) == "yes")	return "yes";
	if (n % 20 == 0 && canreach(n / 20) == "yes")	return "yes";
	return "no";

}
int nCr(int n, int r) {
	if (r == 0 || n == 0) {
		return 1;
	}
	return nCr(n - 1, r - 1) + nCr(n - 1, r);
}


void maxrange(const vector<int>a, int n, int i, int maxsofar) {
	if (i == n) {
		cout << maxsofar << " "; return;

	}
	maxsofar = max(maxsofar, a[i]);
	cout << maxsofar << " ";
	maxrange(a, n, i + 1, maxsofar);
}
bool exp(vector<int>arr, int n, int tar, int sum, int index) {
	{
		// if sum  = target and we have processed all numbers

		if (index == n) return sum == tar;
		//recursivley explore two possibles: add next number or subtract it...
		return exp(arr, n, tar, sum + arr[index], index + 1) || exp(arr, n, tar, sum - arr[index], index + 1);

	}
	int knapsack(vector<int>w, vector<int>v, int n, int capacity) {
		if (n == 0 || capacity == 0) return 0;
		// if weight is more twn capacity then it cannot be included
		if (w[n - 1] > capacity) return knapsack(w, v, n - 1, capacity);
		//  return max of 2 cases
		// [1] nth item included 
		// [2] not included
		return max(values[n - 1] + knapsack(w, v, n - 1, capacity - w[n - 1]), knapsack(w, v, n - 1, capacity));

	}
	int log2(unsigned long long n) {
		// base case: if n is less than 2 then log2 =0
		if (n < 2) return 0;
		return 1 + log2(n / 2);

	}
	long long sumoflastm(int arr[], int index, int m) {
		if (m == 0)return 0;// best case : if m = 0
		return arr[index] + sumoflastm(arr, index + 1, m - 1);


	}
	void printrow(int r, int n) {// print a single row for a pyramid
		if (r >= n) return;
		for (int i = 0; i < n - r; i++) {// print leading spaces
			cout << " ";
		}for (int i = 0; i < 2 * r + 1; i++) {// print leading spaces
			cout << "*";
		}
		cout << endl;
		// recursive call to print next row
		printrow(r + !, n);

	}
	void dectobin(int n) {
		if (n == 0)return;
		dectobin(n / 2);// recurive call
		cout << n % 2;

	}
	int countdig(int num) {

		return (int)log10(num) + 1;// count digits of number
	}
	unsigned long long gcd(unsigned long long a, unsigned long long b)// getting greatest common divisor factor by using eclidean algorithms
	{
		while (b != 0) {
			unsigned long long temp = b;
			b = a % b;
			a = temp;

		}return a;
	}unsigned long long lcm(unsigned long long a, unsigned long long b, unsigned long long gcd_value)// getting lowest common multiplication factor by using relation between gcd and lcm
	{


		return(a / gcd_value) * b;
	}
	void swapr(vector<vector<int>> matrix, int x, int y) {
		swap(matrix[x], matrix[y]);
	}void(vector<vector<int>> matrix, int x, int y) {
		for (inrt i = 0; i < matrix.size(); i++) {
			swap(matrix[i][x], matrix[i][y]);
		}
	}
	void shiftarr(vector<int>ar, int x) {
		int n = ar.size();
		x = x % n;// reduce number of shifts to min == value
		if (x == 0)return;
		reverse(ar.begin(), ar.end());
		reverse(ar.begin(), ar.begin() + x);
		reverse(ar.begin() + x, ar.end());

	}

	string encrypt(const string s, const string key) {
		unordered_map<char, char>enc; for (int i = 0; i < key.size(); i++) {
			enc["abcdefghijklmnopqrstuvwxyzABCDEFGKLMNOPQRSTUVWXYZ0123456789"[i]] = key[i];

		}
		string encrypted = "";
		for (char c : s) {
			encrypted += enc.count(c) ? enc[c] : c;

		}return encrypted;
	}string decrypt(const string s, const string key) {
		unordered_map<char, char>dec; for (int i = 0; i < key.size(); i++) {
			dec[key[i]] = "abcdefghijklmnopqrstuvwxyzABCDEFGKLMNOPQRSTUVWXYZ0123456789"[i];


		}
		string decrypted = "";
		for (char c : s) {
			decrypted += dec.count(c) ? dec[c] : c;

		}return decrypted;
	}
	bool odd(int n) { return n % 2 != 0; }
	string tobin(int n) {
		string bin = "";
		while (n > 0) {
			bin = (n % 2 == 0 ? '0' : '1') + bin;
			n /= 2;
		}return bin;
	}bool ispal(const string & str) {
		int len = str.length();
		for (int i = 0; i < len / 2; i++) {
			if (str[i] != str[len - i - 1])retutn false;
		}
		return true;

	}
	string smallest(const string s) {
		string smallest = s;
		for (int i = 1; i < s.size(); i++) {
			string f = s.substr(0, i);
			string sec = s.substr(i);
			sort(f.begin(), f.end());	sort(sec.begin(), sec.end());
			string conc = f + sec;
			if (conc < smallest) {
				smallest = conc;
			}

		}return smallest;


	}

	void replace(string & s) {
		size_t pos = 0;
		while ((pos = s.find("EGYPT", pos)) != string::npos) {
			s.replace(pos, 5, " ");
		}
	}
	int egypt(string s) {
		unordered_map <char, int>ch;
		for (char c : s) {
			ch[toupper(c)]++;// convert ch to upper case
		}int coumt = 0;
		if (ch['E'] >= 1 && ch['G'] >= 1 && ch['Y'] >= 1 && ch['P'] >= 1 && ch['T'] >= 1) {
			count = min({ ch['E']  , ch['G'], ch['Y'] ,ch['P'] ,ch['T'] });
			return count;
		}
	}

}
void reverse(string s) {
	int start = 0; int n = s.size();
	for (int i = 0; i <= n; i++) {
		if (i == n || s[i] == ' ')// reverse word from stat to i-1
		{
			int end = i - 1;
			while (start < end) {
				swap(s[start], s[end]);
				start++;
				end--;
			}
			start = i + 1;// move to next word

		}
	}


}

string check(const string st) {
	for (size_t i = 0; i < st.length() - 2; i++) {
		if ((s[i] == '0' && s[i + 1] == '1' && s[i + 2] == '0') || (s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '0'))
			return "good";

	}return "bad";
}
bool subseq(string str) {
	string tar = "hello";
	int targetindex = 0;
	for (char c : str) {
		if (c == tar[targetindex]) { targetindex++; if (targetindex == 5)return true; }

	}return false;

}
string concate(string s, string t) {
	string res;
	while (i < s.size() && j < t.size()) {//merge strings alternately
		res += s[i++]; res += t[j++];
	}// append the remaning part
	while (i < s.size()) {
		res += s[i++];
	}while (j < t.size()) {
		res += t[j++];
	}
	return res;
}
void draw(int n, int m) {
	for (int i = 0; i < n; i++) {
		string row(m, "."); // strat row with dots .
		if (i % 2 == 0) { // fill entire row with #
			row = string(m, '#')
		}
		else if ((i / 2) % 2 == 0) { //. for odd rows in o-index array < fill rightmost cell > .
			row[m - 1] = '#';

		}
		else {//. for odd rows in o-index array < fill leftmost cell > .
			row[0] = '#';
		}
		cout << row << endl;
	}
}
bool issubseq(vector <int>& a, vector<int>& b) {
	int i = 0; j = 0; while (i < a.size() && j < b.size()) {
		if (a[i] == b[j]) {
			j++;
		}i++;
	}return  j == b.size();// true... ||  false...
}


int fibanocci(int nom) { // fibonacci way
	if (nom == 1)return 0;
	if (nom == 2)return 1; return fibanocci(n - 1) + fibanocci(n - 2);
}
int add(int a, int b) {
	return a + b;
}
void print(string name) {
	cout << " hello world!" << "HI" << name << endl;
}
int main() {
	cout << "\n################\n";

	cout << "enter n & r:"; int n, r;
	cin >> n >> r;
	cout << nCr(n, r) << endl;
	
}
