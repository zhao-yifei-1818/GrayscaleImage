# compiler options
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -std=c++17 -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion

# list .h files here
HEADERS = GrayscaleImage.h

# list .cpp files here
TEST_FILES = GrayscaleImageTester.cpp GrayscaleImage.cpp

.PHONY: all
all: tests.exe

tests.exe: $(TEST_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_FILES) -o $@

.PHONY: clean
clean:
	rm -f tests.exe
