#########
# FLAGS #
#########


### GENERAL FLAGS

CC_ASSERTIONS = -DPRE_CONDITIONS -DPOST_CONDITIONS -DINVARIANTS # -DCOSTLY_PRE_CONDITIONS -DCOSTLY_POST_CONDITIONS -DCOSTLY_INVARIANTS
   # Conditional compilation of assertions
   # Note. Comment in order to improve performances, *when the code is correct*!
   # Note 2.  The non-costly assertions usually do not harm the performances.

CC_TRACE = -DTRACE=1
   # Conditional compilation of trace.
   # Level 0 means no trace.  Higher levels usually give more and more details on the execution of a program.


### OPTIMISATION FLAGS

CC_OPTIMISATION = -O3
   # -O3 must always be set... at least for the final executable


### PVM FLAGS

PVM_INCLUDES = $(PVM_ROOT)/include
PVM_LIBRARIES = $(PVM_ROOT)/lib/$(PVM_ARCH)
CPP_FLAGS = -I$(PVM_INCLUDES) -g
LINK_FLAGS  = -L$(PVM_LIBRARIES)
LINK_LIBRARIES = -lpvm3 -lgpvm3 -lm
CC_OPTIONS = -g $(CPP_FLAGS) $(LINK_FLAGS) $(LINK_LIBRARIES)
EXEC_DIR = $(HOME)/pvm3/bin/$(PVM_ARCH)

#
# A SAMPLE PVM PROGRAM
#

sum: sum_farmer.exe sum_worker.exe
	echo "Done"

sum_farmer.exe: sum_farmer.cxx Makefile
	cc sum_farmer.cxx -o sum_farmer.exe $(CC_OPTIMISATION) $(CC_ASSERTIONS) $(CC_TRACE) $(CC_OPTIONS)
	cp sum_farmer.exe $(EXEC_DIR)

sum_worker.exe: sum_worker.cxx Makefile
	cc sum_worker.cxx -o sum_worker.exe $(CC_OPTIMISATION) $(CC_ASSERTIONS) $(CC_TRACE) $(CC_OPTIONS)
	cp sum_worker.exe $(EXEC_DIR)



clean:
	rm *.exe
