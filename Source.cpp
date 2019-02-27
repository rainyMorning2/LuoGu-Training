#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<set>
#include<stack>
#include<algorithm>
#include<list>
#include<string.h>
using namespace std;


int main() {
	
	return 0;
}

void addE(int* number, int* grade, vector<int>* out, int index) {

	bool flag = true;

	if (out->size() == 0) {
		out->push_back(index);
	}
	else {

		vector<int>::iterator it;
		for (it = out->begin(); it != out->end(); it++) {
			if (grade[index] == grade[*it]) {

				if (number[index] < number[*it]) {
					out->insert(it, index);
					flag = false;
					break;
				}

			}
			else if (grade[index] > grade[*it]) {
				out->insert(it, index);
				flag = false;
				break;
			}
		}


		if (flag) {
			out->push_back(index);
		}
	}

}

void P1068() {


	int m, n;
	cin >> n >> m;
	int num = m*1.5;

	int* number = new int[n];
	int* grade = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> number[i] >> grade[i];
	}

	vector<int> out;
	for (int i = 0; i < n; i++) {
		addE(number, grade, &out, i);
	}

	int k = 1;
	while (grade[out[num - 1]] == grade[out[num - 1 + k]]) {
		k++;
	}

	cout << grade[out[num - 1]] << " " << num + k - 1 << endl;
	for (int i = 0; i<num + k - 1; i++) {
		cout << number[out[i]] << " " << grade[out[i]] << endl;
	}

}


void P1781() {
	int n;
	cin >> n;
	char num[21][100];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int max = 0;
	vector<int> index;
	for (int i = 0; i < n; i++) {
		if (strlen(num[i])>max) {
			max = strlen(num[i]);
			index.clear();
			index.push_back(i);
		}
		else if (strlen(num[i]) == max) {
			index.push_back(i);
		}

	}
	if (index.size() == 1) {
		cout << index[0] + 1 << endl << num[index[0]] << endl;
	}
	else {

		int k = 0;

		bool flag = true;
		int o = 0;

		while (flag) {

			char maxx = num[index[0]][k];
			for (int i = 1; i < index.size(); i++) {

				if (num[index[i]][k] > maxx) {
					//		cout << maxx << "  " << num[index[i]][k] << endl;
					maxx = num[index[i]][k];
					o = index[i];
					flag = false;
				}
				else if (num[index[i]][k] < maxx) {
					swap(index[index.size() - 1], index[i]);
					index.pop_back();
					i--;
				}
			}
			k++;

		}

		cout << o + 1 << endl << num[o] << endl;
	}
}
void P1031() {
	int N;
	cin >> N;
	int num[101];
	int sum = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		sum += num[i];
	}
	int avg = sum / N;

	for (int i = 0; i < N; i++) {
		if (num[i] == avg) {
			continue;
		}
		else if (num[i] < avg) {
			num[i + 1] -= (avg - num[i]);
			count++;
		}
		else if (num[i] > avg) {
			num[i + 1] += (num[i] - avg);
			count++;
		}
	}

	cout << count << endl;

}
int cut(int begin, int end, int num[]) {
	static int count = 0;
	int sum1 = 0, sum2 = 0;
	int a = 0, b = 0;

	int j = begin;
	while (num[j] == 0) {
		j++;
	}

	for (int i = j; i < end; i++) {
		sum1 += num[i];
		count++;
		if (sum1 == 0) {
			a = i + 1;
			count--;
			break;
		}
	}

	int k = end - 1;
	while (num[k] == 0) {
		k--;
	}

	for (int i = k; i > a; i--) {
		sum2 += num[i];
		count++;

		if (sum2 == 0) {
			b = i - 1;
			count--;
			break;
		}
	}

	if (b <= a) {
		return count;
	}
	else {
		cut(a, b, num);
	}

}

void P1042() {
	char str[10000];
	scanf("%[^'E']", str);

	int i = 0;
	int a = 0, b = 0;
	while (str[i] != '\0') {

		switch (str[i]) {

		case 'W':
			a++;
			break;
		case 'L':
			b++;
			break;
		default:
			break;

		}
		if ((a >= 11 || b >= 11) && (abs(a - b) >= 2)) {
			cout << a << ":" << b << endl;
			a = 0;
			b = 0;
		}
		i++;
	}
	cout << a << ":" << b << endl;
	cout << endl;
	i = 0;
	a = 0;
	b = 0;
	while (str[i] != '\0') {

		switch (str[i]) {

		case 'W':
			a++;
			break;
		case 'L':
			b++;
			break;
		default:
			break;

		}
		if ((a >= 21 || b >= 21) && (abs(a - b) >= 2)) {
			cout << a << ":" << b << endl;
			a = 0;
			b = 0;
		}
		i++;
	}
	cout << a << ":" << b << endl;
}
int hasNext(int *max, int K, int x, int y) {

	int a = K - (abs(x - max[1])) - (abs(y - max[2])) - max[1] - 1;

	if (a >= 0) {
		return K - (abs(x - max[1])) - (abs(y - max[2]));
	}
	else {
		return -1;
	}

}

void P1086() {
	int M, N, K;
	cin >> M >> N >> K;
	int peanuts[21][21] = { 0 };
	int count = 0;
	int x = 0, y = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> peanuts[i][j];
		}
	}
	int max[3] = { 0 };

	while (true) {

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (peanuts[i][j] > max[0]) {
					max[0] = peanuts[i][j];
					max[1] = i + 1;
					max[2] = j + 1;
					//		cout << "max is " << i+1 <<" "<< j+1 << endl;
				}
			}
		}
		if (count == 0) {
			K += max[2];
		}

		K = hasNext(max, K, x, y);
		if (K != -1) {
			count += max[0];
			K--;
			max[0] = 0;
			peanuts[max[1] - 1][max[2] - 1] = 0;
			x = max[1];
			y = max[2];
		}
		else {
			break;
		}
		//	cout << "count is " << count << endl;
		//	cout << "K is " << K << endl;
	}
	cout << count << endl;

}

void P1067() {
	int n;
	cin >> n;
	int num[101];
	for (int i = 0; i < n + 1; i++) {
		cin >> num[i];
	}
	bool flag = true;
	for (int i = 0; i < n - 1; i++) {

		if (flag) {

			if (num[i] == 0) {
				continue;
			}


			if (num[i] == 1) {
				printf("x^%d", n - i);
				flag = false;
				continue;
			}
			else if (num[i] == -1) {
				printf("-x^%d", n - i);
				flag = false;
				continue;
			}
			else {
				printf("%dx^%d", num[i], n - i);
				flag = false;
				continue;
			}


		}
		else {

			if (num[i] == 0) {
				continue;
			}

			if (num[i] > 0) {
				if (num[i] == 1) {
					printf("+x^%d", n - i);
				}
				else {
					printf("+%dx^%d", num[i], n - i);
				}

			}
			else {
				if (num[i] == -1) {
					printf("-x^%d", n - i);
				}
				else {
					printf("%dx^%d", num[i], n - i);
				}
			}
		}
	}

	if (flag) {
		if (num[n - 1] == 1) {
			printf("x");
		}
		else if (num[n - 1] = -1) {
			printf("-x");
		}
		else {
			printf("%dx", num[n - 1]);
		}

	}
	else {
		if (num[n - 1] > 0) {
			if (num[n - 1] == 1) {
				printf("+x");
			}
			else {
				printf("+%dx", num[n - 1]);
			}
		}
		else if (num[n - 1] < 0) {
			if (num[n - 1] == -1) {
				printf("-x");
			}
			else {
				printf("%dx", num[n - 1]);
			}

		}
	}


	if (flag) {
		if (num[n] != 0) {
			printf("%d\n", num[n]);
		}
		else {
			printf("\n");
		}
	}
	else {
		if (num[n] > 0) {
			printf("+%d\n", num[n]);
		}
		else if (num[n]<0) {
			printf("%d\n", num[n]);
		}
		else {
			printf("\n");
		}
	}


}

void P1540() {
	int M, N;
	cin >> M >> N;
	int word[1000];
	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}
	list<int> l;
	int count = 0;
	list<int>::iterator iter;

	for (int i = 0; i < N; i++) {
		iter = std::find(l.begin(), l.end(), word[i]);
		if (iter == l.end()) {
			l.push_back(word[i]);
			count++;
			if (l.size()>M) {
				l.pop_front();
			}
		}
	}
	cout << count << endl;
}
void P1328() {

	int N, NA, NB;
	cin >> N >> NA >> NB;
	int a[201];
	int b[201];
	for (int i = 0; i < NA; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < NB; i++) {
		cin >> b[i];
	}
	int isWin[5][5] = {
		0,-1, 1, 1,-1,
		1, 0,-1, 1,-1,
		-1, 1, 0,-1, 1,
		-1,-1, 1, 0, 1,
		1, 1,-1,-1, 0
	};
	int c = 0, d = 0;
	for (int i = 0; i < N; i++) {

		if (isWin[a[i%NA]][b[i%NB]]>0) {
			c++;
		}
		else if (isWin[a[i%NA]][b[i%NB]]<0) {
			d++;
		}

	}

	cout << c << " " << d << endl;
}

bool judge(int num[], double A, double B, double C) {

	int a = num[0] * 100 + num[1] * 10 + num[2];
	int b = (int)a*(1.0*B / A);
	int c = (int)a*(1.0*C / A);
	bool visited[10] = { true };
	visited[num[0]] = true;
	visited[num[1]] = true;
	visited[num[2]] = true;
	int x[6] = { b / 100 ,b / 10 % 10 ,b % 10, c / 100 ,c / 10 % 10 ,c % 10 };
	for (int i = 0; i < 6; i++) {
		if (visited[x[i]]) {
			return false;
		}
		else {
			visited[x[i]] = true;
		}
	}
	return true;
}

int dfs(int now[], bool visited[], int A, int B, int C, int time, int start) {

	static int count = 0;
	static bool flag = false;
	if (flag) {
		return count;
	}

	if (time == 3) {

		if (judge(now, A, B, C)) {
			int a = now[0] * 100 + now[1] * 10 + now[2];
			int b = (int)a*(1.0*B / A);
			int c = (int)a*(1.0*C / A);
			cout << a << " " << b << " " << c << endl;
			count++;
		}

		visited[now[2]] = false;
		dfs(now, visited, A, B, C, time - 1, now[2] + 1);
		visited[now[1]] = false;
		dfs(now, visited, A, B, C, time - 2, now[1] + 1);
		visited[now[0]] = false;
		dfs(now, visited, A, B, C, time - 3, now[0] + 1);

	}

	for (int i = start; i < 10; i++) {

		if (visited[i] != true) {
			now[time] = i;
			visited[i] = true;
			dfs(now, visited, A, B, C, time + 1, 1);
		}

	}

	if (now[0] * 100 + now[1] * 10 + now[2] > (1000 / ((double)C / A))) {
		flag = true;
		return count;
	}

	return count;
}
void P1618() {

	bool visited[10] = { true };
	int A, B, C;
	cin >> A >> B >> C;
	int now[3] = { 0,0,0 };
	int a = dfs(now, visited, A, B, C, 0, 1);
	if (a == 0) {
		cout << "No!!!" << endl;
	}
}

void P1428() {
	int n;
	int nums[101];
	int result[101] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (nums[j] < nums[i]) {
				result[i]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
	cout << endl;
}

void P1427() {
	int nums[100];
	int i = 0;
	while (true) {
		cin >> nums[i];
		if (nums[i] == 0) {
			break;
		}
		i++;
	}
	for (int j = i - 1; j >= 0; j--) {
		cout << nums[j] << " ";
	}
	cout << endl;
}

void P1046() {
	int apples[10];
	int n;
	for (int i = 0; i < 10; i++) {
		cin >> apples[i];
	}
	cin >> n;
	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (n + 30 >= apples[i]) {
			count++;
		}
	}
	cout << count << endl;
}

void P1085() {
	int data[7][2] = { 0 };
	int degree[7] = { 0 };
	for (int i = 0; i < 7; i++) {
		cin >> data[i][0] >> data[i][1];
		degree[i] = data[i][0] + data[i][1] - 8;
	}
	int max = 0;
	int day = 0;
	for (int i = 0; i < 7; i++) {

		if (degree[i] > max) {
			max = degree[i];
			day = i + 1;
		}
	}
	cout << day << endl;
}
void P1909() {
	int n;
	cin >> n;
	int a[3];
	int b[3];
	for (int i = 0; i < 3; i++) {
		cin >> a[i] >> b[i];
	}

	int money[3] = { 0 };
	for (int j = 0; j < 3; j++) {
		int sum = 0;
		for (int i = 0; sum < n; i++) {
			sum += a[j];
			money[j] += b[j];
		}
	}

	int min = 999999999;
	for (int i = 0; i < 3; i++) {
		min = money[i] < min ? money[i] : min;
	}
	cout << min << endl;
}

int w(long long a, long long b, long long c, int cal[21][21][21]) {


	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20, cal);
	}
	else if (a < b && b < c) {

		if (cal[a][b][c] == 0) {
			cal[a][b][c] = w(a, b, c - 1, cal) + w(a, b - 1, c - 1, cal) - w(a, b - 1, c, cal);
		}
		return cal[a][b][c];

	}
	else {

		if (cal[a][b][c] == 0) {
			cal[a][b][c] = w(a - 1, b, c, cal) + w(a - 1, b - 1, c, cal) + w(a - 1, b, c - 1, cal) - w(a - 1, b - 1, c - 1, cal);
		}

		return cal[a][b][c];
	}
}

void P1464() {
	long long a, b, c;
	int cal[21][21][21] = { 0 };

	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		printf("w(%lld, %lld, %lld) = %d\n", a, b, c, w(a, b, c, cal));

	}
}

void P1022() {
	char str[1000];
	cin >> str;

	int i = 0;

	int a = 0;
	int b = 0;
	char x;
	bool isAtRight = false;
	stack<char> s;

	while (str[i] != '\0') {

		if (i == 0) {
			if (str[i] == '-') {
				s.push('-');
			}
			else {
				s.push('+');
			}
		}

		if (str[i] >= '0'&&str[i] <= '9') {
			s.push(str[i]);

		}
		else if (str[i] == '-' || str[i] == '+') {

			int j = 0;
			int temp = 0;
			while (s.size() != 1) {
				temp += (s.top() - '0')*(int)pow(10, j);
				s.pop();
				j++;
			}

			if (s.top() == '-') {
				if (!isAtRight) {
					b = b - temp;
				}
				else {
					b = b + temp;
				}
			}
			else {
				if (!isAtRight) {
					b = b + temp;
				}
				else {
					b = b - temp;
				}
			}

			s.pop();
			s.push(str[i]);
		}
		else if (str[i] == '=') {
			isAtRight = true;

			int j = 0;
			int temp = 0;
			while (s.size() != 1) {
				temp += (s.top() - '0')*(int)pow(10, j);
				s.pop();
				j++;
			}

			if (s.top() == '-') {
				b = b - temp;
			}
			else {
				b = b + temp;
			}

			s.pop();
			s.push('+');

		}
		else {
			x = str[i];

			int j = 0;
			int temp = 0;
			while (s.size() != 1) {
				temp += (s.top() - '0')*(int)pow(10, j);
				s.pop();
				j++;
			}

			if (s.top() == '-') {
				if (!isAtRight) {
					a = a - temp;
				}
				else {
					a = a + temp;
				}
			}
			else {
				if (!isAtRight) {
					a = a + temp;
				}
				else {
					a = a - temp;
				}
			}

			s.pop();
			s.push('+');
		}
		i++;
	}

	int j = 0;
	int temp = 0;
	while (s.size() != 1) {
		temp += (s.top() - '0')*(int)pow(10, j);
		s.pop();
		j++;
	}
	if (s.top() == '-') {
		b = b + temp;
	}
	else {
		b = b - temp;
	}
	if (b != 0) {
		printf("%c=%.3f\n", x, -1.0*b / a);
	}
	else {
		printf("%c=%.3f\n", x, 0);
	}

}

void P1426() {
	int s, x;
	cin >> s >> x;
	int sn = 0;
	int step = 7;
	for (int i = 0; sn < s - x; i++) {
		sn += step;
		step *= 0.98;
	}
	if (sn + step >= s + x) {
		cout << "n" << endl;
	}
	else {
		cout << "y" << endl;
	}

}
void rev(char * str) {
	int n = strlen(str);
	for (int i = 0; i < n / 2; i++) {
		swap(str[i], str[n - i - 1]);
	}
}
void term(char * str) {
	int i = 0;
	while (str[i] == '0') {
		i++;
	}
	int j = 0;
	while (str[j + i] != '\0') {
		str[j] = str[j + i];
		j++;
	}
	str[j] = '\0';
}
void P1307() {
	int N;
	cin >> N;

	char str[12];
	sprintf(str, "%d", N);

	if (str[0] != '-') {
		rev(str);
		term(str);
		cout << str << endl;
	}
	else {
		rev(str + 1);
		term(str + 1);
		cout << str << endl;
	}
}

bool flag = false;
vector<int*> vec1;
int search1(int x[], int position, int left, int max) {

	static int count = 0;
	if (flag) {
		return count;
	}

	if (left == 0) {
		vec1.push_back(x);
		count++;
		if (position == -1) {
			flag = true;
			return count;
		}
		else {
			x[position + 1]--;
			search1(x, position, left + 1, max);
		}

	}

	if (position == -1) {
		search1(x, max, left, max);
	}
	else {
		x[position]++;
		search1(x, position - 1, left - 1, max);
	}

}

void P2089() {
	int n;
	cin >> n;

	if (n > 30 || n < 10) {
		cout << 0 << endl;
		return;
	}



	for (int j = 9; j >= 0; j--) {
		int x[10] = { 0 };
		for (int i = 0; i < 10; i++) {
			x[i] = 1;
		}
		search1(x, j, n - 10, j);
		flag = false;
	}

	for (int i = 0; i < vec1.size(); i++) {
		for (int j = 0; i < 10; j++) {
			cout << vec1[i][j] << " ";
		}
		cout << endl;
	}
}

bool isPrime(int n) {

	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

void P1579() {
	int n;
	cin >> n;
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(7);
	for (int i = 10; i < n; i++) {
		if (isPrime(i)) {
			vec.push_back(i);
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec.size(); j++) {
			for (int k = 0; k < vec.size(); k++) {
				if (vec[i] + vec[j] + vec[k] == n) {
					cout << vec[i] << " " << vec[j] << " " << vec[k] << endl;
					return;
				}
			}
		}
	}

}

void P1478() {
	int n, s, a, b;
	cin >> n >> s >> a >> b;
	int x, y;
	int count = 0;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x <= a + b) {
			vec.push_back(y);
		}
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size() && s >= 0; i++) {
		if (s - vec[i] >= 0) {
			s -= vec[i];
			count++;
		}
	}
	cout << count << endl;
}
/*!!!
bool isPrime(int n) {
	if (n == 0) {
		return false;
	}
	else if (n == 1) {
		return true;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}*/
int getMax(int num) {

	static int count = 0;

	if (num / 10 == 0) {
		return count;
	}
	count++;
	getMax(num / 10);
}
vector<int> genNums(vector<int> number, int size) {//1-1,2-1,3-2,4-2,5-3,6-3 size:Î»Êý
												   //needs (size+1)/2 times loop 

	if (size == 1) {
		for (int i = 0; i <= 9; i++) {
			number.push_back(i);
		}
		return number;
	}
	else if (size == 2) {
		for (int i = 0; i <= 9; i++) {
			number.push_back(i * 10 + i);
		}
		return number;
	}

	if (size % 2 == 0) {
		return number;
	}
	vector<int> vec(genNums(number, size - 2));

	for (int j = 1; j <= 9; j++) {
		for (int i = 0; i < vec.size(); i++) {
			number.push_back(j * (int)pow(10, size - 1) + vec[i] * 10 + j);
			if (i % 9 == 0 && size != 3) {
				number.push_back(j * (int)pow(10, size - 1) + vec[i] * 10 + j - vec[i] % 10 * 10 - vec[i] % 10 * (int)pow(10, size - 2));
			}

		}
	}
	return number;
}
void P1217() {

	int a, b;
	cin >> a >> b;
	int max = getMax(b);
	vector<int> vec;

	for (int j = 0; j <= max;) {
		vec.clear();
		vec = genNums(vec, j + 1);
		//	int count = 0;

		sort(vec.begin(), vec.end());
		//	vector<int>::iterator iter = unique(vec.begin(), vec.end());
		//	vec.erase(iter, vec.end());

		for (int i = 0; i < vec.size(); i++) {

			if (vec[i] >= a&&isPrime(vec[i]) && vec[i] <= b) {
				//	count++;

				printf("%d\n", vec[i]);
			}
			cout << vec[i] << endl;
		}
		cout << endl;
		//	cout << "size is " << vec.size() << endl;
		//	cout << "sum is " << count << endl;

		if (j > 1) {
			j = j + 2;
		}
		else {
			j++;
		}
	}
}
int dfs(int a[], int n, int k, int start, int current, int end, int time) {

	int count = 0;

	if (time == k) {
		return isPrime(current);
	}

	for (int i = start; i < end; i++) {
		count += dfs(a, n, k, i + 1, current + a[i], end, time + 1);
	}
	return count;
}
void P1036() {

	int n, k;
	cin >> n >> k;
	int a[20];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << dfs(a, n, k, 0, 0, n, 0) << endl;

}
int leftAdd(int n) {

	static int ans[1001] = { 0 };
	int count = 1;
	ans[1] = 1;

	if (ans[n] != 0) {
		return ans[n];
	}

	for (int i = 1; i < n / 2 + 1; i++) {
		count += leftAdd(i);
	}
	ans[n] = count;
	return count;
}
void P1028() {

	int n;
	cin >> n;
	cout << leftAdd(n) << endl;
}

void P1598() {

	char str[4][100];
	scanf("%[^\n]", str[0]);
	getchar();
	scanf("%[^\n]", str[1]);
	getchar();
	scanf("%[^\n]", str[2]);
	getchar();
	scanf("%[^\n]", str[3]);
	getchar();
	int alp[26] = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; str[i][j] != '\0'; j++) {
			int a = str[i][j] - 'A';
			if (a >= 0 && a < 26) {
				alp[a]++;
			}
		}
	}
	int max = 0;
	for (int i = 0; i < 26; i++) {
		max = alp[i] > max ? alp[i] : max;
	}
	int index = max;
	for (int i = 0; i < max; i++) {

		int end = 0;
		for (int j = 0; j < 26; j++) {
			if (index - alp[j] <= 0) {
				end = j;
			}
		}

		for (int j = 0; j < end + 1; j++) {
			if (index - alp[j] > 0) {
				cout << " ";
			}
			else {
				cout << "*";
			}
			cout << " ";

		}
		cout << endl;
		index--;
	}
	for (int i = 0; i < 26; i++) {
		cout << (char)('A' + i) << " ";
	}

}
void P1914() {
	int n;
	char str[50];
	cin >> n >> str;
	char a = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		a = n + str[i] > 'z' ? n - 'z' + 'a' - 1 : n;
		printf("%c", str[i] + a);
	}
	cout << endl;
}
void P1055() {
	char ISBN[14];
	scanf("%s", ISBN);
	int check = 0;
	int n = 1;
	for (int i = 0; i < 12; i++) {
		if (ISBN[i] == '-') {
			continue;
		}
		check += ((ISBN[i] - '0') * n);
		n++;
	}
	char a = check % 11 == 10 ? 'X' - '0' : check % 11;
	if (ISBN[12] - '0' == a) {
		cout << "Right" << endl;
	}
	else {
		ISBN[12] = '0' + a;
		cout << ISBN << endl;
	}
}
void P1423() {
	double x;
	cin >> x;
	double sn = 0;
	double step = 2;
	int n;
	for (n = 0; sn < x; n++) {

		sn += step;
		step *= 0.98;
	}
	cout << n << endl;

}
void P1035() {
	int k;
	cin >> k;
	double sn = 0;
	int n;
	for (n = 1; sn <= k; n++) {
		sn += 1.0 / n;
	}
	cout << n - 1 << endl;
}

void P1424() {
	int x;
	long long n;
	cin >> x >> n;
	int num = 0;
	for (int i = 0; i < n % 7; i++) {
		if (x > 7) {
			x -= 7;
		}
		if (x >= 1 && x <= 5) {
			num += 250;
		}
		x++;
	}
	cout << n / 7 * 1250 + num << endl;
}
