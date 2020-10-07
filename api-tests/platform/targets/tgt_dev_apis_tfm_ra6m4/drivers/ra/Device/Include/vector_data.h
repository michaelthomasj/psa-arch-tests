/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H

/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
 #define VECTOR_DATA_IRQ_COUNT    (0)
#endif

/* ISR prototypes */

/* Vector table allocations */
typedef enum IRQn
{
    Reset_IRQn = -15,
    NonMaskableInt_IRQn = -14,
    HardFault_IRQn = -13,
    MemoryManagement_IRQn = -12,
    BusFault_IRQn = -11,
    UsageFault_IRQn = -10,
    SVCall_IRQn = -5,
    DebugMonitor_IRQn = -4,
    PendSV_IRQn = -2,
    SysTick_IRQn = -1,
    SCI0_RXI_IRQn = 17, /* SCI0 RXI (Receive data full) */
    SCI0_TXI_IRQn = 18, /* SCI0 TXI (Transmit data empty) */
    SCI0_TEI_IRQn = 19, /* SCI0 TEI (Transmit end) */
    SCI0_ERI_IRQn = 20, /* SCI0 ERI (Receive error) */
} IRQn_Type;
#endif                                 /* VECTOR_DATA_H */
