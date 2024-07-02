/* generated configuration header file - do not edit */
#ifndef BSP_MCU_FAMILY_CFG_RA8D1_H
#define BSP_MCU_FAMILY_CFG_RA8D1_H
#include "../../../fsp/src/bsp/mcu/ra8d1/bsp_override.h"
#include "../../../fsp/src/bsp/mcu/ra8d1/bsp_mcu_info.h"
#include "bsp_clock_cfg.h"
#define BSP_MCU_GROUP_RA8D1    (1)
#define BSP_MCU_GROUP_RA8      (1)     // Temporary group macro to hide confidential part numbers
#define BSP_LOCO_HZ            (32768)
#define BSP_MOCO_HZ            (8000000)
#define BSP_SUB_CLOCK_HZ       (32768)
#if   BSP_CFG_HOCO_FREQUENCY == 0
 #define BSP_HOCO_HZ           (16000000)
#elif BSP_CFG_HOCO_FREQUENCY == 1
 #define BSP_HOCO_HZ           (18000000)
#elif BSP_CFG_HOCO_FREQUENCY == 2
 #define BSP_HOCO_HZ           (20000000)
#elif BSP_CFG_HOCO_FREQUENCY == 4
 #define BSP_HOCO_HZ           (32000000)
#elif BSP_CFG_HOCO_FREQUENCY == 7
 #define BSP_HOCO_HZ           (48000000)
#else
 #error "Invalid HOCO frequency chosen (BSP_CFG_HOCO_FREQUENCY) in bsp_clock_cfg.h"
#endif

#ifndef BSP_CFG_FLL_ENABLE
 #define BSP_CFG_FLL_ENABLE                    (0)
#endif

#define BSP_CORTEX_VECTOR_TABLE_ENTRIES        (16U)
#define BSP_VECTOR_TABLE_MAX_ENTRIES           (112U)

#ifndef OFS_SEQ1
 #define OFS_SEQ1                              (0xA001A001U) | (1U << 1) | (3U << 2)
#endif
#ifndef OFS_SEQ2
 #define OFS_SEQ2                              (15U << 4) | (3U << 8) | (3U << 10)
#endif
#ifndef OFS_SEQ3
 #define OFS_SEQ3                              (1U << 12) | (1U << 14) | (1U << 17)
#endif
#ifndef OFS_SEQ4
 #define OFS_SEQ4                              (3U << 18) | (15U << 20) | (3U << 24) | (3U << 26)
#endif
#ifndef OFS_SEQ5
 #define OFS_SEQ5                              (1U << 28) | (1U << 30)
#endif
#ifndef BSP_CFG_ROM_REG_OFS0
 #define BSP_CFG_ROM_REG_OFS0                  (OFS_SEQ1 | OFS_SEQ2 | OFS_SEQ3 | OFS_SEQ4 | OFS_SEQ5)
#endif
#ifndef BSP_CFG_ROM_REG_OFS1_INITECCEN
 #define BSP_CFG_ROM_REG_OFS1_INITECCEN        (0U << 25)
#endif
#ifndef BSP_CFG_ROM_REG_OFS1
 #define BSP_CFG_ROM_REG_OFS1                  (0xFDFFFEF8U | (1U << 2) | (3U) | (1U << 8) | \
                                                BSP_CFG_ROM_REG_OFS1_INITECCEN)
#endif
#ifndef BSP_CFG_ROM_REG_OFS2
 #define BSP_CFG_ROM_REG_OFS2                  (0xFFFFFFFFU)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_PC0_ENABLE
 #define BSP_CFG_ROM_REG_MPU_PC0_ENABLE        (1)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_PC0_START
 #define BSP_CFG_ROM_REG_MPU_PC0_START         (0xFFFFFFFFU)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_PC0_END
 #define BSP_CFG_ROM_REG_MPU_PC0_END           (0xFFFFFFFFU)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_PC1_ENABLE
 #define BSP_CFG_ROM_REG_MPU_PC1_ENABLE        (1)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_PC1_START
 #define BSP_CFG_ROM_REG_MPU_PC1_START         (0xFFFFFFFFU)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_PC1_END
 #define BSP_CFG_ROM_REG_MPU_PC1_END           (0xFFFFFFFFU)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_REGION0_ENABLE
 #define BSP_CFG_ROM_REG_MPU_REGION0_ENABLE    (1)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_REGION0_START
 #define BSP_CFG_ROM_REG_MPU_REGION0_START     (0xFFFFFFFFU)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_REGION0_END
 #define BSP_CFG_ROM_REG_MPU_REGION0_END       (0xFFFFFFFFU)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_REGION1_ENABLE
 #define BSP_CFG_ROM_REG_MPU_REGION1_ENABLE    (1)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_REGION1_START
 #define BSP_CFG_ROM_REG_MPU_REGION1_START     (0xFFFFFFFFU)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_REGION1_END
 #define BSP_CFG_ROM_REG_MPU_REGION1_END       (0xFFFFFFFFU)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_REGION2_ENABLE
 #define BSP_CFG_ROM_REG_MPU_REGION2_ENABLE    (1)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_REGION2_START
 #define BSP_CFG_ROM_REG_MPU_REGION2_START     (0xFFFFFFFFU)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_REGION2_END
 #define BSP_CFG_ROM_REG_MPU_REGION2_END       (0xFFFFFFFFU)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_REGION3_ENABLE
 #define BSP_CFG_ROM_REG_MPU_REGION3_ENABLE    (1)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_REGION3_START
 #define BSP_CFG_ROM_REG_MPU_REGION3_START     (0xFFFFFFFFU)
#endif
#ifndef BSP_CFG_ROM_REG_MPU_REGION3_END
 #define BSP_CFG_ROM_REG_MPU_REGION3_END       (0xFFFFFFFFU)
#endif

/* Dual Mode Select Register */
#ifndef BSP_CFG_ROM_REG_DUALSEL
 #define BSP_CFG_ROM_REG_DUALSEL               (0xFFFFFFFFU)
#endif

/* Block Protection Register 0 */
#ifndef BSP_CFG_ROM_REG_BPS0
 #define BSP_CFG_ROM_REG_BPS0                  (0xFFFFFFFFU)
#endif

/* Block Protection Register 1 */
#ifndef BSP_CFG_ROM_REG_BPS1
 #define BSP_CFG_ROM_REG_BPS1                  (0xFFFFFFFFU)
#endif

/* Block Protection Register 2 */
#ifndef BSP_CFG_ROM_REG_BPS2
 #define BSP_CFG_ROM_REG_BPS2                  (0xFFFFFFFFU)
#endif

/* Block Protection Register 3 */
#ifndef BSP_CFG_ROM_REG_BPS3
 #define BSP_CFG_ROM_REG_BPS3                  (0xFFFFFFFFU)
#endif

/* Permanent Block Protection Register 0 */
#ifndef BSP_CFG_ROM_REG_PBPS0
 #define BSP_CFG_ROM_REG_PBPS0                 (0xFFFFFFFFU)
#endif

/* Permanent Block Protection Register 1 */
#ifndef BSP_CFG_ROM_REG_PBPS1
 #define BSP_CFG_ROM_REG_PBPS1                 (0xFFFFFFFFU)
#endif

/* Permanent Block Protection Register 2 */
#ifndef BSP_CFG_ROM_REG_PBPS2
 #define BSP_CFG_ROM_REG_PBPS2                 (0xFFFFFFFFU)
#endif

/* Permanent Block Protection Register 3 */
#ifndef BSP_CFG_ROM_REG_PBPS3
 #define BSP_CFG_ROM_REG_PBPS3                 (0xFFFFFFFFU)
#endif

/* Security Attribution for Block Protection Register 0 (If any blocks are marked as protected in the secure application, then mark them as secure) */
#ifndef BSP_CFG_ROM_REG_BPS_SEL0
 #define BSP_CFG_ROM_REG_BPS_SEL0              (0xFFFFFFFFU)
#endif

/* Security Attribution for Block Protection Register 1 (If any blocks are marked as protected in the secure application, then mark them as secure) */
#ifndef BSP_CFG_ROM_REG_BPS_SEL1
 #define BSP_CFG_ROM_REG_BPS_SEL1              (0xFFFFFFFFU)
#endif

/* Security Attribution for Block Protection Register 2 (If any blocks are marked as protected in the secure application, then mark them as secure) */
#ifndef BSP_CFG_ROM_REG_BPS_SEL2
 #define BSP_CFG_ROM_REG_BPS_SEL2              (0xFFFFFFFFU)
#endif

/* Security Attribution for Block Protection Register 3 (If any blocks are marked as protected in the secure application, then mark them as secure) */
#ifndef BSP_CFG_ROM_REG_BPS_SEL3
 #define BSP_CFG_ROM_REG_BPS_SEL3              (0xFFFFFFFFU)
#endif

/* Security Attribution for Bank Select Register */
#ifndef BSP_CFG_ROM_REG_BANKSEL_SEL
 #define BSP_CFG_ROM_REG_BANKSEL_SEL           (0xFFFFFFFFU)
#endif

/* FSBL Control Register 0 */
#ifndef BSP_CFG_ROM_REG_FSBLCTRL0
 #define BSP_CFG_ROM_REG_FSBLCTRL0             (0xFFFFFFFFU)
#endif

/* FSBL Control Register 1 */
#ifndef BSP_CFG_ROM_REG_FSBLCTRL1
 #define BSP_CFG_ROM_REG_FSBLCTRL1             (0xFFFFFFFFU)
#endif

/* FSBL Control Register 2 */
#ifndef BSP_CFG_ROM_REG_FSBLCTRL2
 #define BSP_CFG_ROM_REG_FSBLCTRL2             (0xFFFFFFFFU)
#endif

/* Start Address of Code Certificate Register 0 */
#ifndef BSP_CFG_ROM_REG_SACC0
 #define BSP_CFG_ROM_REG_SACC0                 (0xFFFFFFFFU)
#endif

/* Start Address of Code Certificate Register 1 */
#ifndef BSP_CFG_ROM_REG_SACC1
 #define BSP_CFG_ROM_REG_SACC1                 (0xFFFFFFFFU)
#endif

/* Start Address of Measurement Report Register */
#ifndef BSP_CFG_ROM_REG_SAMR
 #define BSP_CFG_ROM_REG_SAMR                  (0xFFFFFFFFU)
#endif

/* Used to create IELS values for the interrupt initialization table g_interrupt_event_link_select. */
#define BSP_PRV_IELS_ENUM(vector)    (ELC_ ## vector)

#ifndef BSP_CFG_DCACHE_ENABLED
 #define BSP_CFG_DCACHE_ENABLED    (0)
#endif

#endif
