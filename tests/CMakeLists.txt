add_executable (test AllTests.cpp VolumeIndexing.cpp  VolumeSize.cpp test.cpp gtest/gtest-all.cc)
include_directories(../include)

find_package (Threads)
target_link_libraries (test ${CMAKE_THREAD_LIBS_INIT})
