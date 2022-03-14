cdir := BLACS/TESTING

#  ---------------------------------------------------------------------
#  The file tools.f contains some LAPACK routines that the tester calls.
#  If you have ScaLAPACK, you may point to your tools library instead
#  of compiling this file.
#  ---------------------------------------------------------------------
blacs_tools = \
	$(cdir)/tools.o

blacs_tst = \
	$(cdir)/blacstest.o \
	$(cdir)/btprim.o

blacsexe = \
	$(cdir)/xCbtest \
	$(cdir)/xFbtest

blacsexe: $(blacsexe)

$(cdir)/Cbt.o: $(cdir)/Cbt.c
	$(CC) -c -o $@ $(CDEFS) $(CCFLAGS) -DBTCINTFACE $<

# Putting SCALAPACKLIB in $^ presumes it is static (.a).
$(cdir)/xCbtest: $(blacs_tst) $(blacs_tools) $(cdir)/Cbt.o $(SCALAPACKLIB)
	$(FCLOADER) $(FCLOADFLAGS) -o $@ $^

$(cdir)/xFbtest: $(blacs_tst) $(blacs_tools) $(SCALAPACKLIB)
	$(FCLOADER) $(FCLOADFLAGS) -o $@ $^

#  --------------------------------------------------------------------
#  The files tools.f and blacstest.f are compiled without optimization.
#  Tools.f contains the LAPACK routines slamch and dlamch, which only
#  operate correctly for low-levels of optimization.  Blacstest.f is
#  extremely large, and optimizing it takes a long time.  More
#  importantly, the sun's f77 compiler seems to produce errors in
#  trying to optimize such a large file.  We therefore insist that it
#  also not be optimized.
#  --------------------------------------------------------------------
$(cdir)/tools.o: $(cdir)/tools.f
	$(FC) $(NOOPT) -c -o $@ $<

$(cdir)/blacstest.o: $(cdir)/blacstest.f
	$(FC) $(NOOPT) -c -o $@ $<

cleanexe += $(blacsexe) $(blacs_tools) $(blacs_tst) $(cdir)/Cbt.o
