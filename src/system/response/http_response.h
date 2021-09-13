#ifndef HTTP_RESPONSE
#define HTTP_RESPONSE

#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "../serializable.h"

class HttpResponse : public Serializable
{
    std::string out;
    int status;
    std::string contentType;

public:
    HttpResponse(std::string content, int sc = 200, std::string ct = "text/html")
        : out(content), status(sc), contentType(ct)
    {
    }

    HttpResponse(Serializable &content, int sc = 200, std::string ct = "text/html")
        : out(content.serialize()), status(sc), contentType(ct)
    {
    }

    std::string serialize() override
    {
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);

        std::string out = this->getContent();

        std::ostringstream oss;
        oss << "HTTP/1.1 " << getStatusCodeLine() << "\n"
            << "Date: " << std::put_time(&tm, "%a, %d %m %Y %H:%M:%S %Z") << "\n"
            << "Server: Custom\n"
            << "Last-Modified: " << std::put_time(&tm, "%a, %d %m %Y %H:%M:%S %Z") << "\n"
            << "ETag: \"aaaaa\"\n" // TODO
            << "Accept-Ranges: bytes\n"
            << "Content-Length: " << std::to_string(out.length()) << "\n"
            << "Connection: close\n"
            << "Content-Type: " << contentType << "\n\n"
            << out;

        return oss.str();
    }

    std::string getContent()
    {
        return out;
    }

    std::string getStatusCodeLine()
    {
        if (status == 200)
        {
            return "200 OK";
        }
        return std::to_string(status); // TODO
    }
};

#endif