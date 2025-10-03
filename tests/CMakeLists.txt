add_executable(test_updater test_updater.cpp)
target_link_libraries(test_updater PRIVATE gtest gtest_main ota)
add_test(NAME test_updater COMMAND test_updater)

add_executable(test_manifest test_manifest.cpp)
target_link_libraries(test_manifest PRIVATE gtest gtest_main ota)
add_test(NAME test_manifest COMMAND test_manifest)
