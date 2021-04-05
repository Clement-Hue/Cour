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
   # Caution.  The trace is send on the standard output, not the error one, so it can be mixed up with the expected result.


### APPLICATION FLAGS

IMAGE_WIDTH = 1080
N_MAX = 5000
DRY_RUN = false
   # false to generate actual images
   # true to compute them only in memory for finer performance computations


### OPTIMISATION FLAGS

CC_OPTIMISATION =  -O3
   # -O3 must always be set... at least for the final executable
CC_OPENMP = -fopenmp
   # Must be set when OpenMP is intended to be used


### PVM FLAGS

PVM_INCLUDES = $(PVM_ROOT)/include
PVM_LIBRARIES = $(PVM_ROOT)/lib/$(PVM_ARCH)
CPP_FLAGS = -I$(PVM_INCLUDES) -g
LINK_FLAGS  = -L$(PVM_LIBRARIES)
LINK_LIBRARIES = -lpvm3 -lm
CC_OPTIONS = -g $(CPP_FLAGS) $(LINK_FLAGS) $(LINK_LIBRARIES)
EXEC_DIR = $(HOME)/pvm3/bin/$(PVM_ARCH)/ # idem PVM_PATH

### OpenMPI FLAGS

NB_PROC = 13 # Number of processors plus one for the farmer


#########################
# SEQUENTIAL MANDELBROT #
#########################

seq:  MandelbrotSeq.exe
	echo "Done with sequential version"

MandelbrotSeq.exe: MandelbrotSeq.cxx Makefile
	g++ MandelbrotSeq.cxx -o MandelbrotSeq.exe -std=c++11 $(CC_OPTIMISATION) $(CC_ASSERTIONS) $(CC_TRACE) -DDRY_RUN=$(DRY_RUN)

#MandelbrotSeq.exe: MandelbrotImproved.cxx Makefile
#	g++ MandelbrotImproved.cxx -o MandelbrotSeq.exe -std=c++11 $(CC_OPTIMISATION) $(CC_OPENMP) $(CC_ASSERTIONS) $(CC_TRACE) -DDRY_RUN=$(DRY_RUN)

SamplesSeq:  MandelbrotSeq.exe
	./MandelbrotSeq.exe  0      0      3       2       $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_0_seq.ppm
	./MandelbrotSeq.exe  0     -1      1       1       $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_1_seq.ppm
	./MandelbrotSeq.exe  0     -1      0.25    0.25    $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_2_seq.ppm
	./MandelbrotSeq.exe -0.1   -1      0.1     0.1     $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_3_seq.ppm
	./MandelbrotSeq.exe -0.15  -1.03   0.02    0.02    $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_4_seq.ppm 
	./MandelbrotSeq.exe -0.165 -1.035  0.005   0.005   $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_5_seq.ppm 
	./MandelbrotSeq.exe -0.165 -1.036  0.0008  0.0008  $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_6_seq.ppm 
	./MandelbrotSeq.exe -0.165 -1.035  0.0007  0.0007  $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_7_seq.ppm 
	./MandelbrotSeq.exe -0.165 -1.0351 0.00008 0.00008 $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_8_seq.ppm 



#####################
# MANDELBROT OPENMP #
#####################

omp:  MandelbrotOpenMP.exe
	echo "Done with OpenMP version"

MandelbrotOpenMP.exe: MandelbrotOpenMP.cxx Makefile
	g++ MandelbrotOpenMP.cxx -o MandelbrotOpenMP.exe -std=c++11 $(CC_OPTIMISATION) $(CC_ASSERTIONS) $(CC_TRACE) $(CC_OPENMP) -DDRY_RUN=$(DRY_RUN)

SamplesOmp:  MandelbrotOpenMP.exe
	./MandelbrotOpenMP.exe  0      0      3       2       $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_0_omp.ppm
	./MandelbrotOpenMP.exe  0     -1      1       1       $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_1_omp.ppm
	./MandelbrotOpenMP.exe  0     -1      0.25    0.25    $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_2_omp.ppm
	./MandelbrotOpenMP.exe -0.1   -1      0.1     0.1     $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_3_omp.ppm
	./MandelbrotOpenMP.exe -0.15  -1.03   0.02    0.02    $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_4_omp.ppm 
	./MandelbrotOpenMP.exe -0.165 -1.035  0.005   0.005   $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_5_omp.ppm 
	./MandelbrotOpenMP.exe -0.165 -1.036  0.0008  0.0008  $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_6_omp.ppm 
	./MandelbrotOpenMP.exe -0.165 -1.035  0.0007  0.0007  $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_7_omp.ppm 
	./MandelbrotOpenMP.exe -0.165 -1.0351 0.00008 0.00008 $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_8_omp.ppm 



##################
# MANDELBROT PVM #
##################

pvm:  MandelbrotPvm.exe MandelbrotPvmWorker.exe
	echo "Done with PVM version"

MandelbrotPvm.exe: MandelbrotPvmFarmer.cxx MandelbrotPvmConstants.h MandelbrotPvmMessages.h Makefile
	g++ MandelbrotPvmFarmer.cxx -o MandelbrotPvm.exe -std=c++11 $(CC_OPTIMISATION) $(CC_ASSERTIONS) $(CC_TRACE) $(CC_OPTIONS) -DDRY_RUN=$(DRY_RUN)
	cp MandelbrotPvm.exe $(EXEC_DIR)

MandelbrotPvmWorker.exe: MandelbrotPvmWorker.cxx MandelbrotPvmConstants.h MandelbrotPvmMessages.h Makefile
	cc MandelbrotPvmWorker.cxx -o MandelbrotPvmWorker.exe $(CC_OPTIMISATION) $(CC_ASSERTIONS) $(CC_TRACE) $(CC_OPTIONS) -DDRY_RUN=$(DRY_RUN)
	cp MandelbrotPvmWorker.exe $(EXEC_DIR)


SamplesPvm:  MandelbrotPvm.exe
	./MandelbrotPvm.exe  0      0      3       2       $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_0_pvm.ppm
	./MandelbrotPvm.exe  0     -1      1       1       $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_1_pvm.ppm
	./MandelbrotPvm.exe  0     -1      0.25    0.25    $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_2_pvm.ppm
	./MandelbrotPvm.exe -0.1   -1      0.1     0.1     $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_3_pvm.ppm
	./MandelbrotPvm.exe -0.15  -1.03   0.02    0.02    $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_4_pvm.ppm 
	./MandelbrotPvm.exe -0.165 -1.035  0.005   0.005   $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_5_pvm.ppm 
	./MandelbrotPvm.exe -0.165 -1.036  0.0008  0.0008  $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_6_pvm.ppm 
	./MandelbrotPvm.exe -0.165 -1.035  0.0007  0.0007  $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_7_pvm.ppm 
	./MandelbrotPvm.exe -0.165 -1.0351 0.00008 0.00008 $(IMAGE_WIDTH) $(N_MAX) > Images/Sample_8_pvm.ppm 



##################
# MANDELBROT MPI #
##################

mpi:  MandelbrotMpi.exe
	echo "Done with version"

MandelbrotMpi.exe: MandelbrotMpi.cxx Makefile
	mpicxx MandelbrotMpi.cxx -o MandelbrotMpi.exe -std=c++11 $(CC_OPTIMISATION) $(CC_ASSERTIONS) $(CC_TRACE) $(CC_OPTIONS) -DDRY_RUN=$(DRY_RUN)

SamplesMpi:  MandelbrotMpi.exe
	mpiexec -n $(NB_PROC) -oversubscribe ./MandelbrotMpi.exe  0      0      3       2       $(IMAGE_WIDTH) $(N_MAX) | sed "1s/.*P3/P3/" > Images/Sample_0_mpi.ppm
	mpiexec -n $(NB_PROC) -oversubscribe ./MandelbrotMpi.exe  0     -1      1       1       $(IMAGE_WIDTH) $(N_MAX) | sed "1s/.*P3/P3/" > Images/Sample_1_mpi.ppm
	mpiexec -n $(NB_PROC) -oversubscribe ./MandelbrotMpi.exe  0     -1      0.25    0.25    $(IMAGE_WIDTH) $(N_MAX) | sed "1s/.*P3/P3/" > Images/Sample_2_mpi.ppm
	mpiexec -n $(NB_PROC) -oversubscribe ./MandelbrotMpi.exe -0.1   -1      0.1     0.1     $(IMAGE_WIDTH) $(N_MAX) | sed "1s/.*P3/P3/" > Images/Sample_3_mpi.ppm
	mpiexec -n $(NB_PROC) -oversubscribe ./MandelbrotMpi.exe -0.15  -1.03   0.02    0.02    $(IMAGE_WIDTH) $(N_MAX) | sed "1s/.*P3/P3/" > Images/Sample_4_mpi.ppm 
	mpiexec -n $(NB_PROC) -oversubscribe ./MandelbrotMpi.exe -0.165 -1.035  0.005   0.005   $(IMAGE_WIDTH) $(N_MAX) | sed "1s/.*P3/P3/" > Images/Sample_5_mpi.ppm 
	mpiexec -n $(NB_PROC) -oversubscribe ./MandelbrotMpi.exe -0.165 -1.036  0.0008  0.0008  $(IMAGE_WIDTH) $(N_MAX) | sed "1s/.*P3/P3/" > Images/Sample_6_mpi.ppm 
	mpiexec -n $(NB_PROC) -oversubscribe ./MandelbrotMpi.exe -0.165 -1.035  0.0007  0.0007  $(IMAGE_WIDTH) $(N_MAX) | sed "1s/.*P3/P3/" > Images/Sample_7_mpi.ppm 
	mpiexec -n $(NB_PROC) -oversubscribe ./MandelbrotMpi.exe -0.165 -1.0351 0.00008 0.00008 $(IMAGE_WIDTH) $(N_MAX) | sed "1s/.*P3/P3/" > Images/Sample_8_mpi.ppm 

# Nota.  The command "mpiexec" inserts the command line at the beginning of the standard output, hence the "sed" command intertwined in order to remove it.
#        Nevertheless, this post-processing is not costly.
#        Firstly, the "sed" command applies only to the very first line of the file.
#        Secondly, the system is able to pipe everything in main memory before writing the final result into a file.
#        Thus, there is only one additional scan of the image in main memory, which is marginal.
#        This claim can be checked by replacing the end of the command line by a redirection into /dev/null.
#        In an experiment with 12 processors, no optimisation, and no dry-run, the cumulated wall-clock time goes down from 13.546 to 12.158, which amounts to almost 90%.
#        With the -O3 optimisation level, and no actual output, the cumulated wall-clock time only goes down from 5.916 to 5.644, which amounts to more than 95%.


######################################
# ALL                                #
######################################

all:  seq omp pvm mpi
	echo "Done with *all* the versions"

clean:
	rm *.exe
	rm Images/*.ppm

