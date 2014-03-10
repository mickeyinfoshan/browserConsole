#include "Document.h"
#include <iostream>

Document::Document(string html)
{
	HTML::ParserDom parser;

	dom = parser.parseTree(html);
}

/*vector<HTML::Node&> Document::getElementsByTagName(string tagName)
{
	vector<HTML::Node&> v;
	tree<HTML::Node>::iterator it = dom.begin();
	tree<HTML::Node>::iterator end = dom.end();
	for(; it!=end;it++)
	{
		if(it->tagName() == tagName)
		{
			v.push_back(*it);
		}
	}
	return v;
}*/

void Document::display()
{
	tree<HTML::Node>::iterator it = dom.begin();
	tree<HTML::Node>::iterator end = dom.end();

	 for (; it != end; ++it)
  {
    if ((!it->isTag()) && (!it->isComment()))
    {
      std::cout << it->text();
    }
  }
}