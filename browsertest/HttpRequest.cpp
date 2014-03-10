#include "HttpRequest.h"
#include <Windows.h>
#include <winhttp.h>
#include <atlbase.h>
#include <atlconv.h>
 #pragma comment(lib, "winhttp.lib")


HttpRequest::HttpRequest()
{
	url = URL();
	response = "";
}

HttpRequest::HttpRequest(URL u)
{
	url = u;
}

bool HttpRequest::setUrl(URL u)
{
	url = u;
	return true;
}

URL HttpRequest::getUrl()
{
	return url;
}

bool HttpRequest::sendRequest()
{
	USES_CONVERSION;
	DWORD dwSize = 0;
    DWORD dwDownloaded = 0;
    LPSTR pszOutBuffer;
    BOOL  bResults = FALSE;
	HINTERNET hSession = NULL,hConnect = NULL,hRequest = NULL;
	hSession = WinHttpOpen(L"WinHTTP Example/1.0",  
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        WINHTTP_NO_PROXY_NAME, 
        WINHTTP_NO_PROXY_BYPASS, 0);
	hConnect = WinHttpConnect(hSession,A2CW(url.getDomainName().c_str()),INTERNET_DEFAULT_HTTP_PORT, 0);
	hRequest = WinHttpOpenRequest(hConnect,L"GET",A2CW(url.getRoute().c_str()), NULL, WINHTTP_NO_REFERER, NULL, NULL);
	WinHttpSendRequest(hRequest,WINHTTP_NO_ADDITIONAL_HEADERS,
        0, WINHTTP_NO_REQUEST_DATA, 0, 
        0, 0);
	bResults = WinHttpReceiveResponse(hRequest,NULL);
	if(!bResults)
	{
		return false;
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
					response = response + next;
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

	return true;
}

string HttpRequest::getResponse()
{
	return response;
}

bool HttpRequest::setResponse(string str)
{
	response = str;
	return true;
}