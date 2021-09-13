#ifndef HTTP_RESPONSE
#define HTTP_RESPONSE

#include <stdio.h>
#include <iostream>
#include <string>
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
        return std::string("HTTP/1.1 200 OK\n") +
               "Date: Sun, 10 Oct 2010 23:26:07 GMT\n" +
               "Server: Custom\n" +
               "Last-Modified: Sun, 26 Sep 2010 22:04:35 GMT\n" +
               "ETag: \"45b6-834-49130cc1182c0\"\n"
               "Accept-Ranges: bytes\n" +
               "Content-Length: 12\n" +
               "Connection: close\n" +
               "Content-Type: " + contentType + "\n\n" +
               out;
    }
};

#endif