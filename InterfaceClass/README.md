# 用接口类让两个动态库通信

最小控制台示例：主程序和两个动态库运行在同一个进程里，没有窗口，也不需要信号槽。

```text
主程序从 Logger.dll（B）获取 ILogger*
主程序把 ILogger* 传给 Business.dll（A）
A 调用 logger->Log(...) → 实际执行 B 的 ConsoleLogger::Log(...)
```

## 运行

1. 用 Qt Creator 打开本目录的 `LearnDll.pro`。
2. 选择一个桌面 Qt Kit，构建整个项目。
3. 运行 `Demo`，输出：

```text
[Logger B] Hello! Business A is using ILogger.
```

程序和两个动态库会放在构建目录的 `bin` 文件夹里。使用 Qt Creator 运行，由所选 Kit 提供 Qt 运行环境。

## 只看这三步

**1. 定义大家都认识的接口**，见 `common/ilogger.h`：

```cpp
class ILogger
{
public:
    virtual ~ILogger() = default;
    virtual void Log(const char *message) = 0;
};
```

`= 0` 表示纯虚函数：这里只规定“能输出日志”，具体怎么输出由子类实现。

**2. B 实现接口**，见 `logger/logger.cpp`：

```cpp
class ConsoleLogger : public ILogger
{
public:
    void Log(const char *message) override
    {
        std::printf("[Logger B] %s\n", message);
    }
};
```

`override` 表示实现父类的虚函数。B 的 `GetLogger()` 返回这个对象的接口指针；对象是静态对象，由 B 持有，主程序不用 `delete`。

**3. 主程序把接口传给 A，A 通过接口调用 B**：

```cpp
// app/main.cpp
ILogger *logger = GetLogger();
DoWork(logger);

// business/business.cpp 中的 DoWork()
logger->Log("Hello! Business A is using ILogger.");
```

虽然指针类型是 `ILogger*`，但它指向的实际对象是 `ConsoleLogger`，所以虚函数调用会执行 B 中的实现。

## 为什么减少了依赖？

看看 `business/business.pro`：它只包含公共接口目录，**没有链接 Logger 库**。A 不包含 `logger.h`，也不知道 `ConsoleLogger`，只需要拿到一个可用的 `ILogger*`。

以后换一个实现了 `ILogger` 的日志对象，主程序把新对象传给 A 即可，A 的代码不用改。

这个学习示例用普通导出函数连接各模块，不涉及动态加载插件。请让三个模块使用同一个 Qt Kit 构建，保证 C++ 接口的二进制兼容；调用期间也要保持对象及其所在动态库有效。
