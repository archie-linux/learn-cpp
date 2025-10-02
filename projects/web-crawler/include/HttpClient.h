#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <string>
#include <curl/curl.h>

class HttpClient {
public:
    HttpClient();
    ~HttpClient();
    std::string fetch(const std::string& url);
private:
    static size_t write_callback(void* contents, size_t size, size_t nmemb, std::string* userp);
    CURL* curl_;
};

#endif
