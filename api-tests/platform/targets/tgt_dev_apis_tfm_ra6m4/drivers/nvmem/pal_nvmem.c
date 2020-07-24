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

#include "pal_nvmem.h"

flash_hp_instance_ctrl_t g_flash0_ctrl;

const flash_cfg_t g_flash0_cfg =
{ .data_flash_bgo = false, .p_callback = NULL, .p_context = NULL,
  .irq = ((IRQn_Type) - 33), /*VECTOR_NUMBER_FCU_FRDYI,*/
  .err_irq = ((IRQn_Type) - 33), /*VECTOR_NUMBER_FCU_FIFERR,*/
  .err_ipl = (0xFFU),
  .ipl = (0xFFU), };

/* Instance structure to use this module. */
const flash_instance_t g_flash0 =
{ .p_ctrl = &g_flash0_ctrl, .p_cfg = &g_flash0_cfg, .p_api = &g_flash_on_flash_hp };

/**
    @brief    - Writes into given non-volatile address.
    @param    - base    : Base address of non-volatile memory
                offset  : Offset
                buffer  : Pointer to source address
                size    : Number of bytes
    @return   - 1/0
**/
int nvmem_ra6m4_write(addr_t base, uint32_t offset, void *buffer, int size)
{
    int err;

    if (buffer == NULL) {
        return 0;
    }

    err = (int)(R_FLASH_HP_Write(g_flash0.p_ctrl, (uint32_t)buffer, (base+offset), (uint32_t)size));

    return err/*1*/;
}

/**
    @brief    - Reads from given non-volatile address.
    @param    - base    : Base address of non-volatile memory
                offset  : Offset
                buffer  : Pointer to source address
                size    : Number of bytes
    @return   - 1/0
**/
int nvmem_ra6m4_read(addr_t base, uint32_t offset, void *buffer, int size)
{

    if (buffer == NULL) {
        return 0;
    }
    memcpy(buffer, (uint8_t *)(base+offset), size);
    return 1;
}

