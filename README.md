# LearnDll

学习同一个进程中，不同动态库之间如何通信，使用 Qt qmake（`.pro`）组织项目。

## 示例

- [导出函数接口](ExportedFunInterface/README.md)：主程序调用动态库 A，A 直接调用动态库 B 导出的 `Log()`。

用 Qt Creator 打开 `ExportedFunInterface/LearnDll.pro`，构建后运行 `Demo`。
