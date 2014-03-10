#pragma comment(lib,"htmlcxx.lib")

#include "htmlcxx/html/ParserDom.h"
#include <string>
#include <vector>
using namespace std;
using namespace htmlcxx;

class Document
{
	private:
		tree<HTML::Node> dom;
	public:
		Document(string html = "");
		//vector<HTML::Node&> getElementsByTagName(string tagName);
		void display();
};