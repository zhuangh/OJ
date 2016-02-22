#include <htmlcxx/html/ParserDom.h>
#include <iostream>
#include <string>
using namespace std;
using namespace htmlcxx;
int main()
{
  string html = "<html><body>hey<a href='http//:www.google.com.au'>Google</a></body></html>";
  HTML::ParserDom parser;
  tree<HTML::Node> dom = parser.parseTree(html);

  cout << dom << endl;

  tree<HTML::Node>::iterator it = dom.begin();
  tree<HTML::Node>::iterator end = dom.end();
  for (; it != end; ++it) {
    if (it -> tagName() == "a") {
      it -> parseAttributes();
      cout << it -> attribute("href").second;
    }
  }

  return 0;
}
