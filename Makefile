# Declaration of variables
CC = g++
CC_FLAGS = -Wall -g -std=c++11 
LIBS = -lrt

#directory names
SRCDIR = SRC
OBJDIR = OBJ

# File names
EXEC = run
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

#all:
#	@echo $(OBJECTS)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $^ -o $(EXEC) $(LIBS)

# To obtain object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
