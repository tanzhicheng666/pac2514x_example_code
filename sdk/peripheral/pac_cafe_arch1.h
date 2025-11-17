/**
 * @file pac_cafe_arch1.h
 * @brief 
 */

//=============================================================================
// Copyright (C) 2021-2022, Qorvo, Inc.
//
// THIS SOFTWARE IS SUBJECT TO A SOURCE CODE LICENSE AGREEMENT WHICH PROVIDES,
// AMONG OTHER THINGS:  (i) THAT IT CAN BE USED ONLY TO ADAPT THE LICENSEE'S
// APPLICATION TO PAC PROCESSORS SUPPLIED BY QORVO, INC.;
// (ii) THAT  IT IS PROVIDED "AS IS" WITHOUT WARRANTY;  (iii) THAT
// QORVO, INC. IS NOT LIABLE FOR ANY INDIRECT DAMAGES OR FOR DIRECT
// DAMAGES EXCEEDING US$1,500;  AND (iv) THAT IT CAN BE DISCLOSED TO AND USED
// ONLY BY CERTAIN AUTHORIZED PERSONS.
//
//=============================================================================

#ifndef PAC_CAFE_ARCH_1_H
#define PAC_CAFE_ARCH_1_H


//====================================
// CELL
//====================================
#define MAX_NUM_CELLS                               20

//====================================
// KEYS
//====================================
#define FUSE_KEY                                    0x66
#define PROT_KEY                                    0xA5

//====================================
// AFEMUX
//====================================
#define AFEMUX_BAT_DIV                              50
#define AFEMUX_LOADDET_DIV                          1
#define AFEMUX_PACK_DIV                             50

//====================================
// AFE
//====================================
#define AFE_ENABLE                                  1
#define AFE_RESET                                   1
#define AFE_W1C                                     1

//====================================
// Voltage ADC
//====================================
#define VADC_START                                  1
#define VADC_BITS                                   16
#define VADC_VREF                                   2.5f
#define VADC_MAX_COUNT                              ((1 << VADC_BITS) - 1)
#define VADC_VOLTS_PER_COUNT                        (VADC_VREF / VADC_MAX_COUNT)
#define VADC_DIV                                    2

//====================================
// Current ADC
//====================================
#define IADC_START                                  1
#define IADC_BITS                                   16
#define IADC_VREF                                   0.5f
#define IADC_MAX_COUNT                              ((1 << IADC_BITS) - 1)
#define IADC_VOLTS_PER_COUNT                        (IADC_VREF / IADC_MAX_COUNT)
#define IADC_DIV                                    2

//====================================
// SCP DAC
//====================================
#define SCPDAC_BITS                                 8
#define SCPDAC_VREF                                 0.5f
#define SCPDAC_MAX_COUNT                            ((1 << SCPDAC_BITS) - 1)
#define SCPDAC_VOLTS_PER_COUNT                      (SCPDAC_VREF / SCPDAC_MAX_COUNT)

//====================================
// OCD DAC
//====================================
#define OCDDAC_BITS                                 8
#define OCDDAC_VREF                                 0.5f
#define OCDDAC_MAX_COUNT                            ((1 << OCDDAC_BITS) - 1)
#define OCDDAC_VOLTS_PER_COUNT                      (OCDDAC_VREF / OCDDAC_MAX_COUNT)

//====================================
// OCC DAC
//====================================
#define OCCDAC_BITS                                 8
#define OCCDAC_VREF                                 0.5f
#define OCCDAC_MAX_COUNT                            ((1 << OCDDAC_BITS) - 1)
#define OCCDAC_VOLTS_PER_COUNT                      (OCCDAC_VREF / OCCDAC_MAX_COUNT)

//====================================
// BATOV DAC
//====================================
#define BATOVDAC_BITS                               8
#define BATOVDAC_VREF                               2.5f
#define BATOVDAC_VBAT_MAX                           125.0f
#define BATOVDAC_MAX_COUNT                          ((1 << BATOVDAC_BITS) - 1)
#define BATOVDAC_COUNTS_PER_VOLT                    (BATOVDAC_MAX_COUNT / BATOVDAC_VBAT_MAX)
//====================================
// Watchdog
//====================================
#define WWDT_ENABLE                                 1
#define WWDT_ALLOW_WRITE_REGS_KEY                   0x14
#define WWDT_RESET_KEY                              0xAC

/** HVBK Switching Frequency Enumeration Type */
typedef enum
{
    AFECTL2_HVBUCK_FREQ_50KHZ = 0,
    AFECTL2_HVBUCK_FREQ_100KHZ = 1,
    AFECTL2_HVBUCK_FREQ_200KHZ = 2,
    AFECTL2_HVBUCK_FREQ_400KHZ = 3
} AFECTL2_HVBUCK_FREQSEL_Type;

/** Driver Mode Enumeration Type */
typedef enum
{
    DRVCTL_DRVMODE_DISABLED = 0,
    DRVCTL_DRVMODE_ENABLED = 1,
    DRVCTL_DRVMODE_SOURCE_FOLLOWER = 2,
    DRVCTL_DRVMODE_RESERVED = 3
} DRVCTL_DRVMODE_Type;

/** AFEMUX Selection Enumeration Type */
typedef enum
{
    AFEMUXSEL_AFEMUX_VCORE = 0,
    AFEMUXSEL_AFEMUX_VCORE_DIV2P5 = 1,
    AFEMUXSEL_AFEMUX_VDDA_DIV2P5 = 2,
    AFEMUXSEL_AFEMUX_VCCIO_DIV2P5 = 3,
    AFEMUXSEL_AFEMUX_VSYS_DIV2P5 = 4,
    AFEMUXSEL_AFEMUX_ISENSE = 5,
    AFEMUXSEL_AFEMUX_VPTAT = 6,
    AFEMUXSEL_AFEMUX_VP_DIV10 = 7,
    AFEMUXSEL_AFEMUX_VREF_DIV2 = 8,
    AFEMUXSEL_AFEMUX_FUSE_DIV10 = 9,
    AFEMUXSEL_AFEMUX_CHG_DIV50 = 10,
    AFEMUXSEL_AFEMUX_DSG_DIV50 = 11,
    AFEMUXSEL_AFEMUX_BAT_DIV50 = 12,
    AFEMUXSEL_AFEMUX_AIO0A = 13,
    AFEMUXSEL_AFEMUX_LOADDET = 14,
    AFEMUXSEL_AFEMUX_SCPDAC = 15,
    AFEMUXSEL_AFEMUX_OCCDAC = 16,
    AFEMUXSEL_AFEMUX_OCDDAC = 17,
    AFEMUXSEL_AFEMUX_BATOVDAC_DIV2 = 18,
    AFEMUXSEL_AFEMUX_VIN_DIV50 = 19,
    AFEMUXSEL_AFEMUX_PACK_DIV50 = 20,
    AFEMUXSEL_AFEMUX_VCP_DIV50 = 21
} AFEMUXSEL_AFEMUX_Type;

/** PACK Wakeup Vref Enumeration Type */
typedef enum
{
    HIBCTL_PACKWAKEVREF_5V = 0,
    HIBCTL_PACKWAKEVREF_20V = 1
} HIBCTL_PACKWAKEVREF_VOLSEL_Type;

/** Wakeup Source Enumeration Type */
typedef enum
{
    HIBCTL_WAKESRC_PB = 0,
    HIBCTL_WAKESRC_PACK = 1,
    HIBCTL_WAKESRC_WUTIMER = 2,
    HIBCTL_WAKESRC_RFU = 3
} HIBCTL_WAKESRC_Type;

/** Wakeup Timer Period Enumeration Type */
typedef enum
{
    HIBCTL_WAKETIMER_DISABLED = 0,
    HIBCTL_WAKETIMER_125MS = 1,
    HIBCTL_WAKETIMER_250MS = 2,
    HIBCTL_WAKETIMER_500MS = 3,
    HIBCTL_WAKETIMER_1000MS = 4,
    HIBCTL_WAKETIMER_2000MS = 5,
    HIBCTL_WAKETIMER_4000MS = 6,
    HIBCTL_WAKETIMER_8000MS = 7
} HIBCTL_WAKETIMER_Type;

/** Push Button Deglitch Time Enumeration Type */
typedef enum
{
    PB_DEGLITCH_TIME_1MS = 0,
    PB_DEGLITCH_TIME_4MS = 1,
    PB_DEGLITCH_TIME_8MS = 2,
    PB_DEGLITCH_TIME_32MS = 3,
} PB_DEGLITCH_TIMESEL_Type;

/** Push Button Polarity Enumeration Type */
typedef enum
{
    PB_POLARITY_ACTIVE_LOW = 0,
    PB_POLARITY_ACTIVE_HIGH = 1
} PB_POLARITY_Type;

/** AIO0 Mode Enumeration Type */
typedef enum
{
    AIO0CFG_MODE_INPUT = 0,
    AIO0CFG_MODE_OUTPUT = 1
} AIO0CFG_MODE_Type;

/** AIO Mux Selection Enumeration Type */
typedef enum
{
    AIO0CFG_MUX_VREF = 0,
    AIO0CFG_MUX_AFEMUXOUT = 1,
    AIO0CFG_MUX_IMUXOUT = 2,
    AIO0CFG_MUX_VBMUXOUT = 3
} AIO0CFG_MUX_Type;

/** BATOV Blanking Time Base Enumeration Type */
typedef enum
{
    BATOVCFG_TIMEBASE_32US = 0,
    BATOVCFG_TIMEBASE_64US = 1,
    BATOVCFG_TIMEBASE_128US = 2,
    BATOVCFG_TIMEBASE_256US = 3,
    BATOVCFG_TIMEBASE_512US = 4,
    BATOVCFG_TIMEBASE_1024US = 5,
    BATOVCFG_TIMEBASE_2048US = 6,
    BATOVCFG_TIMEBASE_4096US = 7,
    BATOVCFG_TIMEBASE_8192US = 8,
    BATOVCFG_TIMEBASE_16384US = 9,
    BATOVCFG_TIMEBASE_32768US = 10,
    BATOVCFG_TIMEBASE_65536US = 11,
    BATOVCFG_TIMEBASE_131072US = 12,
    BATOVCFG_TIMEBASE_262144US = 13,
    BATOVCFG_TIMEBASE_524288US = 14,
    BATOVCFG_TIMEBASE_1048576US = 15
} BATOVCFG_TIMEBASE_Type;

/** BATOV Blanking Scale Factor Enumeration Type */
typedef enum
{
    BATOVCFG_BLANKSF_1 = 0,
    BATOVCFG_BLANKSF_2 = 1,
    BATOVCFG_BLANKSF_3 = 2,
    BATOVCFG_BLANKSF_4 = 3,
    BATOVCFG_BLANKSF_5 = 4,
    BATOVCFG_BLANKSF_6 = 5,
    BATOVCFG_BLANKSF_7 = 6,
    BATOVCFG_BLANKSF_8 = 7,
    BATOVCFG_BLANKSF_9 = 8,
    BATOVCFG_BLANKSF_10 = 9,
    BATOVCFG_BLANKSF_11 = 10,
    BATOVCFG_BLANKSF_12 = 11,
    BATOVCFG_BLANKSF_13 = 12,
    BATOVCFG_BLANKSF_14 = 13,
    BATOVCFG_BLANKSF_15 = 14,
    BATOVCFG_BLANKSF_16 = 15
} BATOVCFG_BLANKSF_Type;

/** VADC VBMux Selection Enumeration Type */
typedef enum
{
    VADCCTL_VBMUX_VB1 = 0,
    VADCCTL_VBMUX_VB2 = 1,
    VADCCTL_VBMUX_VB3 = 2,
    VADCCTL_VBMUX_VB4 = 3,
    VADCCTL_VBMUX_VB5 = 4,
    VADCCTL_VBMUX_VB6 = 5,
    VADCCTL_VBMUX_VB7 = 6,
    VADCCTL_VBMUX_VB8 = 7,
    VADCCTL_VBMUX_VB9 = 8,
    VADCCTL_VBMUX_VB10 = 9,
    VADCCTL_VBMUX_VB11 = 10,
    VADCCTL_VBMUX_VB12 = 11,
    VADCCTL_VBMUX_VB13 = 12,
    VADCCTL_VBMUX_VB14 = 13,
    VADCCTL_VBMUX_VB15 = 14,
    VADCCTL_VBMUX_VB16 = 15,
    VADCCTL_VBMUX_VB17 = 16,
    VADCCTL_VBMUX_VB18 = 17,
    VADCCTL_VBMUX_VB19 = 18,
    VADCCTL_VBMUX_VB20 = 19,
    VADCCTL_VBMUX_BATOVDACDIV2 = 20
} VADCCTL_VBMUX_Type;

/** IADC DA Gain Enumeration Type */
typedef enum
{
    IADCCTL_DAGAIN_1 = 0,
    IADCCTL_DAGAIN_2 = 1,
    IADCCTL_DAGAIN_4 = 2,
    IADCCTL_DAGAIN_8 = 3,
    IADCCTL_DAGAIN_16 = 4,
    IADCCTL_DAGAIN_32 = 5,
    IADCCTL_DAGAIN_64 = 6,
    IADCCTL_DAGAIN_128 = 7
} IADCCTL_DAGAIN_Type;

/** IADC IMux Selection Enumeration Type */
typedef enum
{
    IADCCTL_IMUX_ISNSDA = 0,
    IADCCTL_IMUX_SCPDAC = 1,
    IADCCTL_IMUX_OCCDAC = 2,
    IADCCTL_IMUX_OCDDAC = 3
} IADCCTL_IMUX_Type;

/** SCP Blanking Time Base Enumeration Type */
typedef enum
{
    SCPCFG_TIMEBASE_1US = 0,
    SCPCFG_TIMEBASE_2US = 1,
    SCPCFG_TIMEBASE_4US = 2,
    SCPCFG_TIMEBASE_8US = 3,
    SCPCFG_TIMEBASE_16US = 4,
    SCPCFG_TIMEBASE_32US = 5,
    SCPCFG_TIMEBASE_64US = 6,
    SCPCFG_TIMEBASE_128US = 7,
    SCPCFG_TIMEBASE_256US = 8,
    SCPCFG_TIMEBASE_512US = 9,
    SCPCFG_TIMEBASE_1024US = 10,
    SCPCFG_TIMEBASE_2048US = 11,
    SCPCFG_TIMEBASE_4096US = 12,
    SCPCFG_TIMEBASE_8192US = 13,
    SCPCFG_TIMEBASE_16384US = 14,
    SCPCFG_TIMEBASE_32768US = 15
} SCPCFG_TIMEBASE_Type;

/** SCP Blanking Scale Factor Enumeration Type */
typedef enum
{
    SCPCFG_BLANKSF_1 = 0,
    SCPCFG_BLANKSF_2 = 1,
    SCPCFG_BLANKSF_3 = 2,
    SCPCFG_BLANKSF_4 = 3,
    SCPCFG_BLANKSF_5 = 4,
    SCPCFG_BLANKSF_6 = 5,
    SCPCFG_BLANKSF_7 = 6,
    SCPCFG_BLANKSF_8 = 7,
    SCPCFG_BLANKSF_9 = 8,
    SCPCFG_BLANKSF_10 = 9,
    SCPCFG_BLANKSF_11 = 10,
    SCPCFG_BLANKSF_12 = 11,
    SCPCFG_BLANKSF_13 = 12,
    SCPCFG_BLANKSF_14 = 13,
    SCPCFG_BLANKSF_15 = 14,
    SCPCFG_BLANKSF_16 = 15
} SCPCFG_BLANKSF_Type;

/** OCC Blanking Time Base Enumeration Type */
typedef enum
{
    OCCCFG_TIMEBASE_1US = 0,
    OCCCFG_TIMEBASE_2US = 1,
    OCCCFG_TIMEBASE_4US = 2,
    OCCCFG_TIMEBASE_8US = 3,
    OCCCFG_TIMEBASE_16US = 4,
    OCCCFG_TIMEBASE_32US = 5,
    OCCCFG_TIMEBASE_64US = 6,
    OCCCFG_TIMEBASE_128US = 7,
    OCCCFG_TIMEBASE_256US = 8,
    OCCCFG_TIMEBASE_512US = 9,
    OCCCFG_TIMEBASE_1024US = 10,
    OCCCFG_TIMEBASE_2048US = 11,
    OCCCFG_TIMEBASE_4096US = 12,
    OCCCFG_TIMEBASE_8192US = 13,
    OCCCFG_TIMEBASE_16384US = 14,
    OCCCFG_TIMEBASE_32768US = 15
} OCCCFG_TIMEBASE_Type;

/** OCC Blanking Scale Factor Enumeration Type */
typedef enum
{
    OCCCFG_BLANKSF_1 = 0,
    OCCCFG_BLANKSF_2 = 1,
    OCCCFG_BLANKSF_3 = 2,
    OCCCFG_BLANKSF_4 = 3,
    OCCCFG_BLANKSF_5 = 4,
    OCCCFG_BLANKSF_6 = 5,
    OCCCFG_BLANKSF_7 = 6,
    OCCCFG_BLANKSF_8 = 7,
    OCCCFG_BLANKSF_9 = 8,
    OCCCFG_BLANKSF_10 = 9,
    OCCCFG_BLANKSF_11 = 10,
    OCCCFG_BLANKSF_12 = 11,
    OCCCFG_BLANKSF_13 = 12,
    OCCCFG_BLANKSF_14 = 13,
    OCCCFG_BLANKSF_15 = 14,
    OCCCFG_BLANKSF_16 = 15
} OCCCFG_BLANKSF_Type;

/** OCD Blanking Time Base Enumeration Type */
typedef enum
{
    OCDCFG_TIMEBASE_1US = 0,
    OCDCFG_TIMEBASE_2US = 1,
    OCDCFG_TIMEBASE_4US = 2,
    OCDCFG_TIMEBASE_8US = 3,
    OCDCFG_TIMEBASE_16US = 4,
    OCDCFG_TIMEBASE_32US = 5,
    OCDCFG_TIMEBASE_64US = 6,
    OCDCFG_TIMEBASE_128US = 7,
    OCDCFG_TIMEBASE_256US = 8,
    OCDCFG_TIMEBASE_512US = 9,
    OCDCFG_TIMEBASE_1024US = 10,
    OCDCFG_TIMEBASE_2048US = 11,
    OCDCFG_TIMEBASE_4096US = 12,
    OCDCFG_TIMEBASE_8192US = 13,
    OCDCFG_TIMEBASE_16384US = 14,
    OCDCFG_TIMEBASE_32768US = 15
} OCDCFG_TIMEBASE_Type;

/** OCD Blanking Scale Factor Enumeration Type */
typedef enum
{
    OCDCFG_BLANKSF_1 = 0,
    OCDCFG_BLANKSF_2 = 1,
    OCDCFG_BLANKSF_3 = 2,
    OCDCFG_BLANKSF_4 = 3,
    OCDCFG_BLANKSF_5 = 4,
    OCDCFG_BLANKSF_6 = 5,
    OCDCFG_BLANKSF_7 = 6,
    OCDCFG_BLANKSF_8 = 7,
    OCDCFG_BLANKSF_9 = 8,
    OCDCFG_BLANKSF_10 = 9,
    OCDCFG_BLANKSF_11 = 10,
    OCDCFG_BLANKSF_12 = 11,
    OCDCFG_BLANKSF_13 = 12,
    OCDCFG_BLANKSF_14 = 13,
    OCDCFG_BLANKSF_15 = 14,
    OCDCFG_BLANKSF_16 = 15
} OCDCFG_BLANKSF_Type;

/** CLKOUT Frequency Enumeration Type */
typedef enum
{
    CLKOUTCFG_FREQ_250HZ = 0,
    CLKOUTCFG_FREQ_500HZ = 1,
    CLKOUTCFG_FREQ_1000HZ = 2,
    CLKOUTCFG_FREQ_2000HZ = 3
} CLKOUTCFG_FREQSEL_Type;

/** Watchdog Clock Divider Enumeration Type */
typedef enum
{
    WWDTCTL_CLKDIV_DIV2 = 0,
    WWDTCTL_CLKDIV_DIV16 = 1,
    WWDTCTL_CLKDIV_DIV128 = 2,
    WWDTCTL_CLKDIV_DIV1024 = 3
} WWDTCTL_CLKDIV_Type;


/** AFE Register Addresses */
typedef enum 
{
    ADDR_AFECTL1 = 0x00,
    ADDR_AFECTL2 = 0x01,
    ADDR_DRVCTL = 0x02,
    ADDR_AFEMUXCTL = 0x03,
    ADDR_AFEMUXSEL = 0x04,
    ADDR_HIBCTL = 0x05,
    ADDR_HIBENTER = 0x06,
    ADDR_RSTSTAT = 0x07,
    ADDR_PB = 0x08,
    ADDR_AIO0CFG = 0x09,

    ADDR_PROT_KEY = 0x10,
    ADDR_SIGMGRCTL1 = 0x11,
    ADDR_SIGMGRCTL2 = 0x12,
    ADDR_PROTEN = 0x13,
    ADDR_FUSE = 0x14,
    ADDR_PWRFAULTEN = 0x15,
    ADDR_PWRFAULT = 0x16,
    ADDR_TEMPFAULTEN = 0x17,
    ADDR_TEMPFAULT = 0x18,
    ADDR_SIGFAULTEN = 0x19,
    ADDR_SIGFAULT = 0x1A,
    ADDR_BATRTS = 0x1B,

    ADDR_BATOVCFG = 0x20,
    ADDR_BATOVDAC = 0x21,
    ADDR_VADCCTL = 0x22,
    ADDR_VADCRESHI = 0x23,
    ADDR_VADCRESLO = 0x24,
    ADDR_IADCCTL = 0x25,
    ADDR_IADCRESHI = 0x26,
    ADDR_IADCRESLO = 0x27,
    ADDR_SCPDAC = 0x28,
    ADDR_SCPCFG = 0x29,
    ADDR_OCDDAC = 0x2A,
    ADDR_OCCCFG = 0x2B,
    ADDR_OCCDAC = 0x2C,
    ADDR_OCDCFG = 0x2D,

    ADDR_CELLEN1 = 0x030,
    ADDR_CELLEN2 = 0x031,
    ADDR_CELLEN3 = 0x032,
    ADDR_CFGCB1 = 0x033,
    ADDR_CFGCB2 = 0x034,
    ADDR_CFGCB3 = 0x035,

    ADDR_GP = 0x40,
    ADDR_CLKOUTCFG = 0x41,
    ADDR_WWDTCTL = 0x42,
    ADDR_WWDTCTR = 0x43,
    ADDR_WWDTCDV = 0x44,
    ADDR_WWDTWIN = 0x45,
    ADDR_WWDTRST = 0x46
} AFE_REG_ADDR;


/* --------------------------------  AFECTL1  -------------------------------- */
#define AFECTL1_SIGEN_Pos                           0                                                   /*!< AFECTL1 SIGEN: SIGEN Position              */
#define AFECTL1_SIGEN_Msk                           (0x01UL << AFECTL1_SIGEN_Pos)                       /*!< AFECTL1 SIGEN: SIGEN Mask                  */
#define AFECTL1_HVCPEN_Pos                          1                                                   /*!< AFECTL1 HVCPEN: HVCPEN Position            */
#define AFECTL1_HVCPEN_Msk                          (0x01UL << AFECTL1_HVCPEN_Pos)                      /*!< AFECTL1 HVCPEN: HVCPEN Mask                */
#define AFECTL1_LOADDETEN_Pos                       2                                                   /*!< AFECTL1 LOADDETEN: LOADDETEN Position      */
#define AFECTL1_LOADDETEN_Msk                       (0x01UL << AFECTL1_LOADDETEN_Pos)                   /*!< AFECTL1 LOADDETEN: LOADDETEN Mask          */
#define AFECTL1_SCPDAC2VADC_Pos                     3                                                   /*!< AFECTL1 SCPDAC2VADC: SCPDAC2VADC Position  */
#define AFECTL1_SCPDAC2VADC_Msk                     (0x01UL << AFECTL1_SCPDAC2VADC_Pos)                 /*!< AFECTR1 SCPDAC2VADC: SCPDAC2VADC Mask      */    
#define AFECTL1_Dis_CPOK_QUAL_Pos                   4                                                   /*!< AFECTR1 Dis_CPOK_QUAL: Dis_CPOK_QUAL Pos   */
#define AFECTL1_Dis_CPOK_QUAL_Msk                   (0x01UL << AFECTL1_Dis_CPOK_QUAL_Pos)               /*!< AFECTR1 Dis_CPOK_QUAL: Dis_CPOK_QUAL Msk   */ 
#define AFECTL1_MCUALIVE_Pos                        6                                                   /*!< AFECTL1 MCUALIVE: MCUALIVE Position        */
#define AFECTL1_MCUALIVE_Msk                        (0x01UL << AFECTL1_MCUALIVE_Pos)                    /*!< AFECTL1 MCUALIVE: MCUALIVE Mask            */
#define AFECTL1_SRST_Pos                            7                                                   /*!< AFECTL1 SRST: SRST Position                */
#define AFECTL1_SRST_Msk                            (0x01UL << AFECTL1_SRST_Pos)                        /*!< AFECTL1 SRST: SRST Mask                    */

/* --------------------------------  AFECTL2  -------------------------------- */
#define AFECTL2_VP_PD_DIS_Pos                       0
#define AFECTL2_VP_PD_DIS_Msk                       (0x01UL << AFECTL2_VP_PD_DIS_Pos)
#define AFECTL2_BK_FREQ_Pos                         1
#define AFECTL2_BK_FREQ_Msk                         (0x03UL << AFECTL2_BK_FREQ_Pos)

/* --------------------------------  DRVCTL  -------------------------------- */
#define DRVCTL_DRVMODE_Pos                          0
#define DRVCTL_DRVMODE_Msk                          (0x03UL << DRVCTL_DRVMODE_Pos)

/* --------------------------------  AFEMUXCTL  -------------------------------- */
#define AFEMUXCTL_EMUXEN_Pos                        0
#define AFEMUXCTL_EMUXEN_Msk                        (0x01UL << AFEMUXCTL_EMUXEN_Pos)
#define AFEMUXCTL_BUFFEN_Pos                        1
#define AFEMUXCTL_BUFFEN_Msk                        (0x01UL << AFEMUXCTL_BUFFEN_Pos)

/* --------------------------------  HIBCTL  -------------------------------- */
#define HIBCTL_PBWAKEEN_Pos                         0
#define HIBCTL_PBWAKEEN_Msk                         (0x01UL << HIBCTL_PBWAKEEN_Pos)
#define HIBCTL_PACKWAKEEN_Pos                       1
#define HIBCTL_PACKWAKEEN_Msk                       (0x01UL << HIBCTL_PACKWAKEEN_Pos)
#define HIBCTL_PACKWAKEVREF_Pos                     2
#define HIBCTL_PACKWAKEVREF_Msk                     (0x01UL << HIBCTL_PACKWAKEVREF_Pos)
#define HIBCTL_WAKESRC_Pos                          3
#define HIBCTL_WAKESRC_Msk                          (0x03UL << HIBCTL_WAKESRC_Pos)
#define HIBCTL_WUTIMER_Pos                          5
#define HIBCTL_WUTIMER_Msk                          (0x07UL << HIBCTL_WUTIMER_Pos)

/* --------------------------------  HIBENTER  -------------------------------- */
#define HIBENTER_HIB_Pos                            0
#define HIBENTER_HIB_Msk                            (0x01UL << HIBENTER_HIB_Pos)

/* --------------------------------  RSTSTAT  -------------------------------- */
#define RSTSTAT_FLTRST_Pos                          0
#define RSTSTAT_FLTRST_Msk                          (0x01UL << RSTSTAT_FLTRST_Pos)
#define RSTSTAT_SOFTRST_Pos                         1
#define RSTSTAT_SOFTRST_Msk                         (0x01UL << RSTSTAT_SOFTRST_Pos)
#define RSTSTAT_WDTRST_Pos                          2
#define RSTSTAT_WDTRST_Msk                          (0x01UL << RSTSTAT_WDTRST_Pos)
#define RSTSTAT_HIBRST_Pos                          3
#define RSTSTAT_HIBRST_Msk                          (0x01UL << RSTSTAT_HIBRST_Pos)
#define RSTSTAT_PBRST_Pos                           4
#define RSTSTAT_PBRST_Msk                           (0x01UL << RSTSTAT_PBRST_Pos)

/* --------------------------------  PB  -------------------------------- */
#define PB_PBEN_Pos                                 0
#define PB_PBEN_Msk                                 (0x01UL << PB_PBEN_Pos)
#define PB_PBRSTEN_Pos                              1
#define PB_PBRSTEN_Msk                              (0x01UL << PB_PBRSTEN_Pos)
#define PB_PBDT_Pos                                 2
#define PB_PBDT_Msk                                 (0x03UL << PB_PBDT_Pos)
#define PB_PBPOL_Pos                                4
#define PB_PBPOL_Msk                                (0x01UL << PB_PBPOL_Pos)
#define PB_PBINTEN_Pos                              5
#define PB_PBINTEN_Msk                              (0x01UL << PB_PBINTEN_Pos)
#define PB_PBINTF_Pos                               6
#define PB_PBINTF_Msk                               (0x01UL << PB_PBINTF_Pos)
#define PB_PBSTAT_RTS_Pos                           7
#define PB_PBSTAT_RTS_Msk                           (0x01UL << PB_PBSTAT_RTS_Pos)

/* --------------------------------  AIO0CFG  -------------------------------- */
#define AIO0CFG_AIO0EN_Pos                          0
#define AIO0CFG_AIO0EN_Msk                          (0x01UL << AIO0CFG_AIO0EN_Pos)
#define AIO0CFG_MODE_Pos                            1
#define AIO0CFG_MODE_Msk                            (0x01UL << AIO0CFG_MODE_Pos)
#define AIO0CFG_SWAP_Pos                            2
#define AIO0CFG_SWAP_Msk                            (0x01UL << AIO0CFG_SWAP_Pos)
#define AIO0CFG_MUXSEL_Pos                          4
#define AIO0CFG_MUXSEL_Msk                          (0x0FUL << AIO0CFG_MUXSEL_Pos)

/* --------------------------------  SIGMGRCTL1  -------------------------------- */
#define SIGMGRCTL1_BATOVEN_Pos                      0
#define SIGMGRCTL1_BATOVEN_Msk                      (0x01UL << SIGMGRCTL1_BATOVEN_Pos)
#define SIGMGRCTL1_OCDEN_Pos                        1
#define SIGMGRCTL1_OCDEN_Msk                        (0x01UL << SIGMGRCTL1_OCDEN_Pos)
#define SIGMGRCTL1_OCCEN_Pos                        2
#define SIGMGRCTL1_OCCEN_Msk                        (0x01UL << SIGMGRCTL1_OCCEN_Pos)
#define SIGMGRCTL1_SCPEN_Pos                        3
#define SIGMGRCTL1_SCPEN_Msk                        (0x01UL << SIGMGRCTL1_SCPEN_Pos)
#define SIGMGRCTL1_DAEN_Pos                         4
#define SIGMGRCTL1_DAEN_Msk                         (0x01UL << SIGMGRCTL1_DAEN_Pos)

/* --------------------------------  SIGMGRCTL2  -------------------------------- */
#define SIGMGRCTL2_VADCEN_Pos                       0
#define SIGMGRCTL2_VADCEN_Msk                       (0x01UL << SIGMGRCTL2_VADCEN_Pos)
#define SIGMGRCTL2_IADCEN_Pos                       1
#define SIGMGRCTL2_IADCEN_Msk                       (0x01UL << SIGMGRCTL2_IADCEN_Pos)
#define SIGMGRCTL2_PBPTEN_Pos                       2
#define SIGMGRCTL2_PBPTEN_Msk                       (0x01UL << SIGMGRCTL2_PBPTEN_Pos)

/* --------------------------------  PROTEN  -------------------------------- */
#define PROTEN_BATOVDPROTEN_Pos                     0
#define PROTEN_BATOVDPROTEN_Msk                     (0x01UL << PROTEN_BATOVDPROTEN_Pos)
#define PROTEN_BATOVCPROTEN_Pos                     1
#define PROTEN_BATOVCPROTEN_Msk                     (0x01UL << PROTEN_BATOVCPROTEN_Pos)
#define PROTEN_OCDPROTEN_Pos                        2
#define PROTEN_OCDPROTEN_Msk                        (0x01UL << PROTEN_OCDPROTEN_Pos)
#define PROTEN_OCCPROTEN_Pos                        3
#define PROTEN_OCCPROTEN_Msk                        (0x01UL << PROTEN_OCCPROTEN_Pos)
#define PROTEN_SCPDPROTEN_Pos                       4
#define PROTEN_SCPDPROTEN_Msk                       (0x01UL << PROTEN_SCPDPROTEN_Pos)
#define PROTEN_SCPCPROTEN_Pos                       5
#define PROTEN_SCPCPROTEN_Msk                       (0x01UL << PROTEN_SCPCPROTEN_Pos)

/* --------------------------------  PWRFAULTEN  -------------------------------- */
#define PWRFAULTEN_HVCPFLTEN_Pos                    0
#define PWRFAULTEN_HVCPFLTEN_Msk                    (0x01UL << PWRFAULTEN_HVCPFLTEN_Pos)
#define PWRFAULTEN_VPFLTEN_Pos                      1
#define PWRFAULTEN_VPFLTEN_Msk                      (0x01UL << PWRFAULTEN_VPFLTEN_Pos)
#define PWRFAULTEN_VSYSFLTEN_Pos                    2
#define PWRFAULTEN_VSYSFLTEN_Msk                    (0x01UL << PWRFAULTEN_VSYSFLTEN_Pos)
#define PWRFAULTEN_VCOREFLTEN_Pos                   3
#define PWRFAULTEN_VCOREFLTEN_Msk                   (0x01UL << PWRFAULTEN_VCOREFLTEN_Pos)
#define PWRFAULTEN_VDDAFLTEN_Pos                    4
#define PWRFAULTEN_VDDAFLTEN_Msk                    (0x01UL << PWRFAULTEN_VDDAFLTEN_Pos)
#define PWRFAULTEN_VCCIOFLTEN_Pos                   5
#define PWRFAULTEN_VCCIOFLTEN_Msk                   (0x01UL << PWRFAULTEN_VCCIOFLTEN_Pos)
#define PWRFAULTEN_DRVFLTEN_Pos                     6
#define PWRFAULTEN_DRVFLTEN_Msk                     (0x01UL << PWRFAULTEN_DRVFLTEN_Pos)

/* --------------------------------  PWRFAULT  -------------------------------- */
#define PWRFAULT_HVCPFLT_Pos                        0
#define PWRFAULT_HVCPFLT_Msk                        (0x01UL << PWRFAULT_HVCPFLT_Pos)
#define PWRFAULT_VPFLT_Pos                          1
#define PWRFAULT_VPFLT_Msk                          (0x01UL << PWRFAULT_VPFLT_Pos)
#define PWRFAULT_VSYSFLT_Pos                        2
#define PWRFAULT_VSYSFLT_Msk                        (0x01UL << PWRFAULT_VSYSFLT_Pos)
#define PWRFAULT_VCOREFLT_Pos                       3
#define PWRFAULT_VCOREFLT_Msk                       (0x01UL << PWRFAULT_VCOREFLT_Pos)
#define PWRFAULT_VDDAFLT_Pos                        4
#define PWRFAULT_VDDAFLT_Msk                        (0x01UL << PWRFAULT_VDDAFLT_Pos)
#define PWRFAULT_VCCIOFLT_Pos                       5
#define PWRFAULT_VCCIOFLT_Msk                       (0x01UL << PWRFAULT_VCCIOFLT_Pos)
#define PWRFAULT_DRVFLT_Pos                         6
#define PWRFAULT_DRVFLT_Msk                         (0x01UL << PWRFAULT_DRVFLT_Pos)

/* --------------------------------  TEMPFAULTEN  -------------------------------- */
#define TEMPFAULTEN_TWARN1EN_Pos                    0
#define TEMPFAULTEN_TWARN1EN_Msk                    (0x01UL << TEMPFAULTEN_TWARN1EN_Pos)
#define TEMPFAULTEN_TWARN2EN_Pos                    1
#define TEMPFAULTEN_TWARN2EN_Msk                    (0x01UL << TEMPFAULTEN_TWARN2EN_Pos)
#define TEMPFAULTEN_TMPFLTEN_Pos                    2
#define TEMPFAULTEN_TMPFLTEN_Msk                    (0x01UL << TEMPFAULTEN_TMPFLTEN_Pos)
#define TEMPFAULTEN_TWARN1CBDEN_Pos                 4
#define TEMPFAULTEN_TWARN1CBDEN_Msk                 (0x01UL << TEMPFAULTEN_TWARN1CBDEN_Pos)
#define TEMPFAULTEN_TWARN2CBDEN_Pos                 5
#define TEMPFAULTEN_TWARN2CBDEN_Msk                 (0x01UL << TEMPFAULTEN_TWARN2CBDEN_Pos)

/* --------------------------------  TEMPFAULT  -------------------------------- */
#define TEMPFAULT_TWARN1_Pos                        0
#define TEMPFAULT_TWARN1_Msk                        (0x01UL << TEMPFAULT_TWARN1_Pos)
#define TEMPFAULT_TWARN2_Pos                        1
#define TEMPFAULT_TWARN2_Msk                        (0x01UL << TEMPFAULT_TWARN2_Pos)
#define TEMPFAULT_TMPFLT_Pos                        2
#define TEMPFAULT_TMPFLT_Msk                        (0x01UL << TEMPFAULT_TMPFLT_Pos)
#define TEMPFAULT_TWARN1RTS_Pos                     6
#define TEMPFAULT_TWARN1RTS_Msk                     (0x01UL << TEMPFAULT_TWARN1RTS_Pos)
#define TEMPFAULT_TWARN2RTS_Pos                     7
#define TEMPFAULT_TWARN2RTS_Msk                     (0x01UL << TEMPFAULT_TWARN2RTS_Pos)

/* --------------------------------  SIGFAULTEN  -------------------------------- */
#define SIGFAULTEN_BATOVFLTEN_Pos                   0                                                   /*!< SIGFAULTEN: BATOVFLTEN Position            */
#define SIGFAULTEN_BATOVFLTEN_Msk                   (0x01UL << SIGFAULTEN_BATOVFLTEN_Pos)               /*!< SIGFAULTEN: BATOVFLTEN Mask                */
#define SIGFAULTEN_OCDFLTEN_Pos                     1                                                   /*!< SIGFAULTEN: OCDFLTEN Position              */
#define SIGFAULTEN_OCDFLTEN_Msk                     (0x01UL << SIGFAULTEN_OCDFLTEN_Pos)                 /*!< SIGFAULTEN: OCDFLTEN Mask                  */
#define SIGFAULTEN_OCCFLTEN_Pos                     2                                                   /*!< SIGFAULTEN: OCCFLTEN Position              */
#define SIGFAULTEN_OCCFLTEN_Msk                     (0x01UL << SIGFAULTEN_OCCFLTEN_Pos)                 /*!< SIGFAULTEN: OCCFLTEN Mask                  */
#define SIGFAULTEN_SCPFLTEN_Pos                     3                                                   /*!< SIGFAULTEN: SCPFLTEN Position              */
#define SIGFAULTEN_SCPFLTEN_Msk                     (0x01UL << SIGFAULTEN_SCPFLTEN_Pos)                 /*!< SIGFAULTEN: SCPFLTEN Mask                  */
#define SIGFAULTEN_EMUXFLTEN_Pos                    4                                                   /*!< SIGFAULTEN: EMUXFLTEN Position             */
#define SIGFAULTEN_EMUXFLTEN_Msk                    (0x01UL << SIGFAULTEN_EMUXFLTEN_Pos)                /*!< SIGFAULTEN: EMUXFLTEN Mask                 */

/* --------------------------------  SIGFAULT  -------------------------------- */
#define SIGFAULT_BATOVFLT_Pos                       0                                                   /*!< SIGFAULT: BATOVFLT Position                */
#define SIGFAULT_BATOVFLT_Msk                       (0x01UL << SIGFAULT_BATOVFLT_Pos)                   /*!< SIGFAULT: BATOVFLT Mask                    */
#define SIGFAULT_OCDFLT_Pos                         1                                                   /*!< SIGFAULT: OCDFLT Position                  */
#define SIGFAULT_OCDFLT_Msk                         (0x01UL << SIGFAULT_OCDFLT_Pos)                     /*!< SIGFAULT: OCDFLT Mask                      */
#define SIGFAULT_OCCFLT_Pos                         2                                                   /*!< SIGFAULT: OCCFLT Position                  */
#define SIGFAULT_OCCFLT_Msk                         (0x01UL << SIGFAULT_OCCFLT_Pos)                     /*!< SIGFAULT: OCCFLT Mask                      */
#define SIGFAULT_SCPFLT_Pos                         3                                                   /*!< SIGFAULT: SCPFLT Position                  */
#define SIGFAULT_SCPFLT_Msk                         (0x01UL << SIGFAULT_SCPFLT_Pos)                     /*!< SIGFAULT: SCPFLT Mask                      */
#define SIGFAULT_EMUXFLT_Pos                        4                                                   /*!< SIGFAULT: EMUXFLT Position                 */
#define SIGFAULT_EMUXFLT_Msk                        (0x01UL << SIGFAULT_EMUXFLT_Pos)                    /*!< SIGFAULT: EMUXFLT Mask                     */
#define SIGFAULT_DSGFLT_LATCH_Pos                   5                                               /*!< SIGFAULT: DSGFLT_LATCH Position            */
#define SIGFAULT_DSGFLT_LATCH_Msk                   (0x01UL << SIGFAULT_DSGFLT_LATCH_Pos)               /*!< SIGFAULT: DSGFLT_LATCH Mask                */
#define SIGFAULT_CHGFLT_LATCH_Pos                   6                                               /*!< SIGFAULT: CHGFLT_LATCH Position            */
#define SIGFAULT_CHGFLT_LATCH_Msk                   (0x01UL << SIGFAULT_CHGFLT_LATCH_Pos)               /*!< SIGFAULT: CHGFLT_LATCH Mask                */

/* --------------------------------  BATRTS  -------------------------------- */
#define BATRTS_BATOV_RTS_Pos                        0                                                   /*!< BATRTS: BATOV_RTS Position                 */
#define BATRTS_BATOV_RTS_Msk                        (0x01UL << BATRTS_BATOV_RTS_Pos)                    /*!< BATRTS: BATOV_RTS Mask                     */
#define BATRTS_OCD_RTS_Pos                          1                                                   /*!< BATRTS: OCD_RTS Position                   */
#define BATRTS_OCD_RTS_Msk                          (0x01UL << BATRTS_OCD_RTS_Pos)                      /*!< BATRTS: OCD_RTS Mask                       */
#define BATRTS_OCC_RTS_Pos                          2                                                   /*!< BATRTS: OCC_RTS Position                   */
#define BATRTS_OCC_RTS_Msk                          (0x01UL << BATRTS_OCC_RTS_Pos)                      /*!< BATRTS: OCC_RTS Mask                       */
#define BATRTS_SCP_RTS_Pos                          3                                                   /*!< BATRTS: SCP_RTS Position                   */
#define BATRTS_SCP_RTS_Msk                          (0x01UL << BATRTS_SCP_RTS_Pos)                      /*!< BATRTS: SCP_RTS Mask                       */

/* --------------------------------  BATOVCFG  -------------------------------- */
#define BATOVCFG_TIMEBASE_Pos                       0                                                   /*!< BATOVCFG: TIMEBASE Position                */
#define BATOVCFG_TIMEBASE_Msk                       (0x0FUL << BATOVCFG_TIMEBASE_Pos)                   /*!< BATOVCFG: TIMEBASE Mask                    */
#define BATOVCFG_BLANKSF_Pos                        4                                                   /*!< BATOVCFG: BLANKSF Position                 */
#define BATOVCFG_BLANKSF_Msk                        (0x0FUL << BATOVCFG_BLANKSF_Pos)                    /*!< BATOVCFG: BLANKSF Mask                     */

/* --------------------------------  VADCCTL  -------------------------------- */
#define VADCCTL_VBMUXSEL_Pos                        0                                                   /*!< VADCCTL: VBMUXSEL Position                 */
#define VADCCTL_VBMUXSEL_Msk                        (0x1FUL << VADCCTL_VBMUXSEL_Pos)                    /*!< VADCCTL: VBMUXSEL Mask                     */
#define VADCCTL_VADCBUSY_Pos                        6                                                   /*!< VADCCTL: VADCBUSY Position                 */
#define VADCCTL_VADCBUSY_Msk                        (0x01UL << VADCCTL_VADCBUSY_Pos)                    /*!< VADCCTL: VADCBUSY Mask                     */
#define VADCCTL_VADCSTART_Pos                       7                                                   /*!< VADCCTL: VADCSTART Position                */
#define VADCCTL_VADCSTART_Msk                       (0x01UL << VADCCTL_VADCSTART_Pos)                   /*!< VADCCTL: VADCSTART Mask                    */

/* --------------------------------  IADCCTL  -------------------------------- */
#define IADCCTL_DAGAIN_Pos                          0                                                   /*!< IADCCTL: DAGAIN Position                   */
#define IADCCTL_DAGAIN_Msk                          (0x07UL << IADCCTL_DAGAIN_Pos)                      /*!< IADCCTL: DAGAIN Mask                       */
#define IADCCTL_IMUXSEL_Pos                         3                                                   /*!< IADCCTL: IMUXSEL Position                  */
#define IADCCTL_IMUXSEL_Msk                         (0x03UL << IADCCTL_IMUXSEL_Pos)                     /*!< IADCCTL: IMUXSEL Mask                      */
#define IADCCTL_IADCBUSY_Pos                        6                                                   /*!< IADCCTL: IADCBUSY Position                 */
#define IADCCTL_IADCBUSY_Msk                        (0x01UL << IADCCTL_IADCBUSY_Pos)                    /*!< IADCCTL: IADCBUSY Mask                     */
#define IADCCTL_IADCSTART_Pos                       7                                                   /*!< IADCCTL: IADCSTART Position                */
#define IADCCTL_IADCSTART_Msk                       (0x01UL << IADCCTL_IADCSTART_Pos)                   /*!< IADCCTL: IADCSTART Mask                    */

/* --------------------------------  SCPCFG  -------------------------------- */
#define SCPCFG_TIMEBASE_Pos                         0                                                   /*!< SCPCFG: TIMEBASE Position                  */
#define SCPCFG_TIMEBASE_Msk                         (0x0FUL << SCPCFG_TIMEBASE_Pos)                     /*!< SCPCFG: TIMEBASE Mask                      */
#define SCPCFG_BLANKSF_Pos                          4                                                   /*!< SCPCFG: BLANKSF Position                   */
#define SCPCFG_BLANKSF_Msk                          (0x0FUL << SCPCFG_BLANKSF_Pos)                      /*!< SCPCFG: BLANKSF Mask                       */

/* --------------------------------  OCCCFG  -------------------------------- */
#define OCCCFG_TIMEBASE_Pos                         0                                                   /*!< OCCCFG: TIMEBASE Position                  */
#define OCCCFG_TIMEBASE_Msk                         (0x0FUL << OCCCFG_TIMEBASE_Pos)                     /*!< OCCCFG: TIMEBASE Mask                      */
#define OCCCFG_BLANKSF_Pos                          4                                                   /*!< OCCCFG: BLANKSF Position                   */
#define OCCCFG_BLANKSF_Msk                          (0x0FUL << OCCCFG_BLANKSF_Pos)                      /*!< OCCCFG: BLANKSF Mask                       */

/* --------------------------------  OCDCFG  -------------------------------- */
#define OCDCFG_TIMEBASE_Pos                         0                                                   /*!< OCDCFG: TIMEBASE Position                  */
#define OCDCFG_TIMEBASE_Msk                         (0x0FUL << OCDCFG_TIMEBASE_Pos)                     /*!< OCDCFG: TIMEBASE Mask                      */
#define OCDCFG_BLANKSF_Pos                          4                                                   /*!< OCDCFG: BLANKSF Position                   */
#define OCDCFG_BLANKSF_Msk                          (0x0FUL << OCDCFG_BLANKSF_Pos)                      /*!< OCDCFG: BLANKSF Mask                       */

/* --------------------------------  CELLEN1  -------------------------------- */
#define CELLEN1_CEN1_Pos                            0                                                   /*!< CELLEN1: CEN1 Position                     */
#define CELLEN1_CEN1_Msk                            (0x01UL << CELLEN1_CEN1_Pos)                        /*!< CELLEN1: CEN1 Mask                         */
#define CELLEN1_CEN2_Pos                            1                                                   /*!< CELLEN1: CEN2 Position                     */
#define CELLEN1_CEN2_Msk                            (0x01UL << CELLEN1_CEN2_Pos)                        /*!< CELLEN1: CEN2 Mask                         */
#define CELLEN1_CEN3_Pos                            2                                                   /*!< CELLEN1: CEN3 Position                     */
#define CELLEN1_CEN3_Msk                            (0x01UL << CELLEN1_CEN3_Pos)                        /*!< CELLEN1: CEN3 Mask                         */
#define CELLEN1_CEN4_Pos                            3                                                   /*!< CELLEN1: CEN4 Position                     */
#define CELLEN1_CEN4_Msk                            (0x01UL << CELLEN1_CEN4_Pos)                        /*!< CELLEN1: CEN4 Mask                         */
#define CELLEN1_CEN5_Pos                            4                                                   /*!< CELLEN1: CEN5 Position                     */
#define CELLEN1_CEN5_Msk                            (0x01UL << CELLEN1_CEN5_Pos)                        /*!< CELLEN1: CEN5 Mask                         */
#define CELLEN1_CEN6_Pos                            5                                                   /*!< CELLEN1: CEN6 Position                     */
#define CELLEN1_CEN6_Msk                            (0x01UL << CELLEN1_CEN6_Pos)                        /*!< CELLEN1: CEN6 Mask                         */
#define CELLEN1_CEN7_Pos                            6                                                   /*!< CELLEN1: CEN7 Position                     */
#define CELLEN1_CEN7_Msk                            (0x01UL << CELLEN1_CEN7_Pos)                        /*!< CELLEN1: CEN7 Mask                         */
#define CELLEN1_CEN8_Pos                            7                                                   /*!< CELLEN1: CEN8 Position                     */
#define CELLEN1_CEN8_Msk                            (0x01UL << CELLEN1_CEN8_Pos)                        /*!< CELLEN1: CEN8 Mask                         */

/* --------------------------------  CELLEN2  -------------------------------- */
#define CELLEN2_CEN9_Pos                            0                                                   /*!< CELLEN2: CEN9 Position                     */
#define CELLEN2_CEN9_Msk                            (0x01UL << CELLEN2_CEN9_Pos)                        /*!< CELLEN2: CEN9 Mask                         */
#define CELLEN2_CEN10_Pos                           1                                                   /*!< CELLEN2: CEN10 Position                    */
#define CELLEN2_CEN10_Msk                           (0x01UL << CELLEN2_CEN10_Pos)                       /*!< CELLEN2: CEN10 Mask                        */
#define CELLEN2_CEN11_Pos                           2                                                   /*!< CELLEN2: CEN11 Position                    */
#define CELLEN2_CEN11_Msk                           (0x01UL << CELLEN2_CEN11_Pos)                       /*!< CELLEN2: CEN11 Mask                        */
#define CELLEN2_CEN12_Pos                           3                                                   /*!< CELLEN2: CEN12 Position                    */
#define CELLEN2_CEN12_Msk                           (0x01UL << CELLEN2_CEN12_Pos)                       /*!< CELLEN2: CEN12 Mask                        */
#define CELLEN2_CEN13_Pos                           4                                                   /*!< CELLEN2: CEN13 Position                    */
#define CELLEN2_CEN13_Msk                           (0x01UL << CELLEN2_CEN13_Pos)                       /*!< CELLEN2: CEN13 Mask                        */
#define CELLEN2_CEN14_Pos                           5                                                   /*!< CELLEN2: CEN14 Position                    */
#define CELLEN2_CEN14_Msk                           (0x01UL << CELLEN2_CEN14_Pos)                       /*!< CELLEN2: CEN14 Mask                        */
#define CELLEN2_CEN15_Pos                           6                                                   /*!< CELLEN2: CEN15 Position                    */
#define CELLEN2_CEN15_Msk                           (0x01UL << CELLEN2_CEN15_Pos)                       /*!< CELLEN2: CEN15 Mask                        */
#define CELLEN2_CEN16_Pos                           7                                                   /*!< CELLEN2: CEN16 Position                    */
#define CELLEN2_CEN16_Msk                           (0x01UL << CELLEN2_CEN16_Pos)                       /*!< CELLEN2: CEN16 Mask                        */

/* --------------------------------  CELLEN3  -------------------------------- */
#define CELLEN3_CEN17_Pos                           0                                                   /*!< CELLEN3: CEN17 Position                    */
#define CELLEN3_CEN17_Msk                           (0x01UL << CELLEN3_CEN17_Pos)                       /*!< CELLEN3: CEN17 Mask                        */
#define CELLEN3_CEN18_Pos                           1                                                   /*!< CELLEN3: CEN18 Position                    */
#define CELLEN3_CEN18_Msk                           (0x01UL << CELLEN3_CEN18_Pos)                       /*!< CELLEN3: CEN18 Mask                        */
#define CELLEN3_CEN19_Pos                           2                                                   /*!< CELLEN3: CEN19 Position                    */
#define CELLEN3_CEN19_Msk                           (0x01UL << CELLEN3_CEN19_Pos)                       /*!< CELLEN3: CEN19 Mask                        */
#define CELLEN3_CEN20_Pos                           3                                                   /*!< CELLEN3: CEN20 Position                    */
#define CELLEN3_CEN20_Msk                           (0x01UL << CELLEN3_CEN20_Pos)                       /*!< CELLEN3: CEN20 Mask                        */

/* --------------------------------  CFGCB1  -------------------------------- */
#define CFGCB1_VB1_Pos                              0                                                   /*!< CFGCB1: VB1 Position                       */
#define CFGCB1_VB1_Msk                              (0x01UL << CFGCB1_VB1_Pos)                          /*!< CFGCB1: VB1 Mask                           */
#define CFGCB1_VB2_Pos                              1                                                   /*!< CFGCB1: VB2 Position                       */
#define CFGCB1_VB2_Msk                              (0x01UL << CFGCB1_VB2_Pos)                          /*!< CFGCB1: VB2 Mask                           */
#define CFGCB1_VB3_Pos                              2                                                   /*!< CFGCB1: VB3 Position                       */
#define CFGCB1_VB3_Msk                              (0x01UL << CFGCB1_VB3_Pos)                          /*!< CFGCB1: VB3 Mask                           */
#define CFGCB1_VB4_Pos                              3                                                   /*!< CFGCB1: VB4 Position                       */
#define CFGCB1_VB4_Msk                              (0x01UL << CFGCB1_VB4_Pos)                          /*!< CFGCB1: VB4 Mask                           */
#define CFGCB1_VB5_Pos                              4                                                   /*!< CFGCB1: VB5 Position                       */
#define CFGCB1_VB5_Msk                              (0x01UL << CFGCB1_VB5_Pos)                          /*!< CFGCB1: VB5 Mask                           */
#define CFGCB1_VB6_Pos                              5                                                   /*!< CFGCB1: VB6 Position                       */
#define CFGCB1_VB6_Msk                              (0x01UL << CFGCB1_VB6_Pos)                          /*!< CFGCB1: VB6 Mask                           */
#define CFGCB1_VB7_Pos                              6                                                   /*!< CFGCB1: VB7 Position                       */
#define CFGCB1_VB7_Msk                              (0x01UL << CFGCB1_VB7_Pos)                          /*!< CFGCB1: VB7 Mask                           */
#define CFGCB1_VB8_Pos                              7                                                   /*!< CFGCB1: VB8 Position                       */
#define CFGCB1_VB8_Msk                              (0x01UL << CFGCB1_VB8_Pos)                          /*!< CFGCB1: VB8 Mask                           */

/* --------------------------------  CFGCB2  -------------------------------- */
#define CFGCB2_VB9_Pos                              0                                                   /*!< CFGCB2: VB9 Position                       */
#define CFGCB2_VB9_Msk                              (0x01UL << CFGCB2_VB9_Pos)                          /*!< CFGCB2: VB9 Mask                           */
#define CFGCB2_VB10_Pos                             1                                                   /*!< CFGCB2: VB10 Position                      */
#define CFGCB2_VB10_Msk                             (0x01UL << CFGCB2_VB10_Pos)                         /*!< CFGCB2: VB10 Mask                          */
#define CFGCB2_VB11_Pos                             2                                                   /*!< CFGCB2: VB11 Position                      */
#define CFGCB2_VB11_Msk                             (0x01UL << CFGCB2_VB11_Pos)                         /*!< CFGCB2: VB11 Mask                          */
#define CFGCB2_VB12_Pos                             3                                                   /*!< CFGCB2: VB12 Position                      */
#define CFGCB2_VB12_Msk                             (0x01UL << CFGCB2_VB12_Pos)                         /*!< CFGCB2: VB12 Mask                          */
#define CFGCB2_VB13_Pos                             4                                                   /*!< CFGCB2: VB13 Position                      */
#define CFGCB2_VB13_Msk                             (0x01UL << CFGCB2_VB13_Pos)                         /*!< CFGCB2: VB13 Mask                          */
#define CFGCB2_VB14_Pos                             5                                                   /*!< CFGCB2: VB14 Position                      */
#define CFGCB2_VB14_Msk                             (0x01UL << CFGCB2_VB14_Pos)                         /*!< CFGCB2: VB14 Mask                          */
#define CFGCB2_VB15_Pos                             6                                                   /*!< CFGCB2: VB15 Position                      */
#define CFGCB2_VB15_Msk                             (0x01UL << CFGCB2_VB15_Pos)                         /*!< CFGCB2: VB15 Mask                          */
#define CFGCB2_VB16_Pos                             7                                                   /*!< CFGCB2: VB16 Position                      */
#define CFGCB2_VB16_Msk                             (0x01UL << CFGCB2_VB16_Pos)                         /*!< CFGCB2: VB16 Mask                          */

/* --------------------------------  CFGCB3  -------------------------------- */
#define CFGCB3_VB17_Pos                             0                                                   /*!< CFGCB3: VB17 Position                      */
#define CFGCB3_VB17_Msk                             (0x01UL << CFGCB3_VB17_Pos)                         /*!< CFGCB3: VB17 Mask                          */
#define CFGCB3_VB18_Pos                             1                                                   /*!< CFGCB3: VB18 Position                      */
#define CFGCB3_VB18_Msk                             (0x01UL << CFGCB3_VB18_Pos)                         /*!< CFGCB3: VB18 Mask                          */
#define CFGCB3_VB19_Pos                             2                                                   /*!< CFGCB3: VB19 Position                      */
#define CFGCB3_VB19_Msk                             (0x01UL << CFGCB3_VB19_Pos)                         /*!< CFGCB3: VB19 Mask                          */
#define CFGCB3_VB20_Pos                             3                                                   /*!< CFGCB3: VB20 Position                      */
#define CFGCB3_VB20_Msk                             (0x01UL << CFGCB3_VB20_Pos)                         /*!< CFGCB3: VB20 Mask                          */

/* --------------------------------  CLKOUTCFG  -------------------------------- */
#define CLKOUTCFG_CLKOUTEN_Pos                      0                                                   /*!< CLKOUTCFG: CLKOUTEN Position               */
#define CLKOUTCFG_CLKOUTEN_Msk                      (0x01UL << CLKOUTCFG_CLKOUTEN_Pos)                  /*!< CLKOUTCFG: CLKOUTEN Mask                   */
#define CLKOUTCFG_CLKOUTFREQ_Pos                    1                                                   /*!< CLKOUTCFG: CLKOUTFREQ Position             */
#define CLKOUTCFG_CLKOUTFREQ_Msk                    (0x03UL << CLKOUTCFG_CLKOUTFREQ_Pos)                /*!< CLKOUTCFG: CLKOUTFREQ Mask                 */

/* --------------------------------  WWDTCTL  -------------------------------- */
#define WWDTCTL_EN_Pos                              0                                                   /*!< WWDTCTL: EN Position                       */
#define WWDTCTL_EN_Msk                              (0x01UL << WWDTCTL_EN_Pos)                          /*!< WWDTCTL: EN Mask                           */
#define WWDTCTL_CLKDIV_Pos                          1                                                   /*!< WWDTCTL: CLKDIV Position                   */
#define WWDTCTL_CLKDIV_Msk                          (0x03UL << WWDTCTL_CLKDIV_Pos)                      /*!< WWDTCTL: CLKDIV Mask                       */
#define WWDTCTL_KEY_Pos                             3                                                   /*!< WWDTCTL: KEY Position                      */
#define WWDTCTL_KEY_Msk                             (0x1FUL << WWDTCTL_KEY_Pos)                         /*!< WWDTCTL: KEY Mask                          */

#endif // #ifndef PAC_AFE_ARCH_1_H
