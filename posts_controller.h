#ifndef POSTS_CONTROLLER
#define POSTS_CONTROLLER

#include <stdio.h>
#include <iostream>
#include "response.h"

class PostController
{

public:
    static JsonResponse list()
    {
        return {"{'posts' : [] }"};
    }

    static JsonResponse insert()
    {
        return {"{'new_post' : {}}"};
    }
};

#endif