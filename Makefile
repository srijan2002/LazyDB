
test:
	g++ -o runAllTests unit-tests/runAllTests.cpp -lgtest -lgtest_main -pthread && ./runAllTests && rm -rf runAllTests

run:
	g++ main.cpp -o main && "/home/srijan/Desktop/LazyDB/"main