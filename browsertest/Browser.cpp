#include "Browser.h"
#include <iostream>

using namespace std;

void Browser::run()
{
	string url;
	cout<<"Enter a url(\"exit\" to exit)"<<endl;
	while((cin>>url)&&(url!="exit")&&(url!="EXIT"))
	{	
		URL u(url);
		
		httpRequest.setUrl(u);
		if(httpRequest.sendRequest())
		{
			document = Document(httpRequest.getResponse());
			document.display();
		}
		else
		{
			cout<<"fail to send request,please try again"<<endl;
		}
		cout<<"Enter a url(\"exit\" to exit)"<<endl;
	}
	return ;
}