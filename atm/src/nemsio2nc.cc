/*
 * nemsio2nc
 * convert NCEP NEMSIO formatted file
 * to FV3GFS NCIO netCDF formatted file
 * supports GFSv15 to GFSv16 conversion
 */
#include "nems2nc.h"
#include <mpi.h>

 int main(int argc,  char ** argv) {
  int status;
  nems2nc::Convert nemsio2nc;
  // MPI init
  status = MPI_Init (&argc, &argv);
  if ( status !=0) {
    return status;
  }
  // init code
  status = nemsio2nc.init(argc, argv);
  if ( status != 0) {
    return status;
  }
  // run conversion
  status = nemsio2nc.run();
  if ( status != 0) {
    return status;
  }
  return status;
 }
