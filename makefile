GTEST_DIR=~/Embedded_Systems_Project/googletest/googletest

link : linked_list_testcase.o linked_list.o Gtest_main.o libgtest.a
	g++ -isystem ${GTEST_DIR}/include linked_list_testcase.c linked_list.c Gtest_main.c libgtest.a -pthread -o my_test
linked_list_testcase.o : linked_list_testcase.c
	g++ -c -isystem ${GTEST_DIR}/include -I${GTEST_DIR} linked_list_testcase.c
linked_list.o : linked_list.c
	g++ -c linked_list.c
Gtest_main.o : Gtest_main.c
	g++ -c -isystem ${GTEST_DIR}/include -I${GTEST_DIR} Gtest_main.c
libgtest.a :
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o
clean:
	rm -f *.o

