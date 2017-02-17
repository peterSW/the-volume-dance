add_executable (test AllTests.cpp speedTest.cpp VolumeIndexing.cpp  VolumeSize.cpp test.cpp gtest/gtest-all.cc)
include_directories(../include .)

find_package (Threads)
target_link_libraries (test ${CMAKE_THREAD_LIBS_INIT})

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE=1)
endif()
