# alaasalah142@gmail.com
# Compiler and flags
CXX       = clang++
CXXFLAGS  = -std=c++23 -Wall -Iinclude -Itest/doctest

# Directories
SRCDIR       = src
DS_SRCDIR    = $(SRCDIR)/data_structures
GRAPH_SRCDIR = $(SRCDIR)/graph
TESTDIR      = test

UTILS_OBJ   = $(DS_SRCDIR)/utils.o
GRAPH_OBJ	= $(GRAPH_SRCDIR)/graph.o
ALGO_OBJ	= $(GRAPH_SRCDIR)/algorithms.o

# Source files
SRC_OBJECTS = $(UTILS_OBJ) \
              $(GRAPH_OBJ) \
              $(ALGO_OBJ)

# Test exe's
TEST_ALGO  = $(TESTDIR)/doctest_algorithms
TEST_DS    = $(TESTDIR)/doctest_data_structures

# Demo exe
DEMO	   = demo

# Default targets
all: $(TEST_ALGO) $(TEST_DS) $(DEMO)

# Build doctest_algorithms.exe
$(TEST_ALGO): $(TESTDIR)/doctest_algorithms.cpp $(SRC_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Build doctest_data_structures.exe
$(TEST_DS): $(TESTDIR)/doctest_data_structures.cpp $(SRC_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Build demo.exe
$(DEMO): main.cpp $(SRC_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(DS_SRCDIR)/%.o: $(DS_SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(GRAPH_SRCDIR)/%.o: $(GRAPH_SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build only demo
demo: $(DEMO)

# Build only tests
test: $(TEST_ALGO) $(TEST_DS)

# Valgrind targets
valgrind-algo: $(TEST_ALGO)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_ALGO)

valgrind-ds: $(TEST_DS)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_DS)

valgrind-demo: $(DEMO)
	valgrind --leak-check-full --show-leak-kinds=all ./$(DEMO)

clean:
	rm -f $(DS_SRCDIR)/*.o $(GRAPH_SRCDIR)/*.o $(TEST_ALGO) $(TEST_DS) $(DEMO)

.PHONY: all clean valgrind-algo valgrind-ds