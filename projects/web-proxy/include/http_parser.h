#ifndef HTTP_PARSER_H
#define HTTP_PARSER_H

#include "proxy_server.h"  // Reuse structs

HttpRequest parseHttpRequest(const std::string& raw);
HttpResponse parseHttpResponse(const std::string& raw);

#endif
