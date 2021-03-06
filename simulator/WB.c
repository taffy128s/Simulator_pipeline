#include "defines.h"
#include "global.h"
#include "ID.h"
#include "DM.h"
#include "WB.h"

void WB() {
	if (DM_WB.reg_write_out == 1) {
		if (DM_WB.mem_to_reg_out == 1) reg[DM_WB.reg_to_write_out] = DM_WB.read_data_out;
		else reg[DM_WB.reg_to_write_out] = DM_WB.alu_result_out;
		
		if (DM_WB.reg_to_write_out == 0) {
			if (DM_WB.opcode_out == R && DM_WB.funct_out == SLL) {
				if (!(DM_WB.rt_out == 0 && DM_WB.shamt_out == 0)) {
					write_to_zero = 1;
					reg[DM_WB.reg_to_write_out] = 0;
				}
			} else {
				write_to_zero = 1;
				reg[DM_WB.reg_to_write_out] = 0;
			}
		}
	}
	
	if (DM_WB.opcode_out == HALT) WB_HALT = 1;
	else WB_HALT = 0;
}
