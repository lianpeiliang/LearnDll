# 回调函数：B 完成后通知 A

这是一个最小控制台示例，主程序、业务库 A（Business.dll）、下载库 B（Download.dll）在同一个进程里运行。

为了方便理解，下载只用打印模拟，没有真实网络请求，也没有线程。

## 运行

1. 用 Qt Creator 打开本目录的 `LearnDll.pro`。
2. 选择桌面 Qt Kit，构建整个项目。
3. 运行 `Demo`，输出：

```text
A: Asking B to download a file.
B: Downloading hello.txt... (simulated)
A: Received download-complete notification: hello.txt
```

程序和两个动态库会生成在构建目录的 `bin` 中。三个模块用同一个 Kit 构建，运行时由 Qt Creator 提供 Qt 环境。

## 重点只看这三步

**1. A 写好一个函数，准备接收通知。** 见 `business/business.cpp`：

```cpp
static void OnDownloadFinished(const char *fileName)
{
    std::printf("A: Received download-complete notification: %s\n", fileName);
}
```

**2. A 调用 B，并把这个函数的地址交给 B。**

```cpp
DownloadFile("hello.txt", &OnDownloadFinished);
```

`&OnDownloadFinished` 表示获取函数地址，这里还没有执行这个回调函数。

**3. B 完成事情后，通过这个地址调用 A 的函数。** 见 `download/download.cpp`：

```cpp
onFinished(fileName);
```

此时执行的就是 A 中的 `OnDownloadFinished()`，A 因此收到了通知。

整个过程：`主程序 → A 的 DoWork → B 的 DownloadFile → A 的 OnDownloadFinished`。

## 那个函数指针怎么理解？

`download/download.h` 中：

```cpp
using DownloadCallback = void (*)(const char *fileName);
```

这句话给一种“函数指针类型”起名叫 `DownloadCallback`。它能保存这样的函数的地址：接收一个 `const char*` 参数，返回 `void`。

因此 `DownloadFile()` 的第二个参数 `onFinished`，就是用来保存 A 传来的函数地址的变量。

B 只需要知道回调的参数和返回值，不需要知道 A 的函数叫什么，也不需要链接 Business 库。A 的回调函数不需要导出，因为 B 已经拿到了它的地址。

本例是同步回调：B 在 `DownloadFile()` 返回前立即通知 A。回调不一定是异步的；这里也没有保存回调供以后使用。
