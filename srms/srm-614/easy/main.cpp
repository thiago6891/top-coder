#include <string>
#include <vector>
#include <sstream>
using namespace std;

class MicroStrings {
public:
	string makeMicroString(int, int);
}

string MicroStrings::makeMicroString(int A, int D) {
	vector<int> nums;
	int n = A / D;
	for (int i = 0; i <= n; i++) nums.push_back(A - i * D);
	
	stringstream ss;
	for (int i = 0; i < nums.size(); i++) ss << nums[i];
	
	return ss.str();
}
