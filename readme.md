# Test framework

[![C/C++ CI](https://github.com/biscofil/test_cpp_framework/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/biscofil/test_cpp_framework/actions/workflows/c-cpp.yml)

## Define routes

```c++
Router::get("posts", PostController::list);
Router::post("posts", PostController::insert);
```

## Compile

```sh
make
```

## Use

```sh
./main GET posts
```

```sh
./main POST posts
```

```sh
./main GET posts123
```

## TODO

* [ ] Wildcards in paths