#include <glog/logging.h>

int main(int argc, char **argv) {
    FLAGS_log_dir = "./";
    FLAGS_logtostdout = true;
    FLAGS_alsologtostderr = false;
    google::InitGoogleLogging(argv[0]);

    LOG(INFO) << "Hello World!";
    return 0;
}