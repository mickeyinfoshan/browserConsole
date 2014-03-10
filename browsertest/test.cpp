#pragma comment(lib,"htmlcxx.lib")

#include "htmlcxx/html/ParserDom.h"
#include <iostream>
#include <Windows.h>
#include <winhttp.h>
#include <atlbase.h>
#include <atlconv.h>
 #pragma comment(lib, "winhttp.lib")
using namespace std;
using namespace htmlcxx;
//WinHttp
/*http://technet.microsoft.com/zh-cn/library/aa384101*/
/*http://www.cnblogs.com/barrysgy/archive/2012/02/16/2354597.html*/
/*http://msdn.microsoft.com/zh-cn/subscriptions/downloads/aa384101.aspx*/

//htmlcxx
/*http://blog.csdn.net/q408384053/article/details/8070627*/
/*int main()
{
	string page;
	DWORD dwSize = 0;
    DWORD dwDownloaded = 0;
    LPSTR pszOutBuffer;
    BOOL  bResults = FALSE;
	HINTERNET hSession = NULL,hConnect = NULL,hRequest = NULL;
	hSession = WinHttpOpen(L"WinHTTP Example/1.0",  
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        WINHTTP_NO_PROXY_NAME, 
        WINHTTP_NO_PROXY_BYPASS, 0);
	hConnect = WinHttpConnect(hSession,(L"mwqinfoshan.tk"),INTERNET_DEFAULT_HTTP_PORT, 0);
	hRequest = WinHttpOpenRequest(hConnect,L"GET",L"/index.html", NULL, WINHTTP_NO_REFERER, NULL, NULL);
	WinHttpSendRequest(hRequest,WINHTTP_NO_ADDITIONAL_HEADERS,
        0, WINHTTP_NO_REQUEST_DATA, 0, 
        0, 0);
	bResults = WinHttpReceiveResponse(hRequest,NULL);
	if(!bResults)
	{
		cout<<"Fail to send Request";
	}

	 if (bResults)
       
        do{

            // Verify available data.
            dwSize = 0;
            if (!WinHttpQueryDataAvailable( hRequest, &dwSize))
                printf( "Error %u in WinHttpQueryDataAvailable.\n",
                        GetLastError());

            // Allocate space for the buffer.
            pszOutBuffer = new char[dwSize+1];
            if (!pszOutBuffer)
            {
                printf("Out of memory\n");
                dwSize=0;
            }
            else
            {
                // Read the Data.
                ZeroMemory(pszOutBuffer, dwSize+1);

                if (!WinHttpReadData( hRequest, (LPVOID)pszOutBuffer, 
                                      dwSize, &dwDownloaded))
                    printf( "Error %u in WinHttpReadData.\n", GetLastError());
                else
				{
					string next = pszOutBuffer;
					page = page + next;
				}
            
                // Free the memory allocated to the buffer.
                delete [] pszOutBuffer;
            }

        }while(dwSize>0);


    // Report any errors.
    if (!bResults)
        printf( "Error %d has occurred.\n", GetLastError());

    // Close open handles.
    if (hRequest) WinHttpCloseHandle(hRequest);
    if (hConnect) WinHttpCloseHandle(hConnect);
    if (hSession) WinHttpCloseHandle(hSession);
	cout<<page<<endl<<endl;
	//Parse some html code
	//Parse some html code
  //string html = "<html><body>sb<span>sunhao</span></body></html>";
  HTML::ParserDom parser;
  tree<HTML::Node> dom = parser.parseTree(page);
  
  //Print whole DOM tree
  cout << dom << endl;
  
  //Dump all links in the tree
	tree<HTML::Node>::iterator it = dom.begin();
  tree<HTML::Node>::iterator end = dom.end();
  for (; it != end; ++it)
  {

     if (strcmp(it->tagName().c_str(), "a") == 0)
     {
       it->parseAttributes();
       cout << it->attribute("href").second << endl;
     }
  }
  
  //Dump all text of the document
  it = dom.begin();
  end = dom.end();
  for (; it != end; ++it)
  {
    if ((!it->isTag()) && (!it->isComment()))
    {
      cout << it->text();
    }
  }
  cout << endl;
  system("pause");
	return 0;

}*/