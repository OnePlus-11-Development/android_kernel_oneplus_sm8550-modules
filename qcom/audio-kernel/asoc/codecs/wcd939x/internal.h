/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2018-2020, The Linux Foundation. All rights reserved.
 * Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _WCD939X_INTERNAL_H
#define _WCD939X_INTERNAL_H

#include <asoc/wcd-mbhc-v2.h>
#include <asoc/wcd-irq.h>
#include <asoc/wcd-clsh.h>
#include <soc/soundwire.h>
#include "wcd939x-mbhc.h"
#include "wcd939x.h"

#define SWR_SCP_CONTROL    0x44
#define SWR_SCP_HOST_CLK_DIV2_CTL_BANK 0xE0
#define WCD939X_MAX_MICBIAS 4

/* Convert from vout ctl to micbias voltage in mV */
#define  WCD_VOUT_CTL_TO_MICB(v)  (1000 + v * 50)
#define MAX_PORT 8
#define MAX_CH_PER_PORT 8
#define TX_ADC_MAX 4
#define SWR_NUM_PORTS	4

enum {
	RX_CLK_9P6MHZ,
	RX_CLK_12P288MHZ,
	RX_CLK_11P2896MHZ,
};

enum {
	WCD939X_HPHL,
	WCD939X_HPHR,
	WCD939X_HPH_MAX,
};

enum {
	TX_HDR12 = 0,
	TX_HDR34,
	TX_HDR_MAX,
};

enum xtalk_mode {
	XTALK_NONE = 0,
	XTALK_DIGITAL = 1,
	XTALK_ANALOG = 2
};

extern struct regmap_config wcd939x_regmap_config;

struct comp_coeff_val {
	u8 lsb;
	u8 msb;
};

struct codec_port_info {
	u32 slave_port_type;
	u32 master_port_type;
	u32 ch_mask;
	u32 num_ch;
	u32 ch_rate;
};

struct wcd939x_priv {
	struct device *dev;

	int variant;
	struct snd_soc_component *component;
	struct device_node *rst_np;
	struct regmap *regmap;

	struct swr_device *rx_swr_dev;
	struct swr_device *tx_swr_dev;

	s32 micb_ref[WCD939X_MAX_MICBIAS];
	s32 pullup_ref[WCD939X_MAX_MICBIAS];

	struct fw_info *fw_data;
	struct device_node *wcd_rst_np;

	struct mutex micb_lock;
	struct mutex wakeup_lock;
	s32 dmic_0_1_clk_cnt;
	s32 dmic_2_3_clk_cnt;
	s32 dmic_4_5_clk_cnt;
	s32 dmic_6_7_clk_cnt;
	int hdr_en[TX_HDR_MAX];
	/* class h specific info */
	struct wcd_clsh_cdc_info clsh_info;
	/* mbhc module */
	struct wcd939x_mbhc *mbhc;

	/*compander and xtalk*/
	int compander_enabled[WCD939X_HPH_MAX];
	int xtalk_enabled[WCD939X_HPH_MAX];
	u8 hph_pcm_enabled;

	u32 hph_mode;
	u32 tx_mode[TX_ADC_MAX];
	s32 adc_count;
	bool comp1_enable;
	bool comp2_enable;
	bool ldoh;
	bool bcs_dis;
	bool dapm_bias_off;
	bool in_2Vpk_mode;
	struct irq_domain *virq;
	struct wcd_irq_info irq_info;
	u32 rx_clk_cnt;
	int num_irq_regs;
	/* to track the status */
	unsigned long status_mask;

	u8 num_tx_ports;
	u8 num_rx_ports;
	struct codec_port_info
			tx_port_mapping[MAX_PORT][MAX_CH_PER_PORT];
	struct codec_port_info
			rx_port_mapping[MAX_PORT][MAX_CH_PER_PORT];
	struct swr_port_params tx_port_params[SWR_UC_MAX][SWR_NUM_PORTS];
	struct swr_dev_frame_config swr_tx_port_params[SWR_UC_MAX];
	struct regulator_bulk_data *supplies;
	struct notifier_block nblock;
	/* wcd callback to bolero */
	void *handle;
	int (*update_wcd_event)(void *handle, u16 event, u32 data);
	int (*register_notifier)(void *handle,
				struct notifier_block *nblock,
				bool enable);
	int (*wakeup)(void *handle, bool enable);
	u32 version;
	/* Entry for version info */
	struct snd_info_entry *entry;
	struct snd_info_entry *version_entry;
	struct snd_info_entry *variant_entry;
	int flyback_cur_det_disable;
	int ear_rx_path;
	bool dev_up;
	u8 tx_master_ch_map[WCD939X_MAX_SLAVE_CH_TYPES];
	bool usbc_hs_status;
	u8 rx_clk_config;
	/* wcd to swr dmic notification */
	bool notify_swr_dmic;
	struct blocking_notifier_head notifier;
};

struct wcd939x_micbias_setting {
	u8 ldoh_v;
	u32 cfilt1_mv;
	u32 micb1_mv;
	u32 micb2_mv;
	u32 micb3_mv;
	u32 micb4_mv;
	u8 bias1_cfilt_sel;
};

struct wcd939x_xtalk_params {
	u32 r_gnd_int_fet_mohms;
	u32 r_gnd_par_route1_mohms;
	u32 r_gnd_par_route2_mohms;
	u32 r_gnd_ext_fet_mohms;
	u32 r_conn_par_load_neg_mohms;
	u32 r_aud_int_fet_l_mohms;
	u32 r_aud_int_fet_r_mohms;
	u32 r_aud_ext_fet_l_mohms;
	u32 r_aud_ext_fet_r_mohms;
	u32 r_conn_par_load_pos_l_mohms;
	u32 r_conn_par_load_pos_r_mohms;
	u32 r_gnd_res_tot_mohms;
	u32 r_aud_res_tot_l_mohms;
	u32 r_aud_res_tot_r_mohms;
	u32 zl;
	u32 zr;
	u8 scale_l;
	u8 alpha_l;
	u8 scale_r;
	u8 alpha_r;
	enum xtalk_mode xtalk_config;
};

struct wcd939x_pdata {
	struct device_node *rst_np;
	struct device_node *rx_slave;
	struct device_node *tx_slave;
	struct wcd939x_micbias_setting micbias;
	struct wcd939x_xtalk_params xtalk;

	struct cdc_regulator *regulator;
	int num_supplies;
};

struct wcd_ctrl_platform_data {
	void *handle;
	int (*update_wcd_event)(void *handle, u16 event, u32 data);
	int (*register_notifier)(void *handle,
				 struct notifier_block *nblock,
				 bool enable);
};

enum {
	WCD_RX1,
	WCD_RX2,
	WCD_RX3
};

enum {
	/* INTR_CTRL_INT_MASK_0 */
	WCD939X_IRQ_MBHC_BUTTON_PRESS_DET = 0,
	WCD939X_IRQ_MBHC_BUTTON_RELEASE_DET,
	WCD939X_IRQ_MBHC_ELECT_INS_REM_DET,
	WCD939X_IRQ_MBHC_ELECT_INS_REM_LEG_DET,
	WCD939X_IRQ_MBHC_SW_DET,
	WCD939X_IRQ_HPHR_OCP_INT,
	WCD939X_IRQ_HPHR_CNP_INT,
	WCD939X_IRQ_HPHL_OCP_INT,

	/* INTR_CTRL_INT_MASK_1 */
	WCD939X_IRQ_HPHL_CNP_INT,
	WCD939X_IRQ_EAR_CNP_INT,
	WCD939X_IRQ_EAR_SCD_INT,
	WCD939X_IRQ_HPHL_PDM_WD_INT,
	WCD939X_IRQ_HPHR_PDM_WD_INT,
	WCD939X_IRQ_EAR_PDM_WD_INT,

	/* INTR_CTRL_INT_MASK_2 */
	WCD939X_IRQ_MBHC_MOISTURE_INT,
	WCD939X_IRQ_HPHL_SURGE_DET_INT,
	WCD939X_IRQ_HPHR_SURGE_DET_INT,
	WCD939X_NUM_IRQS,
};

extern struct wcd939x_mbhc *wcd939x_soc_get_mbhc(
				struct snd_soc_component *component);
extern void wcd939x_disable_bcs_before_slow_insert(
				struct snd_soc_component *component,
				bool bcs_disable);
extern int wcd939x_mbhc_micb_adjust_voltage(struct snd_soc_component *component,
					int volt, int micb_num);
extern int wcd939x_get_micb_vout_ctl_val(u32 micb_mv);
extern int wcd939x_micbias_control(struct snd_soc_component *component,
			int micb_num, int req, bool is_dapm);
#endif /* _WCD939X_INTERNAL_H */
