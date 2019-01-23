/*
 * Copyright (c) 2012-2019 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file wni_api.h contains message definitions exported by
 * Sirius software modules.
 * NOTE: See projects/sirius/include/sir_api.h for structure
 * definitions of the host/FW messages.
 *
 * Author:        Chandra Modumudi
 * Date:          04/11/2002
 * History:-
 * Date           Modified by    Modification Information
 * --------------------------------------------------------------------
 */

#ifndef __WNI_API_H
#define __WNI_API_H

#include "sir_api.h"

#define SIR_SME_MSG_TYPES_BEGIN        (SIR_SME_MODULE_ID << 8)

enum eWniMsgTypes {
	eWNI_SME_MSG_TYPES_BEGIN = SIR_SME_MSG_TYPES_BEGIN,
	eWNI_SME_SYS_READY_IND,
	eWNI_SME_JOIN_REQ,
	eWNI_SME_JOIN_RSP,
	eWNI_SME_SETCONTEXT_REQ,
	eWNI_SME_SETCONTEXT_RSP,
	eWNI_SME_REASSOC_REQ,
	eWNI_SME_REASSOC_RSP,
	eWNI_SME_DISASSOC_REQ,
	eWNI_SME_DISASSOC_RSP,
	eWNI_SME_DISASSOC_IND,
	eWNI_SME_DISASSOC_CNF,
	eWNI_SME_DEAUTH_REQ,
	eWNI_SME_DEAUTH_RSP,
	eWNI_SME_DEAUTH_IND,
	eWNI_SME_DISCONNECT_DONE_IND,
	eWNI_SME_WM_STATUS_CHANGE_NTF,
	eWNI_SME_IBSS_NEW_PEER_IND,
	eWNI_SME_IBSS_PEER_DEPARTED_IND,
	eWNI_SME_START_BSS_REQ,
	eWNI_SME_START_BSS_RSP,
	eWNI_SME_ASSOC_IND,
	eWNI_SME_ASSOC_CNF,
	eWNI_SME_SWITCH_CHL_IND,
	eWNI_SME_STOP_BSS_REQ,
	eWNI_SME_STOP_BSS_RSP,
	eWNI_SME_DEAUTH_CNF,
	eWNI_SME_MIC_FAILURE_IND,
	eWNI_SME_ADDTS_REQ,
	eWNI_SME_ADDTS_RSP,
	eWNI_SME_DELTS_REQ,
	eWNI_SME_DELTS_RSP,
	eWNI_SME_DELTS_IND,
	eWNI_SME_GET_STATISTICS_REQ,
	eWNI_SME_GET_STATISTICS_RSP,
	eWNI_SME_GET_RSSI_REQ,
	eWNI_SME_GET_ASSOC_STAS_REQ,
	eWNI_SME_WPS_PBC_PROBE_REQ_IND,
	eWNI_SME_UPPER_LAYER_ASSOC_CNF,
	eWNI_SME_SESSION_UPDATE_PARAM,
	eWNI_SME_CHNG_MCC_BEACON_INTERVAL,
	eWNI_SME_GET_SNR_REQ,

	eWNI_SME_RRM_MSG_TYPE_BEGIN,

	eWNI_SME_NEIGHBOR_REPORT_REQ_IND,
	eWNI_SME_NEIGHBOR_REPORT_IND,
	eWNI_SME_BEACON_REPORT_REQ_IND,
	eWNI_SME_BEACON_REPORT_RESP_XMIT_IND,

	eWNI_SME_ADD_STA_SELF_RSP,
	eWNI_SME_DEL_STA_SELF_RSP,

	eWNI_SME_FT_PRE_AUTH_REQ,
	eWNI_SME_FT_PRE_AUTH_RSP,
	eWNI_SME_FT_UPDATE_KEY,
	eWNI_SME_FT_AGGR_QOS_REQ,
	eWNI_SME_FT_AGGR_QOS_RSP,

#if defined FEATURE_WLAN_ESE
	eWNI_SME_ESE_ADJACENT_AP_REPORT,
#endif

	eWNI_SME_REGISTER_MGMT_FRAME_REQ,
	eWNI_SME_GENERIC_CHANGE_COUNTRY_CODE,
	eWNI_SME_MAX_ASSOC_EXCEEDED,
#ifdef FEATURE_WLAN_TDLS
	eWNI_SME_TDLS_SEND_MGMT_REQ,
	eWNI_SME_TDLS_SEND_MGMT_RSP,
	eWNI_SME_TDLS_ADD_STA_REQ,
	eWNI_SME_TDLS_ADD_STA_RSP,
	eWNI_SME_TDLS_DEL_STA_REQ,
	eWNI_SME_TDLS_DEL_STA_RSP,
	eWNI_SME_TDLS_DEL_STA_IND,
	eWNI_SME_TDLS_DEL_ALL_PEER_IND,
	eWNI_SME_MGMT_FRM_TX_COMPLETION_IND,
	eWNI_SME_TDLS_LINK_ESTABLISH_REQ,
	eWNI_SME_TDLS_LINK_ESTABLISH_RSP,
	eWNI_SME_TDLS_SHOULD_DISCOVER,
	eWNI_SME_TDLS_SHOULD_TEARDOWN,
	eWNI_SME_TDLS_PEER_DISCONNECTED,
	eWNI_SME_TDLS_CONNECTION_TRACKER_NOTIFICATION,
#endif
	/* NOTE: If you are planning to add more mesages, please make sure that */
	/* SIR_LIM_ITC_MSG_TYPES_BEGIN is moved appropriately. It is set as */
	/* SIR_LIM_MSG_TYPES_BEGIN+0xB0 = 12B0 (which means max of 176 messages and */
	/* eWNI_SME_TDLS_DEL_STA_RSP = 175. */
	/* Should fix above issue to enable TDLS_INTERNAL */
	eWNI_SME_RESET_AP_CAPS_CHANGED,
#ifdef WLAN_FEATURE_11W
	eWNI_SME_UNPROT_MGMT_FRM_IND,
#endif
#ifdef WLAN_FEATURE_GTK_OFFLOAD
	eWNI_PMC_GTK_OFFLOAD_GETINFO_RSP,
#endif /* WLAN_FEATURE_GTK_OFFLOAD */
	eWNI_SME_CANDIDATE_FOUND_IND,   /*ROAM candidate indication from FW */
	eWNI_SME_HANDOFF_REQ,   /*upper layer requested handoff to driver in STA mode */
	eWNI_SME_ROAM_SCAN_OFFLOAD_RSP, /*Fwd the LFR scan offload rsp from FW to SME */
	eWNI_SME_IBSS_PEER_INFO_RSP,
	eWNI_SME_GET_TSM_STATS_REQ,
	eWNI_SME_GET_TSM_STATS_RSP,
	eWNI_SME_TSM_IE_IND,

	/* DFS EVENTS */
	eWNI_SME_DFS_RADAR_FOUND,       /* RADAR found indication from DFS */
	eWNI_SME_CHANNEL_CHANGE_REQ,    /* Channel Change Request from SAP */
	eWNI_SME_CHANNEL_CHANGE_RSP,    /* Channel Change Response from WMA */
	eWNI_SME_START_BEACON_REQ,      /* Start Beacon Transmission. */
	eWNI_SME_DFS_BEACON_CHAN_SW_IE_REQ,     /* Transmit CSA IE in beacons */
	eWNI_SME_DFS_CSAIE_TX_COMPLETE_IND,     /* To indicate completion of CSA IE */
	/* update in beacons/probe rsp */
	eWNI_SME_STATS_EXT_EVENT,
	eWNI_SME_GET_PEER_INFO_IND,
	eWNI_SME_GET_PEER_INFO_EXT_IND,
	eWNI_SME_CSA_OFFLOAD_EVENT,
	eWNI_SME_UPDATE_ADDITIONAL_IES, /* indicates Additional IE from hdd to PE */
	eWNI_SME_MODIFY_ADDITIONAL_IES, /* To indicate IE modify from hdd to PE */
#ifdef FEATURE_WLAN_AUTO_SHUTDOWN
	eWNI_SME_AUTO_SHUTDOWN_IND,
#endif
#ifdef QCA_HT_2040_COEX
	eWNI_SME_SET_HT_2040_MODE,
#endif
#ifdef WLAN_FEATURE_ROAM_OFFLOAD
	eWNI_SME_HO_FAIL_IND,   /* Hand Off Failure Ind from WMA to SME */
#endif
#ifdef WLAN_FEATURE_NAN
	eWNI_SME_NAN_EVENT,
#endif
	eWNI_SME_LINK_STATUS_IND,
#ifdef WLAN_FEATURE_EXTWOW_SUPPORT
	eWNI_SME_READY_TO_EXTWOW_IND,
#endif
	eWNI_SME_MSG_GET_TEMPERATURE_IND,
	eWNI_SME_SNR_IND,
#ifdef FEATURE_WLAN_EXTSCAN
	eWNI_SME_EXTSCAN_FULL_SCAN_RESULT_IND,
	eWNI_SME_EPNO_NETWORK_FOUND_IND,
#endif
	eWNI_SME_SET_HW_MODE_REQ,
	eWNI_SME_SET_HW_MODE_RESP,
	eWNI_SME_HW_MODE_TRANS_IND,
	eWNI_SME_NSS_UPDATE_REQ,
	eWNI_SME_NSS_UPDATE_RSP,
	eWNI_SME_OCB_SET_CONFIG_RSP,
	eWNI_SME_OCB_GET_TSF_TIMER_RSP,
	eWNI_SME_DCC_GET_STATS_RSP,
	eWNI_SME_DCC_UPDATE_NDL_RSP,
	eWNI_SME_DCC_STATS_EVENT,
	eWNI_SME_SET_DUAL_MAC_CFG_REQ,
	eWNI_SME_SET_DUAL_MAC_CFG_RESP,
	eWNI_SME_SET_THERMAL_LEVEL_IND,
	eWNI_SME_SET_IE_REQ,
	eWNI_SME_EXT_CHANGE_CHANNEL,
	eWNI_SME_EXT_CHANGE_CHANNEL_IND,
	eWNI_SME_REGISTER_MGMT_FRAME_CB,
	eWNI_SME_HT40_OBSS_SCAN_IND, /* START and UPDATE OBSS SCAN Indication*/
	eWNI_SME_SET_ANTENNA_MODE_REQ,
	eWNI_SME_SET_ANTENNA_MODE_RESP,
	eWNI_SME_TSF_EVENT,
	eWNI_SME_MON_INIT_SESSION,
	eWNI_SME_PDEV_SET_HT_VHT_IE,
	eWNI_SME_SET_VDEV_IES_PER_BAND,
	eWNI_SME_SEND_DISASSOC_FRAME,
	eWNI_SME_UPDATE_ACCESS_POLICY_VENDOR_IE,
	eWNI_SME_DEFAULT_SCAN_IE,
	eWNI_SME_ROAM_INVOKE,
	eWNI_SME_ROAM_SCAN_OFFLOAD_REQ,
	eWNI_SME_LOST_LINK_INFO_IND,
	eWNI_SME_DEL_ALL_TDLS_PEERS,
	eWNI_SME_RSO_CMD_STATUS_IND,
	eWMI_SME_LL_STATS_IND,
	eWNI_SME_DFS_CAC_COMPLETE,
	eWNI_SME_UPDATE_CONFIG,
	eWNI_SME_BT_ACTIVITY_INFO_IND,
	eWNI_SME_SET_HE_BSS_COLOR,
	eWNI_SME_TRIGGER_SAE,
	eWNI_SME_SEND_MGMT_FRAME_TX,
	eWNI_SME_SEND_SAE_MSG,
	eWNI_SME_SET_ADDBA_ACCEPT,
	eWNI_SME_UPDATE_EDCA_PROFILE,
	WNI_SME_UPDATE_MU_EDCA_PARAMS,
	eWNI_SME_CSA_RESTART_REQ,
	eWNI_SME_CSA_RESTART_RSP,
	WNI_SME_CFG_ACTION_FRM_HE_TB_PPDU,
	eWNI_SME_MSG_TYPES_END
};

#define WNI_CFG_MSG_TYPES_BEGIN        0x1200

/*---------------------------------------------------------------------*/
/* CFG to HDD message types                                            */
/*---------------------------------------------------------------------*/
#define WNI_CFG_DNLD_REQ               (WNI_CFG_MSG_TYPES_BEGIN | 0x01)

typedef struct sAniCfgTxRateCtrs {
/* add the rate counters here */
	unsigned long TxFrames_1Mbps;
	unsigned long TxFrames_2Mbps;
	unsigned long TxFrames_5_5Mbps;
	unsigned long TxFrames_6Mbps;
	unsigned long TxFrames_9Mbps;
	unsigned long TxFrames_11Mbps;
	unsigned long TxFrames_12Mbps;
	unsigned long TxFrames_18Mbps;
	unsigned long TxFrames_24Mbps;
	unsigned long TxFrames_36Mbps;
	unsigned long TxFrames_48Mbps;
	unsigned long TxFrames_54Mbps;
	unsigned long TxFrames_72Mbps;
	unsigned long TxFrames_96Mbps;
	unsigned long TxFrames_108Mbps;

} tAniCfgTxRateCtrs, *tpAniCfgTxRateCtrs;
#endif /* __WNI_API_H */
