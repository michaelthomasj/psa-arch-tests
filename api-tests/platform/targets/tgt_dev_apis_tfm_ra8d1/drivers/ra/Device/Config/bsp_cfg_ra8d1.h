/* ${REA_DISCLAIMER_PLACEHOLDER} */

#ifndef BSP_CFG_RA8D1_H
#define BSP_CFG_RA8D1_H

/***********************************************************************************************************************
 * Configuration Options
 **********************************************************************************************************************/

/**
 * @name Part Number Information
 *
 * Enter the product part number for your MCU. This information will be used to obtain information about your MCU such
 * as package and memory size.
 * To help parse this information, the part number will be defined using multiple macros.
 *
 * <PRE>
 * R7 F A 8D 1 A H 3 C FP #AA 0
 * |  | | |  | | | | | |  |   | Macro Name                        Description
 * |  | | |  | | | | | |  |   |_not used                            = Production identification code
 * |  | | |  | | | | | |  |_____not used                            = Packaging, Terminal material (Pb-free)
 * |  | | |  | | | | | |________BSP_CFG_MCU_PART_PACKAGE            = Package Type
 * |  | | |  | | | | |__________not used                            = Quality Grade
 * |  | | |  | | | |____________not used                            = Operating temperature
 * |  | | |  | | |______________BSP_CFG_MCU_PART_MEMORY_SIZE        = Code flash memory size
 * |  | | |  | |________________BSP_CFG_MCU_PART_MIPI_DSI_SUPPORT   = Feature set
 * |  | | |  |__________________BSP_MCU_GROUP_RA8D1                 = Group name
 * |  | | |_____________________BSP_CFG_MCU_PART_SERIES             = Series name
 * |  | |_______________________not used                            = RA family
 * |  |_________________________not used                            = Flash memory
 * |____________________________not used                            = Renesas MCU
 * </PRE>
 */
#define BSP_MCU_GROUP_RA8D1                   (1)

/** Core & Frequency.
 * <PRE>
 * Character(s) = Value for macro = Description
 * 85           = 0x37            = CM85
 * </PRE>
 */
#ifndef BSP_CFG_MCU_PART_CORE
 #define BSP_CFG_MCU_PART_CORE                (85)
#endif

/** Series */
#ifndef BSP_CFG_MCU_PART_SERIES
 #define BSP_CFG_MCU_PART_SERIES              (0x8)
#endif

/** MIPI DSI Support. Set the macro definition based on values below:
 * <PRE>
 * Character(s) = Value for macro = Feature Set
 * A            = 0x0             = MIPI DSI Not Supported
 * B            = 0x1             = MIPI DSI Supported
 * </PRE>
 */
#ifndef BSP_CFG_MCU_PART_MIPI_DSI_SUPPORT
 #define BSP_CFG_MCU_PART_MIPI_DSI_SUPPORT    (0x1)
#endif

/** @} (end of @name Part Number Information) */

/**
 * @name Stack & Heap Size Settings
 */

/** The Main Stack size in bytes. This is the stack that is used out of reset and is required. Exceptions always use
 * the main stack.
 */
#ifndef BSP_CFG_STACK_MAIN_BYTES
 #define BSP_CFG_STACK_MAIN_BYTES    (0x1000)
#endif

/** Heap size in bytes. */
#ifndef BSP_CFG_HEAP_BYTES
 #define BSP_CFG_HEAP_BYTES          (0xe00)
#endif

/** @} (end of 'Stack & Heap Size Settings')*/

#define BSP_ROM_SIZE_BYTES           (0x1F8000)
#define BSP_DATA_FLASH_SIZE_BYTES    (0x3000)

/**
 * @name Option-Setting Memory (ROM registers) Settings
 *
 * Certain registers are stored in ROM and used to configure the MCU out of reset.
 *
 * @note To use the default values for a register, leave the macro as all 0xFF's.
 * @note ALL OPTIONS ARE DISABLED BY DEFAULT.
 */

/** Configure WDT and IWDT settings.
 * OFS0 - Option Function Select Register 0
 * - b31     Reserved (set to 1)
 * - b30     WDTSTPCTL - WDT Stop Control - (0=counting continues, 1=stop when entering sleep mode)
 * - b29     Reserved (set to 1)
 * - b28     WDTRSTIRQS - WDT Reset Interrupt Request - What to do on underflow (0=take interrupt, 1=reset MCU)
 * - b27:b26 WDTRPSS - WDT Window Start Position Select - (0=25%, 1=50%, 2=75%, 3=100%,don't use)
 * - b25:b24 WDTRPES - WDT Window End Position Select - (0=75%, 1=50%, 2=25%, 3=0%,don't use)
 * - b23:b20 WDTCKS - WDT Clock Frequency Division Ratio - (1=/4, 4=/64, 0xF=/128, 6=/512, 7=/2048, 8=/8192)
 * - b19:b18 WDTTOPS - WDT Timeout Period Select - (0=1024 cycles, 1=4096, 2=8192, 3=16384)
 * - b17     WDTSTRT - WDT Start Mode Select - (0=auto-start after reset, 1=halt after reset)
 * - b16:b15 Reserved (set to 1)
 * - b14     IWDTSTPCTL - IWDT Sleep Stop Control - (0=counting continues, 1=stop w/some low power modes)
 * - b13     Reserved (set to 1)
 * - b12     IWDTRSTIRQS - IWDT Reset Interrupt Request - What to do on underflow (0=take interrupt, 1=reset MCU)
 * - b11:b10 IWDTRPSS - IWDT Window Start Position Select - (0=25%, 1=50%, 2=75%, 3=100%,don't use)
 * - b9:b8   IWDTRPES - IWDT Window End Position Select - (0=75%, 1=50%, 2=25%, 3=0%,don't use)
 * - b7:b4   IWDTCKS - IWDT Clock Frequency Division Ratio - (0=none, 2=/16, 3 = /32, 4=/64, 0xF=/128, 5=/256)
 * - b3:b2   IWDTTOPS - IWDT Timeout Period Select - (0=128 cycles, 1=512, 2=1024, 3=2048)
 * - b1      IWDTSTRT - IWDT Start Mode Select - (0=auto-start after reset, 1=halt after reset)
 * - b0      Reserved (set to 1)
 *
 *  @note A value of 0xFFFFFFFF is the default and will disable all features
 */
#ifndef BSP_CFG_ROM_REG_OFS0
 #define BSP_CFG_ROM_REG_OFS0              (0xFFFFFFFF)
#endif

/** Configure whether voltage detection 0 circuit and HOCO are enabled after reset.
 * OFS1 - Option Function Select Register 1
 * - b31:b26 Reserved (set to 1)
 * - b25     INITECCEN - Initial ECC Enable (Enable ECC function of TCM and CACHE).
 * - b24     SWDBG - Software Debug Control (IWDT and WDT automattically stop when the CPU is in debug mode).
 * - b23:b12 Reserved (set to 1)
 * - b11:b9  HOCOFRQ0 - HOCO frequency setting (Set using BSP_CFG_HOCO_FREQUENCY in bsp_clock_cfg.h)
 * - b8      HOCOEN - Enable/disable HOCO oscillation after a reset (0=enable, 1=disable)
 * - b7:b3   Reserved (set to 1)
 * - b2      LVDAS - Choose to enable/disable Voltage Detection 0 Circuit after a reset (0=enable, 1=disable)
 * - b1:b0   VDSEL - Voltage Detection 0 Level Select (1=2.94V, 2=2.87V, 3=2.80V)
 *
 * @note A value of 0xFDFFFFFF is the default and will disable all features
 */
#ifndef BSP_CFG_ROM_REG_OFS1_INITECCEN
 #define BSP_CFG_ROM_REG_OFS1_INITECCEN    (0U << 25)
#endif
#ifndef BSP_CFG_ROM_REG_OFS1
 #define BSP_CFG_ROM_REG_OFS1              (0xFDFFFFFF | BSP_CFG_ROM_REG_OFS1_INITECCEN)
#endif

/**
 * OFS2 - Option Function Select Register 2
 * - b31:b1 Reserved (set to 1)
 * - b0     DCDCEN -  DCDC Enable
 *
 * @note A value of 0xFFFFFFFF is the default and will disable all features
 */
#ifndef BSP_CFG_ROM_REG_OFS2
 #define BSP_CFG_ROM_REG_OFS2              (0xFFFFFFFFU)
#endif

#ifndef BSP_CFG_CLOCKS_SECURE
 #define BSP_CFG_CLOCKS_SECURE             (0)
#endif

/**
 * Select whether to use OFS1 or OFS1_SEL settings.
 */
#ifndef BSP_CFG_ROM_REG_OFS1_SEL
 #if defined(_RA_TZ_SECURE) || defined(_RA_TZ_NONSECURE)
  #define BSP_CFG_ROM_REG_OFS1_SEL    (0xFCF0F0D0U | ((BSP_CFG_CLOCKS_SECURE == 0) ? 0xF00U : 0U))
 #else
  #define BSP_CFG_ROM_REG_OFS1_SEL    (0xFCF0F0D0U)
 #endif
#endif

/**
 * Select whether to use OFS2 or OFS2_SEC settings (Use the default setting unless a project overrides this value).
 */
#ifndef BSP_CFG_ROM_REG_OFS2_SEL
 #define BSP_CFG_ROM_REG_OFS2_SEL    (0U)
#endif

/** @} (end of @name 'Option-Setting Memory (ROM registers) Settings') */

/**
 * @name Other Hardware Options
 */

/** This macro is used to define the voltage that is supplied to the MCU (Vcc). This macro is defined in millivolts.
 * This macro does not actually change anything on the MCU. Some AMS modules need this information so it is
 * defined here.
 */
#ifndef BSP_CFG_MCU_VCC_MV
 #define BSP_CFG_MCU_VCC_MV    (3300)
#endif

/** @} (end of @name 'ID Code Protection') */

/**
 *  @name Project-Wide Software Options
 */

/** By default AMS modules will check input parameters to be valid. This is helpful during development but some users
 * will want to disable this for production code. The reason for this would be to save execution time and code space.
 * This macro is a global setting for enabling or disabling parameter checking. Each AMS module will also have its
 * own local macro for this same purpose. By default the local macros will take the global value from here though
 * they can be overridden. Therefore, the local setting has priority over this global setting. Disabling parameter
 * checking should only used when inputs are known to be good and the increase in speed or decrease in code space is
 * needed.
 * - 0 = Global setting for parameter checking is disabled.
 * - 1 = Global setting for parameter checking is enabled (Default).
 */
#ifndef BSP_CFG_PARAM_CHECKING_ENABLE
 #define BSP_CFG_PARAM_CHECKING_ENABLE    (1)
#endif

/** Specify which RTOS is being used
 * - 0 = No RTOS
 * - 1 = ThreadX
 * - 2 = Other
 */
#ifndef BSP_CFG_RTOS
 #define BSP_CFG_RTOS                     (0)
#endif

/** Specify what to do if FSP_ASSERT fails
 * - 0 = Return FSP_ERR_ASSERTION.
 * - 1 = Call fsp_error_log, then return FSP_ERR_ASSERTION.  Note that fsp_error_log is a weak function and should be
 *       overridden in user code based on the prototype in fsp/src/bsp/mcu/all/bsp_common.h.
 * - 2 = Use standard assert library to halt execution.
 */
#ifndef BSP_CFG_ASSERT
 #define BSP_CFG_ASSERT                   (0)
#endif

/** Specify what to do when error codes are returned from FSP functions
 * - 0 = Return error code.
 * - 1 = Call fsp_error_log, then return error code.  Note that fsp_error_log is a weak function and should be
 *       overridden in user code based on the prototype in fsp/src/bsp/mcu/all/bsp_common.h.
 */
#ifndef BSP_CFG_ERROR_LOG
 #ifdef TEST_BSP_CFG_ERROR_LOG
  #define BSP_CFG_ERROR_LOG                  (TEST_BSP_CFG_ERROR_LOG)
 #else
  #define BSP_CFG_ERROR_LOG                  (0U)
 #endif
#endif

#if defined(_RA_TZ_SECURE)
 #define BSP_TZ_SECURE_BUILD                 (1)
 #define BSP_TZ_NONSECURE_BUILD              (0)
#elif defined(_RA_TZ_NONSECURE)
 #define BSP_TZ_SECURE_BUILD                 (0)
 #define BSP_TZ_NONSECURE_BUILD              (1)
#else
 #define BSP_TZ_SECURE_BUILD                 (0)
 #define BSP_TZ_NONSECURE_BUILD              (0)
#endif
#ifndef BSP_TZ_CFG_INIT_SECURE_ONLY
 #define BSP_TZ_CFG_INIT_SECURE_ONLY         (1U)
#endif
#ifndef BSP_TZ_CFG_SKIP_INIT
 #define BSP_TZ_CFG_SKIP_INIT                (BSP_TZ_NONSECURE_BUILD && BSP_TZ_CFG_INIT_SECURE_ONLY)
#endif
#ifndef BSP_TZ_CFG_EXCEPTION_RESPONSE
 #define BSP_TZ_CFG_EXCEPTION_RESPONSE       (1U)
#endif

/* CMSIS TrustZone Settings */
#ifndef SCB_CSR_AIRCR_INIT
 #define SCB_CSR_AIRCR_INIT                  (1)
#endif
#ifndef SCB_AIRCR_BFHFNMINS_VAL
 #define SCB_AIRCR_BFHFNMINS_VAL             (0)
#endif
#ifndef SCB_AIRCR_SYSRESETREQS_VAL
 #define SCB_AIRCR_SYSRESETREQS_VAL          (0)
#endif
#ifndef SCB_AIRCR_PRIS_VAL
 #define SCB_AIRCR_PRIS_VAL                  (0)
#endif
#define TZ_FPU_NS_USAGE                      (1)
#ifndef SCB_NSACR_CP10_11_VAL
 #define SCB_NSACR_CP10_11_VAL               (3)
#endif
#ifndef FPU_FPCCR_TS_VAL
 #define FPU_FPCCR_TS_VAL                    (1)
#endif
#define FPU_FPCCR_CLRONRETS_VAL              (1)
#ifndef FPU_FPCCR_CLRONRET_VAL
 #define FPU_FPCCR_CLRONRET_VAL              (0)
#endif

#ifndef BSP_TZ_CFG_NMI_NON_SECURE_ONLY
 #define BSP_TZ_CFG_NMI_NON_SECURE_ONLY      (0U)
#endif
#ifndef BSP_TZ_CFG_SECURE_PRIORITY_BOOST
 #define BSP_TZ_CFG_SECURE_PRIORITY_BOOST    (0U)
#endif
#ifndef BSP_TZ_CFG_FPU_SECURE_ONLY
 #define BSP_TZ_CFG_FPU_SECURE_ONLY          (0U)
#endif
#ifndef BSP_TZ_CFG_FPU_SECURE_REGS
 #define BSP_TZ_CFG_FPU_SECURE_REGS          (0U)
#endif
#ifndef BSP_TZ_CFG_PSARB
 #define BSP_TZ_CFG_PSARB                    (0xF84D9B10)
#endif
#ifndef BSP_TZ_CFG_PSARC
 #define BSP_TZ_CFG_PSARC                    (0x8C01B983)
#endif
#ifndef BSP_TZ_CFG_PSARD
 #define BSP_TZ_CFG_PSARD                    (0x1851F830)
#endif
#ifndef BSP_TZ_CFG_PSARE
 #define BSP_TZ_CFG_PSARE                    (0xFFFC030E)
#endif
#ifndef BSP_TZ_CFG_MSSAR
 #define BSP_TZ_CFG_MSSAR                    (0x80408003)
#endif

/* Type 2 peripheral security attribution. */

/* RSTSRn Security attribution. */
#ifndef BSP_TZ_CFG_RSTSAR
 #define BSP_TZ_CFG_RSTSAR       (0x0000000F)
#endif

/* LVD Security attribution. */
#ifndef BSP_TZ_CFG_LVDSAR
 #define BSP_TZ_CFG_LVDSAR       (0x00000003)
#endif

/* CGCSAR Security attribution. */
#ifndef BSP_TZ_CFG_CGFSAR
 #define BSP_TZ_CFG_CGFSAR       (0x047F3BFD)
#endif

/* LPM Security attribution. */
#ifndef BSP_TZ_CFG_LPMSAR
 #define BSP_TZ_CFG_LPMSAR       (0x002E0107)
#endif

/* Deep Software Standby Interrupt Factor Security Attribution */
#ifndef BSP_TZ_CFG_DPFSAR
 #define BSP_TZ_CFG_DPFSAR       (0xAF1FFFFF)
#endif

/* RAM Standby Control Security Attribution */
#ifndef BSP_TZ_CFG_RSCSAR
 #define BSP_TZ_CFG_RSCSAR       (0x00037FFF)
#endif

/* Power Gating Control Security Attribution */
#ifndef BSP_TZ_CFG_PGCSAR
 #define BSP_TZ_CFG_PGCSAR       (0x00037FFF)
#endif

/* External IRQ Channel Security attribution */
#ifndef BSP_TZ_CFG_ICUSARA
 #define BSP_TZ_CFG_ICUSARA      (0x0000FFFF)
#endif

/* NMI Channel Security attribution */
#ifndef BSP_TZ_CFG_ICUSARB
 #define BSP_TZ_CFG_ICUSARB      (0x00000001)
#endif

/* DMAC Channel Security attribution */
#ifndef BSP_TZ_CFG_DMACCHSAR
 #define BSP_TZ_CFG_DMACCHSAR    (0x000000FF)
#endif

/* WUPEN0 Channel Security attribution */
#ifndef BSP_TZ_CFG_ICUSARE
 #define BSP_TZ_CFG_ICUSARE      (0xFF1D0000)
#endif

#ifndef BSP_TZ_CFG_TEVTRCR
 #define BSP_TZ_CFG_TEVTRCR      (0U)
#endif

/* ELC Security attribution. */
#ifndef BSP_TZ_CFG_ELCSARA
 #define BSP_TZ_CFG_ELCSARA      (0x00000007U)
#endif

/* If DTC is used in secure mode, DTCST should be set. */
#ifndef BSP_TZ_CFG_DTC_USED
 #define BSP_TZ_CFG_DTC_USED     (0U)
#endif

/* Flash Security Attribution Register (FLWT, FCKMHZ). */
#ifndef BSP_TZ_CFG_FSAR
 #define BSP_TZ_CFG_FSAR         (0x0703)
#endif

/* SRAM Security Attribution Register (SRAMPRCR, SRAMPRCR2, SRAMECC). */
#ifndef BSP_TZ_CFG_SRAMSAR
 #define BSP_TZ_CFG_SRAMSAR      (0x00000183)
#endif

/* Bus Master MPU Security Attribution. */
#ifndef BSP_TZ_CFG_MMPUSARA
 #define BSP_TZ_CFG_MMPUSARA     (BSP_TZ_CFG_DMACCHSAR)
#endif

/* Security Attribution Register A for Bus Control Registers. */
#ifndef BSP_TZ_CFG_BUSSARA
 #define BSP_TZ_CFG_BUSSARA      (0)
#endif

/* Security Attribution Register B for Bus Control Registers. */
#ifndef BSP_TZ_CFG_BUSSARB
 #define BSP_TZ_CFG_BUSSARB      (0)
#endif

#ifndef BSP_CFG_RTC_USED
 #define BSP_CFG_RTC_USED        (1)
#endif

/** @} (end of @name 'Project-Wide Software Options') */

#endif
