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

#ifndef _PAL_UART_RA6M4_H_
#define _PAL_UART_RA6M4_H_

#include <stdint.h>
#include "r_sci_uart.h"
#include "r_ioport.h"


void pal_user_uart_callback(uart_callback_args_t *p_args);


/* function prototypes */
void pal_uart_ra6m4_init(uint32_t uart_base_addr);
void pal_ra6m4_print(const char *str, int32_t data);
void pal_uart_ra6m4_generate_irq(void);
void pal_uart_ra6m4_disable_irq(void);

#endif /* _PAL_UART_RA6M4_H_ */
