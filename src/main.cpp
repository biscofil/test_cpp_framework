#include <stdio.h>
#include <iostream>
#include "controllers/posts_controller.h"
#include "system/router.h"

int main(int argc, char *argv[])
{

    Router::get("posts", PostController::list);
    Router::post("posts", PostController::insert);

    if (argc < 3)
    {
        std::cout << "Usage " << argv[0] << " <METHOD> <PATH>" << std::endl;
        return 1;
    }

    std::string method = argv[1];
    std::string path = argv[2];

    std::cout << Router::run(method, path).serialize() << std::endl;

    return 0;
}