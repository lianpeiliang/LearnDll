# 函数指针表：两个动态库之间通信

这是一个最小控制台示例，主程序、Business.dll（A）、Logger.dll（B）运行在同一个进程里。

```text
B 把日志函数的地址填进表 → 主程序拿到表 → 把表传给 A → A 通过函数指针调用 B
```

## 运行

1. 用 Qt Creator 打开本目录的 `LearnDll.pro`。
2. 选择一个桌面 Qt Kit，构建整个项目。
3. 运行 `Demo`，输出：

```text
[Logger B] Hello! Business A is using a function pointer table.
```

程序和两个动态库都在构建目录的 `bin` 下。三个模块使用同一个 Kit 构建，运行时由 Qt Creator 提供 Qt 环境。

## 按这四步看代码

**1. 公共头文件定义表**：`common/loggerapi.h`

```cpp
struct LoggerApi
{
    void (*Log)(const char *message);
};
```

`Log` 是一个变量，保存函数地址。它可以指向“接收 `const char*`、返回 `void`”的函数。这里只放一个函数指针，方便理解；需要更多功能时，可以继续添加成员。

**2. B 把函数地址填进表**：`logger/logger.cpp`

```cpp
LoggerApi api;
api.Log = &PrintLog;
return api;
```

`&PrintLog` 是获取函数地址，这一步还没有调用函数。真正打印日志的 `PrintLog()` 就在这个文件里。

**3. 主程序拿到表，传给 A**：`app/main.cpp`

```cpp
LoggerApi api = GetLoggerApi();
DoWork(&api);
```

这里的 `&api` 是获取整个结构体的地址。

**4. A 通过函数指针调用**：`business/business.cpp`

```cpp
api->Log("Hello! Business A is using a function pointer table.");
```

这时才真正调用函数，执行的是 B 中的 `PrintLog()`。

## 和接口类示例的区别

接口类示例用 `virtual` 实现多态；这里没有继承和虚函数，函数地址由我们自己填进结构体。

A 只包含公共的 `loggerapi.h`，不需要知道 `PrintLog` 的名字，也不链接 Logger 库。主程序负责连接两边。B 只导出获取表的 `GetLoggerApi()`，内部的 `PrintLog()` 不用导出，因为 A 已经通过表拿到了它的地址。

本例同步调用 `DoWork(&api)`，调用结束前表始终有效，B 也始终处于加载状态。表中只有函数地址，没有需要 `new` 或 `delete` 的对象。
