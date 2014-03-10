#include <string>
#include <Windows.h>
using namespace std;
class URL
{
	private:
		string protocol;
		string domainName;
		string route;
	public:
		URL(string url);
		URL();
		string getProtocol();
		string getDomainName();
		string getRoute();
};