#include <string>
using namespace std;

class PackingBallsDiv2 {
public:
	int minPacks(int R, int G, int B) {
		int count = 0;

		int min = (int)fmin(R, G);
		min = (int)fmin(min, B);

		count += min;
		R -= min;
		G -= min;
		B -= min;

		if (R != 0) {
			int div = R / 3;
			R %= 3;
			count += div;
		}

		if (G != 0) {
			int div = G / 3;
			G %= 3;
			count += div;
		}

		if (B != 0) {
			int div = B / 3;
			B %= 3;
			count += div;
		}

		if (R == 0) {
			min = (int)fmin(G, B);
			count += min;
			G -= min;
			B -= min;
		}

		if (G == 0) {
			min = (int)fmin(R, B);
			count += min;
			R -= min;
			B -= min;
		}

		if (B == 0) {
			min = (int)fmin(R, G);
			count += min;
			R -= min;
			G -= min;
		}

		if (R != 0 || G != 0 || B != 0) {
			count++;
		}

		return count;
	}
};

int main() {}