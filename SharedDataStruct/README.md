# 共享数据结构：两个动态库使用同一份数据

这是一个最小控制台示例：主程序、库 A（Writer.dll）、库 B（Reader.dll）在同一个进程中运行。

主程序创建一个 `SharedData` 对象，把它的地址分别传给两个库。A 修改其中的数字，B 就能读到修改后的数字。

## 运行

1. 用 Qt Creator 打开本目录的 `LearnDll.pro`。
2. 选择桌面 Qt Kit，构建整个项目。
3. 运行 `Demo`，输出：

```text
Reader: count = 0
Reader: count = 1
```

程序和两个动态库生成在构建目录的 `bin` 中。三个模块使用同一个 Qt Kit 构建，运行时由 Qt Creator 提供 Qt 环境。

## 只看这几个地方

`common/shareddata.h` 定义数据长什么样：

```cpp
struct SharedData
{
    int count = 0;
};
```

`app/main.cpp` 创建数据，并把地址传给两个库：

```cpp
SharedData data;
PrintCount(&data);  // B 读到 0
AddOne(&data);      // A 把它改成 1
PrintCount(&data);  // B 读到 1
```

`&data` 就是“这份数据的地址”。两个库收到的都是这个地址，因此操作的是同一个对象。

库 A 的 `writer/writer.cpp` 只有一个操作：

```cpp
data->count += 1;
```

`data->count` 表示“通过指针访问那份数据里的 count”。

库 B 的 `reader/reader.cpp` 读取它并打印：

```cpp
std::printf("Reader: count = %d\n", data->count);
```

这里 B 的参数是 `const SharedData *`，表示 B 只能通过这个指针读取数据，不能修改。

## 记住这几点就够了

- 公共头文件只定义结构体，不会自动创建共享对象。真正的对象是主程序里的 `data`。
- A、B 不需要互相调用或链接；它们通过同一份数据传递状态。这里由主程序安排先修改、再读取。
- 数据由主程序管理。本例所有调用结束后 `main()` 才退出，所以调用期间数据一直有效。
- 这是同一进程中的普通指针，没有用到跨进程共享内存，也没有线程。以后如果多个线程同时读写，需要另加同步保护。

头文件中的 `Q_DECL_EXPORT` / `Q_DECL_IMPORT` 用来导出和导入动态库函数。初学时先关注 `main.cpp`、`AddOne()` 和 `PrintCount()` 即可。
