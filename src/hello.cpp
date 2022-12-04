#include <future>
#include <glog/logging.h>
#include <iostream>
#include <thread>

int foo() {

    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 2;
}

int main(int argc, char **argv) {
    FLAGS_log_dir = "./";
    FLAGS_logtostdout = true;
    FLAGS_alsologtostderr = false;
    google::InitGoogleLogging(argv[0]);

    auto future = std::async(std::launch::async, []() {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        return 42;
    });

    auto future2 = std::async(std::launch::async, foo);

    // Do something else ?
    LOG(INFO) << "Hello World!";
    LOG(INFO) << "Wait 5 sec...";

    future.wait();
    future2.wait();

    std::cout << future2.get() << std::endl;
    std::cout << future.get() << std::endl;

    return 0;
}
