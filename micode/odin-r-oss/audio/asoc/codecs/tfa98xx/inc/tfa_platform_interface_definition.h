/*
 * Copyright 2015-2018 NXP Semiconductors
 * Copyright (C) 2021 XiaoMi, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _TFA_PLATFORM_INTERFACE_DEFINITION_H_
#define _TFA_PLATFORM_INTERFACE_DEFINITION_H_

#define AFE_MODULE_ID_TFADSP_RX					(0x1000B911)
#define AFE_MODULE_ID_TFADSP_TX					(0x1000B912)
#define AFE_PARAM_ID_TFADSP_TX_SET_ENABLE		(0x1000B920)
#define AFE_PARAM_ID_TFADSP_RX_CFG 				(0x1000B921)
#define AFE_PARAM_ID_TFADSP_RX_GET_RESULT		(0x1000B922)
#define AFE_PARAM_ID_TFADSP_RX_SET_BYPASS		(0x1000B923)


#define TFA_USING_TERTIARY_MI2S

#if defined(TFA_USING_PRIMARY_TDM)
	/*Attention: port_id =	AFE_PORT_ID_SECONDARY_MI2S_RX/TX, AFE_PORT_ID_TERTIARY_MI2S_RX/TX,
							AFE_PORT_ID_QUATERNARY_MI2S_RX/TX or AFE_PORT_ID_QUINARY_MI2S_RX/TX*/
	#define AFE_PORT_ID_TFADSP_RX				(AFE_PORT_ID_PRIMARY_TDM_RX)
	#define AFE_PORT_ID_TFADSP_TX				(AFE_PORT_ID_PRIMARY_TDM_TX)

	#define PLATFORM_TDM_RX_VI_FB_RX_MUX_TEXT		"PRI_TDM_RX_0"
	#define PLATFORM_TDM_RX_VI_FB_TX_MUX_TEXT		"PRI_TDM_TX_0"
	#define PLATFORM_TDM_RX_VI_FB_MUX_NAME			"PRI_TDM_RX_VI_FB_MUX"
	#define PLATFORM_TDM_RX_VI_FB_TX_VALUE			MSM_BACKEND_DAI_PRI_TDM_TX_0
	#define PLATFORM_TDM_RX_VI_FB_MUX_ENUM			MSM_BACKEND_DAI_PRI_TDM_RX_0

	#define TFA_TX_HOSTLESS_CODEC_NAME			"PRI_TDM_TX_0_HOSTLESS"
	#define TFA_TX_HOSTLESS_STREAM_NAME			"Primary TDM0 Hostless Capture"
	#define TFA_TX_HOSTLESS_CPU_DAI_NAME		"PRI_TDM_TX_0_HOSTLESS"

#elif defined(TFA_USING_PRIMARY_MI2S)
	/*Attention: port_id =	AFE_PORT_ID_SECONDARY_MI2S_RX/TX, AFE_PORT_ID_TERTIARY_MI2S_RX/TX,
							AFE_PORT_ID_QUATERNARY_MI2S_RX/TX or AFE_PORT_ID_QUINARY_MI2S_RX/TX*/
	#define AFE_PORT_ID_TFADSP_RX				(AFE_PORT_ID_PRIMARY_MI2S_RX)
	#define AFE_PORT_ID_TFADSP_TX				(AFE_PORT_ID_PRIMARY_MI2S_TX)

	#define PLATFORM_RX_VI_FB_RX_MUX_TEXT		"PRI_MI2S_RX"
	#define PLATFORM_RX_VI_FB_TX_MUX_TEXT		"PRI_MI2S_TX"
	#define PLATFORM_RX_VI_FB_MUX_NAME			"PRI_MI2S_RX_VI_FB_MUX"
	#define PLATFORM_RX_VI_FB_TX_VALUE			MSM_BACKEND_DAI_PRI_MI2S_TX
	#define PLATFORM_RX_VI_FB_MUX_ENUM			MSM_BACKEND_DAI_PRI_MI2S_RX

	#define TFA_TX_HOSTLESS_CODEC_NAME			"Primary MI2S_TX Hostless"
	#define TFA_TX_HOSTLESS_STREAM_NAME			"Primary MI2S_TX Hostless"
	#define TFA_TX_HOSTLESS_CPU_DAI_NAME		"PRI_MI2S_TX_HOSTLESS"

#elif defined(TFA_USING_SECONDARY_MI2S)
	/*Attention: port_id = 	AFE_PORT_ID_SECONDARY_MI2S_RX/TX, AFE_PORT_ID_TERTIARY_MI2S_RX/TX,
							AFE_PORT_ID_QUATERNARY_MI2S_RX/TX or AFE_PORT_ID_QUINARY_MI2S_RX/TX*/
	#define AFE_PORT_ID_TFADSP_RX				(AFE_PORT_ID_SECONDARY_MI2S_RX)
	#define AFE_PORT_ID_TFADSP_TX				(AFE_PORT_ID_SECONDARY_MI2S_TX)

	#define PLATFORM_RX_VI_FB_RX_MUX_TEXT		"SEC_MI2S_RX"
	#define PLATFORM_RX_VI_FB_TX_MUX_TEXT		"SEC_MI2S_TX"
	#define PLATFORM_RX_VI_FB_MUX_NAME			"SECONDARY_MI2S_RX_VI_FB_MUX"
	#define PLATFORM_RX_VI_FB_TX_VALUE			MSM_BACKEND_DAI_SECONDARY_MI2S_TX
	#define PLATFORM_RX_VI_FB_MUX_ENUM			MSM_BACKEND_DAI_SECONDARY_MI2S_RX
	
	#define TFA_TX_HOSTLESS_CODEC_NAME			"Secondary MI2S_TX Hostless"
	#define TFA_TX_HOSTLESS_STREAM_NAME			"Secondary MI2S_TX Hostless"
	#define TFA_TX_HOSTLESS_CPU_DAI_NAME		"SEC_MI2S_TX_HOSTLESS"
	
#elif defined(TFA_USING_TERTIARY_MI2S)
	/*Attention: port_id = 	AFE_PORT_ID_SECONDARY_MI2S_RX/TX, AFE_PORT_ID_TERTIARY_MI2S_RX/TX,
							AFE_PORT_ID_QUATERNARY_MI2S_RX/TX or AFE_PORT_ID_QUINARY_MI2S_RX/TX*/
	#define AFE_PORT_ID_TFADSP_RX				(AFE_PORT_ID_TERTIARY_MI2S_RX)
	#define AFE_PORT_ID_TFADSP_TX				(AFE_PORT_ID_TERTIARY_MI2S_TX)

	#define PLATFORM_RX_VI_FB_RX_MUX_TEXT		"TERT_MI2S_RX"
	#define PLATFORM_RX_VI_FB_TX_MUX_TEXT		"TERT_MI2S_TX"
	#define PLATFORM_RX_VI_FB_MUX_NAME			"TERTIARY_MI2S_RX_VI_FB_MUX"
	#define PLATFORM_RX_VI_FB_TX_VALUE			MSM_BACKEND_DAI_TERTIARY_MI2S_TX
	#define PLATFORM_RX_VI_FB_MUX_ENUM			MSM_BACKEND_DAI_TERTIARY_MI2S_RX

	#define TFA_TX_HOSTLESS_CODEC_NAME			"Tertiary MI2S_TX Hostless"
	#define TFA_TX_HOSTLESS_STREAM_NAME			"Tertiary MI2S_TX Hostless"
	#define TFA_TX_HOSTLESS_CPU_DAI_NAME		"TERT_MI2S_TX_HOSTLESS"

#elif defined(TFA_USING_QUATERNARY_MI2S)
	/*Attention: port_id = 	AFE_PORT_ID_SECONDARY_MI2S_RX/TX, AFE_PORT_ID_TERTIARY_MI2S_RX/TX,
							AFE_PORT_ID_QUATERNARY_MI2S_RX/TX or AFE_PORT_ID_QUINARY_MI2S_RX/TX*/
	#define AFE_PORT_ID_TFADSP_RX				(AFE_PORT_ID_QUATERNARY_MI2S_RX)
	#define AFE_PORT_ID_TFADSP_TX				(AFE_PORT_ID_QUATERNARY_MI2S_TX)

	#define PLATFORM_RX_VI_FB_RX_MUX_TEXT		"QUAT_MI2S_RX"
	#define PLATFORM_RX_VI_FB_TX_MUX_TEXT		"QUAT_MI2S_TX"
	#define PLATFORM_RX_VI_FB_MUX_NAME			"QUATERNARY_MI2S_RX_VI_FB_MUX"
	#define PLATFORM_RX_VI_FB_TX_VALUE			MSM_BACKEND_DAI_QUATERNARY_MI2S_TX
	#define PLATFORM_RX_VI_FB_MUX_ENUM			MSM_BACKEND_DAI_QUATERNARY_MI2S_RX

	#define TFA_TX_HOSTLESS_CODEC_NAME			"Quaternary MI2S_TX Hostless"
	#define TFA_TX_HOSTLESS_STREAM_NAME			"Quaternary MI2S_TX Hostless"
	#define TFA_TX_HOSTLESS_CPU_DAI_NAME		"QUAT_MI2S_TX_HOSTLESS"

#elif defined(TFA_USING_QUINARY_MI2S)
	/*Attention: port_id = 	AFE_PORT_ID_SECONDARY_MI2S_RX/TX, AFE_PORT_ID_TERTIARY_MI2S_RX/TX,
							AFE_PORT_ID_QUATERNARY_MI2S_RX/TX or AFE_PORT_ID_QUINARY_MI2S_RX/TX*/
	#define AFE_PORT_ID_TFADSP_RX				(AFE_PORT_ID_QUINARY_MI2S_RX)
	#define AFE_PORT_ID_TFADSP_TX				(AFE_PORT_ID_QUINARY_MI2S_TX)

	#define PLATFORM_RX_VI_FB_RX_MUX_TEXT		"QUIN_MI2S_RX"
	#define PLATFORM_RX_VI_FB_TX_MUX_TEXT		"QUIN_MI2S_TX"
	#define PLATFORM_RX_VI_FB_MUX_NAME			"QUINARY_MI2S_RX_VI_FB_MUX"
	#define PLATFORM_RX_VI_FB_TX_VALUE			MSM_BACKEND_DAI_QUINARY_MI2S_TX
	#define PLATFORM_RX_VI_FB_MUX_ENUM			MSM_BACKEND_DAI_QUINARY_MI2S_RX

	#define TFA_TX_HOSTLESS_CODEC_NAME			"Quinary MI2S_TX Hostless"
	#define TFA_TX_HOSTLESS_STREAM_NAME			"Quinary MI2S_TX Hostless"
	#define TFA_TX_HOSTLESS_CPU_DAI_NAME		"QUIN_MI2S_TX_HOSTLESS"

#else
	#error you should define which mi2s will be used for TFA device.
#endif

#endif /* _TFA_PLATFORM_INTERFACE_DEFINITION_H_ */
