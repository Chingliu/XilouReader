/**
 * Copyright (C) 2023 chingliu.  All rights reserved.
 *
 * @file		xilou_view.h
 * @author		余清留(chingliu)
 * @date		2023-5-01
 * @brief		PDF/OFD双版式，库/文档/页相关接口
 */
#ifndef XILOU_PUBLIC_XILOU_VIEW_H_
#define XILOU_PUBLIC_XILOU_VIEW_H_


#include <stddef.h>

#if defined(_WIN32) && !defined(__WINDOWS__)
#include <windows.h>
#endif

#if defined(COMPONENT_BUILD)
#if defined(WIN32)
#if defined(FPDF_IMPLEMENTATION)
#define XILOU_EXPORT __declspec(dllexport)
#else
#define XILOU_EXPORT __declspec(dllimport)
#endif  // defined(FPDF_IMPLEMENTATION)
#else
#if defined(FPDF_IMPLEMENTATION)
#define XILOU_EXPORT __attribute__((visibility("default")))
#else
#define XILOU_EXPORT
#endif  // defined(FPDF_IMPLEMENTATION)
#endif  // defined(WIN32)
#else
#define XILOU_EXPORT
#endif  // defined(COMPONENT_BUILD)

#if defined(WIN32) && defined(FPDFSDK_EXPORTS)
#define XILOU_CALLCONV __stdcall
#else
#define XILOU_CALLCONV
#endif


typedef struct xilou_package_t__* XILOU_PACKAGE;
typedef struct xilou_document_t__* XILOU_DOCUMENT;
typedef struct xilou_page_t__* XILOU_PAGE;

typedef struct fpdf_bitmap_t__* FPDF_BITMAP;
typedef FPDF_BITMAP XILOU_BITMAP;

    //see FPDF_STRING
typedef const char* XILOU_STRING;
//see FPDF_BYTESTRING
typedef const char* XILOU_BYTESTRING;

typedef const char* XILOU_UTF8STRING;

// Exported Functions
#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////////////////////////////
/// @brief		<tt><b>库初始化</b></tt>
/// @param[in]	
/// @param[out]	
/// @param[in]	
/// @return		
/// @since		
/// @author		chingliu
/// @note  
XILOU_EXPORT void XILOU_CALLCONV xilou_InitLibrary();

/////////////////////////////////////////////////////////////////////////////////////
/// @brief		<tt><b>库释放</b></tt>
/// @param[in]
/// @param[out]
/// @param[in]
/// @return
/// @since
/// @author		chingliu
/// @note
XILOU_EXPORT void XILOU_CALLCONV xilou_DestroyLibrary();

/////////////////////////////////////////////////////////////////////////////////////
/// @brief		<tt><b>载入文件</b></tt>
/// @param[in] file_path  文件路径，UTF8编码
/// @param[out] XILOU_PACKAGE 句柄
/// @return
/// @since
/// @author		chingliu
/// @note
XILOU_EXPORT XILOU_PACKAGE XILOU_CALLCONV
xilou_OpenPackage(XILOU_UTF8STRING file_path, XILOU_BYTESTRING password);
XILOU_EXPORT void XILOU_CALLCONV xilou_ClosePackage(XILOU_PACKAGE package);
/////////////////////////////////////////////////////////////////////////////////////
/// @brief		<tt><b>打开包内指定文档</b></tt>
/// @param[in] package xilou_OpenPackage返回的包句柄。
/// @param[in] index 文档索引，从零开始。
/// @param[out] XILOU_DOCUMENT 文件句柄
/// @return
/// @since
/// @author		chingliu
/// @note
XILOU_EXPORT XILOU_DOCUMENT XILOU_CALLCONV
xilou_LoadDocument(XILOU_PACKAGE package, int index);
XILOU_EXPORT void XILOU_CALLCONV xilou_DropDocument(XILOU_DOCUMENT document);

/////////////////////////////////////////////////////////////////////////////////////
/// @brief		<tt><b>获取页面总数</b></tt>
/// @param[in] document 文档句柄。
/// @param[out]  页面数量
/// @return
/// @since
/// @author		chingliu
/// @note
XILOU_EXPORT int XILOU_CALLCONV xilou_GetPageCount(XILOU_DOCUMENT document);
/////////////////////////////////////////////////////////////////////////////////////
/// @brief		<tt><b>载入指定页</b></tt>
/// @param[in] document 文档句柄。
/// @param[in] index 页面索引，从零开始。
/// @param[out] XILOU_PAGE 页面句柄
/// @return
/// @since
/// @author		chingliu
/// @note
XILOU_EXPORT XILOU_PAGE XILOU_CALLCONV xilou_LoadPage(XILOU_DOCUMENT document,
                                                  int page_index);
XILOU_EXPORT void XILOU_CALLCONV xilou_DropPage(XILOU_PAGE page);

/////////////////////////////////////////////////////////////////////////////////////
/// @brief		<tt><b>获取页面宽</b></tt>
/// @param[in] page 页面句柄。
/// @param[out] 页面宽
/// @return
/// @since
/// @author		chingliu
/// @note Page width (excluding non-displayable area) measured in points。 One point is 1/72 inch (around 0.3528 mm).
XILOU_EXPORT double XILOU_CALLCONV xilou_GetPageWidth(XILOU_PAGE page);
/////////////////////////////////////////////////////////////////////////////////////
/// @brief		<tt><b>获取页面高</b></tt>
/// @param[in] page 页面句柄。
/// @param[out] 页面高
/// @return
/// @since
/// @author		chingliu
/// @note Page height (excluding non-displayable area) measured in points。 One
/// point is 1/72 inch (around 0.3528 mm).
XILOU_EXPORT double XILOU_CALLCONV xilou_GetPageHeight(XILOU_PAGE page);



/////////////////////////////////////////////////////////////////////////////////////
/// @brief		<tt><b>获取页面高</b></tt>
/// @param[in] 参数详解见FPDF_RenderPageBitmap，与FPDF_RenderPageBitmap参数相同。
/// @param[out] 
/// @return
/// @since
/// @author		chingliu
XILOU_EXPORT void XILOU_CALLCONV xilou_RenderPageBitmap(XILOU_BITMAP bitmap,
                                                        XILOU_PAGE page,
                                                     int start_x,
                                                     int start_y,
                                                     int size_x,
                                                     int size_y,
                                                     int rotate,
                                                     int flags);

#ifdef __cplusplus
}
#endif

#endif