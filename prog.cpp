// c++ course [study it well!]...
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <regex> 
#include <unordered_map>
#include<cmath>
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
	reverse(ar.begin(), ar.begin()+x);
	reverse(ar.begin()+x, ar.end());

}

string encrypt(const string s,const string key) {
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
}bool ispal(const string& str) {
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

void replace(string& s) {
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
void draw(int n, int m){
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
	int i = 0; j = 0; while ( i < a.size() && j < b.size()) {
		if (a[i] == b[j]) {
			j++;
		}i++;
	}return  j == b.size();// true... ||  false...
}


int fibanocci(int nom) { // fibonacci way
	if (nom == 1)return 0;
	if (nom == 2)return 1; return fibanocci(n-1)+ fibanocci(n-2);
}
int add(int a, int b) {
	return a + b;
}
void print(string name) {
	cout << " hello world!" << "HI"<< name<< endl;
}
int main() {
	int n; cin >> n;
	int year = n / 365;
	n %= 365;
	int month = n / 30;

	n %= 30;
	int day = n;
	cout << '\n' << year << ' ' << "years" << endl;
	cout << month << ' ' << "months" << endl;
	cout << day << ' ' << "days" << endl;
	cout << "\n################\n";
	// prime number check
	cout << "enter the number: ";
	int x;
	cin >> x;
	int cnt = 0;
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			cnt++;
		}
	}
	cnt == 0 ? cout << "number is prime" : cout << "number isnot prime";
	cout << "\n################\n";
	int r;
	cin >> r;
	for (int k = 0; k <= r; k++) {
		for (int j = 0; j <= k; j++) {
			cout << '*';
		}cout << "\n";
	}
	cout << "\n################\n";
	cout << "enter size of array : ";
	int num;
	cin >> num;
	cout << "enter array : ";
	int arr[10000];

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}	double min = 1e9, index = 0;
	for (int i = 0; i < num; i++) {
		if (arr[i] < min) {
			min = arr[i];
			index = i;
		}
	}
	cout << min << ' ' << index;
	cout << "\n################\n";
	cout << "enter the character : ";
	char ar[100];
	int ni; cin >> ni;
	cin >> ar;
	for (int i = 0; i < ni; i++) {
		if (ar[i] >= 'A' && ar[i] <= 'Z') {
			ar[i] += 32;
		}
		else if (ar[i] >= 'a' && ar[i] <= 'z') {
			ar[i] -= 32;
		}
		else {
			ar[i] = ar[i];
		}
	}
	cout << ar;
	cout << "\n################\n";
	int sz = 5;
	int a[5] = { -2,8,9,0,5 };
	for (int i = 0; i < (sz - 1); i++) {
		for (int j = 0; j < (sz - i - 1); j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
	cout << "array afer bubble sort:";
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}cout << "\n################\n";
	int m, b, c, d;
	cin >> m >> b >> c >> d;
	long long res = m * b * c * d;
	int last2 = res % 100;
	cout << last2 << endl;
	cout << "\n################\n";
	cout << "enter size of 2d array : ";
	int row, column; cin >> row >> column;
	int array[110][500];
	cout << "enter the array : ";
	for (int k = 0; k < row; k++) {
		for (int j = 0; j < column; j++) {
			cin >> array[k][j];
		}
	}
	for (int k = 0; k < row; k++) {
		for (int j = 0; j < column; j++) {
			cout << array[k][j] << ' ';
		}
		cout << "\n";
	}cout << "\n################\n";
	cout << "enter size of 2d array : ";
	int rw, coln; cin >> rw >> coln;
	int ay[110][500];
	cout << "enter the array : ";
	for (int k = 0; k < rw; k++) {
		for (int j = 0; j < coln; j++) {
			cin >> ay[k][j];
		}
	}
	for (int k = 0; k < rw; k++) {
		int se = 0, so = 0;
		for (int j = 0; j < coln; j++) {
			if (ay[k][j] % 2 == 0) {
				se += ay[k][j];
			}
			else {
				so += ay[k][j];
			}
			cout << "sum even : " << se << ' | ' << "sum odd : " << so << endl;
		}
	}cout << "\n################\n";
	cout << "enter size of array : ";
	int n; cin >> n;
	int arr[100];
	cout << "enter array : ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "enter target : ";
	int tar;
	cin >> tar;
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (right + left) / 2;
		if (tar = arr[mid]) {
			cout << arr[mid];
		}
		else if (arr[mid] > tar) {
			right = mid - 1;
		}
		else if (arr[mid] < tar) {
			left = mid + 1;
		}
	}
	return -1;
	cout << "\n################\n";
	int freq[100] = { 0 };
	cout << "enter size of array : ";
	int n; cin >> n;
	int arr[100];
	cout << "enter array [numbers is limited from 1 to 10]  : ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}	for (int i = 1; i < 10; i++) {
		cout << i << ":" << freq[i] << endl;

	}
	cout << "\n################\n";
	cout << "enter the string:";
	string s; cin >> s;
	int fre[26] = { 0 };
	for (int i = 0; i < s.size(); i++) {
		fre[s[i] - 'a']++;
	}bool val = true;
	for (int i = 0; i < 26; i++) {
		if (fre[i] == 0) {
			val = false;
		}
	}
	(val = true) ? cout << "valid!" : cout << "valid!";
	cout << "\n################\n";
	cout << "enter the string:";
	string s; cin >> s;
	int freq[26] = { 0 };
	for (int i = 0; i < s.size(); i++) {
		freq[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << char(i + 'a') << ' : ' << freq[i] << endl;
	}
	cout << "\n################\n";
	cout << "enter the size of array and the query resprctively :";
	int no, q; cin >> no >> q;
	int arr[1000];
	cout << "enter the array:";
	for (int i = 0; i < no; i++) {
		arr[i] += arr[i - 1];
	} // => add each element to its before element.
	/*
	we use 1 index array
	*/
	cout << "enter left and right to sum:";
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		cout << arr[r] - arr[l - 1];
	}
	cout << "\n################\n";
	string str = "Egyptian Olympaid International";

	str.pop_back();
	str.push_back('h');
	cout << str.size() << ' ' << str.back() << ' ' << str.front() << ' ' << str.substr(0, 9) << " " << str.erase(3, 6) << '\n';
	string ss;
	getline(cin, ss);
	cout << ss << endl;
	cout << "\n################\n";
	cout << "enter the size of vector:";
	int n; cin >> n;
	vector <int>vec;
	cout << "enter the vector elements:";
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());// => arrange in acending order
	int cou = 1;
	for (int i = 0; i < n; i++) {
		if (vec[i] != cou) {
			break;
		}
		cou++;
	}
	cout << cou << endl;
	cout << "\n################\n";
	cout << "enter 2 numbers :";
	int num1, num2;
	cin >> num1 >> num2;
	cout << "the sum is :" << add(num1, num2) << "\n";
	cout << "\n################\n";
	cout << "enter your name :";
	string name; cin >> name
		;
	print(name);
	cout << "\n################\n";
	stack<char>st;// stack [last in first out]...
	string sr;
	cin >> sr;
	for (int i = 0; i < sr.size(); i++) {
		if (sr[i] == '{') {
			st.push(sr[i]);
		}
		else if (!st.empty() && s[i] == '}' && st.top() == '{') {
			st.pop();
		}
		else {
			st.push('}');
		}
	}
	(st.empty()) ? cout << "valid" : cout << "not valid";
	cout << "\n################\n";
	priority_queue<int> numb; // pr_queue & queue[ first in first out]...
	numb.push(1);
	numb.push(2);
	numb.push(3);
	numb.push(4);
	while (!numb.empty()) {
		cout << numb.top() << endl;
		numb.pop();
	}
	priority_queue<int, vector<int>, greater<int>>pqname; // => arrange in descending order
	cout << "\n################\n";
	vector<pair<string, int>>vp(10);
	cout << "enter your name and mark:";
	for (int i = 0; i < 3; i++) {
		string name;
		cin >> name;
		int mark; cin >> mark;
		vp[i].first = name;
		vp[i].second = mark;
	}for (int i = 0; i < 3; i++) {
		cout << vp[i].first << " " << vp[i].second << endl;
	}cout << "\n################\n";
	cout << "enter size of vector and frequency:";
	int n, k; cin >> n >> k;
	vector<int>v;
	int fr[100];
	for (int i = 0; i < n; i++) {
		fr[v[i]]++;
	}
	priority_queue<pair<int, int>>pq;
	for (int i = 0; i < 100; i++) {
		if (fr[i]) {
			pq.push({ fr[i], i });
		}
	}while (!pq.empty()) {
		cout << pq.top().first << ' ' << pq.top().second << endl;
		pq.pop();
	}

	cout << "\n################\n";
	set<int>myset;// unique and sorted => [set]
	myset.insert(5);
	myset.insert(2);
	myset.insert(4);
	myset.insert(3);
	auto it = myset.begin();
	while (it != myset.end()) {
		cout << *it << ' ';
		it++;
	}cout << "\n################\n";
	set<int>set;
	cout << "enter the size of set : ";
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		set.insert(x);
	}
	cout << set.size() << endl;
	for (auto it = set.begin(); it != set.end(); it++) {
		cout << *it << " ";

	}cout << "\n################\n";
	map <string, int>mp;
	cout << "enter the size of map : ";
	int t; cin >> t;
	cout << "enter the query (1 or 2) and name: ";
	while (t--) {
		int q; cin >> q;
		string nm; cin >> nm;
		cout << "enter the price : ";
		if (q == 1) {
			int price;
			cin >> price;
			mp[nm] += price;
		}
		else {
			cout << mp[nm] << endl;
		}

	}cout << "\n################\n";
	//data types with size{8bit=>byte} ,{kilo byte = 1024 byte},{megabyte=1024 kilobyte},{gegabyte=1024 megabyte},{tetrabyte=1024 gegabyte}
	cout << sizeof(4);
	cout << sizeof(4.7777);
	cout << sizeof(111111111111111);
	cout << sizeof(1.111111111131);
	cout << sizeof(true);
	cout << sizeof("ahmed"); 
	cout << "\n################\n";
	cout << "enter the day from 1 to 7:";
	int day; cin >> day;
	switch (day) {
	case 1:
			cout << "open from 8 to 14"; break;
	case 2:
		cout << "open from 11 to 16";
		break;
	case 3:
		cout << "open from 10 to 18";
		break;
	default:
		cout << "closed"; break;
	}cout << "\n################\n";
	vector<int>v = { 10,20,30,40 };
	vector<int>::iterator it = v.begin();
	auto ite = v.begin()+1;
	cout << "first:" << *it << endl;
	cout << "second:" << *ite << endl;
	cout << "first:" << *v.begin() << endl; cout << "\n################\n";
	int nums[3] = { 1,2,3 };
	int *ptr = nums;
	cout << ptr << "\n";
	cout << *ptr << "\n";
	cout <<nums << "\n";
	cout << &nums[0] << "\n"; cout << nums[0] << "\n"; cout << *nums << "\n"; cout << *(nums + 1) << "\n"; int w = 100;
	void* ptr = &w;
	cout << ptr << endl;
	cout << *(int*)ptr << "\n"; // 100.{by C-style}
	cout << *static_cast<int*>(ptr) << "\n"; // 100.{by modern style}
	cout << "\n################\n";
	cout << "enter the coordinate : ";
	int l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	int inter_l = max(l1, l2);
	int inter_r = min(r1, r2);
	if (inter_l > inter_r) {
		cout << -1 << endl;
	}
	else {
		cout << inter_l <<' '<< inter_r << endl;

	}cout << "\n################\n";
	cout << ceil(6.1);
	cout <<floor(6.8);
	cout << round(6.5);
	cout << "\n################\n";
	cout << "enter the letter:";
		char let;
	cin >> let;
	if (islower(let)) {
		cout << char(toupper(let)) << '\n';
	}
	else {
		cout << char(tolower(let))<< endl;
	}cout << "\n################\n";
	cout << "enter the number of rows:";
	// create a matrix shape
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j && i == n / 2) {
				cout << 'X';
			}
			else if (i == j) {
				cout < "//";
			}
			else if (i + j == n - 1) {
				cout < "/";
			}

			else {
				cout << '*';
			}
			cout << endl;
		
	}
		cout << "\n################\n";
		cout << "enter the number of test cases:";
		int t; cin >> t;

		cout << "enter the number (n) and the sum (s):";
		while (t--) {
			long long n, s;
			cin >> n >> s;
			vector<int> res;
			long long maxsum = n * (n + 1) / 2;
			if (s > maxsum) {
				cout << -1;
				continue;
			}for (int i = n; i > 0; i++) {
				if (s >= i) {
					res.push_back(i);
					s -= i;
				}
				if (s == 0) break;
			}if (s != 0) {
				cout << -1 << endl;
			}
			else {
				for (size_t i = 0; i < res.size(); i++) {
					if (i > 0) cout << " "; cout << res[i];
				}cout << endl;
			}
			cout << "\n################\n";
			cout << "enter the size of array:";
			// check palindrome array
			int n; cin >> n;
			vector <int> arr(n); cout << "enter the array:";
			for (int i = 0; i < n; i++) {
				cin >> arr[i];
			}
			int l = 0; r = n - 1; bool is_pal = true;
			while (l < r) {
				if (arr[l] != arr[r]) {
					is_pal = false; break;

				}
				l++; r--;
			}(is_pal) ? cout << "yes<" << endl; : cout << "no" << endl;
			cout << "\n################\n";
			cout << "enter the number of digits:";
			int n; cin >> n;
			cout << "enter the digits:";
			string digs;
			cin >> digs;
			int s = 0;
			for (char dig : digs) {
				s += dig - '0';
			}
			cout << s<< endl; 
			cout << "\n################\n";
			cout << "enter the size of array:";
			int n; cin >> n; cout << "enter the array:";
			vector<int>a(n); for (int i = 0; i < n; i++) { cin >> a[i]; }// check even numbers
			bool even = true;
			for (int i = 0; i < n; i++) {
				if (a[i] % 2 != 0) {
					even = false;
					break;
				}// calc the max possible operation
				int max = 0;
				if (even) {
					while (true) {
						bool div = false;
						for (int i = 0; i < n; i++) {
							if (a[i] % 2 == 0) {
								a[i] /= 2;
								div = true;
							}
							else {
								even = false; break;
							}
						}
						if (div) {
							max++;
						}
						else { break; }

					}

				}cout << max; cout << "\n################\n";
				cout << "enter the size of array:"; int n; cin >> n;
				cout << fibanocci(n) << endl;
				cout << max; cout << "\n################\n"; const int maxn = 1e7 + 1;
				cout << "enter the size of array:"; int n; cin >> n;
				int freqa[maxn] = { 0 }; int freqb[maxn] = { 0 };
				cout << "enter the array:";
				for (int i = 0; i < n; i++) { int num; cin >> num; freqa[num]++; } // => determine the frequency of array A
				for (int i = 0; i < n; i++) { int num;cin >> num; freqb[num]++; } // => determine the frequency of array B
				bool is_permutation = true;
				for (int i = 0; i < maxn; i++) { // check that b is permutation of a or not
					if (freqa[i] != freqb[i]) {
						is_permutation = false;
						break;
					}
				}
				cout << (is_permutation ? 'yes' : 'no') << endl; cout << "\n################\n";
				cout << "enter the size of 2 arrays:"; int n, m; cin >> n >> m;
				vector <int>a(n); vector <int>b(n); cout << "enter the 2 arrays:"; for (int i = 0; i < n; i++) { cin >> a[i]; }
				for (int i = 0; i < m; i++) { cin >> b[i]; }
				if (issubseq(a, b)) {
					cout << 'yes \n';
				}
				else { cout << 'no \n'; } cout << "\n################\n";
				cout << "enter the size of array and the number of queries :"; int n, q; cin >> n >> q;
				unordered_set<int> nums; cout << "enter the array: ";
				for (int i = 0; i < n; i++) { int num; cin >> num; nums.insert(num); }cout << "enter the queries: ";
				for (int i = 0; i < q; i++) {
					int x; cin >> x;
					if (nums.find(x) != nums.end(x)) {
						cout << "found" << endl;
					}
					else {
						cout << "not found" << endl;
					}
				} cout << "\n################\n"; vector<int> values; cout << "enter the size of array:";
					int n; cin >> n;	 cout << "enter the array:"; for (int i = 0; i < values.size(); i++) { cin >> values[i]; }
				double res = 0;
				for (int i = 0; i < values.size(); i++) {
					res += values[i];
				}cout << res / values.size();
				cout << "\n################\n";
				int num
				string res = "";
				int number; cout << "enter the number:"
				cin>> number;
				for (int i = 0; i < number; i++) {
					res += to_string(i) + "sheep ...";
				}cout << res; 			cout << "\n################\n";	cout << "enter the string A and B :";
	 string a,b; cin >> a >> b;
	 cout << to_string(stoi(a == "" ? "0" : a) + stoi(b == "" ? "0" : b));
	 cout << "\n################\n";	cout << "enter the number :";
	 int num; cin >> num;
	 string res = ""; for (int i = 1; i <= 10; i++) {
		 res += to_string(i) + " * " + to_string(num) + " = " + to_string(i * num);
	 }cout << res; cout << "\n################\n";	 vector<int> values; cout << "enter the size of array:";
	 int n; cin >> n;	 cout << "enter the array:"; for (int i = 0; i < values.size(); i++) { cin >> values[i]; }
	int res = 0;
	sort(values.rbegin(), values.rend());
	if (values.size <= 1) res = 0;

	else {
		for (int i = 0; i < values.size(); i++) {
			res += values[i] - values[i + 1];
		}
	} cout << res;
	cout << "\n################\n";	 vector<string>s; cout << "enter the size of array:";
	int n; cin >> n;	 cout << "enter the array:"; for (int i = 0; i < s.size(); i++) { cin >> s[i]; }

	sort(s.begin(), s.end());
	string res = s.at(0); for (int i = 1; i < res.size(); i += 4) {
		res.insert(i, "***");
	}cout << res; cout << "\n################\n";
	cout << "enter the usernmame: "; string s; cin >> s;
	regex pattern("[hazem100good")
		cout << regex_replace(s, pattern, "!");
	cout << "\n################\n"; cout << "enter the string: "; string s; cin >> s;	 vector<string>v;
	string temp = "";
	for (auto ch : s) {
		if (ch != ' ') {
			temp += ch;

		}
		else {
			v.push_back(temp);
			temp.clear();
		}
	}v.push_back(temp); cout << v;
	cout << "\n################\n"; cout << "enter your dna: "; string s; cin >> s;
	replace(s.begin(), s.end(), "T", "U")
		cout << s;
	cout << "\n################\n"; cout << "enter the number: "; unsigned long a; cin >> a;
	vector<int> result;
	string str = to_string(a);
	for (int i = 0; i < str.length(); i++) {
		result.push_back(str[i] - "0");
		// asci value : 55-48= 7 || 57-48 = 9 
	}cout << result;
	cout << "\n################\n"; cout << "enter the string: "; string s; cin >> s;
	for (int i = 0; i < s.length(); i++) { // check the palindrome...
		if (tolower(s[i]) != tolower(s.size() - 1 - i) {
			cout << false;
		}
		else { cout << true; }
	}cout << "\n################\n"; cout << "enter the string: "; string st; cin >> st;string r ="";
			string temp= "";
		for (int i = 0; i < st.length(); i++) {
			if (st[i] == " ") { r = temp + " " + r };
			else {
			temp+= st[i]; }
		} r = temp + " " + r;
		r.pop_back(); cout << r;
		cout << "\n################\n";	 vector<int> values; cout << "enter the size of array:";
		int n; cin >> n;	 cout << "enter the array:"; for (int i = 0; i < values.size(); i++) { cin >> values[i]; }
		int res = 0; for (int num: values) {
			if (count(values.begin(), values.end(), num) == 1) res += num;
		}cout << res; cout << "\n################\n"; cout << "enter a string: "; 
		string sp; cin >> sp;
		string rs = "";
		for (int i = sp[0]; i <= sp[2]; i++) {
			rs.push_back(char(i));
		}cout << rs; cout << "\n################\n";	 vector<int> values; cout << "enter the size of array:";
		int n; cin >> n;	 cout << "enter the array:"; for (int i = 0; i < values.size(); i++) { cin >> values[i]; }
		int res = 0; for (int i = 0; i < values.size(); i++) {
			int count = 0;
		
			for (int j = 0; j < values.size(); j++) { if (values[i] == valys[j]) count++; }
		
		}if (count > res)res = count;
		cout << "\n################\n";	 vector<int> values; cout << "enter the default number (d):";
		int d; cin >> d;	 cout << "enter the array:"; for (int i = 0; i < values.size(); i++) { cin >> values.at(i); }
		int res = 0; int arcount =values.size(); for (int i = 0; i < values.size(); i++) {
			int index = arcount - 1 - i; if (values[i].size() > index) res += values[i][index];
			else res += d;
			}
		}cout << res; cout << "\n################\n"; cout << " enter a number: "; int n; cin >> n;
		string stng = to_string(n);
		vector<int> res; for (int i = 0; i < stng.size(); i++) {
			for (int j = i + 1; j < string.size(); j++) {
				res.push_back((stng[i] - 48) + (stng[j] - 48)); // to sum it in integers by substracting it by asci value of zero
			}
		}cout << res; cout << "\n################\n"; cout << " enter a string: "; string s; cin >> s;
		string reversed;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] != " ") reversed += s[i];
			if (s[reversed.length()] += " ") reversed += " ";
			cout << reversed;
		} cout << "\n################\n"; cout << " enter a string: "; string s; cin >> s;
		cout << " enter the first and last index: "; int f, l; cin >> f >> l;
		if (l < s.size()) reverse(s.begin() + f, s.begin() + l + 1);// reverse it but not included end
		else reverse(s.bein() + f, s.end());
		cout << s;
			cout << "\n################\n";
			/*
			search binary values for all characters on keyboard
				
			search asci values for all characters on keyboard

			*/
			cout << "\n################\n"; cout << " enter a string: "; string str; cin >> str;
			int result = 0;
			int curr = 0;
			for (char ch : str) {
				if (isdigit(ch)) curr = curr * 10 + (ch - "0"); // curr *10 to shift numbers to opereate with asci values
				// (ch-48) to get number not its asci value
				else {
					result += curr;
					curr = 0;
				}
			}result += curr;
			cout << result;
			cout << "\n################\n"; cout << " enter a string: "; string str; cin >> str; string re;
			for (char current : str) {
				if (re.empty() || current != re.back()) re.push_back();
				else { re.pop_back() };
			}cout << re;
			cout << "\n################\n"; cout << " enter the width and the ratio: "; string w, ratio; cin >>w>> ratio; 
			int i = ratio.find(":"); int wratio = stoi(ratio.substr(0, i)); int hratio = stoi(ratio.substr(i+1));
			int h = (w * hratio) / wratio;
			cout << to_string(w) + "X" + to_string(h);
			cout << "\n################\n"; cout << " enter a string: "; string in; cin >> in;
			int inp = in.size(); int cut = 0;
			if (inp % 2 == 0) { // input is even
				cut = (inp / 2) - 1; // to get the middle
				cout << in.substr(cut, 2);
			}
			else {// input is odd
				cut = (inp -1) / 2; // to get the middle
				cout << in.substr(cut, 1);
			}	cout << "\n################\n";	 vector<int> values; cout << "enter the available (hd) number:";
			int hd; cin >> hd;	int total = 0; int count;  cout << "enter the array:"; for (int i = 0; i < values.size(); i++) { cin >> values.at(i); }
			for (count = 0; count < values.size(); count++) {
				total += values[count];
				if (total > hd) break;
			}cout << count;
			cout << "\n################\n"; cout << " enter a string: "; string ss; cin >> ss; string end; cin >> end;
			if (ss.length() < end.length()) cout << false;
			else {
cout<< ss.compare(ss.length() - end.length(), end.length(), end) == 0; // true [compare ==0]... // s.compare(pos,len, str);
			}cout << "\n################\n";	 vector<int> values; ;
			  cout << "enter the array:"; for (int i = 0; i < values.size(); i++) { cin >> values.at(i); }
				if (values.empty()) cout << {};
				else {
					values.erase(min_element(values.begin(), values.end()));
					cout << values;
				}cout << "\n################\n";	 vector<int> values; ;
				int n = values.size();  cout << "enter the array:"; for (int i = 0; i < values.size(); i++) { cin >> values.at(i); }
				int front = 0; int end = n - 1;
				while (front <= end) {
					cout << values[front++] << " ";
					if (front <= end) cout << values[end--] + " ";
				}cout << endl;
				cout << "\n################\n"; cout << " enter a string: "; string s; cin >> s;
				int num = s.length();
				for (int i = 0; i < (n / 2); i++) {
					int j = n - 1 - i;
					if (s[i] == '?' && s[j] == '?') {
						s[i] = s[j] = 'a';
					else if (s[i] == '?') s[i] = s[j];		else if (s[j] == '?') s[i] = s[j];		else if (s[i] != '?') cout << -1 << endl;
					}
				}// if length is odd , handle middle character
				if (n % 2 == 1 && s[n / 2] == '?') s[n / 2] = 'a';
				 cout << "\n################\n"; cout << " enter the number of elements: ";
				int n; cin >> n; cout << " enter the prev element: ";
				string prev; cin >> prev;
				int gp = 1;// initialize with 1 group for first magnet
				cout << " enter the current elements: ";
				for(int i=1; i<n; i++){
					{
						string cur; cin >> cur;
						if (cur != prev) {
							gp++;
							prev = cur;
						}
					} cout << gp << endl;	cout << s; cout << "\n################\n"; cout << " enter the rows and columns number : ";
					int n, m; cin >> n >> m; draw(n, m);// draw the snake
					 cout << "\n################\n"; cout << " enter the string1 and atring2 : ";
					string s, t; cin >> s >> t; int pos = 0;// liss start at 0 index first stone.
					for (char instr : t) {
						if (s[pos] == instr) {// move to next stone
							pos++;
						}
					}cout << pos + 1 << endl; // 1 based index.
 cout << "\n################\n";	 vector<int> values; cout << "enter the size of array:";
					int n; cin >> n;	 cout << "enter the array:"; for (int i = 0; i < values.size(); i++) { cin >> values[i]; }
					int ser = 0, dima = 0;
					int l = 0; r = n - 1;
					bool ser_turn = true;
					while (l <= r) {
						if (values[l] >= values[r]) {
							if (ser_turn) ser += values[l];
							else dima += values[l];
							left++;
						}
						else {
							if (ser_turn) ser += values[r];
							else dima += values[r];
							r--;
						}
						ser_turn = !ser_turn;
					}cout << ser << " " << dima << endl;
					cout << "\n################\n"; cout << " enter the numbers x,y,z : ";
					intx, y, z; cin >> x >> y >> z;
					int pos[] = { x,y,z };
					sort(pos, pos + 3);
					int mid = pos[1]; // median value...
					int tot = (abs(mid - pos[0]) + abs(mid - pos[1]) + abs(mid - pos[2])); cout << tot;
					cout << "\n################\n"; cout << " enter the numbers of row and column : "; int r, c; cin >> r >> c;
					vector<string> cake(r);
					for (int i = 0; i < r; i++) { cin >> cake[i]; }
					vector<bool> eatr(r, true);		vector<bool> eatc(c, true);
					for (int i = 0; i < r; i++) {
						for (int j = 0; j < c; j++) {
							if (cake[i][j] == "s") eatr[i] = false; eatc[j] = false;
						}
					}int total = 0;
					for (int i = 0; i < r; i++) {// count eatabla cells in rows
						if (eatr[i]) total += c;

					}	for (int j = 0; j < c; j++)// count eatabla cells in rows
					{
						if (eatc[j])
						{
							for (int i = 0; i < r; i++) {// count eatabla cells in rows
								if (!eatr[i]) {
									if (cake[i][j] == '.')total++;
								}

							}

						}

					}cout << total;
					cout << "\n################\n";
					cout << "enter the size of array:";
					int n; cin >> n; cout << "enter the array:";
					vector<int>a(n); for (int i = 0; i < n; i++) { cin >> a[i]; }
					int officers = 0; int crimes = 0;
					for (int i = 0; i < n; i++) {
						if (a[i] == -1) {
							if (officers > 0) officers--;
							else crimes++;

						}
						else {
							officers += a[i];

						}

					}cout << crimes << endl;
					cout << "\n################\n";
					cout << "enter the string:"; string s; cin >> s;// proplem for alphapets rotation for a word
					int rotation = 0;
					char cur = 'a';
					for (char target : s) {
						int clockwise = abs(target - cur);
						int anticlockwise = 26 - clockwise;
						rotation += min(clockwise, anticlockwise);
						cur = target;

					}cout << rotation; cout << "\n################\n";
					cout << "enter the size of array:";
					int n; cin >> n; cout << "enter the array:";
					vector<int>a(n); for (int i = 0; i < n; i++) { cin >> a[i]; }
					int max= a[0];
					int min = a[n - 1];
					int soldiers = 0;
					for (int i = 1; i < n - 1; i++) {// check the unordered number
						if (a[i] > max || a[i] < min) {
							soldiers++;
						}
					}cout << soldiers;
					cout << "\n################\n";
					cout << "enter the size of string:"; int n; cin >> n;
					cout << "enter the string:"; string encoded; cin >> encoded;
					string decoded;
					int mid = n / 2;
					for (char ch : encoded) {
						decoded.insert(decoded.begin() + mid, ch);
						if (n % 2 == 0) mid++:

					}cout << decoded;
					cout << "\n################\n";// مش فاكرها المسالة ديه
					cout << "enter the size of array (n) and (k):"; int n, k; cin >> n>>k;
					int count = 0; unordered_set<char> digits;
					cout << " enter the strings in arrray : "
						for (int i = 0; i < n; i++) {
							string num; cin >> num;
							digits.clear();
							for (char ch; num) {
								digits.insert(ch);
							}
							bool good = true;
							for (char d = '0'; d <= '0' + k; d++) {
								if (digits.find(d) == digits.end())good = false; break;
							}if (good) count++
						}cout << count; cout << "\n################\n";
					cout << "enter the size of string:";int t; cin >> t;
					vector <string>s(t); cout << "enter the string:";
					for (int i = 0; i < t; i++) {
						string st; cin >> st;

						s[i] = check(st);
					}for (const string r : s) {
						cout << r << endl;
					}
					cout << "\n################\n";
					cout << "enter the size of string:";

					; int t; cin >> t;
					vector <string>res; cout << "enter the 2 strings:";
					for (int i = 0; i < t; i++) {
						string s, t;
						cin >> s >> t;
						res.push_back(concate(s, t));

					}for (const string r : res) {
						cout << r << endl;
					}cout << "\n################\n";
					cout << "enter the string:";// check hello substr
					string e; cin>> e
					if (subseq(e)) cout<<"true" << endl;
					else cout<<"false" << endl;
					cout << "\n################\n";
					cout << "enter the string:";
					string s; getline(cin, s);
					reverse(s);
					cout << s<< endl; cout << "\n################\n";
					cout << "enter the string:"; string s; getline(cin, s)
						// find ? and = character in url

					size_t posq = s.find('?');
					size_t poseq= s.find('=');
					for (int i = 0; i < 5; i++) {// extract and print each parameter
						size_t pos_ampersand = s.find('&', poseq + 1);
						strin parameter = s.substr(poseq + 1, pos_ampersand - poseq - 1);
						size_t pos_nexteq = s.find('=', pos_ampersand + 1);
						string val = s.substr(pos_ampersand + 1, pos_nexteq - pos_ampersand - 1);
						cout << parameter << ": " << value << endl;
						poseq = pos_nexteq;
					} cout << "\n################\n";
					cout << "enter the string:"; string s; cin >> s;
					cout << egypt(s) << endl; cout << "\n################\n";
					cout << "enter the string:"; string s; cin >> s;
					relace(s);
					cout << s << endl; cout << "\n################\n";
					cout << "enter the string:"; string s; cin >> s;
				
					cout << smallest(s) << endl;
					cout << "\n################\n";
					cout << "enter the query: (1 or 2) ";// encrypt and decrypt problem
					int q; cin >> q;
					cout << "enter the string:";
					string s; cin >> s;
					string key = "PgEfTYaWGHjDAmxQqFLBownyUKZXbvzIdshurMiLNSVOtec#@_!=.+-*/";
					if (q == 1) cout << encrypt(s, key)<< endl;
					else if (q == 2) cout << decrypt(s, key) << endl;
					cout << "\n################\n";
					cout << "enter the  number n ";
					int n; cin >> n;
					if (odd(n) && ispal(tobin(n)))cout << "yes"<< endl;
					else cout << 'no'<< endl; cout << "\n################\n";
					cout << "enter the size of array (n) and x";
					int n, x; cin >> n >> x;
					vectror<int>v(n);
					for (int i = 0; i < n; i++) { cin >> v[i]; }
					shiftarr(v, x); // shift zeroes to the right
					for (int i = 0; i < n; i++) { cout << v[i] << " "; }
					cout << endl; cout << "\n################\n";
					cout << "enter the size of array (n) and x and y [you want to reverse x and y]";

					int n, x,y; cin >> n >> x>>y;
					x -= 1;
					y -= 1;// adjust for 0-based index
					vector<vector<int>>matrix(n, vector<int>(n));
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++)
						{
							cin >> matrix[i][j];
						}
					}
					swapr(matrix, x, y); swapcol(matrix, x, y); for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++)
						{
							cout << matrix[i][j] << " ";
						}cout << endl;
					}cout << endl; cout << "\n################\n";
					cout << "enter the number:";
					long long n; cin >> n;
					if (n > 0 && (n & (n - 1)) == 0) {
						cout << "yes" << endl;
					}
					else cout << "no" << endl;
					cout << endl; cout << "\n################\n";
					cout << "enter the 2 mumbers A , B:";
					unsigned long long a, b; cin >> a >> b;
					unsigned long long gcd_value = gcd(a, b);
					unsigned long long lcm_value = lcm(a,b);
					cout << gcd_value << " " << lcm_value << endl;
					cout << endl; cout << "\n################\n";
					cout << "enter the number:";
				int n; cin >> n;// pascal triangle problem
				vector<vector<int>>triangle(n, vector<int>(n, 0));// forming a vector 2d
				for (int i = 0; i < n; i++) {// fill first col by 1
					triangle[i][0] = 1;
				}for (int i = 1; i < n; i++) {// fill the triangle
					for (int j = 1; j < = 1; j++) {
						triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
					}
				}for (int i = 0; i < n; i++) {
					for (int j = 0; j < = i; j++) {// print the pascal triangle

						cout << triangle[i][j] << " ";
					} cout << endl;
				}cout << endl; cout << "\n################\n";
				cout << "enter the number of query: ";
				int t; cin >> t;
			if (t == 1) {
				cout << "enter the number n and base x: ";
				
				string n;
				int x;
				cin >> n >>x;
				//convert from base x to decimal
				int decimal = stoi(n, nullptr, x);
				cout << decimal << endl;

			}
			else if(t==2){
				cout << "enter the number n and base x: ";
				int n, x;
				cin >> n >> x;
				// convert from decimal to base x
				string res = "";
				while (n > 0) {

					int dig = n % x;
					if (dig < 10) {
						res = to_string(dig) + res;
					}
					else {
						res = char('A', +dig - 10) + res;

					}n / +x;
				}		cout << res<< endl;
			
			}cout << endl; cout << "\n################\n";
			cout << "enter the number : "; int n; cin >> n;
			// calc factorial
			long long fact = 1;
			for (int i = 2; i <= n; i++){
				fact *= i;
			
			}

			// count dig in factorial
			int numdig = countdig(fact);
			cout << "number of digits: " << n << "! is " << numdig << endl;
			cout << "\n################\n";
			cout << "enter the 4 cooordinates points respectivley (x and y) : ";
			int x1, y1, x2,y2,x3, y3, x4, y4;
			cin>>x1>> y1>> x2>> y2>>x3>> y3>> x4>> y4;
			// find min and max (x and y) coordinates of the rectangle
			int minx = min(x1, min(x2, min(x3, x4)));
			int maxx = max(x1, max(x2,max(x3, x4)));
			int miny = min(y1, min(y2, min(y3,y4)));	int maxy = max(y1, max(y2, max(y3, y4)));
			cout << "enter the number of test cases: ";	
			int n; cin >> n; cout << "enter the cooordinates points respectivley (x and y) to check it : "; for (int i = 0; i < n; i++) {
				int xi, yi; cin >> xi, yi;
				// check if points belongs to the rectangle
				if (xi >= minx && xi <= maxx && yi >= miny && yi <= maxy) cout << "yes" << endl;
				else cout << "no" << endl;
			}	cout << "\n################\n";
			cout << "enter the number of test cases: ";
			int n; cin >> n; cout << "enter the numbers:";
			for(int t = 1; t <= n, t++) {
				int no; cin >> no;
				int maxx1 = -1e5; , maxy1 = -1e5, minx2 = 1e5, miny2 = 1e5;
				cout << "enter the cooordinates points respectivley (x and y) to check it : ";
				for (int i = 0; i < no; i++) {
					int x1, y1, x2, y2;cin>> x1>> y1>> x2>> y2;
					maxx1 = max(maxx1, x1);	minx2 = min(minxx2, x2);	maxy1 = max(maxy1, y1);	miny2 = min(mainy2, y2);

				}
				int width = minx2 - maxx1;
				int height = miny2 - maxy1;
				int area = max(0, width) * max(0, height);
				cout << "case #" << t << ": " << area << endl;

			}cout << "\n################\n";// matrix multiplication problem
			cout << "enter the number of  rows and cols of A: ";
			int ra, ca;
			cin >> ra >> ca; cout << "enter the rows and cols:"
			vector<vector<int>>a(ra, vector<int>(ca)); for (int i = 0; i < ra; i++) {
				for (int j = 0; j <ca; j++) {
					cin >> a[i][j];
				}
			}cout << "enter the number of rows and cols of B: ";
			int rb, cb;
			cin >> rb >> cb;
			cout<< "enter the rows and cols:"
			vector<vector<int>>b(rb, vector<int>(cb)); for (int i = 0; i < rb; i++) {
				for (int j = 0; j < cb; j++) {
					cin >> b[i][j];
				}
			}vector<vector<int>>res(ra, vector<int>(cb));// perform multiply of matrix
			for (int i = 0; i < ra; i++) {
				for (int j = 0; j < cb; j++) {
					for (int k = 0; k < ca; k++) {
						res[i][j] += a[i][k] * b[i][k];
					}
				}
			}for (int i = 0; i < ra; i++) {
				for (int j = 0; j < cb; j++) {
					cout << res[i][j] << " ";
				}cout << endl;
			}cout << "\n################\n";
			cout << "enter number of test cases:";
			;
			int t; cin >> t; cout << "enter numbers:"; while (t--) {
				int n; cin >> n;
				if (n == "0") cout << "0";
				else dectobin(n);
				cout << endl;
			} cout << "\n################\n";
			cout << "enter the height of pyramid :"; int n; cin >> n;// draw a pyramid
			printrow(0, n);
			cout << "\n################\n";
			cout << "enter the number of elements (n) and the number of lat elements to sum (m) :";
			int  n, m; cin>>N>>M:
			int a[n];
			cout << "enter the numbers :";
			for (int i = 0; i < n; i++) {
				cin >> a[i];

			}long long res = sumoflastm(a, n - m, m);// calc the sum of last m elements
			cout << res << endl; cout << "\n################\n";
			cout << "enter the number :";
			unsigned long long n; cin >> n;
			int res = log2(n);
			cout << res<< endl; cout << "\n################\n";// knapsack

			cout << "enter the number and the capacity:";
			int n, cap; cin >> n >> cap;
			vector<int> w(n), v(n);
			cout << "enter the weights numbers and its values:";
			for (int i = 0; i < n; i++) {
				cin >> w[i] >> v[i];
			}cout << knapsack(w, v, n, cap);
			cout << "\n################\n";

			cout << "enter the size of array and the target:";
			int n, tar; cin >> n >> tar;
			cout<<"enter he numbers"
			vector<int> arr(n); for (int i = 0; i < n; i++) {
				cin >> arr[i];
			}if (exp(arr, n, tar, 0, 0))cout << "yes\n";
			else cout << "no\n"; cout << "\n################\n";

			cout << "enter the size of array:";
			int n; cin >> n;
			cout << "enter he numbers"
				vector<int> arr(n); for (int i = 0; i < n; i++) {
				cin >> arr[i];
			}
			maxrange(arr, n, 0, INT_MIN);
			cout << "\n################\n";

			cout << "enter the number of test cases:";
			int t; cin >> t;
			cout<< "enter the number:"
			while (t--) {
				long long n; cin >> n;
				cout << canreach(n) << endl;
			}
			cout << "\n################\n";

			cout << "enter n & r:"; int n, r;
			cin >> n >> r;
			cout << nCr(n, r) << endl;

	return 0;
	/*
	the END
	*/
}