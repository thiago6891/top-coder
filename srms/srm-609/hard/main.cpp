#include <cstring>
using namespace std;

class VocaloidsAndSongs {
	int l[51][51][51][51] = {};
	int solve(int, int, int, int);
public:
	VocaloidsAndSongs() { memset(l, -1, sizeof(int) * 51 * 51 * 51 * 51); }
	int count(int S, int gumi, int ia, int mayu) {
		return solve(S, gumi, ia, mayu);
	}
};

int VocaloidsAndSongs::solve(int s, int a, int b, int c) {
	if (s < 0 || a < 0 || b < 0 || c < 0) return 0;
	
	if (l[s][a][b][c] != -1) return l[s][a][b][c];
	
	if (a + b + c < s) {
		l[s][a][b][c] = 0;
	} else if (s == 1 && a <= 1 && b <= 1 && c <= 1) {
		l[s][a][b][c] = 1;
	} else {
		l[s][a][b][c] = 0;
		l[s][a][b][c] += solve_test(s - 1, a - 1, b - 1, c - 1);
		l[s][a][b][c] = (l[s][a][b][c] + solve_test(s - 1, a - 1, b - 1, c)) % 1000000007;
		l[s][a][b][c] = (l[s][a][b][c] + solve_test(s - 1, a - 1, b, c - 1)) % 1000000007;
		l[s][a][b][c] = (l[s][a][b][c] + solve_test(s - 1, a, b - 1, c - 1)) % 1000000007;
		l[s][a][b][c] = (l[s][a][b][c] + solve_test(s - 1, a - 1, b, c)) % 1000000007;
		l[s][a][b][c] = (l[s][a][b][c] + solve_test(s - 1, a, b - 1, c)) % 1000000007;
		l[s][a][b][c] = (l[s][a][b][c] + solve_test(s - 1, a, b, c - 1)) % 1000000007;
	}
	
	return l[s][a][b][c];
}

int main() {}
