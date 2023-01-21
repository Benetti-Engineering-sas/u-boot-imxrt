// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2023 TEKVOX, Inc.
 */

#include <init.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <miiphy.h>

DECLARE_GLOBAL_DATA_PTR;

int dram_init(void)
{
	gd->ram_size = imx_ddr_size();

	return 0;
}

#if CONFIG_IS_ENABLED(NET)
static void setup_fec_clocks(void)
{
	struct iomuxc *const iomuxc_regs = (struct iomuxc *)IOMUXC_BASE_ADDR;

	/*
	 * Use external 50MHz oscillator as REF_CLK1 input for ENET1,
	 * set gpr1[13], clear gpr1[17].
	 */
	clrsetbits_le32(&iomuxc_regs->gpr[1], IOMUX_GPR1_FEC1_MASK,
			IOMUX_GPR1_FEC1_CLOCK_MUX2_SEL_MASK);
	/*
	 * Use external 50MHz oscillator as REF_CLK2 input for ENET2,
	 * set gpr1[14], clear gpr1[18].
	 */
	clrsetbits_le32(&iomuxc_regs->gpr[1], IOMUX_GPR1_FEC2_MASK,
			IOMUX_GPR1_FEC2_CLOCK_MUX2_SEL_MASK);

	enable_fec_anatop_clock(1, ENET_50MHZ);

	enable_enet_clk(1);
}

int board_phy_config(struct phy_device *phydev)
{
	phy_write(phydev, MDIO_DEVAD_NONE, 0x1f, 0x8190);

	if (phydev->drv->config)
		phydev->drv->config(phydev);

	return 0;
}
#else
static void setup_fec_clocks(void) {};
#endif

int board_init(void)
{
	/* Address of boot parameters */
	gd->bd->bi_boot_params = PHYS_SDRAM + 0x100;

	setup_fec_clocks();

	return 0;
}

int board_late_init(void)
{
	if (is_boot_from_usb()) {
		env_set("bootcmd", "run bootcmd_mfg");
		env_set("bootdelay", "0");
	}

	return 0;
}
