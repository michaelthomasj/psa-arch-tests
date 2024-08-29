/** @file
 * Copyright (c) 2018-2020, Arm Limited or its affiliates. All rights reserved.
 * SPDX-License-Identifier : Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
**/
#include "pal_uart.h"

#ifndef ARG_UNUSED
#define ARG_UNUSED(arg)  (void)arg
#endif

static volatile uint8_t tx_data_empty_test = 1;
static volatile uint8_t tx_irq_triggered_test = 0;
static volatile uint8_t tx_irq_generate_test = 0;

extern void call_spm_handle_interrupt(void);

 /* Instance structure to use this module. */
sci_uart_instance_ctrl_t g_uart0_ctrl;

baud_setting_t g_uart0_baud_setting =
        {
        /* Baud rate calculated with 0.469% error. */.semr_baudrate_bits_b.abcse = 0,
          .semr_baudrate_bits_b.abcs = 0, .semr_baudrate_bits_b.bgdm = 1, .cks = 1, .brr = 161, .mddr = (uint8_t) 256, .semr_baudrate_bits_b.brme =
                  false };

/** UART extended configuration for UARTonSCI HAL driver */
const sci_uart_extended_cfg_t g_uart0_cfg_extend =
{ .clock = SCI_UART_CLOCK_INT, .rx_edge_start = SCI_UART_START_BIT_FALLING_EDGE, .noise_cancel =
          SCI_UART_NOISE_CANCELLATION_DISABLE,
  .rx_fifo_trigger = SCI_UART_RX_FIFO_TRIGGER_MAX, .p_baud_setting = &g_uart0_baud_setting, .flow_control =
          SCI_UART_FLOW_CONTROL_RTS,
  .flow_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
  .rs485_setting =
  { .enable = SCI_UART_RS485_DISABLE, .polarity = SCI_UART_RS485_DE_POLARITY_HIGH,
    .de_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
          },
  .irda_setting =
  { .ircr_bits_b.ire = 0, .ircr_bits_b.irrxinv = 0, .ircr_bits_b.irtxinv = 0, }, };

/** UART interface configuration */
const uart_cfg_t g_uart0_cfg =
{ .channel = 0, .data_bits = UART_DATA_BITS_8, .parity = UART_PARITY_OFF, .stop_bits = UART_STOP_BITS_1, .p_callback =
          user_uart_callback,
  .p_context = NULL, .p_extend = &g_uart0_cfg_extend,
  .p_transfer_tx = NULL,
  .p_transfer_rx = NULL,
  .rxi_ipl = (12),
  .txi_ipl = (12), .tei_ipl = (12), .eri_ipl = (12),
                .rxi_irq             = VECTOR_NUMBER_SCI0_RXI,
                .txi_irq             = VECTOR_NUMBER_SCI0_TXI,
                .tei_irq             = VECTOR_NUMBER_SCI0_TEI,
                .eri_irq             = VECTOR_NUMBER_SCI0_ERI,
        };

/* Instance structure to use this module. */
const uart_instance_t g_uart0 =
{ .p_ctrl = &g_uart0_ctrl, .p_cfg = &g_uart0_cfg, .p_api = &g_uart_on_sci };

/**
    @brief    - This function initializes the UART
**/

void pal_uart_ra6m4_init(uint32_t uart_base_addr)
{
	ARG_UNUSED(uart_base_addr);
    R_SCI_UART_Open(g_uart0.p_ctrl, g_uart0.p_cfg);

}

/**
    @brief    - This function checks for empty TX FIFO
**/
static int pal_uart_ra6m4_is_tx_empty(void)
{
    /* Note: Check for empty TX FIFO */
    return ((tx_data_empty_test));
}

/**
    @brief    - This function checks for empty TX FIFO and writes to FIFO register
**/
void pal_uart_ra6m4_putc(uint8_t c)
{
    uint32_t bytes = 1U;
    
    /* ensure TX buffer to be empty */
    /* write the data (upper 24 bits are reserved) */
    while (!pal_uart_ra6m4_is_tx_empty());
    tx_data_empty_test = 0U;

    R_SCI_UART_Write(g_uart0.p_ctrl, &c, bytes);
	
}

/**
    @brief    - This function parses the input string and writes bytes into UART TX FIFO
    @param    - str      : Input String
              - data     : Value for format specifier
**/
void pal_ra6m4_print(const char *str, int32_t data)
{
    uint8_t j, buffer[16];
    int8_t  i = 0, is_neg = 0, k = 2 * sizeof(data);

    for (; *str != '\0'; ++str)
    {
        if (*str == '%')
        {
            ++str;
            if (*str == 'd')
            {
                if (data < 0)
                {
                    data = -(data);
                    is_neg = 1;
                }

                while (data != 0)
                {
                    j         = data % 10;
                    data      = data /10;
                    buffer[i] = j + 48;
                    i        += 1;
                }

                if (is_neg)
                    buffer[i++] = '-';
            }
            else if (*str == 'x' || *str == 'X')
            {
                while (k--)
                {
                    j         = data & 0xf;
                    data    >>= 4;
                    buffer[i] = j + ((j > 9) ? 55 : 48);
                    i        += 1;
                }
            }
            if (i > 0)
            {
                while (i > 0) 
				{
                    pal_uart_ra6m4_putc(buffer[--i]);
                }
            }
            else
            {
                pal_uart_ra6m4_putc(48);
            }
        }
        else
        {
            pal_uart_ra6m4_putc(*str);
            if (*str == '\n')
            {
                pal_uart_ra6m4_putc('\r');
            }
        }
    }
}

/**
    @brief    - This function checks for TX interrupt triggered or not
**/
static int pal_uart_ra6m4_is_tx_irq_triggerd(void)
{
    return tx_irq_triggered_test;
}

/**
    @brief    - This function triggers the UART TX interrupt
**/
void pal_uart_ra6m4_generate_irq(void)
{
    tx_irq_generate_test = 1;
    /* Fill the TX buffer to generate TX IRQ */
    pal_uart_ra6m4_putc(' ');
    pal_uart_ra6m4_putc(' ');

    /* Loop until TX interrupt trigger */
    while (!pal_uart_ra6m4_is_tx_irq_triggerd());
}

/**
    @brief    - This function disable the UART TX interrupt
**/
void pal_uart_ra6m4_disable_irq(void)
{

}

void user_uart_callback(uart_callback_args_t *p_args)
{
    if(p_args->event == UART_EVENT_TX_DATA_EMPTY)
    {
       tx_data_empty_test = 1U;
    }
    if(p_args->event == UART_EVENT_TX_COMPLETE)
    {
       tx_data_empty_test = 1U;
       if(tx_irq_generate_test == 1)
       {
        call_spm_handle_interrupt();
        tx_irq_generate_test = 0;
        tx_irq_triggered_test = 1U;
       }
    }
}
