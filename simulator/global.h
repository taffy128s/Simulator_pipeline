#include <stdio.h>
#include <stdlib.h>

unsigned write_to_zero, num_overflow, mem_overflow, mem_misalign;
unsigned IF_HALT, ID_HALT, EX_HALT, DM_HALT, WB_HALT, FWD_RS_TO_EX, FWD_RT_TO_EX, FWD_RS_TO_ID, FWD_RT_TO_ID, STALL;
unsigned iImgLen, dImgLen, iImgLenResult, dImgLenResult, reg[32], PC, cycle;
char *iImgBuffer, *dImgBuffer;
char dMemory[1024], iMemory[1024];
FILE *err, *snap, *iImg, *dImg;
