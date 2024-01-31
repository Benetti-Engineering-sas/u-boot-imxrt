// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2024 Benetti Engineering sas
 * Author: Giulio Benetti <giulio.benetti@benettiengineering.com>
 */

#include <common.h>
#include <dm.h>
#include <syscon.h>
#include <asm/arch-rockchip/clock.h>

static const struct udevice_id rk3562_syscon_ids[] = {
	{ .compatible = "rockchip,rk3562-grf", .data = ROCKCHIP_SYSCON_GRF },
	{ .compatible = "rockchip,rk3562-pmugrf", .data = ROCKCHIP_SYSCON_PMUGRF },
	{ }
};

U_BOOT_DRIVER(syscon_rk3562) = {
	.name = "rk3562_syscon",
	.id = UCLASS_SYSCON,
	.of_match = rk3562_syscon_ids,
#if CONFIG_IS_ENABLED(OF_REAL)
	.bind = dm_scan_fdt_dev,
#endif
};
