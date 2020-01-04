.RECIPEPREFIX = -
# Specify extensions of files to delete when cleaning
CLEANEXTS   = o a 

# Specify the target file and the install directory
OUTPUTFILE  = libsupersimpleprogressbar.a
INSTALLDIR  = bin

# Build object file
progress_bar.o: src/progress_bar.cpp
- g++ $< -o $@ -c

# Build library from object files
$(OUTPUTFILE): progress_bar.o
- ar ru $@ $^
- ranlib $@

# Default target
.PHONY: all
all: $(OUTPUTFILE)

.PHONY: install
install:
- mkdir -p $(INSTALLDIR)
- cp -p $(OUTPUTFILE) $(INSTALLDIR)
- cp -p "src/progress_bar.hpp" $(INSTALLDIR)
- cp -p "src/colors.hpp" $(INSTALLDIR)

.PHONY: clean 
clean:
- for file in $(CLEANEXTS); do rm -f *.$$file; done
