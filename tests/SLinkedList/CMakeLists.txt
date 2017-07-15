add_executable(tester_SLinkedList
               tester_slinkedlist.h
               tester_slinkedlist.cpp
               main.cpp)
target_link_libraries(tester_SLinkedList gtest_main gtest)
