add_executable(mlapp
    ml.cpp
)

target_compile_features(mlapp PRIVATE cxx_std_17)

target_link_libraries(mlapp PRIVATE 
    fmt::fmt 
    spdlog::spdlog_header_only
)
