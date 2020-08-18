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

const flash_cfg_t g_flash0_cfg =
{ .data_flash_bgo = false, .p_callback = NULL, .p_context = NULL,
  .irq = ((IRQn_Type) - 33), /*VECTOR_NUMBER_FCU_FRDYI,*/
  .err_irq = (0x00U), /*VECTOR_NUMBER_FCU_FIFERR,*/
  .err_ipl = (0x00U),
  .ipl = (0x05U)/*(0xFFU)*/, };

flash_hp_instance_ctrl_t g_flash0_ctrl =
{
    .opened = 0x4f50454e,
    .p_callback = NULL,
    .p_cfg = &g_flash0_cfg,
    .timeout_write_cf = 0x8094a,
    .timeout_write_df = 0x1eeca,
    .timeout_dbfull = 0x42,
    .timeout_blank_check = 0xaf0,
    .timeout_write_config = 0x9c25f5,
    .timeout_erase_cf_small_block = 0x843e2a,
    .timeout_erase_cf_large_block = 0x210f8aa,
    .timeout_erase_df_block = 0x927c0,
    .current_operation = 0x0,
};

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
    flash_result_t blank_check_result = FLASH_RESULT_BLANK;

    if (buffer == NULL) {
        return 0;
    }

    /* Data flash blank check */
    err = (int)R_FLASH_HP_BlankCheck(g_flash0.p_ctrl, (base+offset),64, &blank_check_result);

    /* Validate the blank check result */
    if (FLASH_RESULT_NOT_BLANK == blank_check_result)
    {
        /* Erase Block */
        err = (int)R_FLASH_HP_Erase(g_flash0.p_ctrl, (base+offset), 1);
        err = (int)(R_FLASH_HP_Write(g_flash0.p_ctrl, (uint32_t)buffer, (base+offset), (uint32_t)size));
    }
    if (FLASH_RESULT_BLANK == blank_check_result)
    {
        err = (int)(R_FLASH_HP_Write(g_flash0.p_ctrl, (uint32_t)buffer, (base+offset), (uint32_t)size));
    }
    
    return (!err)/*1*/;
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
    memcpy(buffer, (const void*)(base+offset), size);
    return 1;
}

