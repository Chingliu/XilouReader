/**
 * Copyright (C) 2023 chingliu.  All rights reserved.
 *
 * @file		xilou_convert.h
 * @author		余清留(chingliu)
 * @date		2023-5-01
 * @brief		PDF/OFD互转接口
 */
#ifndef XILOU_PUBLIC_XILOU_CONVERT_H_
#define XILOU_PUBLIC_XILOU_CONVERT_H_

#include "xilou_view.h"

// Exported Functions
#ifdef __cplusplus
extern "C" {
#endif

XILOU_EXPORT bool XILOU_CALLCONV
xilou_Convert(XILOU_UTF8STRING src_fpath,
              XILOU_UTF8STRING dest_fpath,
              XILOU_UTF8STRING page_range);
/////////////////////////////////////////////////////////////////////////////////////
/// @brief		<tt><b>将图像作为新页面追加到文档中去</b></tt>
/// @param[in/out] pkg  如果*pkg= NULL,会创建新文档，并在pkg中返回新文档句柄，否则追加到指定文档中
/// @param[in] img_path 图像绝对路径，png,jpg
/// @return
/// @since
/// @author		chingliu
/// @note
XILOU_EXPORT int XILOU_CALLCONV
xilou_AppendImagePage(XILOU_PACKAGE* pkg, XILOU_UTF8STRING img_path);

XILOU_EXPORT int XILOU_CALLCONV xilou_Save2File(XILOU_PACKAGE* pkg,
                                                XILOU_UTF8STRING dst_path);

#ifdef __cplusplus
}
#endif

#endif