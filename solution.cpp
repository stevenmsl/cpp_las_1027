#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <bitset>
using namespace sol1027;
using namespace std;

/*takeaways
  - use DP
    - check question 1048
  - dp[i][diff]
    - up to A[i] the number of occurrences of "diff"
    - A = [3,6,9,12]
    - A[3][3] = 3, so up to A[3] there are three
      occurrences of diff "3": (6-3), (9-6), (12-9)
    - the total length will be 3 + 1 as you need
      4 numbers to produce 3 occurrences of diff "3".
  - since the diff can be negative and can't be used
    as index to access the dp vector we have to convert
    it to a positive number
*/

int Solution::findLongest(vector<int> &A)
{
  /* max number of occurences among all different diff's
   */
  int maxNo = 0, n = A.size();
  /*
    - the number is ranging from 0 to 500
    - so the diff can be (0-500) = -500 to (500-0) = 500
    - we just add 500 to the diff to shift it from
      [-500,500] to [0,1000]
  */
  auto dp = vector<vector<int>>(n, vector<int>(1001));

  for (auto i = 0; i < n; i++)
  {
    for (auto j = 0; j < i; j++)
    {
      /* make sure the diff is positive */
      auto diff = A[i] - A[j] + 500;
      dp[i][diff] = dp[j][diff] + 1;
      maxNo = max(maxNo, dp[i][diff]);
    }
  }

  return maxNo + 1;
}