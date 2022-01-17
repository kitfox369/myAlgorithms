#include<iostream>
#include<string>
using namespace std;

// 10845번 큐
//큐 구현
class QueueS {
public:
	int front;
	int back;
	int size;
	int *values;		//모든 값들을 담은 배열을 가리키는 포인터

	//생성자
	QueueS() {
		size = 10001;		//큐의 사이즈 
		values = new int[size];
		front = 0;
		back=0;
	}
	//소멸자
	~QueueS() {
		delete[] values;
	}

	void push(int data) {
		if ((back+1)%size!=front) {
			values[back] = data;
			back = (back + 1) % size;
		}
	}

	void pop() {
		front = (front + 1) % size;
	}

	bool empty() {
		if (back == front)
			return true;
		else
			return false;
	}
};

QueueS st;

void getNumSize(string str) {
	int temp;

	if (str == "back") {
		if (st.back - st.front != 0) {
			cout << st.values[st.back - 1] << "\n";
		}
		else cout << "-1\n";
	}
	else if (str == "front") {
		if (st.back - st.front != 0) {
			cout << st.values[st.front] << "\n";
		}
		else cout << "-1\n";
	}
	else if (str == "size") {
		cout << st.back-st.front << "\n";
	}
	else if (str == "empty") {
		cout << ((st.back - st.front==0)?true:false) << "\n";
	}
	else if (str == "pop") {
		if (st.back - st.front!=0) {
			cout << st.values[st.front] << "\n";
			st.pop();
		}
		else {
			cout << "-1\n";
		}
	}
	else if (str == "push")
	{
		cin >> temp;
		st.push(temp);
	}
}

int main() {

	int n;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		getNumSize(str);
	}

	return 0;
}