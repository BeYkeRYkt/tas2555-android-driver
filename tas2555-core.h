/*
** =============================================================================
** Copyright (c) 2016  Texas Instruments Inc.
**
** This program is free software; you can redistribute it and/or modify it under
** the terms of the GNU General Public License as published by the Free Software 
** Foundation; version 2.
**
** This program is distributed in the hope that it will be useful, but WITHOUT
** ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
** FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with
** this program; if not, write to the Free Software Foundation, Inc., 51 Franklin
** Street, Fifth Floor, Boston, MA 02110-1301, USA.
**
** File:
**     tas2555-core.h
**
** Description:
**     header file for tas2555-core.c
**
** =============================================================================
*/

#ifndef _TAS2555_CORE_H
#define _TAS2555_CORE_H

#include "tas2555.h"

#define TAS2555_YRAM_BOOK				140
#define TAS2555_YRAM1_PAGE				42
#define TAS2555_YRAM1_START_REG			88
#define TAS2555_YRAM1_END_REG			127

#define TAS2555_YRAM2_START_PAGE		43
#define TAS2555_YRAM2_END_PAGE			52
#define TAS2555_YRAM2_START_REG			8
#define TAS2555_YRAM2_END_REG			127

#define TAS2555_YRAM3_PAGE				53
#define TAS2555_YRAM3_START_REG			8
#define TAS2555_YRAM3_END_REG			55

typedef struct {
	unsigned char mnOffset;
	unsigned char mnLen;
} TYCRC;

int tas2555_enable(struct tas2555_priv *pTAS2555, bool bEnable);
int tas2555_set_sampling_rate(struct tas2555_priv *pTAS2555, 
	unsigned int nSamplingRate);
int tas2555_set_config(struct tas2555_priv *pTAS2555, int config);
int tas2555_get_f0_a1(struct tas2555_priv *pTAS2555, unsigned int *pA1);
int tas2555_get_f0_a2(struct tas2555_priv *pTAS2555, unsigned int *pA2);
void tas2555_load_fs_firmware(struct tas2555_priv *pTAS2555,
	char *pFileName);
void tas2555_fw_ready(const struct firmware *pFW, void *pContext);
int tas2555_set_program(struct tas2555_priv *pTAS2555,
	unsigned int nProgram);
int tas2555_set_calibration(struct tas2555_priv *pTAS2555,
	int nCalibration);
int tas2555_get_Re(struct tas2555_priv *pTAS2555, unsigned int *pRe);
int tas2555_load_default(struct tas2555_priv *pTAS2555);
void tas2555_clear_firmware(TFirmware *pFirmware);

#endif /* _TAS2555_CORE_H */
