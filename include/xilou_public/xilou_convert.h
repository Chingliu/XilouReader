/**
 * Copyright (C) 2023 chingliu.  All rights reserved.
 *
 * @file		xilou_convert.h
 * @author		������(chingliu)
 * @date		2023-5-01
 * @brief		PDF/OFD��ת�ӿ�
 */

#include "xilou_view.h"

XILOU_EXPORT bool XILOU_CALLCONV
xilou_Convert(XILOU_UTF8STRING src_fpath,
              XILOU_UTF8STRING dest_fpath,
              XILOU_UTF8STRING page_range);