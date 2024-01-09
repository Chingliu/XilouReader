/**
 * Copyright (C) 2023 chingliu.  All rights reserved.
 *
 * @file		xilou_view.h
 * @author		余清留(chingliu)
 * @date		2023-5-01
 * @brief		引擎层错误码定义
 */
#ifndef XILOU_PUBLIC_XILOU_ERROR_CODE_HEADER_H
#define XILOU_PUBLIC_XILOU_ERROR_CODE_HEADER_H



/**
* 成功
*/
#define XILOU_E_SUC  0
/**
 * PDF错误起始号
 */
#define XILOU_E_PDF   20000

/**
 * OFD错误起始号
 */
#define XILOU_E_OFD 40000
/**
 * 无效的signature.xml
 */
#define XILOU_E_OFD_INVALID_SIGNATURE_XML 40001

/**
 * 无效的signature.xml
 */
#define XILOU_E_OFD_OES_LOADER 40002
/**
 * 条目的hash值发生了变化
 */
#define XILOU_E_OFD_ENTRY_HASH 40003

/**
 * 签名值验证失败
 */
#define XILOU_E_OFD_SIGNED_VERIFY_ERROR 40004

/**
 * feature not implement
 */
#define XILOU_E_FEATURE_NOT_IMPLEMENT_ERROR 40005

/**
 * invalid handle
 */
#define XILOU_E_INVALID_HANDLE_ERROR 40006

/**
 * out of range
 */
#define XILOU_E_OUT_OF_RANGE_ERROR 40007

#endif