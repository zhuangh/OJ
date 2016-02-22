#include <string>
#include <vector>
#include <iostream>
#include <boost/algorithm/string.hpp>

using namespace boost::algorithm;
using namespace std;

int main() {
  string s = "<html>\n<body> hey </body>\n</html>";
  vector<string> v;
  split(v, s, is_space());
  cout << v.size() << endl;
}
