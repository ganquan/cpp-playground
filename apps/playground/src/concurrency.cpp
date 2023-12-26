#include <future>
#include <iostream>
#include <thread>

void foo() {
    std::cout << "foo()" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
}

void bar(int i) {
    i += 1;
    std::cout << "bar(), i += 1: " << i << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
}

void bar_ref(int &i) {
    i += 1;
    std::cout << "bar_ref(), i += 1: " << i << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void bar_promise(std::promise<int> &promise) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    promise.set_value(42);
}

int main() {

    std::packaged_task<int(int, int)> task([](int a, int b) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        return a + b;
    });

    auto future_task = task.get_future();
    task(5, 8);

    std::cout << "future = " << future_task.get() << std::endl;
#if 1

    std::promise<int>
        p;
    std::thread bar_promise_thread(bar_promise, std::ref(p));
    bar_promise_thread.detach();
    /* bar_promise_thread.join(); */
    std::future<int> future = p.get_future();
    std::cout << "future = " << future.get() << std::endl;

    std::promise<int> p2;
    auto f2 = p2.get_future();
    std::thread lambda_thread([&p2]() {
        std::cout << "this is lambda_thread" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        p2.set_value(50);
    });
    lambda_thread.detach();
    std::cout << "f2 = " << f2.get() << std::endl;

#else
    std::thread foo_thread(foo);
    int i = 2;
    int j = 3;
    std::thread bar_thread(bar, i);
    std::thread bar_thread2(bar, std::ref(j));

    foo_thread.join();

    bar_thread.join();
    bar_thread2.join();
    std::cout << "mainthread: i = " << i << std::endl;
    std::cout << "mainthread: j = " << j << std::endl;

    std::thread bar_ref_thread(bar_ref, std::ref(j));
    bar_ref_thread.join();

    std::cout << "mainthread: j = " << j << std::endl;

    std::thread lambda_thread([]() {
        std::cout << "this is lambda_thread" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    });

    lambda_thread.join();
#endif

    return 0;
}
