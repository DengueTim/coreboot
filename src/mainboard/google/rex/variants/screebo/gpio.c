/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <baseboard/gpio.h>
#include <baseboard/variants.h>
#include <types.h>
#include <soc/gpio.h>
#include <vendorcode/google/chromeos/chromeos.h>

/* Pad configuration in ramstage */
static const struct pad_config gpio_table[] = {
	/* GPP_A00 : GPP_A00 ==> ESPI_SOC_IO0_R configured on reset, do not touch */
	/* GPP_A01 : GPP_A01 ==> ESPI_SOC_IO1_R configured on reset, do not touch */
	/* GPP_A02 : GPP_A02 ==> ESPI_SOC_IO2_R configured on reset, do not touch */
	/* GPP_A03 : GPP_A03 ==> ESPI_SOC_IO3_R configured on reset, do not touch */
	/* GPP_A04 : GPP_A04 ==> ESPI_SOC_CS0_L configured on reset, do not touch */
	/* GPP_A05 : GPP_A05 ==> ESPI_SOC_CLK_R configured on reset, do not touch */
	/* GPP_A06 : GPP_A06 ==> ESPI_SOC_RESET_L configured on reset, do not touch */
	/* GPP_A11 : [] ==> EN_UCAM_SENR_PWR */
	PAD_CFG_GPO(GPP_A11, 0, DEEP),
	/* GPP_A12 : [] ==> EN_UCAM_PWR */
	PAD_CFG_GPO(GPP_A12, 0, DEEP),
	/* GPP_A13 : [] ==> SD_PE_LS_PRSNT_L */
	PAD_CFG_GPI_LOCK(GPP_A13, NONE, LOCK_CONFIG),
	/* GPP_A14 : net NC is not present in the given design */
	PAD_NC(GPP_A14, NONE),
	/* GPP_A15 : net NC is not present in the given design */
	PAD_NC(GPP_A15, NONE),
	/* GPP_A16 : GPP_A16 ==> ESPI_SOC_ALERT_L configured on reset, do not touch */
	/* GPP_A17 : [] ==> EC_SOC_INT_ODL */
	PAD_CFG_GPI_APIC_LOCK(GPP_A17, NONE, LEVEL, INVERT, LOCK_CONFIG),

	/* GPP_A18 : net NC.  Test pad. */
	PAD_NC(GPP_A18, NONE),
	/* GPP_A19 : [] ==> EN_PP3300_SSD */
	PAD_CFG_GPO(GPP_A19, 1, DEEP),
	/* GPP_A20 : [] ==> SSD_PERST_L */
	PAD_CFG_GPO_LOCK(GPP_A20, 1, LOCK_CONFIG),
	/* GPP_A21 : [] ==> PMCALERT */
	PAD_CFG_NF(GPP_A21, NONE, DEEP, NF1),

	/* GPP_B00 : [] ==> TCHPAD_INT_ODL_LS */
	PAD_CFG_GPI_IRQ_WAKE_LOCK(GPP_B00, NONE, LEVEL, INVERT, LOCK_CONFIG),
	/* GPP_B01 : [] ==> BT_DISABLE_L */
	PAD_CFG_GPO(GPP_B01, 1, DEEP),
	/* GPP_B02 : net NC is not present in the given design */
	PAD_NC(GPP_B02, NONE),
	/* GPP_B03 : net NC is not present in the given design */
	PAD_NC(GPP_B03, NONE),
	/* GPP_B04 : GPP_B04_STRAP ==> Component NC */
	PAD_NC(GPP_B04, NONE),
	/* GPP_B05 : [] ==> SPKR_INT_L_R */
	/* GPP_B05 : net NC is not present in the given design */
	PAD_NC(GPP_B05, NONE),
	/* GPP_B06 : [] ==> HP_INT_L_R */
	PAD_CFG_GPI_INT(GPP_B06, NONE, PLTRST, EDGE_BOTH),
	/* GPP_B07 : [] ==> EN_SPKR */
	PAD_CFG_GPO(GPP_B07, 1, DEEP),
	/* GPP_B08 : [] ==> EN_FP_PWR */
	PAD_CFG_GPO_LOCK(GPP_B08, 1, LOCK_CONFIG),
	/* GPP_B09 : net NC is not present in the given design */
	PAD_NC(GPP_B09, NONE),
	/* GPP_B10 : net NC is not present in the given design */
	PAD_NC(GPP_B10, NONE),
	/* GPP_B11 : [] ==> USB_C1_OC_ODL*/
	PAD_CFG_NF_LOCK(GPP_B11, NONE, NF1, LOCK_CONFIG),
	/* GPP_B12 : [] ==> SLP_SO_R_L */
	PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1),
	/* GPP_B13 : [] ==> PLT_RST_L */
	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),
	/* GPP_B14 : GPP_B14_STRAP ==> Component NC */
	PAD_NC(GPP_B14, NONE),
	/* GPP_B15 : [] ==> USB_OC3# */
	PAD_CFG_NF_LOCK(GPP_B15, NONE, NF1, LOCK_CONFIG),
	/* GPP_B16 : [] ==> SOC_HDMI_HPD_L */
	PAD_CFG_NF(GPP_B16, NONE, DEEP, NF2),
	/* GPP_B17 : net NC.  Test pad. */
	PAD_NC(GPP_B17, NONE),
	/* GPP_B18 : [] ==> SOC_I2C_TPM_SDA */
	PAD_CFG_NF_LOCK(GPP_B18, NONE, NF2, LOCK_CONFIG),
	/* GPP_B19 : [] ==> SOC_I2C_TPM_SCL */
	PAD_CFG_NF_LOCK(GPP_B19, NONE, NF2, LOCK_CONFIG),
	/* GPP_B20 : [] ==> SOC_I2C_MISC_SDA */
	PAD_CFG_NF_LOCK(GPP_B20, NONE, NF2, LOCK_CONFIG),
	/* GPP_B21 : [] ==> SOC_I2C_MISC_SCL */
	PAD_CFG_NF_LOCK(GPP_B21, NONE, NF2, LOCK_CONFIG),
	/* GPP_B22 : [] ==> USB4_RT_FORCE_PWR */
	PAD_CFG_GPO(GPP_B22, 0, DEEP),
	/* GPP_B23 : net NC.  Test pad. */
	PAD_NC(GPP_B23, NONE),
	/* GPP_C00 : [] ==> EN_TCHSCR_PWR */
	PAD_CFG_GPO(GPP_C00, 0, DEEP),
	/* GPP_C01 : [] ==>  SOC_TCHSCR_RST_L */
	PAD_CFG_GPO(GPP_C01, 0, DEEP),
	/* GPP_C02 : SOC_TCHSCR_SPI_INT_STRAP ==> Component NC */
	PAD_NC(GPP_C02, NONE),
	/* GPP_C03 : [] ==> SOC_TCP_SMBUS_CLK*/
	PAD_CFG_NF_LOCK(GPP_C03, NONE, NF1, LOCK_CONFIG),
	/* GPP_C04 : [] ==> SOC_TCP_SMBUS_SDA*/
	PAD_CFG_NF_LOCK(GPP_C04, NONE, NF1, LOCK_CONFIG),
	/* GPP_C05 : [] ==> WWAN_PERST_L_STRAP */
	PAD_NC(GPP_C05, NONE),
	/* GPP_C06 : [] ==> SOC_TCHSCR_RPT_EN */
	PAD_CFG_GPO(GPP_C06, 1, DEEP),
	/* GPP_C07 : [] ==> SOC_TCHSCR_INT */
	PAD_CFG_GPI_APIC(GPP_C07, NONE, PLTRST, LEVEL, NONE),
	/* GPP_C08 : [] ==> SOCHOT_ODL */
	PAD_CFG_NF(GPP_C08, NONE, DEEP, NF2),
	/* GPP_C09 : net NC is not present in the given design */
	PAD_NC(GPP_C09, NONE),
	/* GPP_C10 : net NC is not present in the given design */
	PAD_NC(GPP_C10, NONE),
	/* GPP_C11 : [] ==> SD_CLKREQ_ODL */
	/* PAD_CFG_NF(GPP_C11, NONE, DEEP, NF1),*/
	PAD_NC(GPP_C11, NONE),
	/* GPP_C12 : [] ==> WWAN_CLKREQ_ODL */
	/* PAD_CFG_NF(GPP_C12, NONE, DEEP, NF1),*/
	PAD_NC(GPP_C12, NONE),
	/* GPP_C13 : [] ==> SSD_CLKREQ_ODL */
	PAD_CFG_NF(GPP_C13, NONE, DEEP, NF1),
	/* GPP_C15 : [] ==> WWAN_DPR_SAR_ODL */
	PAD_CFG_GPO(GPP_C15, 1, DEEP),
	/* GPP_C16 : [] ==> USB_C0_AUX_DC_P */
	PAD_CFG_NF(GPP_C16, NONE, DEEP, NF6),
	/* GPP_C17 : [] ==> USB_C0_AUX_DC_N */
	PAD_CFG_NF(GPP_C17, NONE, DEEP, NF6),
	/* GPP_C18 : [] ==> USB_C0_LSX_TX */
	PAD_CFG_NF(GPP_C18, NONE, DEEP, NF1),
	/* GPP_C19 : [] ==> USB_C0_LSX_RX */
	PAD_CFG_NF(GPP_C19, NONE, DEEP, NF1),
	/* GPP_C20 : [] ==> SOC_FP_BOOT0 */
	PAD_CFG_GPO_LOCK(GPP_C20, 0, LOCK_CONFIG),
	/* GPP_C21 : [] ==> FP_RST_ODL */
	PAD_CFG_GPO_LOCK(GPP_C21, 1, LOCK_CONFIG),
	/* GPP_C22 : [] ==> USB_C1_LSX_TX */
	PAD_CFG_NF(GPP_C22, NONE, DEEP, NF1),
	/* GPP_C23 : [] ==> USB_C1_LSX_RX */
	PAD_CFG_NF(GPP_C23, NONE, DEEP, NF1),

	/* GPP_D00 : net NC is not present in the given design */
	PAD_NC(GPP_D00, NONE),
	/* GPP_D01 : [] ==> SD_PE_WAKE_ODL */
	PAD_CFG_GPI_LOCK(GPP_D01, NONE, LOCK_CONFIG),
	/* GPP_D02 : [] ==> SD_PERST_L */
	PAD_CFG_GPO_LOCK(GPP_D02, 1, LOCK_CONFIG),
	/* GPP_D03 : [] ==> EN_PP3300_SD */
	PAD_CFG_GPO_LOCK(GPP_D03, 1, LOCK_CONFIG),
	/* GPP_D04 : net NC is not present in the given design */
	PAD_NC(GPP_D04, NONE),
	/* GPP_D05 : [] ==> UART0_RXD. */
	PAD_CFG_NF_LOCK(GPP_D05, NONE, NF1, LOCK_CONFIG),
	/* GPP_D06 : [] ==> UART0_TXD. */
	PAD_CFG_NF_LOCK(GPP_D06, NONE, NF1, LOCK_CONFIG),
	/* GPP_D07 : net NC.  Test pad. */
	PAD_NC(GPP_D07, NONE),
	/* GPP_D08 : net NC.  Test pad. */
	PAD_NC(GPP_D08, NONE),
	/* GPP_D09 : [] ==> I2S_MCLK_R */
	PAD_CFG_NF(GPP_D09, NONE, DEEP, NF2),
	/* GPP_D10 : [] ==> I2S_SPKR_SCLK_R */
	PAD_CFG_NF(GPP_D10, NONE, DEEP, NF2),
	/* GPP_D11 : [] ==> I2S_SPKR_SFRM_R */
	PAD_CFG_NF(GPP_D11, NONE, DEEP, NF2),
	/* GPP_D12 : [] ==> I2S_SOC_TX_SPKR_RX_R_STRAP */
	PAD_CFG_NF(GPP_D12, DN_20K, DEEP, NF2),
	/* GPP_D13 : [] ==> I2S_SOC_RX_SPKR_TX */
	/* GPP_D13 : net NC is not present in the given design */
	PAD_NC(GPP_D13, NONE),
	/* GPP_D14 : [] ==> I2S_HP_SCLK_R */
	PAD_CFG_NF(GPP_D14, NONE, DEEP, NF2),
	/* GPP_D15 : [] ==> I2S_HP_SFRM_R */
	PAD_CFG_NF(GPP_D15, NONE, DEEP, NF2),
	/* GPP_D16 : [] ==> I2S_SOC_TX_HP_RX_R */
	PAD_CFG_NF(GPP_D16, NONE, DEEP, NF2),
	/* GPP_D17 : [] ==> I2S_SOC_RX_HP_TX */
	PAD_CFG_NF(GPP_D17, NONE, DEEP, NF2),
	/* GPP_D18 : net NC is not present in the given design */
	PAD_NC(GPP_D18, NONE),
	/* GPP_D19 : [] ==> SD_CLKREQ_ODL */
	PAD_CFG_NF(GPP_D19, NONE, DEEP, NF1),
	/* GPP_D20 : net NC is not present in the given design */
	PAD_NC(GPP_D20, NONE),
	/* GPP_D21 : net NC is not present in the given design */
	PAD_NC(GPP_D21, NONE),
	/* GPP_D22 : net NC.  Test pad. */
	PAD_NC(GPP_D22, NONE),
	/* GPP_D23 : net NC.  Test pad. */
	PAD_NC(GPP_D23, NONE),

	/* GPP_E00 : net NC is not present in the given design */
	PAD_NC(GPP_E00, NONE),
	/* GPP_E01 : MEM_STRAP_2 ==> Component NC */
	PAD_CFG_GPI_LOCK(GPP_E01, NONE, LOCK_CONFIG),
	/* GPP_E02 : MEM_STRAP_1 ==> Component NC */
	PAD_CFG_GPI_LOCK(GPP_E02, NONE, LOCK_CONFIG),
	/* GPP_E03 : [] ==> GSC_SOC_INT_ODL */
	PAD_CFG_GPI_APIC_LOCK(GPP_E03, NONE, LEVEL, INVERT, LOCK_CONFIG),
	/* GPP_E04 : net NC is not present in the given design */
	PAD_NC(GPP_E04, NONE),
	/* GPP_E05 : net NC is not present in the given design */
	PAD_NC(GPP_E05, NONE),
	/* GPP_E06 : GPP_E06_STRAP ==> Component NC */
	PAD_NC(GPP_E06, NONE),
	/* GPP_E07 : net NC is not present in the given design */
	PAD_NC(GPP_E07, NONE),
	/* GPP_E08 : net NC is not present in the given design */
	PAD_NC(GPP_E08, NONE),
	/* GPP_E09 : No heuristic was found useful */
	PAD_CFG_NF_LOCK(GPP_E09, NONE, NF1, LOCK_CONFIG),
	/* GPP_E10 : [] ==> SOC_FPMCU_INT_L */
	PAD_CFG_GPI_IRQ_WAKE_LOCK(GPP_E10, NONE, LEVEL, INVERT, LOCK_CONFIG),
	/* GPP_E11 : [] ==> MEM_STRAP_0 */
	PAD_CFG_GPI_LOCK(GPP_E11, NONE, LOCK_CONFIG),
	/* GPP_E12 : [] ==> MEM_STRAP_3 */
	PAD_CFG_GPI_LOCK(GPP_E12, NONE, LOCK_CONFIG),
	/* GPP_E13 :  [] ==> MEM_CH_SEL */
	PAD_CFG_GPI_LOCK(GPP_E13, NONE, LOCK_CONFIG),
	/* GPP_E14 : [] ==> SOC_EDP_HPD_L */
	PAD_CFG_NF(GPP_E14, NONE, DEEP, NF1),
	/* GPP_E15 : net NC is not present in the given design */
	PAD_NC(GPP_E15, NONE),
	/* GPP_E16 : net NC.  Test pad. */
	PAD_NC(GPP_E16, NONE),
	/* GPP_E17 : net NC.  Test pad. */
	PAD_NC(GPP_E17, NONE),
	/* GPP_E22 : [] ==> WIFI_DISABLE_L */
	PAD_CFG_GPO(GPP_E22, 1, DEEP),

	/* GPP_F00 :  [] ==> CNV_BRI_DT_R */
	PAD_CFG_NF(GPP_F00, NONE, DEEP, NF1),
	/* GPP_F01 :  [] ==> CNV_BRI_RSP */
	PAD_CFG_NF(GPP_F01, UP_20K, DEEP, NF1),
	/* GPP_F02 :  [] ==> CNV_RGI_DT_Rl */
	PAD_CFG_NF(GPP_F02, NONE, DEEP, NF1),
	/* GPP_F03 :  [] ==> CNV_RGI_RSP */
	PAD_CFG_NF(GPP_F03, UP_20K, DEEP, NF1),
	/* GPP_F04 :  [] ==> CNV_RF_RST_L */
	PAD_CFG_NF(GPP_F04, NONE, DEEP, NF1),
	/* GPP_F05 :  [] ==> CNV_CLKREQ */
	PAD_CFG_NF(GPP_F05, NONE, DEEP, NF3),
	/* GPP_F06 : net NC is not present in the given design */
	PAD_NC(GPP_F06, NONE),
	/* GPP_F07 :  [] ==> UCAM_MCLK_R */
	PAD_CFG_NF(GPP_F07, NONE, DEEP, NF1),
	/* GPP_F08 : net NC is not present in the given design */
	PAD_NC(GPP_F08, NONE),
	/* GPP_F09 : net NC is not present in the given design */
	PAD_NC(GPP_F09, NONE),
	/* GPP_F10 : net NC is not present in the given design */
	PAD_NC(GPP_F10, NONE),
	/* GPP_F11 : GSP1_SOC_CLK_R */
	PAD_CFG_NF(GPP_F11, NONE, DEEP, NF5),
	/* GPP_F12 : GSPI1_SOC_DO_FPMCU_DI_R */
	PAD_CFG_NF(GPP_F12, NONE, DEEP, NF5),
	/* GPP_F13 : GSPI1_SOC_DI_FPMCU_DO_LS */
	PAD_CFG_NF(GPP_F13, NONE, DEEP, NF5),
	/* GPP_F14 :  net NC.  Test pad. */
	PAD_NC(GPP_F14, NONE),
	/* GPP_F15 :  net NC.  Test pad. */
	PAD_NC(GPP_F15, NONE),
	/* GPP_F16 : net NC.  Test pad. */
	PAD_NC(GPP_F16, NONE),
	/* GPP_F17 : [] ==> GSPI1_SOC_CS_L */
	PAD_CFG_NF(GPP_F17, NONE, DEEP, NF5),
	/* GPP_F18 : net NC is not present in the given design */
	PAD_NC(GPP_F18, NONE),
	/* GPP_F19 : [] ==> GPP_F19_STRAP */
	PAD_NC(GPP_F19, NONE),
	/* GPP_F20 : [] ==> GPP_F20_STRAP */
	PAD_NC(GPP_F20, NONE),
	/* GPP_F21 : [] ==> GPP_F21_STRAP */
	PAD_NC(GPP_F21, NONE),
	/* GPP_F22 : net NC is not present in the given design */
	PAD_NC(GPP_F22, NONE),
	/* GPP_F23 : net NC is not present in the given design */
	PAD_NC(GPP_F23, NONE),

	/* GPP_H00 : GPP_H00_STRAP ==> Component NC */
	PAD_NC(GPP_H00, NONE),
	/* GPP_H01 : GPP_H01_STRAP ==> Component NC */
	PAD_NC(GPP_H01, NONE),
	/* GPP_H02 : GPP_H02_STRAP ==> Component NC */
	PAD_NC(GPP_H02, NONE),
	/* GPP_H04 : net NC is not present in the given design */
	PAD_NC(GPP_H04, NONE),
	/* GPP_H05 : net NC is not present in the given design */
	PAD_NC(GPP_H05, NONE),
	/* GPP_H06 : [] ==> SOC_I2C_TCHPAD_SDA */
	PAD_CFG_NF_LOCK(GPP_H06, NONE, NF1, LOCK_CONFIG),
	/* GPP_H07 : [] ==> SOC_I2C_TCHPAD_SCL */
	PAD_CFG_NF_LOCK(GPP_H07, NONE, NF1, LOCK_CONFIG),
	/* GPP_H08 : [] ==> UART_DBG_TX_SOC_RX_R */
	PAD_CFG_NF(GPP_H08, NONE, DEEP, NF1),
	/* GPP_H09 : [] ==> UART_SOC_TX_DBG_RX_R */
	PAD_CFG_NF(GPP_H09, NONE, DEEP, NF1),
	/* GPP_H10 : [] ==> SOC_WP_OD */
	PAD_CFG_GPI_GPIO_DRIVER_LOCK(GPP_H10, NONE, LOCK_CONFIG),
	/* GPP_H11 : net NC is not present in the given design */
	PAD_NC(GPP_H11, NONE),
	/* GPP_H13 : [] ==> CPU_C10_GATE_L */
	PAD_CFG_NF(GPP_H13, NONE, DEEP, NF1),
	/* GPP_H14 : [] ==> SLP_S0_GATE_R */
	PAD_CFG_GPO(GPP_H14, 1, PLTRST),
	/* GPP_H15 : [] ==> EN_DMIC_SOC_DATA */
	/* GPP_H15 : net NC is not present in the given design */
	PAD_NC(GPP_H15, NONE),
	/* GPP_H16 : [] ==> DDIB_HDMI_CTRLCLK*/
	PAD_CFG_NF(GPP_H16, NONE, DEEP, NF1),
	/* GPP_H17 : [] ==> DDIB_HDMI_CTRLDATA */
	PAD_CFG_NF(GPP_H17, NONE, DEEP, NF1),
	/* GPP_H19 : [] ==> SOC_I2C_AUD_WFC_SDA */
	PAD_CFG_NF(GPP_H19, NONE, DEEP, NF1),
	/* GPP_H20 : [] ==> SOC_I2C_AUD_WFC_SCL */
	PAD_CFG_NF(GPP_H20, NONE, DEEP, NF1),
	/* GPP_H21 : [] ==>  SOC_I2C_TCHSCR_SDA */
	PAD_CFG_NF(GPP_H21, NONE, DEEP, NF1),
	/* GPP_H22 : [] ==>  SOC_I2C_TCHSCR_SCL */
	PAD_CFG_NF(GPP_H22, NONE, DEEP, NF1),

	/* GPP_S00 : net NC is not present in the given design */
	PAD_NC(GPP_S00, NONE),
	/* GPP_S01 : net NC is not present in the given design */
	PAD_NC(GPP_S01, NONE),
	/* GPP_S02 : net NC is not present in the given design */
	PAD_NC(GPP_S02, NONE),
	/* GPP_S03 : net NC is not present in the given design */
	PAD_NC(GPP_S03, NONE),
	/* GPP_S04 : net NC is not present in the given design */
	PAD_NC(GPP_S04, NONE),
	/* GPP_S05 : net NC is not present in the given design */
	PAD_NC(GPP_S05, NONE),
	/* GPP_S06 : [] ==> DMIC_SOC_CLK1_DB_RC */
	PAD_CFG_NF(GPP_S06, NONE, DEEP, NF3),
	/* GPP_S07 : [] ==> DMIC_SOC_DATA1_DB */
	PAD_CFG_NF(GPP_S07, NONE, DEEP, NF3),

	/* GPP_V00 : [] ==> BATLOW_L */
	PAD_CFG_NF(GPP_V00, NONE, DEEP, NF1),
	/* GPP_V01 : [] ==> ACPRESENT */
	PAD_CFG_NF(GPP_V01, NONE, DEEP, NF1),
	/* GPP_V02 : [] ==> EC_SOC_WAKE_ODL */
	PAD_CFG_NF(GPP_V02, NONE, DEEP, NF1),
	/* GPP_V03 : [] ==> EC_SOC_PWR_BTN_ODL */
	PAD_CFG_NF(GPP_V03, NONE, DEEP, NF1),
	/* GPP_V04 : [] ==> SLP_S3_L */
	PAD_CFG_NF(GPP_V04, NONE, DEEP, NF1),
	/* GPP_V05 : [] ==> SLP_S4_L */
	PAD_CFG_NF(GPP_V05, NONE, DEEP, NF1),
	/* GPP_V06 : [] ==> SOC_SLP_A_L */
	PAD_CFG_NF(GPP_V06, NONE, DEEP, NF1),
	/* GPP_V08 : [] ==> SOC_SUSCLK */
	PAD_CFG_NF(GPP_V08, NONE, DEEP, NF1),
	/* GPP_V09 : [] ==> SOC_SLP_WLAN_L */
	PAD_CFG_NF(GPP_V09, NONE, DEEP, NF1),
	/* GPP_V10 : [] ==> SLP_S5_L */
	PAD_CFG_NF(GPP_V10, NONE, DEEP, NF1),
	/* GPP_V11 : [] ==> SOC_GPP_V11 testpoint*/
	PAD_NC(GPP_V11, NONE),
	/* GPP_V12 : [] ==> SOC_SLP_LAN_L */
	PAD_CFG_NF(GPP_V12, NONE, DEEP, NF1),
	/* GPP_V14 : [] ==> SOC_WAKE_L */
	PAD_CFG_NF(GPP_V14, NONE, DEEP, NF1),
	/* GPP_V22 : [] ==> WCAM_RST_L */
	/* GPP_V22 : net NC is not present in the given design */
	PAD_NC(GPP_V22, NONE),
	/* GPP_V23 : [] ==> UCAM_RST_L */
	PAD_CFG_GPO(GPP_V23, 0, DEEP),
};

/* Early pad configuration in bootblock */
static const struct pad_config early_gpio_table[] = {
	/* GPP_B18 : [] ==> SOC_I2C_TPM_SDA */
	PAD_CFG_NF(GPP_B18, NONE, DEEP, NF2),
	/* GPP_B19 : [] ==> SOC_I2C_TPM_SCL */
	PAD_CFG_NF(GPP_B19, NONE, DEEP, NF2),
	/* GPP_E03 : [] ==> GSC_SOC_INT_ODL */
	PAD_CFG_GPI_APIC(GPP_E03, NONE, PLTRST, LEVEL, INVERT),

	/* GPP_H08 : [] ==> UART_DBG_TX_SOC_RX_R */
	PAD_CFG_NF(GPP_H08, NONE, DEEP, NF1),
	/* GPP_H09 : [] ==> UART_SOC_TX_DBG_RX_R */
	PAD_CFG_NF(GPP_H09, NONE, DEEP, NF1),

	/* GPP_D03 : [] ==> EN_PP3300_SD */
	PAD_CFG_GPO(GPP_D03, 1, DEEP),

	/* GPP_E13 :  [] ==> MEM_CH_SEL */
	PAD_CFG_GPI(GPP_E13, NONE, DEEP),

	/* GPP_A20 : [] ==> SSD_PERST_L */
	PAD_CFG_GPO(GPP_A20, 0, DEEP),

	/* GPP_H10 : [] ==> SOC_WP_OD */
	PAD_CFG_GPI_GPIO_DRIVER_LOCK(GPP_H10, NONE, LOCK_CONFIG),
};

static const struct pad_config romstage_gpio_table[] = {
	/* GPP_B11 : [] ==> EN_FP_PWR */
	PAD_CFG_GPO(GPP_B08, 0, DEEP),
	/* A20 : [] ==> SSD_PERST_L */
	PAD_CFG_GPO(GPP_A20, 0, DEEP),
	/* GPP_C23 : [] ==> FP_RST_ODL */
	PAD_CFG_GPO(GPP_C21, 0, DEEP),
	/* GPP_D02 : [] ==> SD_PERST_L */
	PAD_CFG_GPO(GPP_D02, 1, DEEP),
};

const struct pad_config *variant_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(gpio_table);
	return gpio_table;
}

const struct pad_config *variant_early_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(early_gpio_table);
	return early_gpio_table;
}

static const struct cros_gpio cros_gpios[] = {
	CROS_GPIO_REC_AL(CROS_GPIO_VIRTUAL, CROS_GPIO_DEVICE_NAME),
	CROS_GPIO_WP_AH(GPIO_PCH_WP, CROS_GPIO_DEVICE_NAME),
};

DECLARE_CROS_GPIOS(cros_gpios);

const struct pad_config *variant_romstage_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(romstage_gpio_table);
	return romstage_gpio_table;
}
