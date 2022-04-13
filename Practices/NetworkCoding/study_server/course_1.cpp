/* ************************************************************************
> File Name:     course.cpp
> Author:         汪泽中
> Created Time:  2021年10月29日 星期五 07时33分21秒
> Description:
 ************************************************************************/
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>

// #include <bits/stdc++.h>

double calculate(double v) {
    if (v <= 0)
        return v;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return std::sqrt(v * v + std::sqrt(v - 5) * (v * 23.223) / v);
}

template <typename Iter, typename Fun>
double visitRange(std::thread::id id, Iter iterBegin, Iter iterEnd, Fun fun) {
    auto curThreadID = std::this_thread::get_id();
    if (id == curThreadID)
        std::cout << curThreadID << " this is main thread\n";
    else
        std::cout << curThreadID << " this is work thread\n";

    double v = 0;
    for (auto iter = iterBegin; iter != iterEnd; ++iter) v += fun(*iter);
    return v;
}

void printNum(int times) {
    for (int i = 0; i < times; ++i) {
        std::cout << i << std::endl;
    }
}

int main() {
    auto mainThreadId = std::this_thread::get_id();
    std::vector<double> v;
    for (int i = 0; i < 1000; ++i) {
        v.push_back(rand());
    }
    std::cout << v.size() << std::endl;
    clock_t startTime = clock();
    double value = 0;
    for (int i = 0; i < v.size(); ++i) {
        value += calculate(v[i]);
    }
    std::cout << "single thread: " << value << std::endl;
    clock_t endTime = clock();
    std::cout << "need time = " << endTime - startTime << std::endl;

    startTime = clock();
    std::cout << "mutil thread => \n";
    auto iteHalf = v.begin() + v.size() / 2;
    double secondHalfResult = 0.0;
    auto iteEnd = v.end();

    // 单开一个线程计算
    std::thread s([&secondHalfResult, mainThreadId, iteHalf, iteEnd]() {
        secondHalfResult = visitRange(mainThreadId, iteHalf, iteEnd, calculate);
    });

    // 主线程计算
    double firstHalfResult =
        visitRange(mainThreadId, v.begin(), iteHalf, calculate);

    // 清理工作
    if (s.joinable()) {
        s.join();
    }
    endTime = clock();
    std::cout << firstHalfResult + secondHalfResult << std::endl;
    std::cout << "need time = " << endTime - startTime << std::endl;

    int num = 10000;
    std::thread t([num] { printNum(num); });
    // 当主线程结束后会杀死 t
    // t.detach();
    if (t.joinable()) {
        t.join();
    }
}
