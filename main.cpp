#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1027;

/*
Input: [3,6,9,12]
Output: 4
Explanation:
The whole array is an arithmetic sequence with steps of length = 3.
*/

tuple<vector<int>, int>
testFixture1()
{
  auto input = vector<int>{3, 6, 9, 12};
  return make_tuple(input, 4);
}

/*
Input: [9,4,7,2,10]
Output: 3
Explanation:
The longest arithmetic subsequence is [4,7,10].
*/

tuple<vector<int>, int>
testFixture2()
{
  auto input = vector<int>{9, 4, 7, 2, 10};
  return make_tuple(input, 3);
}

/*
Input: [20,1,15,3,10,5,8]
Output: 4
Explanation:
The longest arithmetic subsequence is [20,15,10,5].
*/

tuple<vector<int>, int>
testFixture3()
{
  auto input = vector<int>{20, 1, 15, 3, 10, 5, 8};
  return make_tuple(input, 4);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.findLongest(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.findLongest(get<0>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Expect to see: " << get<1>(f) << endl;
  Solution sol;
  cout << sol.findLongest(get<0>(f)) << endl;
}
main()
{
  test1();
  test2();
  test3();
  return 0;
}