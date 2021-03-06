#ifndef ROUTER
#define ROUTER

#include <stdio.h>
#include <iostream>
#include <map>
#include <functional>
#include <string>
#include "response/http_response.h"

class Router
{

    static std::map<std::string, std::function<HttpResponse()>> routes; // METHOD_path, action

public:

    template <typename Function>
    static void add(std::string method, std::string path, Function &&action)
    {
        auto c = method + "_" + path;
        routes[c] = std::forward<Function>(action);
    }

    template <typename Function>
    static void get(std::string path, Function &&action)
    {
        add("GET", path, action);
    }

    template <typename Function>
    static void post(std::string path, Function &&action)
    {
        add("POST", path, action);
    }

    template <typename Function>
    static void put(std::string path, Function &&action)
    {
        add("PUT", path, action);
    }

    template <typename Function>
    static void delete_(std::string path, Function &&action)
    {
        add("DELETE", path, action);
    }

    static HttpResponse run(std::string method, std::string path)
    {
        //std::cout << method << " @ " << path << std::endl;
        auto c = method + "_" + path;
        if (!routes.count(c))
        {
            return {"NOT FOUND", 404};
        }
        return (routes.find(c)->second)();
    }
};

std::map<std::string, std::function<HttpResponse()>> Router::routes = {};

#endif