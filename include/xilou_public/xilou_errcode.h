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
 * 未实现功能
 */
#define XILOU_E_NOTIMPLEMENT 1

/**
 * 图像解析错误
 */
#define XILOU_E_LOADIMAGE 10000

/**
 * 错误的文档句柄类型
 */
#define XILOU_E_FILEHANDLETYPE 10001

/**
 * 生成新对象错误
 */
#define XILOU_E_NEWPAGEOBJECT 10002

/**
 * 设置BITMAP错误
 */
#define XILOU_E_SETBITMAP 10003

/**
 * 构建新页面错误
 */
#define XILOU_E_NEWPAGE 10004

/**
 * 无效的参数
 */
#define XILOU_E_INVALIDPARAMETER 10005

/**
 * 页码错误
 */
#define XILOU_E_INVALIDPAGEINDEX 10006

/**
 * 附加文字的json格式错误
 */
#define XILOU_E_INVALIDTEXTJSON 10007

/**
 * LoadPage错误
 */
#define XILOU_E_LOADPAGE 10008
/**
 * PDF错误起始号
 */
#define XILOU_E_PDF   20000

/**
 * PDF转OFD错误
 */
#define XILOU_E_PDF2OFD 20001

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