EXEC = MyLeetCode
SRC_DIR = ../../catch ../../include ../../src
SOURCES := $(foreach x, ${SRC_DIR},\
	$(wildcard \
	$(addprefix ${x}/*,.cpp)))
OBJECTS = $(SOURCES:.cpp=.o)

CXX = g++
CXXFLAGS = -I../../catch -I../../include -I../../src -std=c++11

$(EXEC): $(OBJECTS)
	$(CXX) -o $@ $^

.PHONY : clean
clean:
	$(RM) $(OBJECTS)
	$(RM) $(EXEC)
