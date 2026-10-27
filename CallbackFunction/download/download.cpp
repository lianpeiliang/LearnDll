#include "download.h"
#include <cstdio>

void DownloadFile(const char *fileName, DownloadCallback onFinished)
{
    // 为了简单，只打印一句话，模拟下载完成。
    std::printf("B: Downloading %s... (simulated)\n", fileName);

    if (onFinished)
    {
        onFinished(fileName); // B 调用 A 传来的函数，通知 A 下载完成。
    }
}
