/*
 * Copyright (c) 2012 David Brandt
 *  All rights reserved.
 *
 * Licensed under: CC BY-NC-SA 3.0 (full license in file LICENSE)
 * 
 * You are free:
 * - to Share - to copy, distribute and transmit the work
 * - to Remix - to adapt the work
 * 
 * Under the following conditions:
 * - Attribution - You must attribute the work in the manner specified by
 *   the author or licensor (but not in any way that suggests that
 *   they endorse you or your use of the work).
 * 
 * - Noncommercial - You may not use this work for commercial purposes.
 * 
 * - Share Alike - If you alter, transform, or build upon this work, you may
 *   distribute the resulting work only under the same or similar license
 *   to this one.
 */

#ifndef SLAVE_H
#define	SLAVE_H
	SLAVE_CMD_READ_CONFIG = 0x02,
	SLAVE_CMD_READ_VOLTAGES = 0x04,
// read diagnostics register
#define slave_set_maskint(slave, maskint) slave_configs[slave][3] = maskint & 0xFF; slave_configs[slave][2] &= 0x0F; slave_configs[slave][2] |= (maskint >> 4) & 0xF0
extern volatile unsigned char slave_read_configs[NUMSLAVES][6];
extern volatile unsigned char slave_diags[NUMSLAVES][2];
extern volatile unsigned int cell_voltages[NUMCELLS];
extern volatile unsigned int cell_temps[NUMTEMPS];
extern volatile unsigned int cell_temps_raw[NUMTEMPS];
extern volatile unsigned int slave_fsm_raw[NUMSLAVES];
extern volatile unsigned int slave_fsm[NUMSLAVES];
extern volatile unsigned int ltc_temps[NUMSLAVES];
extern volatile uint32_t slave_ouv[NUMSLAVES];
extern volatile unsigned int slave_errors;
extern volatile unsigned int slave_uv_time;
extern volatile unsigned int slave_ov_time;
extern volatile unsigned int slave_ot_time;
extern volatile uint32_t batt_fsm_volt_copy;
extern volatile uint32_t batt_fsm_volt;
extern volatile unsigned int slave_cycle_ms;
extern volatile unsigned int slave_adc_time;

// voltage min/max/avg
extern volatile unsigned int slave_max_cell_volt;
extern volatile unsigned char slave_max_cell;
extern volatile unsigned int slave_min_cell_volt;
extern volatile unsigned char slave_min_cell;
extern volatile unsigned int slave_avg_cell_volt;

// temprature min/max/avg
extern volatile unsigned int slave_max_temp_val;
extern volatile unsigned char slave_max_temp;
extern volatile unsigned int slave_min_temp_val;
extern volatile unsigned char slave_min_temp;
extern volatile unsigned int slave_avg_temp_val;

unsigned char slave_loop(void);
void slave_set_balance_cell(unsigned char cell, unsigned char balance);
void slave_set_cdcs(char cdc);
void slave_set_wdts(char wdt);
void slave_set_lvlpls(char lvlpl);
void slave_set_cell10s(char cell10);
void slave_set_vuvs(char vuv);
void slave_set_vovs(char vov);
void slave_set_balancings(unsigned int balancing);
void slave_set_maskints(unsigned int maskint);
void slave_init(void);
void slave_write_config(void);
void slave_start_diag(void);
void slave_read_diag(void);
void slave_start_cell_conv(char what);
void slave_start_temp_conv(void);
void slave_read_temp(void);
void slave_read_flags(void);
void slave_read_all_cellvoltages(void);
void slave_read_cellvoltages(void);
void slave_read_config(void);
void slave_verify_config(void);
unsigned char slave_tempfromadc(unsigned int adc);