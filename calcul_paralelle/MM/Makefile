CPP_FLAGS      = # -g # -std=c90 is twice slower!
LINK_FLAGS     = # 
LINK_LIBRARIES = # -fopenmp -lfpvm3 -lpvm3 
CC_OPTIONS     = -g -O3 $(CPP_FLAGS) $(LINK_FLAGS) $(LINK_LIBRARIES)
EXEC_DIR       = $(HOME)/pvm3/bin/$(PVM_ARCH)

#
# VARIOUS SEQUENTIAL MATRIX MULTIPLY PROGRAMS
#

MATRIX_SIZE = 1000
MIN_COLUMN_WIDTH = 8
   # See /sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size in modern Linux
   # divide by 8 for doubles, divide by two for unaligned data
MIN_ROW_HEIGHT = 8
   # See /sys/devices/system/cpu/cpu0/cache/index0/ways_of_associativity
   #
   # Obtain all the cache information with the shell command:
   # grep . /sys/devices/system/cpu/cpu0/cache/index*/*
   #
   # Other informations on the CPUs:
   # lscpu
   # cat /proc/cpuinfo
   #
   # Benchmarked performances:
   # http://browser.primatelabs.com/

MM: MMNaive \
    MMRegister MMLocalSum \
    MMNaive03 \
    MMUnfolded4 \
    MMInterchanged \
    MMTranspose \
    MMUnfolded2x2 \
    MMBlocked10 MMBlocked20 MMBlocked40 MMBlocked50 MMBlocked100 MMBlocked250 \
    MMBlockedRectangular4-8 MMBlockedRectangular8-8 MMBlockedRectangular8-4 MMBlockedRectangular40-8 \
    MMRecursive \
    MMRecursiveBlocked-4K MMRecursiveBlocked-8K MMRecursiveBlocked-16K MMRecursiveBlocked-32K \
    MMRecursiveRectangular4-8 MMRecursiveRectangular8-8 MMRecursiveRectangular8-4 MMRecursiveRectangular40-8 \
    Sustained \
    Makefile

MMNaive: MMNaive.c matrixalloc.h timer.h Makefile
	cc MMNaive.c -o MMNaive -DMATRIX_SIZE=$(MATRIX_SIZE)
MMRegister: MMRegister.c matrixalloc.h timer.h Makefile
	cc MMRegister.c -o MMRegister -DMATRIX_SIZE=$(MATRIX_SIZE) $(CC_OPTIONS)
MMLocalSum: MMLocalSum.c matrixalloc.h timer.h Makefile
	cc MMLocalSum.c -o MMLocalSum -DMATRIX_SIZE=$(MATRIX_SIZE) $(CC_OPTIONS)
MMNaive03: MMNaive.c matrixalloc.h timer.h Makefile
	cc MMNaive.c -o MMNaive03 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) $(CC_OPTIONS)
MMUnfolded4: MMUnfolded4.c matrixalloc.h timer.h Makefile
	cc MMUnfolded4.c -o MMUnfolded4 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) $(CC_OPTIONS)
MMInterchanged: MMInterchanged.c matrixalloc.h timer.h Makefile
	cc MMInterchanged.c -o MMInterchanged -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) $(CC_OPTIONS)
MMTranspose: MMTranspose.c matrixalloc.h timer.h Makefile
	cc MMTranspose.c -o MMTranspose -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) $(CC_OPTIONS)
MMUnfolded2x2: MMUnfolded2x2.c matrixalloc.h timer.h Makefile
	cc MMUnfolded2x2.c -o MMUnfolded2x2 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) $(CC_OPTIONS)
MMBlocked10: MMBlocked.c matrixalloc.h timer.h Makefile
	cc MMBlocked.c -o MMBlocked10 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) -DBLOCK_SIZE=10 $(CC_OPTIONS)
MMBlocked20: MMBlocked.c matrixalloc.h timer.h Makefile
	cc MMBlocked.c -o MMBlocked20 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) -DBLOCK_SIZE=20 $(CC_OPTIONS)
MMBlocked40: MMBlocked.c matrixalloc.h timer.h Makefile
	cc MMBlocked.c -o MMBlocked40 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) -DBLOCK_SIZE=40 $(CC_OPTIONS)
MMBlocked50: MMBlocked.c matrixalloc.h timer.h Makefile
	cc MMBlocked.c -o MMBlocked50 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) -DBLOCK_SIZE=50 $(CC_OPTIONS)
MMBlocked100: MMBlocked.c matrixalloc.h timer.h Makefile
	cc MMBlocked.c -o MMBlocked100 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) -DBLOCK_SIZE=100 $(CC_OPTIONS)
MMBlocked250: MMBlocked.c matrixalloc.h timer.h Makefile
	cc MMBlocked.c -o MMBlocked250 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) -DBLOCK_SIZE=250 $(CC_OPTIONS)
MMBlockedRectangular4-8: MMBlockedRectangular.c matrixalloc.h timer.h Makefile
	cc MMBlockedRectangular.c -o MMBlockedRectangular4-8 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) -DMIN_COLUMN_WIDTH=8 -DMIN_ROW_HEIGHT=4 $(CC_OPTIONS)
MMBlockedRectangular8-8: MMBlockedRectangular.c matrixalloc.h timer.h Makefile
	cc MMBlockedRectangular.c -o MMBlockedRectangular8-8 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) -DMIN_COLUMN_WIDTH=8 -DMIN_ROW_HEIGHT=8 $(CC_OPTIONS)
MMBlockedRectangular8-4: MMBlockedRectangular.c matrixalloc.h timer.h Makefile
	cc MMBlockedRectangular.c -o MMBlockedRectangular8-4 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) -DMIN_COLUMN_WIDTH=4 -DMIN_ROW_HEIGHT=8 $(CC_OPTIONS)
MMBlockedRectangular40-8: MMBlockedRectangular.c matrixalloc.h timer.h Makefile
	cc MMBlockedRectangular.c -o MMBlockedRectangular40-8 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) -DMIN_COLUMN_WIDTH=8 -DMIN_ROW_HEIGHT=40 $(CC_OPTIONS)
MMRecursive: MMRecursive.c matrixalloc.h timer.h Makefile
	cc MMRecursive.c -o MMRecursive -DMATRIX_SIZE=$(MATRIX_SIZE) $(CC_OPTIONS)
MMRecursiveBlocked-4K: MMRecursiveBlocked.c matrixalloc.h timer.h Makefile
	cc MMRecursiveBlocked.c -o MMRecursiveBlocked-4K -DMATRIX_SIZE=$(MATRIX_SIZE) $(CC_OPTIONS) -DCACHE_SIZE=4
MMRecursiveBlocked-8K: MMRecursiveBlocked.c matrixalloc.h timer.h Makefile
	cc MMRecursiveBlocked.c -o MMRecursiveBlocked-8K -DMATRIX_SIZE=$(MATRIX_SIZE) $(CC_OPTIONS) -DCACHE_SIZE=8
MMRecursiveBlocked-16K: MMRecursiveBlocked.c matrixalloc.h timer.h Makefile
	cc MMRecursiveBlocked.c -o MMRecursiveBlocked-16K -DMATRIX_SIZE=$(MATRIX_SIZE) $(CC_OPTIONS) -DCACHE_SIZE=16
MMRecursiveBlocked-32K: MMRecursiveBlocked.c matrixalloc.h timer.h Makefile
	cc MMRecursiveBlocked.c -o MMRecursiveBlocked-32K -DMATRIX_SIZE=$(MATRIX_SIZE) $(CC_OPTIONS) -DCACHE_SIZE=32
MMRecursiveRectangular4-8: MMRecursiveRectangular.c matrixalloc.h timer.h Makefile
	cc MMRecursiveRectangular.c -o MMRecursiveRectangular4-8 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) -DMIN_COLUMN_WIDTH=8 -DMIN_ROW_HEIGHT=4 $(CC_OPTIONS)
MMRecursiveRectangular8-8: MMRecursiveRectangular.c matrixalloc.h timer.h Makefile
	cc MMRecursiveRectangular.c -o MMRecursiveRectangular8-8 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) -DMIN_COLUMN_WIDTH=8 -DMIN_ROW_HEIGHT=8 $(CC_OPTIONS)
MMRecursiveRectangular8-4: MMRecursiveRectangular.c matrixalloc.h timer.h Makefile
	cc MMRecursiveRectangular.c -o MMRecursiveRectangular8-4 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) -DMIN_COLUMN_WIDTH=4 -DMIN_ROW_HEIGHT=8 $(CC_OPTIONS)
MMRecursiveRectangular40-8: MMRecursiveRectangular.c matrixalloc.h timer.h Makefile
	cc MMRecursiveRectangular.c -o MMRecursiveRectangular40-8 -O3 -DMATRIX_SIZE=$(MATRIX_SIZE) -DMIN_COLUMN_WIDTH=8 -DMIN_ROW_HEIGHT=40 $(CC_OPTIONS)
Sustained: Sustained.c timer.h Makefile
	cc Sustained.c -o Sustained -DMATRIX_SIZE=$(MATRIX_SIZE) -DBLOCK_SIZE=4 $(CC_OPTIONS)

clean:
	rm MMNaive \
      MMRegister MMLocalSum \
      MMNaive03 \
      MMUnfolded4 \
      MMInterchanged \
      MMTranspose \
      MMUnfolded2x2 \
      MMBlocked10 MMBlocked20 MMBlocked40 MMBlocked50 MMBlocked100 MMBlocked250 \
      MMBlockedRectangular4-8 MMBlockedRectangular8-8 MMBlockedRectangular8-4 MMBlockedRectangular40-8 \
      MMRecursive \
      MMRecursiveBlocked-4K MMRecursiveBlocked-8K MMRecursiveBlocked-16K MMRecursiveBlocked-32K \
      MMRecursiveRectangular4-8 MMRecursiveRectangular8-8 MMRecursiveRectangular8-4 MMRecursiveRectangular40-8 \
      Sustained \

