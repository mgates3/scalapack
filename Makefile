############################################################################
#
#  Program:         ScaLAPACK
#
#  Module:          Makefile
#
#  Purpose:         Top-level Makefile
#
#  Send bug reports, comments or suggestions to scalapack@cs.utk.edu
#
############################################################################
#
### todo: F77 changed to FC?
#
#  The library can be set up to include routines for any combination of the
#  four PRECISIONS.  First, modify the ARCH, ARCHFLAGS, RANLIB, F77, CC,
#  F77FLAGS, CCFLAGS, F77LOADER, CCLOADER, F77LOADFLAGS, CCLOADFLAGS and
#  CDEFS definitions in SLmake.inc to match your library archiver, compiler
#  and the options to be used.
#
#  The command
#       make
#  without any arguments creates the library of precisions defined by the
#  environment variable PRECISIONS as well as the corresponding testing
#  executables,
#       make lib
#  creates only the library,
#       make exe
#  creates only the testing executables.
#       make example
#  creates only the example
#
#  The name of the library is defined in the file called SLmake.inc and
#  is created at this directory level.
#
#  To remove the object files after the library and testing executables
#  are created, enter
#       make clean
#
############################################################################

include SLmake.inc

# Set default PRECISIONS if not in SLmake.inc and decode.
PRECISIONS ?= single double complex complex16

ifneq ($(findstring single, $(PRECISIONS)),)
    single = 1
endif
ifneq ($(findstring double, $(PRECISIONS)),)
    double = 1
endif
ifneq ($(findstring complex, $(PRECISIONS)),)
    complex = 1
endif
ifneq ($(findstring complex16, $(PRECISIONS)),)
    complex16 = 1
endif

# Set default library if not in SLmake.inc, and select static or shared.
SCALAPACKLIB_a  ?= libscalapack.a
SCALAPACKLIB_so ?= libscalapack.so

ifeq ($(shared),1)
    SCALAPACKLIB ?= $(SCALAPACKLIB_so)
    CCFLAGS += -fPIC
    FCFLAGS += -fPIC
    LDFLAGS += -fPIC
else
    SCALAPACKLIB ?= $(SCALAPACKLIB_a)
endif

############################################################################
# Targets

.PHONY: all lib exe clean

all: lib exe #example

lib: $(SCALAPACKLIB)

exe: blacsexe #pblasexe redistexe scalapackexe

clean: cleanlib cleanexe cleanexample

cleanlib :=
cleanlib:
	-rm -f $(SCALAPACKLIB)
	-rm -f $(lib_obj)
	-rm -f $(cleanlib)

cleanexe :=
cleanexe:
	-rm -f $(cleanexe)

cleanexample :=
cleanexample:
	-rm -f $(cleanexample)

############################################################################
# Include subdirectories.
# Each subdir adds to $(lib_obj), $(cleanlib), $(cleanexe), $(cleanexample),
# which must be immediate variables defined by := for += to work properly.

lib_obj :=

subdirs := \
	BLACS/SRC/Makefile.inc \
	BLACS/TESTING/Makefile.inc \
	# end

-include $(subdirs)

############################################################################
# File rules

# Remove all built-in rules.
.SUFFIXES:

.DELETE_ON_ERROR:

$(SCALAPACKLIB): $(lib_obj)

# Build static libraries.
%.a:
	$(ARCH) $(ARCHFLAGS) $@ $^
	$(RANLIB) $@

# Build shared libraries.
%.so:
	$(FC) $(LDFLAGS) -shared -o $@ $^ $(LIBS)

# Compile Fortran sources.
%.o: %.f
	$(FC) -c -o $@ $(FCFLAGS) $<

%.o: %.f90
	$(FC) -c -o $@ $(FCFLAGS) $<

# Compile C sources.
%.o: %.c
	$(CC) -c -o $@ $(CDEFS) $(CCFLAGS) $<

# Special rule for BLACS to build C interfaces with _c suffix.
%_c.o: %.c
	$(CC) -c -o $@ $(CDEFS) $(CCFLAGS) -DCallFromC $<

############################################################################
# Debugging

echo:
	@echo "CC      = $(CC)"
	@echo "FC      = $(FC)"
	@echo "ARCH    = $(ARCH)"
	@echo "RANLIB  = $(RANLIB)"
	@echo
	@echo "CDEFS   = $(CDEFS)"
	@echo "CCFLAGS = $(CCFLAGS)"
	@echo "FCFLAGS = $(FCFLAGS)"
	@echo
	@echo "SCALAPACKLIB_a  = $(SCALAPACKLIB)"
	@echo "SCALAPACKLIB_a  = $(SCALAPACKLIB)"
	@echo "SCALAPACKLIB_a  = $(SCALAPACKLIB)"
	@echo
	@echo "lib_obj = $(lib_obj)"
	@echo
	@echo "PRECISIONS = $(PRECISIONS)"
	@echo "single     = $(single)"
	@echo "double     = $(double)"
	@echo "complex    = $(complex)"
	@echo "complex16  = $(complex16)"
