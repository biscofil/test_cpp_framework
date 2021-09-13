# Test framework

## Define routes

```c++
Router::add(Router::GET, "posts", PostController::list);
Router::add(Router::POST, "posts", PostController::insert);
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