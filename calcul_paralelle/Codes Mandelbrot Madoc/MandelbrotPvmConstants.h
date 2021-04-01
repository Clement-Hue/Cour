#ifndef sum_constants
#define sum_constants


// It is wise to declare constants in a common file,
// in order to ensure that all the parts of the program
// will actually use the very same values.

// Farm-of-workers related constants

#define WORKER_PROGRAM    ((char *) "MandelbrotPvm.exe") // Name of the compiled worker program to spawn
#define MAX_WORKERS       300
#define NUMBER_OF_WORKERS   8 // <= MAX_WORKERS // twice the number of cores seems fine for running on a single machine

// Messages related constants

#define PVM_DATA_ENCODING PvmDataRaw // when running on machines with the same architecture in order to avoid transcoding costs, otherwise use PvmDataDefault

#define PARAMETERS_TAG 0 // For the message sent from the master to the workers
#define RESULT_TAG     1 // For the messages sent from the workers to the master

// Application related constants

#define MAX_DATA_SIZE 10000
#define DATA_SIZE      9997
#define DATA_VALUE        2.0


#endif

