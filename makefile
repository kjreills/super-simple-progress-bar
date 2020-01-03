.RECIPEPREFIX = -
# Specify extensions of files to delete when cleaning
CLEANEXTS   = o a 

# Specify the target file and the install directory
OUTPUTFILE  = libsupersimpleprogressbar.a
INSTALLDIR  = ../bin

# Default target
.PHONY: build
build: "src/progress_bar.o"

progress_bar.o: "src/progress_bar.cpp"
- g++ -o $@ $^

.PHONY: all
all: $(OUTPUTFILE)

# Build library from object files
# Object files are built automatically from .cpp files by make's database of implicit rules
$(OUTPUTFILE): "src/progress_bar.o"
- ar ru $@ $^
- ranlib $@

.PHONY: install
install:
- mkdir -p $(INSTALLDIR)
- cp -p $(OUTPUTFILE) $(INSTALLDIR)

.PHONY: clean 
clean:
- for file in $(CLEANEXTS); do rm -f *.$$file; done

# Indicate dependencies of .cpp files on .hpp files
progress_bar.o: progress_bar.hpp colors.hpp
