/* ${REA_DISCLAIMER_PLACEHOLDER} */

/*******************************************************************************************************************//**
 * @ingroup BSP_CONFIG_DK9M
 * @defgroup BSP_CONFIG_DK9M_CLOCKS Build Time Configurations - Clock
 *
 * This file contains build-time clock configuration options. The BSP will use these macros to setup the MCU's clocks
 * for the user before main() is executed.
 *
 * Clock configuration options.
 * The input clock frequency is specified and then the system clocks are set by specifying the multipliers used. The
 * multiplier settings are used to set the clock registers. An example is shown below for a board with a 24MHz
 * XTAL and CPU clock of 240MHz: (NOTE that this is just an example. The RA8D1 has a maximum ICLK of 480 MHz).
 *
 * <PRE>
 * BSP_CFG_XTAL_HZ        = 20000000
 * BSP_CFG_PLL_DIV        = 1  (20 MHz / 1 = 20 MHz)
 * BSP_CFG_PLL_MUL        = 72 (20 MHz x 72 = 1440 MHz)
 * BSP_CFG_PLODIVP        = 6 (1440 MHz / 6 = 240 MHz)
 *
 * BSP_CFG_ICLK_DIV =  1      : System Clock (ICLK)        =
 *                             ((((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) /BSP_CFG_PLODIVP) / BSP_CFG_ICLK_DIV)  = 240MHz
 * BSP_CFG_PCLKA_DIV = 2      : Peripheral Clock A (PCLKA) =
 *                             ((((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) /BSP_CFG_PLODIVP) / BSP_CFG_PCLKA_DIV) = 120MHz
 * BSP_CFG_PCLKB_DIV = 4      : Peripheral Clock B (PCLKB) =
 *                             ((((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) /BSP_CFG_PLODIVP) / BSP_CFG_PCLKB_DIV) = 60MHz
 * BSP_CFG_PCLKC_DIV = 4      : Peripheral Clock C (PCLKC) =
 *                             ((((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) /BSP_CFG_PLODIVP) / BSP_CFG_PCLKC_DIV) = 60MHz
 * BSP_CFG_PCLKD_DIV = 2      : Peripheral Clock D (PCLKD) =
 *                             ((((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) /BSP_CFG_PLODIVP) / BSP_CFG_PCLKD_DIV) = 120MHz
 * BSP_CFG_PCLKE_DIV = 2      : Peripheral Clock E (PCLKE) =
 *                             ((((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) /BSP_CFG_PLODIVP) / BSP_CFG_PCLKE_DIV) = 120MHz
 * BSP_CFG_FCLK_DIV =  4      : Flash IF Clock (FCLK)      =
 *                             ((((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) /BSP_CFG_PLODIVP) / BSP_CFG_FCLK_DIV)  = 60MHz
 * BSP_CFG_BCLK_DIV =  2      : External Bus Clock (BCK)   =
 *                             (((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) / BSP_CFG_BCLK_DIV)  = 120MHz
 * BSP_CFG_UCK_DIV  =  5      : USB Clock (UCLK)           =
 *                             (((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) / BSP_CFG_UCK_DIV)  = 48MHz
 * </PRE>
 *
 * @{
 ***********************************************************************************************************************/

#ifndef BSP_CLOCK_CFG_RA8D1_H
#define BSP_CLOCK_CFG_RA8D1_H

/***********************************************************************************************************************
 * Configuration Options
 ***********************************************************************************************************************/

/** Clock source select (CKSEL). The chosen clock will be the base clock provided for the system clock and all
 * peripheral clocks. It is also used for the flash clock and the external bus clocks.
 *
 * Set the macro to one of the enumerations shown.
 *
 * <PRE>
 * Clock                                        -   Enumeration to use for macro
 * High Speed On-Chip Oscillator   (HOCO)       -   BSP_CLOCKS_SOURCE_CLOCK_HOCO
 * Middle Speed On-Chip Oscillator (MOCO)       -   BSP_CLOCKS_SOURCE_CLOCK_MOCO
 * Low Speed On-Chip Oscillator    (LOCO)       -   BSP_CLOCKS_SOURCE_CLOCK_LOCO
 * Main Clock Oscillator                        -   BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC
 * PLL Circuit                                  -   BSP_CLOCKS_SOURCE_CLOCK_PLL
 * </PRE>
 */
#ifndef BSP_CFG_CLOCK_SOURCE
 #define BSP_CFG_CLOCK_SOURCE    (BSP_CLOCKS_SOURCE_CLOCK_PLL)
#endif

/** XTAL - Input clock frequency in Hz */
#ifndef BSP_CFG_XTAL_HZ
 #ifdef RA8D1_DEMO_BUILD
  #define BSP_CFG_XTAL_HZ    (24000000)
 #elif defined(RA8T1_MCK_BUILD)
  #define BSP_CFG_XTAL_HZ    (12000000)
 #else
  #define BSP_CFG_XTAL_HZ    (20000000)
 #endif
#endif

/** The HOCO can operate at several different frequencies. Choose which one using the macro below. The frequency
 * used out of reset depends upon the OFS1.HOCOFRQ0 bits.
 *
 * <PRE>
 * Available frequency settings:
 * 0 = 16MHz
 * 1 = 18MHz
 * 2 = 20MHz
 * 4 = 32MHz
 * 7 = 48MHz
 * </PRE>
 */
#ifndef BSP_CFG_HOCO_FREQUENCY
 #define BSP_CFG_HOCO_FREQUENCY        (7)
#endif

/** PLL clock source (PLLSRCEL). Choose which clock source to input to the PLL circuit.
 *
 * <PRE>
 * Available clock sources:     -   Enumeration to use for macro
 * 0 = Main clock (default)     -   BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC
 * 1 = HOCO                     -   BSP_CLOCKS_SOURCE_CLOCK_HOCO
 * </PRE>
 */
#ifndef BSP_CFG_PLL_SOURCE
 #define BSP_CFG_PLL_SOURCE            (BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC)
#endif

/** PLL Input Frequency Division Ratio Select (PLIDIV).
 *
 * Available divisors = - /1 (no division), - /2, - /3
 *
 * @note Set macro definition to 'BSP_CLOCKS_PLL_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_PLL_DIV
 #define BSP_CFG_PLL_DIV               (BSP_CLOCKS_PLL_DIV_1)
#endif

/** PLL Frequency Multiplication Factor Select (PLLMUL).
 *
 * Available multipliers = x26 to x180
 */
#ifndef BSP_CFG_PLL_MUL
 #define BSP_CFG_PLL_MUL               (BSP_CLOCKS_PLL_MUL(72, 0))
#endif

/** PLL1P Input Frequency Division Ratio Select (PLODIVP).
 *
 * Available divisors = - /2 , - /4, - /6, - /8, - /16
 *
 * @note Set macro definition to 'BSP_CLOCKS_PLL_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_PLODIVP
 #define BSP_CFG_PLODIVP               (BSP_CLOCKS_PLL_DIV_6)
#endif

/** PLL1Q Input Frequency Division Ratio Select (PLODIVQ).
 *
 * Available divisors = - /2 , - /3, - /4, - /5, - /6, - /8, - /9
 *
 * @note Set macro definition to 'BSP_CLOCKS_PLL_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_PLODIVQ
 #define BSP_CFG_PLODIVQ               (BSP_CLOCKS_PLL_DIV_6)
#endif

/** PLL1R Input Frequency Division Ratio Select (PLODIVR).
 *
 * Available divisors = - /2 , - /3, - /4, - /5, - /6, - /8, - /9
 *
 * @note Set macro definition to 'BSP_CLOCKS_PLL_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_PLODIVR
 #define BSP_CFG_PLODIVR               (BSP_CLOCKS_PLL_DIV_6)
#endif

/** Resultant PLL1P Frequency.
 *
 */
#ifndef BSP_CFG_PLL1P_FREQUENCY_HZ
 #define BSP_CFG_PLL1P_FREQUENCY_HZ    (240000000)
#endif

/** Resultant PLL1Q Frequency.
 *
 */
#ifndef BSP_CFG_PLL1Q_FREQUENCY_HZ
 #define BSP_CFG_PLL1Q_FREQUENCY_HZ    (240000000)
#endif

/** Resultant PLL1R Frequency.
 *
 */
#ifndef BSP_CFG_PLL1R_FREQUENCY_HZ
 #define BSP_CFG_PLL1R_FREQUENCY_HZ    (240000000)
#endif

/** Resultant PLL2P Frequency.
 *
 */
#ifndef BSP_CFG_PLL2P_FREQUENCY_HZ
 #define BSP_CFG_PLL2P_FREQUENCY_HZ    (240000000)
#endif

/** Resultant PLL2Q Frequency.
 *
 */
#ifndef BSP_CFG_PLL2Q_FREQUENCY_HZ
 #define BSP_CFG_PLL2Q_FREQUENCY_HZ    (240000000)
#endif

/** Resultant PLL2R Frequency.
 *
 */
#ifndef BSP_CFG_PLL2R_FREQUENCY_HZ
 #define BSP_CFG_PLL2R_FREQUENCY_HZ    (240000000)
#endif

/** CPU Clock Divider (CPUCLK).
 *
 * Available divisors = /1 (no division), /2, /3, /4, /6, /8, /12, /16, /32, /64
 *
 * @note Set macro definition to 'BSP_CLOCKS_SYS_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_CPUCLK_DIV
 #define BSP_CFG_CPUCLK_DIV            (BSP_CLOCKS_SYS_CLOCK_DIV_1)
#endif

/** System Clock Divider (ICK).
 *
 * Available divisors = /1 (no division), /2, /3, /4, /6, /8, /12, /16, /32, /64
 *
 * @note Set macro definition to 'BSP_CLOCKS_SYS_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_ICLK_DIV
 #define BSP_CFG_ICLK_DIV              (BSP_CLOCKS_SYS_CLOCK_DIV_1)
#endif

/** Peripheral Module Clock A Divider (PCKA).
 *
 * Available divisors = /1 (no division), /2, /3, /4, /6, /8, /12, /16, /32, /64
 *
 * @note Set macro definition to 'BSP_CLOCKS_SYS_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_PCLKA_DIV
 #define BSP_CFG_PCLKA_DIV             (BSP_CLOCKS_SYS_CLOCK_DIV_2)
#endif

/** Peripheral Module Clock B Divider (PCKB).
 *
 * Available divisors = /1 (no division), /2, /3, /4, /6, /8, /12, /16, /32, /64
 *
 * @note Set macro definition to 'BSP_CLOCKS_SYS_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_PCLKB_DIV
 #define BSP_CFG_PCLKB_DIV             (BSP_CLOCKS_SYS_CLOCK_DIV_4)
#endif

/** Peripheral Module Clock C Divider (PCKC).
 *
 * Available divisors = /1 (no division), /2, /3, /4, /6, /8, /12, /16, /32, /64
 *
 * @note Set macro definition to 'BSP_CLOCKS_SYS_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_PCLKC_DIV
 #define BSP_CFG_PCLKC_DIV             (BSP_CLOCKS_SYS_CLOCK_DIV_4)
#endif

/** Peripheral Module Clock D Divider (PCKD).
 *
 * Available divisors = /1 (no division), /2, /3, /4, /6, /8, /12, /16, /32, /64
 *
 * @note Set macro definition to 'BSP_CLOCKS_SYS_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_PCLKD_DIV
 #define BSP_CFG_PCLKD_DIV             (BSP_CLOCKS_SYS_CLOCK_DIV_2)
#endif

/** Peripheral Module Clock E Divider (PCKE).
 *
 * Available divisors = /1 (no division), /2, /3, /4, /6, /8, /12, /16, /32, /64
 *
 * @note Set macro definition to 'BSP_CLOCKS_SYS_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_PCLKE_DIV
 #define BSP_CFG_PCLKE_DIV             (BSP_CLOCKS_SYS_CLOCK_DIV_1)
#endif

/** External Bus Clock Divider (BCLK).
 *
 * Available divisors = /1 (no division), /2, /3, /4, /6, /8, /12, /16, /32, /64
 *
 * @note Set macro definition to 'BSP_CLOCKS_SYS_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_BCLK_DIV
 #define BSP_CFG_BCLK_DIV              (BSP_CLOCKS_SYS_CLOCK_DIV_4)
#endif

/** Flash IF Clock Divider (FCK).
 *
 * Available divisors = /1 (no division), /2, /3, /4, /6, /8, /12, /16, /32, /64
 *
 * @note Set macro definition to 'BSP_CLOCKS_SYS_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_FCLK_DIV
 #define BSP_CFG_FCLK_DIV              (BSP_CLOCKS_SYS_CLOCK_DIV_4)
#endif

/** Configure BCLK output pin
 *
 * Available options:
 * - 0 = No output
 * - 1 = BCK frequency
 * - 2 = BCK/2 frequency
 * - 3 = BCK/4 frequency
 * - 4 = BCK/8 frequency
 * - 5 = BCK/16 frequency
 * - 6 = BCK/32 frequency
 * - 7 = BCK/64 frequency
 * - 9 = BCK/3 frequency
 * - 10 = BCK/6 frequency
 * - 11 = BCK/12 frequency
 *
 * @note This macro is only effective when the external bus is enabled
 */
#ifndef BSP_CFG_BCLK_OUTPUT
 #define BSP_CFG_BCLK_OUTPUT           (2)
#endif

/** PLL2 clock source (PLLSRCEL). Choose which clock source to input to the PLL2 circuit.
 *
 * <PRE>
 * Available clock sources:     -   Enumeration to use for macro
 * 0 = Main clock (default)     -   BSP_CLOCKS_SOURCE_CLOCK_MAIN_OSC
 * 1 = HOCO                     -   BSP_CLOCKS_SOURCE_CLOCK_HOCO
 * </PRE>
 */
#ifndef BSP_CFG_PLL2_SOURCE
 #define BSP_CFG_PLL2_SOURCE           (BSP_CLOCKS_CLOCK_DISABLED)
#endif

/** PLL2 Input Frequency Division Ratio Select (PLIDIV).
 *
 * Available divisors = - /1 (no division), - /2, - /3
 *
 * @note Set macro definition to 'BSP_CLOCKS_PLL_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_PLL2_DIV
 #define BSP_CFG_PLL2_DIV              (BSP_CLOCKS_PLL_DIV_1)
#endif

/** PLL2 Frequency Multiplication Factor Select (PLLMUL).
 *
 * Available multipliers = x26 to x180
 */
#ifndef BSP_CFG_PLL2_MUL
 #define BSP_CFG_PLL2_MUL              (BSP_CLOCKS_PLL_MUL(26, 0))
#endif

/** PLL2P Input Frequency Division Ratio Select (PL2ODIVP).
 *
 * Available divisors = - /2 , - /4, - /6, - /8, - /16
 *
 * @note Set macro definition to 'BSP_CLOCKS_PLL_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_PL2ODIVP
 #define BSP_CFG_PL2ODIVP              (BSP_CLOCKS_PLL_DIV_6)
#endif

/** PLL2Q Input Frequency Division Ratio Select (PL2ODIVQ).
 *
 * Available divisors = - /2 , - /3, - /4, - /5, - /6, - /8, - /9
 *
 * @note Set macro definition to 'BSP_CLOCKS_PLL_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_PL2ODIVQ
 #define BSP_CFG_PL2ODIVQ              (BSP_CLOCKS_PLL_DIV_6)
#endif

/** PLL2R Input Frequency Division Ratio Select (PL2ODIVR).
 *
 * Available divisors = - /2 , - /3, - /4, - /5, - /6, - /8, - /9
 *
 * @note Set macro definition to 'BSP_CLOCKS_PLL_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_PL2ODIVR
 #define BSP_CFG_PL2ODIVR              (BSP_CLOCKS_PLL_DIV_6)
#endif

/**
 * The USB Clock source that is configured during startup.
 */
#ifndef BSP_CFG_UCK_SOURCE
 #define BSP_CFG_UCK_SOURCE            (BSP_CLOCKS_CLOCK_DISABLED)
#endif

/** USB Clock Divider Select.
 *
 * Available divisors = /1, /2, /3, /4, /5, /6, /8
 *
 * @note Set macro definition to 'BSP_CLOCKS_USB_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_UCK_DIV
 #define BSP_CFG_UCK_DIV               (BSP_CLOCKS_USB_CLOCK_DIV_5)
#endif

/**
 * The USB60 Clock source that is configured during startup.
 */
#ifndef BSP_CFG_U60CK_SOURCE
 #define BSP_CFG_U60CK_SOURCE          (BSP_CLOCKS_CLOCK_DISABLED)
#endif

/** USB60 Clock Divider Select.
 *
 * Available divisors = /1, /2, /3, /4, /5, /6, /8
 *
 * @note Set macro definition to 'BSP_CLOCKS_USBHS_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_U60CK_DIV
 #define BSP_CFG_U60CK_DIV             (BSP_CLOCKS_USB60_CLOCK_DIV_5)
#endif

/**
 * The GLCD Clock source that is configured during startup.
 */
#ifndef BSP_CFG_LCDCLK_SOURCE
 #define BSP_CFG_LCDCLK_SOURCE         (BSP_CLOCKS_CLOCK_DISABLED)
#endif

/** GLCD Clock Divider Select.
 *
 * Available divisors = /1, /2, /3, /4, /5, /6, /8
 *
 * @note Set macro definition to 'BSP_CLOCKS_LCD_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_LCDCLK_DIV
 #define BSP_CFG_LCDCLK_DIV            (BSP_CLOCKS_LCD_CLOCK_DIV_1)
#endif

/**
 * The CANFD Clock source that is configured during startup.
 */
#ifndef BSP_CFG_CANFDCLK_SOURCE
 #define BSP_CFG_CANFDCLK_SOURCE       (BSP_CLOCKS_CLOCK_DISABLED)
#endif

/** CANFD Clock Divider Select.
 *
 * Available divisors = /1, /2, /4, /6
 *
 * @note Set macro definition to 'BSP_CLOCKS_CANFD_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_CANFDCLK_DIV
 #define BSP_CFG_CANFDCLK_DIV          (BSP_CLOCKS_CANFD_CLOCK_DIV_5)
#endif

/**
 * The SCI Clock source that is configured during startup.
 */
#ifndef BSP_CFG_SCICLK_SOURCE
 #define BSP_CFG_SCICLK_SOURCE         (BSP_CLOCKS_CLOCK_DISABLED)
#endif

/** SCI Clock Divider Select.
 *
 * Available divisors = /1, /2, /3, /4, /5, /6, /8
 *
 * @note Set macro definition to 'BSP_CLOCKS_SCI_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_SCICLK_DIV
 #define BSP_CFG_SCICLK_DIV            (BSP_CLOCKS_SCI_CLOCK_DIV_1)
#endif

/**
 * The SPI Clock source that is configured during startup.
 */
#ifndef BSP_CFG_SPICLK_SOURCE
 #define BSP_CFG_SPICLK_SOURCE         (BSP_CLOCKS_CLOCK_DISABLED)
#endif

/** SPI Clock Divider Select.
 *
 * Available divisors = /1, /2, /3, /4, /5, /6, /8
 *
 * @note Set macro definition to 'BSP_CLOCKS_SPI_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_SPICLK_DIV
 #define BSP_CFG_SPICLK_DIV            (BSP_CLOCKS_SPI_CLOCK_DIV_1)
#endif

/**
 * The I3C Clock source that is configured during startup.
 */
#ifndef BSP_CFG_I3CCLK_SOURCE
 #define BSP_CFG_I3CCLK_SOURCE         (BSP_CLOCKS_CLOCK_DISABLED)
#endif

/** I3C Clock Divider Select.
 *
 * Available divisors = /1, /2, /3, /4, /5, /6, /8
 *
 * @note Set macro definition to 'BSP_CLOCKS_I3C_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_I3CCLK_DIV
 #define BSP_CFG_I3CCLK_DIV            (BSP_CLOCKS_I3C_CLOCK_DIV_1)
#endif

/**
 * The OCTA Clock source that is configured during startup.
 */
#ifndef BSP_CFG_OCTA_SOURCE
 #define BSP_CFG_OCTA_SOURCE           (BSP_CLOCKS_CLOCK_DISABLED)
#endif

/** OCTA Clock Divider Select.
 *
 * Available divisors = /1, /2, /4, /6, /8
 *
 * @note Set macro definition to 'BSP_CLOCKS_OCTA_CLOCK_DIV_' + your divider selection.
 */
#ifndef BSP_CFG_OCTA_DIV
 #define BSP_CFG_OCTA_DIV              (BSP_CLOCKS_OCTA_CLOCK_DIV_1)
#endif

/** Configure SDCLK output pin
 *
 * Available options:
 * - 0 = No output
 * - 1 = BCK frequency
 *
 * @note This macro is only effective when the external bus is enabled
 */
#ifndef BSP_CFG_SDCLK_OUTPUT
 #define BSP_CFG_SDCLK_OUTPUT          (1)
#endif

/** @} (end defgroup BSP_CONFIG_CLOCKS) */

#endif
