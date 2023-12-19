# lamda表达式

## 一般形式

```c++
auto f = [](int a, int b) -> int {
    return a + b
};

int f(int a, int b) {
    return a + b;
};

auto f = [&](int a, int b) -> int {
    return a + b;
};

int f(int &a, int &b) {
    return a + b;
};
```

## 包装后的lamda

~~~c++
std::function< int(int, int) > f = [&](int a, int b) {
    return a + b;
};
f(3, 5);
~~~

