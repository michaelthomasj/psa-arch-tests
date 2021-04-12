/** @file
 * Copyright (c) 2018-2019, Arm Limited or its affiliates. All rights reserved.
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
#include "platform_base_address.h"
#include "G:\TFM\peaks\ra\arm\trusted-firmware-m\platform\ext\driver\Driver_USART.h"
extern ARM_DRIVER_USART Driver_USART1;
extern ARM_DRIVER_USART Driver_USART_IRQ;

volatile uint8_t tx_irq_triggered = 0;
volatile uint8_t tx_irq_triggered_irq = 0;

/**
    @brief    - This function initializes the UART
**/

void pal_uart_ra6m4_init(uint32_t uart_base_addr)
{
    (void)(uart_base_addr);
	Driver_USART1.Initialize(NULL);
    Driver_USART_IRQ.Initialize(NULL);

}

/**
    @brief    - This function checks for empty TX FIFO and writes to FIFO register
**/
static void pal_uart_ra6m4_putc(const uint8_t c)
{
    uint32_t bytes = 1U;
    
    Driver_USART1.Send(&c, bytes);

    if (c == '\n')
    {
        pal_uart_ra6m4_putc('\r');
    }
}

/**
    @brief    - This function parses the input string and writes bytes into UART TX FIFO
    @param    - str      : Input String
              - data     : Value for format specifier
**/
void pal_ra6m4_print(const char *str, int32_t data)
{
    int8_t  j, buffer[16];
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
                while (i > 0) {
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
        }
    }
}

/**
    @brief    - This function checks for TX interrupt triggered or not
**/
static int pal_uart_ra6m4_is_tx_irq_triggerd(void)
{
    return tx_irq_triggered_irq;
}

/**
    @brief    - This function triggers the UART TX interrupt
**/
void pal_uart_ra6m4_generate_irq(void)
{
    /* Fill the TX buffer to generate TX IRQ */
    uint8_t cr = ('c');
    uint32_t bytes = 1U;

    Driver_USART_IRQ.Send(&cr, bytes);
    /* Loop until TX interrupt trigger */
    while (!pal_uart_ra6m4_is_tx_irq_triggerd());
}

/**
    @brief    - This function disable the UART TX interrupt
**/
void pal_uart_ra6m4_disable_irq(void)
{
	tx_irq_triggered_irq = 0;
}

