#include "bsp_api.h"
#include "r_flash_api.h"

typedef enum e_flash_bgo_operation
{
    FLASH_OPERATION_NON_BGO,
    FLASH_OPERATION_DF_BGO_WRITE,
    FLASH_OPERATION_DF_BGO_ERASE,
    FLASH_OPERATION_DF_BGO_BLANKCHECK,
} flash_bgo_operation_t;


typedef struct st_flash_hp_instance_ctrl
{
    uint32_t              opened;      ///< To check whether api has been opened or not.
    flash_cfg_t const   * p_cfg;
    uint32_t              timeout_write_cf;
    uint32_t              timeout_write_df;
    uint32_t              timeout_dbfull;
    uint32_t              timeout_blank_check;
    uint32_t              timeout_write_config;
    uint32_t              timeout_erase_cf_small_block;
    uint32_t              timeout_erase_cf_large_block;
    uint32_t              timeout_erase_df_block;
    uint32_t              source_start_address;
    uint32_t              dest_end_address;
    uint32_t              operations_remaining;
    flash_bgo_operation_t current_operation;      ///< Operation in progress, for example, FLASH_OPERATION_CF_ERASE

    void (* p_callback)(flash_callback_args_t *); // Pointer to callback
    flash_callback_args_t * p_callback_memory;    // Pointer to optional callback argument memory
    void const            * p_context;            // Pointer to context to be passed into callback function
} flash_hp_instance_ctrl_t;

// extern const flash_api_t g_flash_on_flash_hp;

#define FSP_GUARD_g_flash2_R_FLASH_HP_Open() g_flash2_open_guard(FSP_SECURE_ARGUMENT, FSP_SECURE_ARGUMENT)

#define FSP_GUARD_g_flash2_R_FLASH_HP_Write(src_address, flash_address, num_bytes) g_flash2_write_guard(FSP_SECURE_ARGUMENT, src_address, flash_address, num_bytes)

#define FSP_GUARD_g_flash2_R_FLASH_HP_Erase(address, num_blocks) g_flash2_erase_guard(FSP_SECURE_ARGUMENT, address, num_blocks)

#define FSP_GUARD_g_flash2_R_FLASH_HP_BlankCheck(address, num_bytes, p_blank_check_result) g_flash2_blank_check_guard(FSP_SECURE_ARGUMENT, address, num_bytes, p_blank_check_result)

#define FSP_GUARD_g_flash2_R_FLASH_HP_Close() g_flash2_close_guard(FSP_SECURE_ARGUMENT)

#define FSP_GUARD_g_flash2_R_FLASH_HP_StatusGet(p_status) g_flash2_status_get_guard(FSP_SECURE_ARGUMENT, p_status)

#define FSP_GUARD_g_flash2_R_FLASH_HP_AccessWindowSet(start_addr, end_addr) g_flash2_access_window_set_guard(FSP_SECURE_ARGUMENT, start_addr, end_addr)

#define FSP_GUARD_g_flash2_R_FLASH_HP_AccessWindowClear() g_flash2_access_window_clear_guard(FSP_SECURE_ARGUMENT)

#define FSP_GUARD_g_flash2_R_FLASH_HP_IdCodeSet(p_id_code, mode) g_flash2_id_code_set_guard(FSP_SECURE_ARGUMENT, p_id_code, mode)

#define FSP_GUARD_g_flash2_R_FLASH_HP_Reset() g_flash2_reset_guard(FSP_SECURE_ARGUMENT)

#define FSP_GUARD_g_flash2_R_FLASH_HP_UpdateFlashClockFreq() g_flash2_update_flash_clock_freq_guard(FSP_SECURE_ARGUMENT)

#define FSP_GUARD_g_flash2_R_FLASH_HP_StartUpAreaSelect(swap_type, is_temporary) g_flash2_start_up_area_select_guard(FSP_SECURE_ARGUMENT, swap_type, is_temporary)

#define FSP_GUARD_g_flash2_R_FLASH_HP_CallbackSet(p_callback, p_context, p_callback_memory) g_flash2_callback_set_guard(FSP_SECURE_ARGUMENT, p_callback, p_context, p_callback_memory)

#define FSP_GUARD_g_flash2_R_FLASH_HP_BankSwap() g_flash2_bank_swap_guard(FSP_SECURE_ARGUMENT)

#define FSP_GUARD_g_flash2_R_FLASH_HP_InfoGet(p_info) g_flash2_info_get_guard(FSP_SECURE_ARGUMENT, p_info)

#define FSP_GUARD_g_flash2_R_FLASH_HP_Read(dest_address, flash_address, num_bytes) g_flash2_read_guard(dest_address, flash_address, num_bytes)

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_flash2_open_guard(flash_ctrl_t *const p_api_ctrl, flash_cfg_t const *const p_cfg);

 fsp_err_t g_flash2_write_guard(flash_ctrl_t *const p_api_ctrl, uint32_t const src_address,
        uint32_t flash_address, uint32_t const num_bytes);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_flash2_erase_guard(flash_ctrl_t *const p_api_ctrl, uint32_t const address,
        uint32_t const num_blocks);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_flash2_blank_check_guard(flash_ctrl_t *const p_api_ctrl, uint32_t const address,
        uint32_t num_bytes, flash_result_t *p_blank_check_result);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_flash2_close_guard(flash_ctrl_t *const p_api_ctrl);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_flash2_status_get_guard(flash_ctrl_t *const p_api_ctrl,
        flash_status_t *const p_status);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_flash2_access_window_set_guard(flash_ctrl_t *const p_api_ctrl,
        uint32_t const start_addr, uint32_t const end_addr);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_flash2_access_window_clear_guard(flash_ctrl_t *const p_api_ctrl);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_flash2_id_code_set_guard(flash_ctrl_t *const p_api_ctrl,
        uint8_t const *const p_id_code, flash_id_code_mode_t mode);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_flash2_reset_guard(flash_ctrl_t *const p_api_ctrl);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_flash2_update_flash_clock_freq_guard(flash_ctrl_t *const p_api_ctrl);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_flash2_start_up_area_select_guard(flash_ctrl_t *const p_api_ctrl,
        flash_startup_area_swap_t swap_type, bool is_temporary);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_flash2_callback_set_guard(flash_ctrl_t *const p_api_ctrl,
        void (*p_callback)(flash_callback_args_t*), void const *const p_context,
        flash_callback_args_t *const p_callback_memory);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_flash2_bank_swap_guard(flash_ctrl_t *const p_api_ctrl);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_flash2_info_get_guard(flash_ctrl_t *const p_api_ctrl, flash_info_t *const p_info);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_flash2_read_guard(uint32_t dest_address, uint32_t const flash_address, uint32_t const num_bytes);
