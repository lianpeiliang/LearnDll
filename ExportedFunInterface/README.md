# 同一个进程中，动态库 A 调用动态库 B

这是一个最小控制台示例，没有窗口，也不需要信号槽。

调用关系：

```text
Demo.exe → Business.dll（A）→ Logger.dll（B）
            DoWork()          Log()
```

三个模块都在 **Demo.exe 这同一个进程里** 运行。这里的“通信”就是普通的函数调用：A 把字符串传给 B，B 打印出来。

## 用 Qt Creator 运行

1. 打开根目录的 `LearnDll.pro`。
2. 选择一个桌面 Qt Kit，构建整个项目。
3. 在运行配置里选择 `Demo` 并运行。

预期输出：

```text
[Logger B] Hello! Business A is calling Logger B.
```

构建目录的 `bin` 文件夹里会放置程序和两个动态库，方便 Windows 在运行时找到 DLL。使用 Qt Creator 运行时，由所选 Kit 提供 Qt 运行环境。

## 先看这三小段

**B 提供能力**：`logger/logger.h` 声明导出的函数：

```cpp
LOGGER_API void Log(const char *message);
```

**A 调用 B**：`business/business.cpp`：

```cpp
void DoWork()
{
    Log("Hello! Business A is calling Logger B.");
}
```

**主程序调用 A**：`app/main.cpp`：

```cpp
int main()
{
    DoWork();
    return 0;
}
```

## A 为什么能调用 B？

看 `business/business.pro` 里的两行：

```qmake
INCLUDEPATH += $$PWD/../logger
LIBS += -L$$DESTDIR -lLogger
```

- `INCLUDEPATH`：让编译器找到 `logger.h`，知道 `Log()` 的声明。
- `LIBS`：让链接器找到 Logger 库，把调用与库关联起来。Windows 下，构建 Logger 时会同时生成 DLL 和供链接使用的导入库。

运行时还需要能找到 `Logger.dll`，因此示例把它和 `Demo.exe` 放在同一个 `bin` 目录。

`LOGGER_API` 在构建 B 时表示“导出”，在 A 使用 B 时表示“导入”。`LOGGER_LIBRARY` 只在 `logger.pro` 中定义，因此两边会自动选择正确的含义。A 的 `BUSINESS_API` 同理。

根目录的 `.pro` 用 `SUBDIRS` 组织三个子项目，用 `.depends` 指定构建顺序：先 B，再 A，最后 Demo。三个项目使用同一个 Kit 构建即可。
