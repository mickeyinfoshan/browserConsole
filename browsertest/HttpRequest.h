#include "Url.h"

class HttpRequest
{
	private:
		URL url;
		string response;
	public:
		HttpRequest();
		HttpRequest(URL u);
		URL getUrl();
		bool setUrl(URL u);
		bool sendRequest();
		string getResponse();
		bool setResponse(string str = "");
};