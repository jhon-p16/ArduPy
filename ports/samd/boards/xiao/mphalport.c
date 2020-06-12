/**
 * The MIT License (MIT)
 *
 * Author: Baozhu Zuo (baozhu.zuo@gmail.com)
 *
 * Copyright (C) 2019  Seeed Technology Co.,Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "mphalport.h"
#include "hal_init.h"
#include "hal_flash.h"
#include "hpl_pm_base.h"
struct flash_descriptor FLASH_0;

const char grove_help_text[] = "Welcome to MicroPython!\n"
                               "For online help please visit http://micropython.org/help/.\n"
                               "  _____                    _    _____ _             _ _       \n"
                               " / ____|                  | |  / ____| |           | (_)      \n"
                               "| (___   ___  ___  ___  __| | | (___ | |_ _   _  __| |_  ___  \n"
                               " \\___ \\ / _ \\/ _ \\/ _ \\/ _` |  \\___ \\| __| | | |/ _` | |/ _ \\ \n"
                               " ____) |  __/  __/  __/ (_| |  ____) | |_| |_| | (_| | | (_) |\n"
                               "|_____/ \\___|\\___|\\___|\\__,_| |_____/ \\__|\\__,_|\\__,_|_|\\___/ \n"
                               "For further help on a specific object, type help(obj)\n";

#if 0
mp_lexer_t *mp_lexer_new_from_file(const char *filename) {
    mp_raise_OSError(MP_ENOENT);
}
#endif

#include "py/obj.h"
#include "py/mpstate.h"

int32_t board_flash_write(const volatile void *flash_ptr, const void *data, uint32_t size)
{
    int32_t error_code;
    error_code = flash_erase(&FLASH_0,
                             flash_ptr,
                             FILESYSTEM_BLOCK_SIZE / flash_get_page_size(&FLASH_0));
    if (error_code != 0)
    {
        return error_code;
    }

    error_code = flash_append(&FLASH_0, flash_ptr, data, FILESYSTEM_BLOCK_SIZE);

    return error_code;
}

int32_t board_flash_read(const volatile void *flash_ptr, void *data, uint32_t size)
{
    int32_t error_code = flash_read(&FLASH_0, flash_ptr, data, size);
    return error_code;
}
void board_flash_init()
{
    _pm_enable_bus_clock(PM_BUS_APBB, NVMCTRL);
    flash_init(&FLASH_0, NVMCTRL);
}
void board_flash_flush()
{
    return;
}

uint32_t get_fattime(void)
{
    // TODO: Implement this function. For now, fake it.
    return ((2016 - 1980) << 25) | ((12) << 21) | ((4) << 16) | ((00) << 11) | ((18) << 5) | (23 / 2);
}

uint32_t mp_hal_ticks_ms(void) { return millis(); }
uint32_t mp_hal_ticks_us(void) { return micros(); }
uint32_t mp_hal_ticks_cpu(void) { return millis(); }

void mp_hal_delay_ms(mp_uint_t ms)
{
    delay(ms);
}

void mp_hal_delay_us(mp_uint_t us)
{
    delayMicroseconds(us);
}