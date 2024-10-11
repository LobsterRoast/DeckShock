CXXFLAGS := -Wall
LDFLAGS := `pkg-config --cflags --libs sdl2`

CXX := g++
SRC := DeckShock.cpp bluetooth_integration.cpp
OBJS :=$(SRC:.cpp=.o)
TARGET := DeckShock

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

rebuild:
	$(MAKE) clean
	$(MAKE) all