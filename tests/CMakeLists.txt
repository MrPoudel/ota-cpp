add_executable(test_updater test_updater.cpp)
target_link_libraries(test_updater PRIVATE gtest gtest_main ota)
add_test(NAME test_updater COMMAND test_updater)
