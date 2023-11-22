﻿/**
 * Copyright (C) 2023 chingliu.  All rights reserved.
 *
 * @file		xilou_signature.h
 * @author		余清留(chingliu)
 * @date		2023-11-22
 * @brief		PDF/OFD签名验签接口
 */

#include "xilou_view.h"


// Exported Functions
#ifdef __cplusplus
extern "C" {
#endif


XILOU_EXPORT unsigned long XILOU_CALLCONV xilou_verify(XILOU_DOCUMENT document,
              int index);

XILOU_EXPORT unsigned long XILOU_CALLCONV
xilou_docsign_count(XILOU_DOCUMENT document);

XILOU_EXPORT size_t XILOU_CALLCONV xilou_sig_errmsg(XILOU_DOCUMENT document,
                                                       int index, unsigned char **errmsg);

#ifdef __cplusplus
}
#endif