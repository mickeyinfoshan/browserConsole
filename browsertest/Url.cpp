#include "Url.h"

URL::URL()
{
	protocol = "";
	domainName = "";
	route = "";
}

URL::URL(string url)
{
	//get protocol from url
	if(url.substr(0,7) == "http://")
	{
		
		protocol = ("http");
		url = url.substr(7);
		
	}
	else if(url.substr(0,8) == "https://")
	{
		protocol = ("https://");
		url = url.substr(8);
	}
	else if(url.substr(0,6) == "ftp://")
	{
		protocol = ("ftp");
		url = url.substr(6);
	}
	else if(url.substr(0,7) == "smap://")
	{
		protocol = "smap";
		url = url.substr(7);
	}
	else
		protocol = "http";

	int pos = url.find_first_of('/');
	if(pos==string::npos)
	{
		domainName = url;
		route = "/index.html";
	}
	else
	{
		domainName = url.substr(0,pos);
		route = url.substr(pos);
	}
}

string URL::getProtocol()
{
	return protocol;
}

string URL::getDomainName()
{
	return domainName;
}

string URL::getRoute()
{
	return route;
}