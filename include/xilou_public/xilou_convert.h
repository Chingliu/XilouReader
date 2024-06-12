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
/// @return 0成功，其它错误
/// @since
/// @author		chingliu
/// @note  pkg需要关闭 xilou_ClosePackage，目前 pkg只能限定在pdf格式，ofd格式未实现
XILOU_EXPORT int XILOU_CALLCONV
xilou_AppendImagePage(XILOU_PACKAGE* pkg, XILOU_UTF8STRING img_path);

/////////////////////////////////////////////////////////////////////////////////////
/// @brief		<tt><b>将pkg保存到dst_path指定的路径上</b></tt>
/// @param[in] pkg 可以是xilout_openpackage,或xilou_AppendImagePage生成的pkg
/// @param[dst_path] 目标路径
/// @return 0成功，其它错误
/// @since
/// @author		chingliu
/// @note  实际上此函数是为xilou_AppendImagePage服务，所为目前未实现pkg为ofd的场景，pkg为ofd时保存会失败。
XILOU_EXPORT int XILOU_CALLCONV xilou_Save2File(XILOU_PACKAGE* pkg,
                                                XILOU_UTF8STRING dst_path);

/////////////////////////////////////////////////////////////////////////////////////
/// @brief		<tt><b>将text附加于指定页面上</b></tt>
/// @param[in] pkg 可以是xilout_openpackage,或xilou_AppendImagePage生成的pkg
/// @param[page_idx] 页码，从0开始，
/// @param[txt_json] 一个UTF8编码的json格式的字符串，格式如下：
/// {
///"ocrResult" : [ {
///  "text" : "测试字符串",
///  "location" : {
///    "left" : 89.91585,
///    "top" : 87.620804,
///    "right" : 693.8248,
///    "bottom" : 151.00175
///  },
///  "pos" : {"x" : 90.1736, "y" : 87.620804}
///} ]
///}
/// @return 0成功，其它错误
/// @since
/// @author		chingliu
/// @note
XILOU_EXPORT int XILOU_CALLCONV xilou_AddTextOnPage(XILOU_PACKAGE pkg,
                                                    int page_idx,
                                                    XILOU_UTF8STRING txt_json);


XILOU_EXPORT int XILOU_CALLCONV
xilou_OfdMerge(XILOU_UTF8STRING merge2ofd_path,
               XILOU_UTF8STRING been_merged_ofd_path);
#ifdef __cplusplus
}
#endif

#endif