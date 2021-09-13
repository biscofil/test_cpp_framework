#include <stdio.h>
#include <iostream>
#include "posts_controller.h"
#include "router.h"

int main(int argc, char *argv[])
{

    Router::add(Router::GET, "posts", PostController::list);
    Router::add(Router::POST, "posts", PostController::insert);

    if (argc < 3)
    {
        std::cout << "Usage " << argv[0] << " <METHOD> <PATH>" << std::endl;
        return 1;
    }

    std::string method = argv[1];
    std::string path = argv[2];

    Router::run(method, path).serialize();

    return 0;
}