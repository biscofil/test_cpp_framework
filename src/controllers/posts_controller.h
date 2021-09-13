#ifndef POSTS_CONTROLLER
#define POSTS_CONTROLLER

#include <stdio.h>
#include <iostream>
#include "../system/view.h"
#include "../system/response/json_response.h"
#include "../models/post.h"

class PostController
{

public:
    static HttpResponse index()
    {
        return HttpResponse(View("index.html").serialize());
    }

    static JsonResponse list()
    {
        auto posts = Post::all();
        return {"{'posts' : "  + posts.serialize() +" }"};
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