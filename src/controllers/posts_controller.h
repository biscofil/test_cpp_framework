#ifndef POSTS_CONTROLLER
#define POSTS_CONTROLLER

#include <stdio.h>
#include <iostream>
#include "../system/response.h"
#include "../models/post.h"

class PostController
{

public:
    static JsonResponse list()
    {
        return {"{'posts' : [] }"};
    }

    static JsonResponse insert()
    {
        Post post;
        return {"{'new_post' : " + post.serialize() + "}"};
    }

    static JsonResponse update(Post post)
    {
        return {"{'post' : " + post.serialize() + "}"};
    }
};

#endif