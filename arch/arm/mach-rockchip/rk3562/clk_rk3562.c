// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2024 Benetti Engineering sas
 * Author: Giulio Benetti <giulio.benetti@benettiengineering.com>
 */

#include <common.h>
#include <dm.h>
#include <syscon.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/cru_rk3562.h>
#include <linux/err.h>

int rockchip_get_clk(struct udevice **devp)
{
	return uclass_get_device_by_driver(UCLASS_CLK,
			DM_DRIVER_GET(rockchip_rk3562_topcru), devp);
}

void *rockchip_get_cru(void)
{
	struct rk3562_clk_priv *priv;
	struct udevice *dev;
	int ret;

	ret = rockchip_get_clk(&dev);
	if (ret)
		return ERR_PTR(ret);

	priv = dev_get_priv(dev);

	return priv->cru;
}

static int rockchip_get_pmucruclk(struct udevice **devp)
{
	return uclass_get_device_by_driver(UCLASS_CLK,
			DM_DRIVER_GET(rockchip_rk3562_pmu1cru), devp);
}

void *rockchip_get_pmucru(void)
{
	struct rk3562_pmu1clk_priv *priv;
	struct udevice *dev;
	int ret;

	ret = rockchip_get_pmucruclk(&dev);
	if (ret)
		return ERR_PTR(ret);

	priv = dev_get_priv(dev);

	return priv->pmu1cru;
}
