// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (c) 2024 Benetti Engineering sas
 * Author: Giulio Benetti <giulio.benetti@benettiengineering.com>
 */

#include <common.h>
#include <dm.h>
#include <asm/armv8/mmu.h>
#include <asm/io.h>
#include <asm/arch-rockchip/bootrom.h>
#include <asm/arch-rockchip/grf_rk3562.h>
#include <asm/arch-rockchip/hardware.h>
#include <dt-bindings/clock/rk3562-cru.h>

#define PMUGRF_BASE			0xFF010000
#define GPIO0_IOC_BASE			0xFF080000
#define GRF_GPIO1B_DS_2			0x218
#define GRF_GPIO1B_DS_3			0x21c
#define GRF_GPIO1C_DS_0			0x220
#define GRF_GPIO1C_DS_1			0x224
#define GRF_GPIO1C_DS_2			0x228
#define GRF_GPIO1C_DS_3			0x22c
#define SGRF_BASE			0xFDD18000
#define SGRF_SOC_CON4			0x10
#define EMMC_HPROT_SECURE_CTRL		0x03
#define SDMMC0_HPROT_SECURE_CTRL	0x01

#define PMU_BASE_ADDR		0xfdd90000
#define PMU_NOC_AUTO_CON0	(0x70)
#define PMU_NOC_AUTO_CON1	(0x74)
#define EDP_PHY_GRF_BASE	0xfdcb0000
#define EDP_PHY_GRF_CON0	(EDP_PHY_GRF_BASE + 0x00)
#define EDP_PHY_GRF_CON10	(EDP_PHY_GRF_BASE + 0x28)
#define CPU_GRF_BASE		0xfdc30000
#define GRF_CORE_PVTPLL_CON0	(0x10)

/* GPIO0_IOC_GPIO0D_IOMUX_SEL_L */
enum {
	GPIO0D1_SHIFT		= 4,
	GPIO0D1_MASK		= GENMASK(6, 4),
	GPIO0D1_GPIO		= 0,
	GPIO0D1_UART0_TXM0,

	GPIO0D0_SHIFT		= 0,
	GPIO0D0_MASK		= GENMASK(2, 0),
	GPIO0D0_GPIO		= 0,
	GPIO0D0_UART0_RXM0,
};

static struct mm_region rk3562_mem_map[] = {
	{
		.virt = 0x0UL,
		.phys = 0x0UL,
		.size = 0xf0000000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) |
			 PTE_BLOCK_INNER_SHARE
	}, {
		.virt = 0xf0000000UL,
		.phys = 0xf0000000UL,
		.size = 0x10000000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
			 PTE_BLOCK_NON_SHARE |
			 PTE_BLOCK_PXN | PTE_BLOCK_UXN
	}, {
		.virt = 0x300000000,
		.phys = 0x300000000,
		.size = 0x0c0c00000,
		.attrs = PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
			 PTE_BLOCK_NON_SHARE |
			 PTE_BLOCK_PXN | PTE_BLOCK_UXN
	}, {
		/* List terminator */
		0,
	}
};

const char * const boot_devices[BROM_LAST_BOOTSOURCE + 1] = {
	[BROM_BOOTSOURCE_EMMC] = "/mmc@ff870000",
	[BROM_BOOTSOURCE_SPINOR] = "/spi@ff860000/flash@0",
	[BROM_BOOTSOURCE_SD] = "/mmc@ff880000",
};

struct mm_region *mem_map = rk3562_mem_map;

void board_debug_uart_init(void)
{
	static struct rk3562_gpio0_ioc * const gpio0_ioc = (void *)GPIO0_IOC_BASE;

	/* Switch iomux to UART0 M0 */
	rk_clrsetreg(&gpio0_ioc->gpio0d_iomux_l,
		     GPIO0D1_MASK | GPIO0D0_MASK,
		     GPIO0D1_UART0_TXM0 << GPIO0D1_SHIFT |
		     GPIO0D0_UART0_RXM0 << GPIO0D0_SHIFT);
}

int arch_cpu_init(void)
{
	#if 1
	TODOOOOOOOOOOOOOOOOOOOOO!!!!!!!!
#ifdef CONFIG_SPL_BUILD
	
	/*
	 * When perform idle operation, corresponding clock can
	 * be opened or gated automatically.
	 */
	writel(0xffffffff, PMU_BASE_ADDR + PMU_NOC_AUTO_CON0);
	writel(0x000f000f, PMU_BASE_ADDR + PMU_NOC_AUTO_CON1);

	/* Disable eDP phy by default */
	writel(0x00070007, EDP_PHY_GRF_CON10);
	writel(0x0ff10ff1, EDP_PHY_GRF_CON0);

	/* Set core pvtpll ring length */
	writel(0x00ff002b, CPU_GRF_BASE + GRF_CORE_PVTPLL_CON0);

	/* Set the emmc sdmmc0 to secure */
	rk_clrreg(SGRF_BASE + SGRF_SOC_CON4, (EMMC_HPROT_SECURE_CTRL << 11
		| SDMMC0_HPROT_SECURE_CTRL << 4));
	/* set the emmc driver strength to level 2 */
	writel(0x3f3f0707, GRF_BASE + GRF_GPIO1B_DS_2);
	writel(0x3f3f0707, GRF_BASE + GRF_GPIO1B_DS_3);
	writel(0x3f3f0707, GRF_BASE + GRF_GPIO1C_DS_0);
	writel(0x3f3f0707, GRF_BASE + GRF_GPIO1C_DS_1);
	writel(0x3f3f0707, GRF_BASE + GRF_GPIO1C_DS_2);
	writel(0x3f3f0707, GRF_BASE + GRF_GPIO1C_DS_3);
#endif
#endif
	return 0;
}
