/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Dan Halbert for Adafruit Industries
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

#ifndef MICROPY_INCLUDED_ATMEL_SAMD_COMMON_HAL_UTIL_H
#define MICROPY_INCLUDED_ATMEL_SAMD_COMMON_HAL_UTIL_H

#include "py/obj.h"

#define MP_IOCTL_POLL (0x100 | 1)

// These values are compatible with Linux, which are in turn
// compatible with iBCS2 spec.
#define MP_IOCTL_POLL_RD  (0x0001)
#define MP_IOCTL_POLL_WR  (0x0004)
#define MP_IOCTL_POLL_ERR (0x0008)
#define MP_IOCTL_POLL_HUP (0x0010)


#if MICROPY_PY_BUILTINS_PROPERTY

typedef struct _mp_obj_property_t {
    mp_obj_base_t base;
    mp_obj_t proxy[3]; // getter, setter, deleter
} mp_obj_property_t;

#endif  // MICROPY_PY_BUILTINS_PROPERTY

MP_DECLARE_CONST_FUN_OBJ_1(default___enter___obj);

void raise_error_if_deinited(bool deinited);
NORETURN void mp_raise_RuntimeError(const char *msg);
NORETURN void mp_raise_AttributeError(const char *msg) ;
void normalize_buffer_bounds(int32_t* start, int32_t end, uint32_t* length);
void generic_method_lookup(mp_obj_t obj, qstr attr, mp_obj_t *dest);


#endif // MICROPY_INCLUDED_ATMEL_SAMD_COMMON_HAL_UTIL_H