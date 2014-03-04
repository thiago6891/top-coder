#include <cassert>
#include <string>
using namespace std;

#define INTERESTING		"Interesting"
#define NOT_INTERESTING "Not interesting"

class InterestingNumber {
public:
	string isInteresting(string);
};

string InterestingNumber::isInteresting(string x) {
	// since x contains only digits from 0 to 9 inclusive, and there has to be either zero or two
	// of each digit, there has to be an even number of digits and no more than 20 digits.
	if (x.size() % 2 != 0 || x.size() > 20) return NOT_INTERESTING;

	int Ds[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int c = 0; c < x.size(); c++) {
		int value = x[c] - '0';
		
		// if we already seen two or more digits of the given value, the number is not interesting.
		if (Ds[value] >= 2) return NOT_INTERESTING;
		// if we haven't already seen a digit of the given value and we can't find that same digit
		// (value + 1) positions later, the number is not interesting.
		else if (Ds[value] == 0 && (c + value + 1 >= x.size() || x[c] != x[c + value + 1]))
			return NOT_INTERESTING;

		Ds[value]++;
	}

	return INTERESTING;
}

int main() {
	InterestingNumber in;

	assert(in.isInteresting("2002") == INTERESTING);
	assert(in.isInteresting("1001") == NOT_INTERESTING);
	assert(in.isInteresting("41312432") == INTERESTING);
	assert(in.isInteresting("611") == NOT_INTERESTING);
	assert(in.isInteresting("64200246") == INTERESTING);
	assert(in.isInteresting("631413164") == NOT_INTERESTING);

	return 0;
}