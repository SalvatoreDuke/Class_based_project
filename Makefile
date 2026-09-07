CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g
SRCDIR   := src
SRCS     := $(wildcard $(SRCDIR)/*.cpp)
OBJS     := $(SRCS:.cpp=.o)
TARGET   := sistema

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
