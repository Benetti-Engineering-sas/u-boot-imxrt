/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) 2024 Benetti Engineering sas
 * Author: Giulio Benetti <giulio.benetti@benettiengineering.com>
 */

#ifndef __SOC_ROCKCHIP_RK3562_GRF_H__
#define __SOC_ROCKCHIP_RK3562_GRF_H__

struct rk3562_pmugrf {
	unsigned int reserved0[(0x0100 - 0x0000) / 4];
	unsigned int pmu_soc_con0;
	unsigned int pmu_soc_con1;
	unsigned int pmu_soc_con2;
	unsigned int pmu_soc_con3;
	unsigned int pmu_soc_con4;
	unsigned int pmu_soc_con5;
	unsigned int pmu_soc_con6;
	unsigned int pmu_soc_con7;
	unsigned int pmu_soc_con8;
	unsigned int pmu_soc_con9;
	unsigned int pmu_soc_con10;
	unsigned int pmu_soc_con11;
	unsigned int pmu_soc_con12;
	unsigned int pmu_soc_con13;
	unsigned int pmu_soc_status0;
	unsigned int reserved1[(0x0180 - 0x0138) / 4 - 1];
	unsigned int pmu_pvtm_con0;
	unsigned int reserved2[(0x0200 - 0x0180) / 4 - 1];
	unsigned int pmu_os_reg0;
	unsigned int pmu_os_reg1;
	unsigned int pmu_os_reg2;
	unsigned int pmu_os_reg3;
	unsigned int pmu_os_reg4;
	unsigned int pmu_os_reg5;
	unsigned int pmu_os_reg6;
	unsigned int pmu_os_reg7;
	unsigned int pmu_os_reg8;
	unsigned int pmu_os_reg9;
	unsigned int pmu_os_reg10;
	unsigned int pmu_os_reg11;
	unsigned int pmu_reset_function_status;
	unsigned int pmu_reset_function_clr;
	unsigned int reserved3[(0x0380 - 0x0234) / 4 - 1];
	unsigned int pmu_sig_detect_con;
	unsigned int reserved4[(0x0390 - 0x0380) / 4 - 1];
	unsigned int pmu_sig_detect_status;
	unsigned int reserved5[(0x03a0 - 0x0390) / 4 - 1];
	unsigned int pmu_sig_detect_status_clear;
	unsigned int reserved6[(0x03b0 - 0x03a0) / 4 - 1];
	unsigned int pmu_sdmmc_det_counter;
};

check_member(rk3562_pmugrf, pmu_sdmmc_det_counter, 0x03b0);

struct rk3562_gpio0_ioc {
	unsigned int gpio0a_iomux_l;
	unsigned int gpio0a_iomux_h;
	unsigned int gpio0b_iomux_l;
	unsigned int gpio0b_iomux_h;
	unsigned int gpio0c_iomux_l;
	unsigned int gpio0c_iomux_h;
	unsigned int gpio0d_iomux_l;
	unsigned int reserved0[(0x0020 - 0x0018) / 4 - 1];
	unsigned int gpio0a_p;
	unsigned int gpio0b_p;
	unsigned int gpio0c_p;
	unsigned int gpio0d_p;
	unsigned int gpio0a_ie;
	unsigned int gpio0b_ie;
	unsigned int gpio0c_ie;
	unsigned int gpio0d_ie;
	unsigned int gpio0a_od;
	unsigned int gpio0b_od;
	unsigned int gpio0c_od;
	unsigned int gpio0d_od;
	unsigned int gpio0a_sus;
	unsigned int gpio0b_sus;
	unsigned int gpio0c_sus;
	unsigned int gpio0d_sus;
	unsigned int gpio0a_sl;
	unsigned int gpio0b_sl;
	unsigned int gpio0c_sl;
	unsigned int gpio0d_sl;
	unsigned int gpio0a_ds_0;
	unsigned int gpio0a_ds_1;
	unsigned int gpio0a_ds_2;
	unsigned int gpio0a_ds_3;
	unsigned int gpio0b_ds_0;
	unsigned int gpio0b_ds_1;
	unsigned int gpio0b_ds_2;
	unsigned int gpio0b_ds_3;
	unsigned int gpio0c_ds_0;
	unsigned int gpio0c_ds_1;
	unsigned int gpio0c_ds_2;
	unsigned int gpio0c_ds_3;
	unsigned int gpio0d_ds_0;
	unsigned int reserved1[(0x0100 - 0x00a0) / 4 - 1];
	unsigned int jtag_m0_con;
	unsigned int uart_io_con;
	unsigned int reserved2[(0x0148 - 0x0104) / 4 - 1];
	unsigned int io_vsel2;
	unsigned int xin_con;
};

check_member(rk3562_gpio0_ioc, xin_con, 0x014c);

struct rk3562_gpio1_ioc {
	unsigned int gpio1a_iomux_l;
	unsigned int gpio1a_iomux_h;
	unsigned int gpio1b_iomux_l;
	unsigned int gpio1b_iomux_h;
	unsigned int gpio1c_iomux_l;
	unsigned int gpio1c_iomux_h;
	unsigned int gpio1d_iomux_l;
	unsigned int gpio1d_iomux_h;
	unsigned int reserved0[(0x0080 - 0x001C) / 4 - 1];
	unsigned int gpio1a_p;
	unsigned int gpio1b_p;
	unsigned int gpio1c_p;
	unsigned int gpio1d_p;
	unsigned int reserved1[(0x00C0 - 0x008C) / 4 - 1];
	unsigned int gpio1a_ie;
	unsigned int gpio1b_ie;
	unsigned int gpio1c_ie;
	unsigned int gpio1d_ie;
	unsigned int reserved2[(0x0100 - 0x00CC) / 4 - 1];
	unsigned int gpio1a_od;
	unsigned int gpio1b_od;
	unsigned int gpio1c_od;
	unsigned int gpio1d_od;
	unsigned int reserved3[(0x0140 - 0x010C) / 4 - 1];
	unsigned int gpio1a_sus;
	unsigned int gpio1b_sus;
	unsigned int gpio1c_sus;
	unsigned int gpio1d_sus;
	unsigned int reserved4[(0x0180 - 0x014C) / 4 - 1];
	unsigned int gpio1a_sl;
	unsigned int gpio1b_sl;
	unsigned int gpio1c_sl;
	unsigned int gpio1d_sl;
	unsigned int reserved5[(0x0200 - 0x018C) / 4 - 1];
	unsigned int gpio1a_ds_0;
	unsigned int gpio1a_ds_1;
	unsigned int gpio1a_ds_2;
	unsigned int gpio1a_ds_3;
	unsigned int gpio1b_ds_0;
	unsigned int gpio1b_ds_1;
	unsigned int gpio1b_ds_2;
	unsigned int gpio1b_ds_3;
	unsigned int gpio1c_ds_0;
	unsigned int gpio1c_ds_1;
	unsigned int gpio1c_ds_2;
	unsigned int gpio1c_ds_3;
	unsigned int gpio1d_ds_0;
	unsigned int gpio1d_ds_1;
	unsigned int gpio1d_ds_2;
	unsigned int gpio1d_ds_3;
};

check_member(rk3562_gpio1_ioc, gpio1d_ds_3, 0x023c);

#endif
