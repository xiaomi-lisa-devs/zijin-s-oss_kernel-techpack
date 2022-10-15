/* SPDX-License-Identifier: (GPL-2.0 OR BSD-3-Clause) */
/*
 * cs35l45.h - CS35L45 ALSA SoC audio driver
 *
 * Copyright 2019 Cirrus Logic, Inc.
 * Copyright (C) 2021 XiaoMi, Inc.
 *
 * Author: James Schulman <james.schulman@cirrus.com>
 *
 */

#ifndef __CS35L45_H__
#define __CS35L45_H__

#include <linux/regmap.h>

#define CS35L45_DEVID				0x00000000
#define CS35L45_REVID				0x00000004
#define CS35L45_RELID				0x0000000C
#define CS35L45_OTPID				0x00000010
#define CS35L45_SFT_RESET			0x00000020
#define CS35L45_GLOBAL_ENABLES			0x00002014
#define CS35L45_BLOCK_ENABLES			0x00002018
#define CS35L45_BLOCK_ENABLES2			0x0000201C
#define CS35L45_GLOBAL_OVERRIDES		0x00002020
#define CS35L45_GLOBAL_SYNC			0x00002024
#define CS35L45_ERROR_RELEASE			0x00002034
#define CS35L45_CHIP_STATUS			0x00002040
#define CS35L45_REG_2114			0x00002114
#define CS35L45_REG_225C			0x0000225C
#define CS35L45_SYNC_GPIO1			0x00002430
#define CS35L45_INTB_GPIO2_MCLK_REF		0x00002434
#define CS35L45_GPIO3				0x00002438
#define CS35L45_GPIO_GLOBAL_ENABLE_CONTROL	0x00002440
#define CS35L45_PWRMGT_CTL			0x00002900
#define CS35L45_WAKESRC_CTL			0x00002904
#define CS35L45_WKI2C_CTL			0x00002908
#define CS35L45_PWRMGT_STS			0x0000290C
#define CS35L45_REFCLK_INPUT			0x00002C04
#define CS35L45_REG_2C08			0x00002C08
#define CS35L45_GLOBAL_SAMPLE_RATE		0x00002C0C
#define CS35L45_SWIRE_CLK_CTRL			0x00002C14
#define CS35L45_SYNC_TX_RX_ENABLES		0x00003400
#define CS35L45_SYNC_SW_TX_ID			0x00003408
#define CS35L45_BOOST_VOLTAGE_CFG		0x00003800
#define CS35L45_BOOST_CCM_CFG			0x00003808
#define CS35L45_BOOST_DCM_CFG			0x0000380C
#define CS35L45_BOOST_LPMODE_CFG		0x00003810
#define CS35L45_BOOST_RAMP_CFG			0x00003814
#define CS35L45_BOOST_STARTUP_CFG		0x00003818
#define CS35L45_BOOST_OV_CFG			0x0000382C
#define CS35L45_BOOST_UV_CFG			0x00003830
#define CS35L45_BOOST_STATUS			0x00003834
#define CS35L45_BST_BPE_INST_THLD		0x00003C00
#define CS35L45_BST_BPE_INST_ILIM		0x00003C04
#define CS35L45_BST_BPE_INST_SS_ILIM		0x00003C08
#define CS35L45_BST_BPE_INST_ATK_RATE		0x00003C0C
#define CS35L45_BST_BPE_INST_HOLD_TIME		0x00003C10
#define CS35L45_BST_BPE_INST_RLS_RATE		0x00003C14
#define CS35L45_BST_BPE_MISC_CONFIG		0x00003C20
#define CS35L45_BST_BPE_IL_LIM_THLD		0x00003C24
#define CS35L45_BST_BPE_IL_LIM_DLY		0x00003C28
#define CS35L45_BST_BPE_IL_LIM_ATK_RATE		0x00003C2C
#define CS35L45_BST_BPE_IL_LIM_RLS_RATE		0x00003C30
#define CS35L45_BST_BPE_INST_STATUS		0x00003C3C
#define CS35L45_MONITOR_FILT			0x00004008
#define CS35L45_IMON_COMP			0x00004010
#define CS35L45_STATUS				0x00004200
#define CS35L45_MON_VALUE			0x00004404
#define CS35L45_ASP_ENABLES1			0x00004800
#define CS35L45_ASP_CONTROL1			0x00004804
#define CS35L45_ASP_CONTROL2			0x00004808
#define CS35L45_ASP_CONTROL3			0x0000480C
#define CS35L45_ASP_FRAME_CONTROL1		0x00004810
#define CS35L45_ASP_FRAME_CONTROL2		0x00004814
#define CS35L45_ASP_FRAME_CONTROL5		0x00004820
#define CS35L45_ASP_DATA_CONTROL1		0x00004830
#define CS35L45_ASP_DATA_CONTROL5		0x00004840
#define CS35L45_DACPCM1_INPUT			0x00004C00
#define CS35L45_MIXER_PILOT0_INPUT		0x00004C04
#define CS35L45_ASPTX1_INPUT			0x00004C20
#define CS35L45_ASPTX2_INPUT			0x00004C24
#define CS35L45_ASPTX3_INPUT			0x00004C28
#define CS35L45_ASPTX4_INPUT			0x00004C2C
#define CS35L45_ASPTX5_INPUT			0x00004C30
#define CS35L45_DSP1RX1_INPUT			0x00004C40
#define CS35L45_DSP1RX2_INPUT			0x00004C44
#define CS35L45_DSP1RX3_INPUT			0x00004C48
#define CS35L45_DSP1RX4_INPUT			0x00004C4C
#define CS35L45_DSP1RX5_INPUT			0x00004C50
#define CS35L45_DSP1RX6_INPUT			0x00004C54
#define CS35L45_DSP1RX7_INPUT			0x00004C58
#define CS35L45_DSP1RX8_INPUT			0x00004C5C
#define CS35L45_NGATE1_INPUT			0x00004C60
#define CS35L45_NGATE2_INPUT			0x00004C64
#define CS35L45_SWIRE_PORT1_CH1_INPUT		0x00004C70
#define CS35L45_SWIRE_PORT1_CH2_INPUT		0x00004C74
#define CS35L45_SWIRE_PORT1_CH3_INPUT		0x00004C78
#define CS35L45_SWIRE_PORT1_CH4_INPUT		0x00004C7C
#define CS35L45_SWIRE_PORT1_CH5_INPUT		0x00004C80
#define CS35L45_AMP_ERR_VOL_SEL			0x00006000
#define CS35L45_TEMP_WARN_THRESHOLD		0x00006020
#define CS35L45_TEMP_WARN_CONFIG		0x00006024
#define CS35L45_TEMP_WARN_TRIG_AUTO		0x00006028
#define CS35L45_TEMP_WARN_STATUS		0x0000602C
#define CS35L45_BPE_INST_THLD			0x00006064
#define CS35L45_BPE_INST_ATTN			0x00006068
#define CS35L45_BPE_INST_ATK_RATE		0x00006074
#define CS35L45_BPE_INST_HOLD_TIME		0x00006080
#define CS35L45_BPE_INST_RLS_RATE		0x00006084
#define CS35L45_BPE_MISC_CONFIG			0x00006090
#define CS35L45_BPE_INST_STATUS			0x00006094
#define CS35L45_HVLV_CONFIG			0x00006400
#define CS35L45_LDPM_CONFIG			0x00006404
#define CS35L45_CLASSH_CONFIG1			0x00006408
#define CS35L45_CLASSH_CONFIG2			0x0000640C
#define CS35L45_CLASSH_CONFIG3			0x00006410
#define CS35L45_AUD_MEM				0x00006418
#define CS35L45_AMP_PCM_CONTROL			0x00007000
#define CS35L45_AMP_PCM_HPF_TST			0x00007004
#define CS35L45_AMP_GAIN			0x00007800
#define CS35L45_DAC_MSM_CONFIG			0x00007C00
#define CS35L45_AMP_OUTPUT_MUTE			0x00007C04
#define CS35L45_AMP_OUTPUT_DRV			0x00007C08
#define CS35L45_ALIVE_DCIN_WD			0x00007C20
#define CS35L45_IRQ1_CFG			0x0000E000
#define CS35L45_IRQ1_STATUS			0x0000E004
#define CS35L45_IRQ1_EINT_1			0x0000E010
#define CS35L45_IRQ1_EINT_2			0x0000E014
#define CS35L45_IRQ1_EINT_3			0x0000E018
#define CS35L45_IRQ1_EINT_4			0x0000E01C
#define CS35L45_IRQ1_EINT_5			0x0000E020
#define CS35L45_IRQ1_EINT_7			0x0000E028
#define CS35L45_IRQ1_EINT_8			0x0000E02C
#define CS35L45_IRQ1_EINT_18			0x0000E054
#define CS35L45_IRQ1_STS_1			0x0000E090
#define CS35L45_IRQ1_STS_2			0x0000E094
#define CS35L45_IRQ1_STS_3			0x0000E098
#define CS35L45_IRQ1_STS_4			0x0000E09C
#define CS35L45_IRQ1_STS_5			0x0000E0A0
#define CS35L45_IRQ1_STS_7			0x0000E0A8
#define CS35L45_IRQ1_STS_8			0x0000E0AC
#define CS35L45_IRQ1_STS_18			0x0000E0D4
#define CS35L45_IRQ1_MASK_1			0x0000E110
#define CS35L45_IRQ1_MASK_2			0x0000E114
#define CS35L45_IRQ1_MASK_3			0x0000E118
#define CS35L45_IRQ1_MASK_4			0x0000E11C
#define CS35L45_IRQ1_MASK_5			0x0000E120
#define CS35L45_IRQ1_MASK_7			0x0000E128
#define CS35L45_IRQ1_MASK_8			0x0000E12C
#define CS35L45_IRQ1_MASK_18			0x0000E154
#define CS35L45_IRQ1_EDGE_1			0x0000E210
#define CS35L45_IRQ1_EDGE_4			0x0000E21C
#define CS35L45_IRQ1_POL_1			0x0000E290
#define CS35L45_IRQ1_POL_2			0x0000E294
#define CS35L45_IRQ1_POL_4			0x0000E29C
#define CS35L45_IRQ1_DB_3			0x0000E318
#define CS35L45_IRQ2_CFG			0x0000E800
#define CS35L45_IRQ2_STATUS			0x0000E804
#define CS35L45_IRQ2_EINT_1			0x0000E810
#define CS35L45_IRQ2_EINT_2			0x0000E814
#define CS35L45_IRQ2_EINT_3			0x0000E818
#define CS35L45_IRQ2_EINT_4			0x0000E81C
#define CS35L45_IRQ2_EINT_5			0x0000E820
#define CS35L45_IRQ2_EINT_7			0x0000E828
#define CS35L45_IRQ2_EINT_8			0x0000E82C
#define CS35L45_IRQ2_EINT_18			0x0000E854
#define CS35L45_IRQ2_STS_1			0x0000E890
#define CS35L45_IRQ2_STS_2			0x0000E894
#define CS35L45_IRQ2_STS_3			0x0000E898
#define CS35L45_IRQ2_STS_4			0x0000E89C
#define CS35L45_IRQ2_STS_5			0x0000E8A0
#define CS35L45_IRQ2_STS_7			0x0000E8A8
#define CS35L45_IRQ2_STS_8			0x0000E8AC
#define CS35L45_IRQ2_STS_18			0x0000E8D4
#define CS35L45_IRQ2_MASK_1			0x0000E910
#define CS35L45_IRQ2_MASK_2			0x0000E914
#define CS35L45_IRQ2_MASK_3			0x0000E918
#define CS35L45_IRQ2_MASK_4			0x0000E91C
#define CS35L45_IRQ2_MASK_5			0x0000E920
#define CS35L45_IRQ2_MASK_7			0x0000E928
#define CS35L45_IRQ2_MASK_8			0x0000E92C
#define CS35L45_IRQ2_MASK_18			0x0000E954
#define CS35L45_IRQ2_EDGE_1			0x0000EA10
#define CS35L45_IRQ2_EDGE_4			0x0000EA1C
#define CS35L45_IRQ2_POL_1			0x0000EA90
#define CS35L45_IRQ2_POL_2			0x0000EA94
#define CS35L45_IRQ2_POL_4			0x0000EA9C
#define CS35L45_IRQ2_DB_3			0x0000EB18
#define CS35L45_GPIO_STATUS1			0x0000F000
#define CS35L45_GPIO1_CTRL1			0x0000F008
#define CS35L45_GPIO2_CTRL1			0x0000F00C
#define CS35L45_GPIO3_CTRL1			0x0000F010
#define CS35L45_MIXER_NGATE_CH1_CFG		0x00010004
#define CS35L45_MIXER_NGATE_CH2_CFG		0x00010008
#define CS35L45_DSP_MBOX_1			0x00011000
#define CS35L45_DSP_MBOX_2			0x00011004
#define CS35L45_DSP_MBOX_3			0x00011008
#define CS35L45_DSP_MBOX_4			0x0001100C
#define CS35L45_DSP_MBOX_5			0x00011010
#define CS35L45_DSP_MBOX_6			0x00011014
#define CS35L45_DSP_MBOX_7			0x00011018
#define CS35L45_DSP_MBOX_8			0x0001101C
#define CS35L45_DSP_VIRT1_MBOX_1		0x00011020
#define CS35L45_DSP_VIRT1_MBOX_2		0x00011024
#define CS35L45_DSP_VIRT1_MBOX_3		0x00011028
#define CS35L45_DSP_VIRT1_MBOX_4		0x0001102C
#define CS35L45_DSP_VIRT1_MBOX_5		0x00011030
#define CS35L45_DSP_VIRT1_MBOX_6		0x00011034
#define CS35L45_DSP_VIRT1_MBOX_7		0x00011038
#define CS35L45_DSP_VIRT1_MBOX_8		0x0001103C
#define CS35L45_DSP_VIRT2_MBOX_1		0x00011040
#define CS35L45_DSP_VIRT2_MBOX_2		0x00011044
#define CS35L45_DSP_VIRT2_MBOX_3		0x00011048
#define CS35L45_DSP_VIRT2_MBOX_4		0x0001104C
#define CS35L45_DSP_VIRT2_MBOX_5		0x00011050
#define CS35L45_DSP_VIRT2_MBOX_6		0x00011054
#define CS35L45_DSP_VIRT2_MBOX_7		0x00011058
#define CS35L45_DSP_VIRT2_MBOX_8		0x0001105C
#define CS35L45_CLOCK_DETECT_1			0x00012000
#define CS35L45_DSP1_XMEM_PACK_0		0x02000000
#define CS35L45_DSP1_XMEM_PACK_4607		0x020047FC
#define CS35L45_DSP1_XMEM_UNPACK32_0		0x02400000
#define CS35L45_DSP1_XMEM_UNPACK32_3071		0x02402FFC
#define CS35L45_DSP1_SYS_ID			0x025E0000
#define CS35L45_DSP1_XMEM_UNPACK24_0		0x02800000
#define CS35L45_DSP1_XMEM_UNPACK24_6143		0x02805FFC
#define CS35L45_DSP1_CLOCK_FREQ			0x02B80000
#define CS35L45_DSP1_RX1_RATE			0x02B80080
#define CS35L45_DSP1_RX2_RATE			0x02B80088
#define CS35L45_DSP1_RX3_RATE			0x02B80090
#define CS35L45_DSP1_RX4_RATE			0x02B80098
#define CS35L45_DSP1_RX5_RATE			0x02B800A0
#define CS35L45_DSP1_RX6_RATE			0x02B800A8
#define CS35L45_DSP1_RX7_RATE			0x02B800B0
#define CS35L45_DSP1_RX8_RATE			0x02B800B8
#define CS35L45_DSP1_TX1_RATE			0x02B80280
#define CS35L45_DSP1_TX2_RATE			0x02B80288
#define CS35L45_DSP1_TX3_RATE			0x02B80290
#define CS35L45_DSP1_TX4_RATE			0x02B80298
#define CS35L45_DSP1_TX5_RATE			0x02B802A0
#define CS35L45_DSP1_TX6_RATE			0x02B802A8
#define CS35L45_DSP1_TX7_RATE			0x02B802B0
#define CS35L45_DSP1_TX8_RATE			0x02B802B8
#define CS35L45_DSP1_SCRATCH1			0x02B805C0
#define CS35L45_DSP1_SCRATCH2			0x02B805C8
#define CS35L45_DSP1_SCRATCH3			0x02B805D0
#define CS35L45_DSP1_SCRATCH4			0x02B805D8
#define CS35L45_DSP1_CCM_CORE_CONTROL		0x02BC1000
#define CS35L45_DSP1_STREAM_ARB_MSTR1_CONFIG_0	0x02BC5000
#define CS35L45_DSP1_STREAM_ARB_TX1_CONFIG_0	0x02BC5200
#define CS35L45_DSP1_YMEM_PACK_0		0x02C00000
#define CS35L45_DSP1_YMEM_PACK_1532		0x02C017F0
#define CS35L45_DSP1_YMEM_UNPACK32_0		0x03000000
#define CS35L45_DSP1_YMEM_UNPACK32_1022		0x03000FF8
#define CS35L45_DSP1_YMEM_UNPACK24_0		0x03400000
#define CS35L45_DSP1_YMEM_UNPACK24_2043		0x03401FEC
#define CS35L45_DSP1_PMEM_0			0x03800000
#define CS35L45_DSP1_PMEM_3834			0x03803BE8
#define CS35L45_LASTREG				0x03C6EFE8

#define CS35L45_SOFT_RESET_TRIGGER		0x5A000000

#define CS35L45_GLOBAL_EN_SHIFT			0
#define CS35L45_GLOBAL_EN_MASK			BIT(0)

#define CS35L45_TEMPMON_GLOBAL_OVR_SHIFT	3
#define CS35L45_TEMPMON_GLOBAL_OVR_MASK		BIT(3)

#define CS35L45_BST_DISABLE_FET_OFF		0x00
#define CS35L45_BST_DISABLE_FET_ON		0x01
#define CS35L45_BST_ENABLE			0x02

#define CS35L45_BST_EN_SHIFT			4
#define CS35L45_BST_EN_MASK			GENMASK(5, 4)

#define CS35L45_AMP_DRE_EN_SHIFT		20
#define CS35L45_AMP_DRE_EN_MASK			BIT(20)
#define CS35L45_SYNC_EN_SHIFT			8
#define CS35L45_SYNC_EN_MASK			BIT(8)

#define CS35L45_MEM_RDY_SHIFT			1
#define CS35L45_MEM_RDY_MASK			BIT(1)

#define CS35L45_WKSRC_SYNC_GPIO1		BIT(0)
#define CS35L45_WKSRC_INT_GPIO2			BIT(1)
#define CS35L45_WKSRC_GPIO3			BIT(2)
#define CS35L45_WKSRC_SPI			BIT(3)
#define CS35L45_WKSRC_I2C			BIT(4)

#define CS35L45_UPDT_WKCTL_SHIFT		15
#define CS35L45_UPDT_WKCTL_MASK			BIT(15)
#define CS35L45_WKSRC_EN_SHIFT			8
#define CS35L45_WKSRC_EN_MASK			GENMASK(12, 8)
#define CS35L45_WKSRC_POL_SHIFT			0
#define CS35L45_WKSRC_POL_MASK			GENMASK(3, 0)

#define CS35L45_UPDT_WKI2C_SHIFT		15
#define CS35L45_UPDT_WKI2C_MASK			BIT(15)
#define CS35L45_WKI2C_ADDR_SHIFT		0
#define CS35L45_WKI2C_ADDR_MASK			GENMASK(6, 0)

#define CS35L45_CCM_CORE_RESET_SHIFT		9
#define CS35L45_CCM_CORE_RESET_MASK		BIT(9)
#define CS35L45_CCM_PM_REMAP_SHIFT		7
#define CS35L45_CCM_PM_REMAP_MASK		BIT(7)
#define CS35L45_CCM_CORE_EN_SHIFT		0
#define CS35L45_CCM_CORE_EN_MASK		BIT(0)

#define CS35L45_DSP1_STREAM_ARB_MSTR0_EN_SHIFT	0
#define CS35L45_DSP1_STREAM_ARB_MSTR0_EN_MASK	BIT(0)

#define CS35L45_DSP1_STREAM_ARB_TX1_EN_SHIFT	0
#define CS35L45_DSP1_STREAM_ARB_TX1_EN_MASK	BIT(0)

#define CS35L45_DSP_N_RX_RATES			8
#define CS35L45_DSP_N_TX_RATES			8
#define CS35L45_DSP_RATE_SHIFT			0
#define CS35L45_DSP_RATE_MASK			0x1f
#define CS35L45_DSP_SAMPLE_RATE_RX1		0x00080
#define CS35L45_DSP_SAMPLE_RATE_TX1		0x00280

#define CS35L45_48P0_KHZ			0x03
#define CS35L45_96P0_KHZ			0x04
#define CS35L45_44P100_KHZ			0x0B
#define CS35L45_88P200_KHZ			0x0C
#define CS35L45_8_KHZ				0x11
#define CS35L45_16_KHZ				0x12

#define CS35L45_GLOBAL_FS_SHIFT			0
#define CS35L45_GLOBAL_FS_MASK			GENMASK(4, 0)

#define CS35L45_SYNC_LSW_RX_EN_SHIFT		19
#define CS35L45_SYNC_LSW_RX_EN_MASK		BIT(19)
#define CS35L45_SYNC_LSW_TX_EN_SHIFT		18
#define CS35L45_SYNC_LSW_TX_EN_MASK		BIT(18)
#define CS35L45_SYNC_SW_RX_EN_SHIFT		17
#define CS35L45_SYNC_SW_RX_EN_MASK		BIT(17)
#define CS35L45_SYNC_SW_TX_EN_SHIFT		16
#define CS35L45_SYNC_SW_TX_EN_MASK		BIT(16)
#define CS35L45_SYNC_PWR_RX_EN_SHIFT		5
#define CS35L45_SYNC_PWR_RX_EN_MASK		BIT(5)
#define CS35L45_SYNC_PWR_TX_EN_SHIFT		4
#define CS35L45_SYNC_PWR_TX_EN_MASK		BIT(4)

#define CS35L45_SYNC_SW_EN_MASK			(CS35L45_SYNC_LSW_RX_EN_MASK | \
						 CS35L45_SYNC_LSW_TX_EN_MASK | \
						 CS35L45_SYNC_SW_RX_EN_MASK | \
						 CS35L45_SYNC_SW_TX_EN_MASK)

#define CS35L45_SYNC_LSW_TXID_SHIFT		8
#define CS35L45_SYNC_LSW_TXID_MASK		GENMASK(10, 8)
#define CS35L45_SYNC_SW_TXID_SHIFT		0
#define CS35L45_SYNC_SW_TXID_MASK		GENMASK(2, 0)

#define CS35L45_PLL_REFCLK_SEL_BCLK		0x0
#define CS35L45_PLL_REFCLK_SEL_SWIRE_CLK	0x7

#define CS35L45_PLL_FORCE_EN_SHIFT		16
#define CS35L45_PLL_FORCE_EN_MASK		BIT(16)
#define CS35L45_PLL_OPEN_LOOP_SHIFT		11
#define CS35L45_PLL_OPEN_LOOP_MASK		BIT(11)
#define CS35L45_PLL_REFCLK_FREQ_SHIFT		5
#define CS35L45_PLL_REFCLK_FREQ_MASK		GENMASK(10, 5)
#define CS35L45_PLL_REFCLK_EN_SHIFT		4
#define CS35L45_PLL_REFCLK_EN_MASK		BIT(4)
#define CS35L45_PLL_REFCLK_SEL_SHIFT		0
#define CS35L45_PLL_REFCLK_SEL_MASK		GENMASK(2, 0)

#define CS35L45_BST_BPE_INST_L3_THLD_SHIFT	24
#define CS35L45_BST_BPE_INST_L3_THLD_MASK	GENMASK(31, 24)
#define CS35L45_BST_BPE_INST_L2_THLD_SHIFT	16
#define CS35L45_BST_BPE_INST_L2_THLD_MASK	GENMASK(23, 16)
#define CS35L45_BST_BPE_INST_L1_THLD_SHIFT	8
#define CS35L45_BST_BPE_INST_L1_THLD_MASK	GENMASK(15, 8)
#define CS35L45_BST_BPE_INST_L0_THLD_SHIFT	0
#define CS35L45_BST_BPE_INST_L0_THLD_MASK	GENMASK(7, 0)

#define CS35L45_BST_BPE_INST_L4_ILIM_SHIFT	24
#define CS35L45_BST_BPE_INST_L4_ILIM_MASK	GENMASK(30, 24)
#define CS35L45_BST_BPE_INST_L3_ILIM_SHIFT	16
#define CS35L45_BST_BPE_INST_L3_ILIM_MASK	GENMASK(22, 16)
#define CS35L45_BST_BPE_INST_L2_ILIM_SHIFT	8
#define CS35L45_BST_BPE_INST_L2_ILIM_MASK	GENMASK(14, 8)
#define CS35L45_BST_BPE_INST_L1_ILIM_SHIFT	0
#define CS35L45_BST_BPE_INST_L1_ILIM_MASK	GENMASK(6, 0)

#define CS35L45_BST_BPE_INST_L4_SS_ILIM_SHIFT	24
#define CS35L45_BST_BPE_INST_L4_SS_ILIM_MASK	GENMASK(30, 24)
#define CS35L45_BST_BPE_INST_L3_SS_ILIM_SHIFT	16
#define CS35L45_BST_BPE_INST_L3_SS_ILIM_MASK	GENMASK(22, 16)
#define CS35L45_BST_BPE_INST_L2_SS_ILIM_SHIFT	8
#define CS35L45_BST_BPE_INST_L2_SS_ILIM_MASK	GENMASK(14, 8)
#define CS35L45_BST_BPE_INST_L1_SS_ILIM_SHIFT	0
#define CS35L45_BST_BPE_INST_L1_SS_ILIM_MASK	GENMASK(6, 0)

#define CS35L45_BST_BPE_INST_L3_ATK_RATE_SHIFT	24
#define CS35L45_BST_BPE_INST_L3_ATK_RATE_MASK	GENMASK(26, 24)
#define CS35L45_BST_BPE_INST_L2_ATK_RATE_SHIFT	16
#define CS35L45_BST_BPE_INST_L2_ATK_RATE_MASK	GENMASK(18, 16)
#define CS35L45_BST_BPE_INST_L1_ATK_RATE_SHIFT	8
#define CS35L45_BST_BPE_INST_L1_ATK_RATE_MASK	GENMASK(10, 8)

#define CS35L45_BST_BPE_INST_L3_HOLD_TIME_SHIFT	24
#define CS35L45_BST_BPE_INST_L3_HOLD_TIME_MASK	GENMASK(27, 24)
#define CS35L45_BST_BPE_INST_L2_HOLD_TIME_SHIFT	16
#define CS35L45_BST_BPE_INST_L2_HOLD_TIME_MASK	GENMASK(19, 16)
#define CS35L45_BST_BPE_INST_L1_HOLD_TIME_SHIFT	8
#define CS35L45_BST_BPE_INST_L1_HOLD_TIME_MASK	GENMASK(11, 8)
#define CS35L45_BST_BPE_INST_L0_HOLD_TIME_SHIFT	0
#define CS35L45_BST_BPE_INST_L0_HOLD_TIME_MASK	GENMASK(3, 0)

#define CS35L45_BST_BPE_INST_L3_RLS_RATE_SHIFT	24
#define CS35L45_BST_BPE_INST_L3_RLS_RATE_MASK	GENMASK(28, 24)
#define CS35L45_BST_BPE_INST_L2_RLS_RATE_SHIFT	16
#define CS35L45_BST_BPE_INST_L2_RLS_RATE_MASK	GENMASK(20, 16)
#define CS35L45_BST_BPE_INST_L1_RLS_RATE_SHIFT	8
#define CS35L45_BST_BPE_INST_L1_RLS_RATE_MASK	GENMASK(12, 8)
#define CS35L45_BST_BPE_INST_L0_RLS_RATE_SHIFT	0
#define CS35L45_BST_BPE_INST_L0_RLS_RATE_MASK	GENMASK(4, 0)

#define CS35L45_BST_BPE_INST_INF_HOLD_RLS_SHIFT	16
#define CS35L45_BST_BPE_INST_INF_HOLD_RLS_MASK	BIT(16)
#define CS35L45_BST_BPE_IL_LIM_MODE_SHIFT	15
#define CS35L45_BST_BPE_IL_LIM_MODE_MASK	BIT(15)
#define CS35L45_BST_BPE_OUT_OPMODE_SEL_SHIFT	12
#define CS35L45_BST_BPE_OUT_OPMODE_SEL_MASK	GENMASK(13, 12)
#define CS35L45_BST_BPE_INST_L3_BYP_SHIFT	10
#define CS35L45_BST_BPE_INST_L3_BYP_MASK	BIT(10)
#define CS35L45_BST_BPE_INST_L2_BYP_SHIFT	9
#define CS35L45_BST_BPE_INST_L2_BYP_MASK	BIT(9)
#define CS35L45_BST_BPE_INST_L1_BYP_SHIFT	8
#define CS35L45_BST_BPE_INST_L1_BYP_MASK	BIT(8)
#define CS35L45_BST_BPE_FILT_SEL_SHIFT		0
#define CS35L45_BST_BPE_FILT_SEL_MASK		GENMASK(1, 0)

#define CS35L45_BST_BPE_IL_LIM_THLD_HYST_SHIFT	24
#define CS35L45_BST_BPE_IL_LIM_THLD_HYST_MASK	GENMASK(28, 24)
#define CS35L45_BST_BPE_IL_LIM_THLD_DEL2_SHIFT	16
#define CS35L45_BST_BPE_IL_LIM_THLD_DEL2_MASK	GENMASK(23, 16)
#define CS35L45_BST_BPE_IL_LIM_THLD_DEL1_SHIFT	8
#define CS35L45_BST_BPE_IL_LIM_THLD_DEL1_MASK	GENMASK(15, 8)
#define CS35L45_BST_BPE_IL_LIM1_THLD_SHIFT	0
#define CS35L45_BST_BPE_IL_LIM1_THLD_MASK	GENMASK(7, 0)

#define CS35L45_BST_BPE_IL_LIM_DLY_HYST_SHIFT	16
#define CS35L45_BST_BPE_IL_LIM_DLY_HYST_MASK	GENMASK(22, 16)
#define CS35L45_BST_BPE_IL_LIM2_DLY_SHIFT	8
#define CS35L45_BST_BPE_IL_LIM2_DLY_MASK	GENMASK(15, 8)
#define CS35L45_BST_BPE_IL_LIM1_DLY_SHIFT	0
#define CS35L45_BST_BPE_IL_LIM1_DLY_MASK	GENMASK(7, 0)

#define CS35L45_BST_BPE_IL_LIM2_ATK_RATE_SHIFT	8
#define CS35L45_BST_BPE_IL_LIM2_ATK_RATE_MASK	GENMASK(10, 8)
#define CS35L45_BST_BPE_IL_LIM1_ATK_RATE_SHIFT	0
#define CS35L45_BST_BPE_IL_LIM1_ATK_RATE_MASK	GENMASK(2, 0)

#define CS35L45_BST_BPE_IL_LIM2_RLS_RATE_SHIFT	8
#define CS35L45_BST_BPE_IL_LIM2_RLS_RATE_MASK	GENMASK(12, 8)
#define CS35L45_BST_BPE_IL_LIM1_RLS_RATE_SHIFT	0
#define CS35L45_BST_BPE_IL_LIM1_RLS_RATE_MASK	GENMASK(4, 0)

#define CS35L45_ASP_WIDTH_16			0x10
#define CS35L45_ASP_WIDTH_24			0x18
#define CS35L45_ASP_WIDTH_32			0x20

#define CS35L45_ASP_WIDTH_RX_SHIFT		24
#define CS35L45_ASP_WIDTH_RX_MASK		GENMASK(31, 24)
#define CS35L45_ASP_WIDTH_TX_SHIFT		16
#define CS35L45_ASP_WIDTH_TX_MASK		GENMASK(23, 16)
#define CS35L45_ASP_FMT_SHIFT			8
#define CS35L45_ASP_FMT_MASK			GENMASK(10, 8)
#define CS35L45_ASP_BCLK_INV_SHIFT		6
#define CS35L45_ASP_BCLK_INV_MASK		BIT(6)
#define CS35L45_ASP_BCLK_MSTR_SHIFT		4
#define CS35L45_ASP_BCLK_MSTR_MASK		BIT(4)
#define CS35L45_ASP_FSYNC_INV_SHIFT		2
#define CS35L45_ASP_FSYNC_INV_MASK		BIT(2)
#define CS35L45_ASP_FSYNC_MSTR_SHIFT		0
#define CS35L45_ASP_FSYNC_MSTR_MASK		BIT(0)

#define CS35L45_ASP_WL_MAX			24
#define CS35L45_ASP_WL_MIN			12

#define CS35L45_ASP_WL_SHIFT			0
#define CS35L45_ASP_WL_MASK			GENMASK(5, 0)

#define CS35L45_ASP_DOUT_HIZ_CTRL_SHIFT		0
#define CS35L45_ASP_DOUT_HIZ_CTRL_MASK		GENMASK(1, 0)

#define CS35L45_ASP_TX4_SLOT_SHIFT		24
#define CS35L45_ASP_TX4_SLOT_MASK		GENMASK(29, 24)
#define CS35L45_ASP_TX3_SLOT_SHIFT		16
#define CS35L45_ASP_TX3_SLOT_MASK		GENMASK(21, 16)
#define CS35L45_ASP_TX2_SLOT_SHIFT		8
#define CS35L45_ASP_TX2_SLOT_MASK		GENMASK(13, 8)
#define CS35L45_ASP_TX1_SLOT_SHIFT		0
#define CS35L45_ASP_TX1_SLOT_MASK		GENMASK(5, 0)

#define CS35L45_ASP_TX_ALL_SLOTS		(CS35L45_ASP_TX4_SLOT_MASK | \
						CS35L45_ASP_TX3_SLOT_MASK  | \
						CS35L45_ASP_TX2_SLOT_MASK  | \
						CS35L45_ASP_TX1_SLOT_MASK)

#define CS35L45_ASP_RX2_SLOT_SHIFT		8
#define CS35L45_ASP_RX2_SLOT_MASK		GENMASK(13, 8)
#define CS35L45_ASP_RX1_SLOT_SHIFT		0
#define CS35L45_ASP_RX1_SLOT_MASK		GENMASK(5, 0)

#define CS35L45_ASP_RX_ALL_SLOTS		(CS35L45_ASP_RX2_SLOT_MASK | \
						CS35L45_ASP_RX1_SLOT_MASK)

#define CS35L45_PCM_SRC_MASK			0x7F
#define CS35L45_PCM_SRC_ZERO			0x00
#define CS35L45_PCM_SRC_ASP_RX1			0x08
#define CS35L45_PCM_SRC_ASP_RX2			0x09
#define CS35L45_PCM_SRC_VMON			0x18
#define CS35L45_PCM_SRC_IMON			0x19
#define CS35L45_PCM_SRC_ERR_VOL			0x20
#define CS35L45_PCM_SRC_CLASSH_TGT		0x21
#define CS35L45_PCM_SRC_VDD_BATTMON		0x28
#define CS35L45_PCM_SRC_VDD_BSTMON		0x29
#define CS35L45_PCM_SRC_DSP_TX1			0x32
#define CS35L45_PCM_SRC_DSP_TX2			0x33
#define CS35L45_PCM_SRC_TEMPMON			0x3A
#define CS35L45_PCM_SRC_SWIRE_RX1		0x44
#define CS35L45_PCM_SRC_SWIRE_RX2		0x45

#define CS35L45_FORCE_LV_OPERATION		0x01
#define CS35L45_FORCE_HV_OPERATION		0x02
#define CS35L45_HVLV_OPERATION			0x03

#define CS35L45_HVLV_THLD_HYS_SHIFT		22
#define CS35L45_HVLV_THLD_HYS_MASK		GENMASK(23, 22)
#define CS35L45_HVLV_THLD_SHIFT			16
#define CS35L45_HVLV_THLD_MASK			GENMASK(20, 16)
#define CS35L45_HVLV_DLY_SHIFT			2
#define CS35L45_HVLV_DLY_MASK			GENMASK(4, 2)
#define CS35L45_HVLV_MODE_SHIFT			0
#define CS35L45_HVLV_MODE_MASK			GENMASK(1, 0)

#define CS35L45_LDPM_GP1_BOOST_SEL_SHIFT	15
#define CS35L45_LDPM_GP1_BOOST_SEL_MASK		BIT(15)
#define CS35L45_LDPM_GP1_AMP_SEL_SHIFT		14
#define CS35L45_LDPM_GP1_AMP_SEL_MASK		BIT(14)
#define CS35L45_LDPM_GP1_DELAY_SHIFT		11
#define CS35L45_LDPM_GP1_DELAY_MASK		GENMASK(13, 11)
#define CS35L45_LDPM_GP1_PCM_THLD_SHIFT		8
#define CS35L45_LDPM_GP1_PCM_THLD_MASK		GENMASK(10, 8)
#define CS35L45_LDPM_GP2_IMON_SEL_SHIFT		7
#define CS35L45_LDPM_GP2_IMON_SEL_MASK		BIT(7)
#define CS35L45_LDPM_GP2_VMON_SEL_SHIFT		6
#define CS35L45_LDPM_GP2_VMON_SEL_MASK		BIT(6)
#define CS35L45_LDPM_GP2_DELAY_SHIFT		3
#define CS35L45_LDPM_GP2_DELAY_MASK		GENMASK(5, 3)
#define CS35L45_LDPM_GP2_PCM_THLD_SHIFT		0
#define CS35L45_LDPM_GP2_PCM_THLD_MASK		GENMASK(2, 0)

#define CS35L45_CH_HDRM_SHIFT			24
#define CS35L45_CH_HDRM_MASK			GENMASK(30, 24)
#define CS35L45_CH_RATIO_SHIFT			8
#define CS35L45_CH_RATIO_MASK			GENMASK(12, 8)
#define CS35L45_CH_REL_RATE_SHIFT		0
#define CS35L45_CH_REL_RATE_MASK		GENMASK(7, 0)

#define CS35L45_CH_OVB_THLD1_SHIFT		16
#define CS35L45_CH_OVB_THLD1_MASK		GENMASK(23, 16)
#define CS35L45_CH_OVB_THLDDELTA_SHIFT		8
#define CS35L45_CH_OVB_THLDDELTA_MASK		GENMASK(15, 8)
#define CS35L45_CH_VDD_BST_MAX_SHIFT		0
#define CS35L45_CH_VDD_BST_MAX_MASK		GENMASK(7, 0)

#define CS35L45_CH_OVB_LATCH_SHIFT		31
#define CS35L45_CH_OVB_LATCH_MASK		BIT(31)
#define CS35L45_CH_OVB_RATIO_SHIFT		16
#define CS35L45_CH_OVB_RATIO_MASK		GENMASK(20, 16)
#define CS35L45_CH_THLD1_OFFSET_SHIFT		0
#define CS35L45_CH_THLD1_OFFSET_MASK		GENMASK(11, 0)

#define CS35L45_AUD_MEM_DEPTH_SHIFT		0
#define CS35L45_AUD_MEM_DEPTH_MASK		GENMASK(2, 0)

#define CS35l45_HPF_DEFAULT			0x00000000
#define CS35L45_HPF_44P1			0x000108BD
#define CS35L45_HPF_88P2			0x0001045F

#define CS35L45_AMP_VOL_PCM_MUTE		0x04CF

#define CS35L45_AMP_VOL_PCM_SHIFT		0
#define CS35L45_AMP_VOL_PCM_MASK		GENMASK(10, 0)

#define CS35L45_AMP_GAIN_PCM_10DBV		0x00
#define CS35L45_AMP_GAIN_PCM_13DBV		0x01
#define CS35L45_AMP_GAIN_PCM_16DBV		0x02
#define CS35L45_AMP_GAIN_PCM_19DBV		0x03

#define CS35L45_AMP_GAIN_PCM_SHIFT		8
#define CS35L45_AMP_GAIN_PCM_MASK		GENMASK(9, 8)

#define CS35L45_AMP_MUTE_SHIFT			0
#define CS35L45_AMP_MUTE_MASK			BIT(0)

#define CS35L45_AMP_SHORT_ERR_MASK		BIT(31)
#define CS35L45_BST_SHORT_ERR_MASK		BIT(8)

#define CS35L45_MSM_PUP_DONE_MASK		BIT(24)
#define CS35L45_MSM_PDN_DONE_MASK		BIT(23)
#define CS35L45_MSM_GLOBAL_EN_ASSERT_MASK	BIT(22)

#define CS35L45_DSP_VIRT1_MBOX_MASK		BIT(20)
#define CS35L45_DSP_VIRT2_MBOX_MASK		BIT(21)

#define CS35L45_PLL_UNLOCK_FLAG_RISE_MASK	BIT(4)
#define CS35L45_PLL_LOCK_FLAG_MASK		BIT(1)

#define CS35L45_OTP_BOOT_DONE_STS_MASK		BIT(1)
#define CS35L45_OTP_BUSY_MASK			BIT(0)

#define CS35L45_GLOBAL_ERROR_MASK		BIT(15)

#define CS35L45_GPIO_DIR_SHIFT			31
#define CS35L45_GPIO_DIR_MASK			BIT(31)
#define CS35L45_GPIO_LVL_SHIFT			15
#define CS35L45_GPIO_LVL_MASK			BIT(15)
#define CS35L45_GPIO_OP_CFG_SHIFT		14
#define CS35L45_GPIO_OP_CFG_MASK		BIT(14)
#define CS35L45_GPIO_POL_SHIFT			12
#define CS35L45_GPIO_POL_MASK			BIT(12)

#define CS35L45_GPIO_CTRL_SHIFT			20
#define CS35L45_GPIO_CTRL_MASK			GENMASK(22, 20)
#define CS35L45_GPIO_INVERT_SHIFT		19
#define CS35L45_GPIO_INVERT_MASK		BIT(19)

#define CS35L45_AUX_NGATE_CH_EN_SHIFT		16
#define CS35L45_AUX_NGATE_CH_EN_MASK		BIT(16)
#define CS35L45_AUX_NGATE_CH_HOLD_SHIFT		8
#define CS35L45_AUX_NGATE_CH_HOLD_MASK		GENMASK(11, 8)
#define CS35L45_AUX_NGATE_CH_THR_SHIFT		0
#define CS35L45_AUX_NGATE_CH_THR_MASK		GENMASK(2, 0)

#define CS35L45_AUX_NGATE_CH_HOLD_DEFAULT	0x03
#define CS35L45_AUX_NGATE_CH_THR_DEFAULT	0x03

#define CS35L45_MAX_CACHE_REG			0x0000006B
#define CS35L45_MAX_PLL_CONFIGS			64
#define CS35L45_REGSTRIDE			4
#define CS35L45_VALID_PDATA			0x80000000
#define CS35L45_DEFAULT_SLOT_WIDTH		32
#define CS35L45_BUFSIZE				64
#define CS35L45_ALGID				0xCD
#define CS35L45_ALGID_MDSYNC			0xF20A

struct cs35l45_private;

struct cs35l45_pll_sysclk_config {
	int freq;
	int clk_cfg;
};

enum cspl_mboxstate {
	CSPL_MBOX_STS_RUNNING = 0,
	CSPL_MBOX_STS_PAUSED = 1,
	CSPL_MBOX_STS_RDY_FOR_REINIT = 2,
	CSPL_MBOX_STS_HIBERNATE = 3,
	CSPL_MBOX_STS_RECONFIGURING = 4,
};

enum cspl_mboxcmd {
	CSPL_MBOX_CMD_NONE = 0,
	CSPL_MBOX_CMD_PAUSE = 1,
	CSPL_MBOX_CMD_RESUME = 2,
	CSPL_MBOX_CMD_REINIT = 3,
	CSPL_MBOX_CMD_STOP_PRE_REINIT = 4,
	CSPL_MBOX_CMD_HIBERNATE = 5,
	CSPL_MBOX_CMD_OUT_OF_HIBERNATE = 6,
	CSPL_MBOX_CMD_PREPARE_RECONFIGURATION = 7,
	CSPL_MBOX_CMD_APPLY_RECONFIGURATION = 8,
	CSPL_MBOX_CMD_UNKNOWN_CMD = -1,
	CSPL_MBOX_CMD_INVALID_SEQUENCE = -2,
};

enum cspl_cmd {
	CSPL_CMD_NONE = 0,
	CSPL_CMD_MUTE = 1,
	CSPL_CMD_UNMUTE = 2,
	CSPL_CMD_UPDATE_PARAM = 8,
};

enum cspl_st {
	CSPL_ST_RUNNING			= 0,
	CSPL_ST_ERROR			= 1,
	CSPL_ST_MUTED			= 2,
	CSPL_ST_REINITING		= 3,
	CSPL_ST_DIAGNOSING		= 6,
};

enum pcm_mixers {
	ASP_TX1 = 0,
	ASP_TX2,
	ASP_TX3,
	ASP_TX4,
	DSP_RX1,
	DSP_RX2,
	DSP_RX3,
	DSP_RX4,
	DSP_RX5,
	DSP_RX6,
	DSP_RX7,
	DSP_RX8,
	DACPCM,
	NGATE1,
	NGATE2,
};

enum amp_mode {
	AMP_MODE_SPK = 0,
	AMP_MODE_RCV = 1,
};

enum hiber_mode {
	HIBER_MODE_DIS = 0,
	HIBER_MODE_EN = 1,
};

enum dapm_route_mode {
	DAPM_MODE_ASP = 0,
	DAPM_MODE_DSP_SLAVE = 1,
	DAPM_MODE_DSP_MASTER = 2,
};

bool cs35l45_readable_reg(struct device *dev, unsigned int reg);
bool cs35l45_volatile_reg(struct device *dev, unsigned int reg);
bool cs35l45_precious_reg(struct device *dev, unsigned int reg);
int cs35l45_set_csplmboxcmd(struct cs35l45_private *cs35l45,
			    enum cspl_mboxcmd cmd);

extern const struct reg_default cs35l45_reg[CS35L45_MAX_CACHE_REG];
extern const struct cs35l45_pll_sysclk_config
		cs35l45_pll_sysclk[CS35L45_MAX_PLL_CONFIGS];

#endif /*__CS35L45_H__*/
