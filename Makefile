# alaasalah142@gmail.com
# Compiler and flags
CXX       = clang++
CXXFLAGS  = -std=c++23 -Wall -Iinclude -Itest/doctest

# Directories
SRCDIR       = src
DS_SRCDIR    = $(SRCDIR)/data_structures
GRAPH_SRCDIR = $(SRCDIR)/graph
TESTDIR      = test

# Source files
SRC_OBJECTS = $(DS_SRCDIR)/utils.o \
              $(GRAPH_SRCDIR)/graph.o \
              $(GRAPH_SRCDIR)/algorithms.o

# Test exe's
TEST_ALGO  = $(TESTDIR)/doctest_algorithms
TEST_DS    = $(TESTDIR)/doctest_data_structures

# Default targets
all: $(TEST_ALGO) $(TEST_DS)

# Build doctest_algorithms.exe
$(TEST_ALGO): $(TESTDIR)/doctest_algorithms.cpp $(SRC_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Build doctest_data_structures.exe
$(TEST_DS): $(TESTDIR)/doctest_data_structures.cpp $(SRC_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(DS_SRCDIR)/%.o: $(DS_SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(GRAPH_SRCDIR)/%.o: $(GRAPH_SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Valgrind targets
valgrind-algo: $(TEST_ALGO)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_ALGO)

valgrind-ds: $(TEST_DS)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TEST_DS)

clean:
	rm -f $(DS_SRCDIR)/*.o $(GRAPH_SRCDIR)/*.o $(TEST_ALGO) $(TEST_DS)

.PHONY: all clean valgrind-algo valgrind-ds