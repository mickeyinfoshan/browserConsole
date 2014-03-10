#include "HttpRequest.h"
#include "Document.h"

class Browser
{
	private:
		HttpRequest httpRequest;
		Document document;
	public:
		void run();
};