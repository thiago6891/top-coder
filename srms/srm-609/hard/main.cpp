#include <iostream>
#include <cstring>
using namespace std;

int dp[51][51][51][51];

class VocaloidsAndSongs {
	int solve(int, int, int, int);
public:
	VocaloidsAndSongs() { memset(dp, -1, sizeof(int) * 51 * 51 * 51 * 51); }
	int count(int S, int gumi, int ia, int mayu) {
		return solve(S, gumi, ia, mayu);
	}
};

int VocaloidsAndSongs::solve(int s, int a, int b, int c) {
	if (s < 0 || a < 0 || b < 0 || c < 0) return 0;
	
	if (dp[s][a][b][c] != -1) return dp[s][a][b][c];
	
	if (a + b + c < s) {
		dp[s][a][b][c] = 0;
	} else if (s == 1 && a <= 1 && b <= 1 && c <= 1) {
		dp[s][a][b][c] = 1;
	} else {
		dp[s][a][b][c] = 0;
		dp[s][a][b][c] += solve(s - 1, a - 1, b - 1, c - 1);
		dp[s][a][b][c] = (dp[s][a][b][c] + solve(s - 1, a - 1, b - 1, c)) % 1000000007;
		dp[s][a][b][c] = (dp[s][a][b][c] + solve(s - 1, a - 1, b, c - 1)) % 1000000007;
		dp[s][a][b][c] = (dp[s][a][b][c] + solve(s - 1, a, b - 1, c - 1)) % 1000000007;
		dp[s][a][b][c] = (dp[s][a][b][c] + solve(s - 1, a - 1, b, c)) % 1000000007;
		dp[s][a][b][c] = (dp[s][a][b][c] + solve(s - 1, a, b - 1, c)) % 1000000007;
		dp[s][a][b][c] = (dp[s][a][b][c] + solve(s - 1, a, b, c - 1)) % 1000000007;
	}
	
	return dp[s][a][b][c];
}

int main(int argc, char** argv) {
	VocaloidsAndSongs vs;
	cout << vs.count(3, 1, 1, 1) << endl;
	cout << vs.count(3, 3, 1, 1) << endl;
	cout << vs.count(50, 10, 10, 10) << endl;
	cout << vs.count(18, 12, 8, 9) << endl;
	cout << vs.count(50, 25, 25, 25) << endl;

	return 0;
}