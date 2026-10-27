#include "business.h"
#include "download.h"
#include <cstdio>

// 回调函数写在 A 里，等 B 完成后调用它。
static void OnDownloadFinished(const char *fileName)
{
    std::printf("A: Received download-complete notification: %s\n", fileName);
}

void DoWork()
{
    std::printf("A: Asking B to download a file.\n");
    DownloadFile("hello.txt", &OnDownloadFinished); // 把函数地址交给 B。
}
