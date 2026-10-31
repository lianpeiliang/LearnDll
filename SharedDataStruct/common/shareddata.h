#pragma once

// 主程序和两个动态库都包含这个头文件，使用同一种数据结构。
struct SharedData
{
    int count = 0;
};
