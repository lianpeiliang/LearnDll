# 超简单的消息总线示例

同一个进程里，登录动态库发送消息，通知动态库接收消息。
使用 Qt 的信号和槽实现，不涉及跨进程通信。

## 怎么运行

用 Qt Creator 打开本目录下的 `LearnDll.pro`，选择桌面 Qt Kit，构建并运行 `MessageBusDemo`。
支持 Qt 5 / Qt 6。生成的程序和三个动态库统一放在构建目录的 `bin` 中。

预期输出：

```text
[Login] login succeeded
[Notice] welcome Alice
```

## 文件分工

```text
MessageBus/
  LearnDll.pro          总工程，安排各子工程的编译顺序
  bus/                  消息总线动态库：MessageBusCore
    messagebus.h/.cpp   定义信号，发布时 emit 信号
    bus.pro
  login/                登录动态库：LoginModule
    login.h/.cpp        发布 login_success，附带用户名 Alice
    login.pro
  notice/               通知动态库：NoticeModule
    notice.h/.cpp       订阅消息，收到 login_success 后打印欢迎信息
    notice.pro
  app/
    main.cpp            创建总线，先订阅，再登录
    app.pro
```

## 先看这三行

```cpp
MessageBus bus;        // 创建消息总线。
SubscribeLogin(&bus); // 通知模块订阅消息。
Login(&bus);          // 登录模块发布消息。
```

消息走向：

```text
登录库 → bus.publish("login_success", "Alice")
       → 总线发出 message 信号
       → 通知库的 lambda 收到消息
       → 打印 welcome Alice
```

`event` 是事件名，`text` 是附带的数据。为了方便理解，本例都用 `QString`。
总线把每条消息发给所有订阅者，订阅者用 `if` 判断是否处理。
可以再连接一个 lambda，这样同一条消息就能通知多个模块。

登录库和通知库都依赖总线库，但彼此没有直接依赖。
主程序把同一个 `bus` 地址传给它们，保证它们使用的是同一个对象。

注意先订阅、再发布：这个简单总线不保存历史消息。
本例在同一个线程同步执行，发布时订阅者立即处理；学习时暂不涉及多线程或动态卸载库。

头文件里的 `Q_DECL_EXPORT` / `Q_DECL_IMPORT` 用于导出和导入 DLL 中的类或函数。
`Q_OBJECT` 让 Qt 为总线生成信号所需的代码，qmake 会自动安排这个步骤。
