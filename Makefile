CXX        := g++
SUBDIRS    := 
INC_FLAGS  := $(addprefix -Isrc/, $(SUBDIRS))
CXXFLAGS   := -Wall -Wextra -std=c++11 -I. -Isrc $(INC_FLAGS)
TARGET     := campusGuard
TARGETTEST := $(TARGET)test

SRCS       := $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
HEADERS    := $(wildcard src/*.h) $(wildcard src/*/*.h)
PDFS       := 

ZIP_NAME   := prac.zip

.PHONY: all run test runtest zip val clean coverage

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@

run: $(TARGET)
	./$(TARGET)

test: $(TARGETTEST)

$(TARGETTEST): $(SRCS)
	$(CXX) -g $(CXXFLAGS) $(SRCS) -o $@

runtest: $(TARGETTEST)
	gdb ./$(TARGETTEST)

zip:
	zip -j $(ZIP_NAME) $(SRCS) $(HEADERS) $(PDFS) Makefile 

val: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm -f $(TARGET) $(TARGETTEST) $(ZIP_NAME)

coverage:
	cd src 
	$(CXX) --coverage *.cpp -o $(TARGET) && ./$(TARGET) 
	gcov -f -m -r *.gcno 
	rm -f *.o $(TARGET) *.gcda *.gcno *.gcov *.json.gz *.gcov.json