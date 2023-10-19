#include "r_flash_api.h"
#include "flash_guards.h"

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

// const flash_api_t g_flash_on_flash_hp =
// {
//     .open                 = g_flash2_open_guard,
//     .close                = g_flash2_close_guard,
//     .write                = g_flash2_write_guard,
//     .erase                = g_flash2_erase_guard,
//     .blankCheck           = g_flash2_blank_check_guard,
//     .statusGet            = FSP_GUARD_g_flash2_R_FLASH_HP_StatusGet,
//     .infoGet              = FSP_GUARD_g_flash2_R_FLASH_HP_InfoGet,
//     .accessWindowSet      = FSP_GUARD_g_flash2_R_FLASH_HP_AccessWindowSet,
//     .accessWindowClear    = FSP_GUARD_g_flash2_R_FLASH_HP_AccessWindowClear,
//     .idCodeSet            = FSP_GUARD_g_flash2_R_FLASH_HP_IdCodeSet,
//     .reset                = FSP_GUARD_g_flash2_R_FLASH_HP_Reset,
//     .startupAreaSelect    = FSP_GUARD_g_flash2_R_FLASH_HP_StartUpAreaSelect,
//     .updateFlashClockFreq = FSP_GUARD_g_flash2_R_FLASH_HP_UpdateFlashClockFreq,
//     .bankSwap             = FSP_GUARD_g_flash2_R_FLASH_HP_BankSwap,
//     .callbackSet          = FSP_GUARD_g_flash2_R_FLASH_HP_CallbackSet,
// };