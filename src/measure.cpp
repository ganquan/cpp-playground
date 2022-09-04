

#include <glog/logging.h>

#include <functional>

void measure(std::string label, std::function<void()> const & lambda) {
    auto start = std::chrono::high_resolution_clock::now();

    lambda();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    LOG(INFO) << "measure " << label << " cost: " << elapsed.count() << " ms\n";
}

int main(int argc, char** argv) {
    FLAGS_log_dir = "./";
    FLAGS_logtostdout = true;
    FLAGS_alsologtostderr = false;
    google::InitGoogleLogging(argv[0]);

    measure("test measure", []() {
        LOG(INFO) << "Enter lambda.";
        LOG(INFO) << "Leave lambda.";
    });

    LOG(INFO) << "end of main()";
    return 0;
}