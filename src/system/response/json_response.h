#ifndef JSON_RESPONSE
#define JSON_RESPONSE

#include <stdio.h>
#include <iostream>
#include <string>
#include "http_response.h"

class JsonResponse : public HttpResponse
{

public:
    JsonResponse(std::string content, int status = 200)
        : HttpResponse::HttpResponse(content, status, "application/json")
    {
    }

    JsonResponse(Serializable &content, int status = 200)
        : HttpResponse::HttpResponse(content.serialize(), status, "application/json")
    {
    }
};

#endif