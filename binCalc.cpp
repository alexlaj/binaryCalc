#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Binary {
	vector<bool> bits;
	public:
		Binary();
		int toDecimal();
		void toBinary(int);
		void print();
};
Binary::Binary() {
	bits.reserve(8);
}
int Binary::toDecimal() {
	int cnt = 0;
	int tmpCnt = 1;
	for (size_t i=0; i<bits.size(); ++i) {
		if (bits[i]) {
			tmpCnt = 1;
			for (size_t j=0; j<i; j++) {
				tmpCnt *= 2;
			}
			cnt += tmpCnt;
		}
	}
	return cnt;
}
void Binary::toBinary(int num) {
	int isNegative = 0;
	if (num < 0) {
		isNegative = 1;
		num = 0-num;
	}
	while(num>0) {
		if (num%2 == 0)
			bits.push_back(0);
		else
			bits.push_back(1);
		num /= 2;
	}
	if (isNegative) {
		// Do two's complement. First flip all bits...
		for (vector<bool>::iterator it = bits.begin(); it != bits.end(); ++it) {
			*it = !*it;
		}
		// ...then add 1. Carry over until a 0 is found.
		for (vector<bool>::iterator it = bits.begin(); it != bits.end(); ++it) {
			if (!*it) {
				*it = 1;
				break;
			}
			else
				*it = 0;
		}
	}
}
void Binary::print() {
	// Stored lsb and end so we have to print in reverse.
	for (vector<bool>::reverse_iterator it = bits.rbegin(); it != bits.rend(); ++it) {
    	cout << *it;
	}
}


int main() {
	while(1) {
		int result, o1, o2 = 0;
		string op;
		Binary bresult, bo1, bo2;
		// Choose operation to perform and set result.
		cout << "Operation (+, -, *, quit): ";
		cin >> op;
		if (op == "quit")
			return 0;
		cout << "Operand 1: ";
		cin >> o1;
		bo1.toBinary(o1);
		cout << "Operand 2: ";
		cin >> o2;
		bo2.toBinary(o2);
		if (op == "+")
			result = o1 + o2;
		else if (op == "-")
			result = o1 - o2;
		else if (op == "*")
			result = o1 * o2;
		else {
			cout << "Invalid operation.\n";
			continue;
		}
		bresult.toBinary(o1);
		// Output result.
		cout << o1 << " " << op << " " << o2 << " = " << result << endl;
		if (o1<0) cout << "-";
		bo1.print();
		cout << " " << op << " ";
		if (o2<0) cout << "-";
		bo2.print();
		cout << " = ";
		bresult.print();
		cout << "\nFinal results will be in 2's complement if negative.\n";
	}
}
