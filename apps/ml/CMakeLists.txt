add_executable(mlapp
    ml.cpp
)

target_compile_features(mlapp PRIVATE cxx_std_17)

target_link_libraries(mlapp PRIVATE 
    fmt::fmt 
    spdlog::spdlog_header_only
)

add_executable(mnist_simple
    mnist_simple.cpp
)
target_link_libraries(mnist_simple PRIVATE 
    armadillo
    fmt::fmt 
    spdlog::spdlog_header_only
)
