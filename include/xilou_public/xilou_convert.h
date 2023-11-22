/**
 * Copyright (C) 2023 chingliu.  All rights reserved.
 *
 * @file		xilou_convert.h
 * @author		余清留(chingliu)
 * @date		2023-5-01
 * @brief		PDF/OFD互转接口
 */

#include "xilou_view.h"

// Exported Functions
#ifdef __cplusplus
extern "C" {
#endif

XILOU_EXPORT bool XILOU_CALLCONV
xilou_Convert(XILOU_UTF8STRING src_fpath,
              XILOU_UTF8STRING dest_fpath,
              XILOU_UTF8STRING page_range);


#ifdef __cplusplus
}
#endif