#include <string>
using namespace std;

class MagicalStringDiv2 {
public:
	int minimalMoves(string s) {
		int count = 0;
		int halfSize = s.size() / 2;

		for (int i = 0; i < halfSize; i++) {
			if (s[i] != '>') count++;
		}

		for (int i = halfSize; i < s.size(); i++) {
			if (s[i] != '<') count++;
		}

		return count;
	}
};

int main() {}