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
		void lsl(); // Logical shift left
		void lsr(); // Logical shift right
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
		for(vector<bool>::iterator it = bits.begin(); it != bits.end(); ++it) {
			*it = !*it;
		}
		// ...then add 1. Carry over until a 0 is found.
		for(vector<bool>::iterator it = bits.begin(); it != bits.end(); ++it) {
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
	for(vector<bool>::reverse_iterator it = bits.rbegin(); it != bits.rend(); ++it) {
    	cout << *it;
	}
}
void Binary::lsl() {

}
void Binary::lsr() {

}


int main() {
	while(1) {
		int o1, o2 = 0;
		string op;
		Binary bits;

		cout << "Operation (add, sub, mult, quit): ";
		cin >> op;
		if (op == "quit")
			return 0;
		cout << "Operand 1: ";
		cin >> o1;
		cout << "Operand 2: ";
		cin >> o2;
		if (op == "add")
			o1 += o2;
		else if (op == "sub")
			o1 -= o2;
		else if (op == "mult")
			o1 *= o2;
		else {
			cout << "Invalid operation.\n";
			continue;
		}

		bits.toBinary(o1);
		cout << "Result: "; // << bits.toDecimal() << " "; 
		bits.print() ;
		cout << " (negative numbers will be in 2's complement)";
		cout << endl;
	}
}
