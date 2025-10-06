#include "HttpClient.h"
#include <stdexcept>

HttpClient::HttpClient() {
    curl_ = curl_easy_init();
    if (!curl_) throw std::runtime_error("CURL initialization failed");
}

HttpClient::~HttpClient() {
    curl_easy_cleanup(curl_);
}

std::string HttpClient::fetch(const std::string& url) {
    std::string read_buffer;
    curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &read_buffer);
    curl_easy_setopt(curl_, CURLOPT_FOLLOWLOCATION, 1L);
    CURLcode res = curl_easy_perform(curl_);
    
    if (res != CURLE_OK) return "";
    return read_buffer;
}

size_t HttpClient::write_callback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}
