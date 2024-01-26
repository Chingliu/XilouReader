/**
 * Copyright (C) 2023 chingliu.  All rights reserved.
 *
 * @file		xilou_signature.h
 * @author		余清留(chingliu)
 * @date		2024-01-26
 * @brief		PDF/OFD日志接口
 */
#ifndef XILOU_PUBLIC_XILOU_LOGGER_H_
#define XILOU_PUBLIC_XILOU_LOGGER_H_
#include "xilou_view.h"

/////////////////////////////////////////////////////////////////////////////////////
    /// @brief		<tt><b>设置日志级别，默认不写日志</b></tt>
    /// @param[in] level as below  0-5
    /// @return
    /// @since
    /// @author		chingliu
    /// @note
    /// trace = SPDLOG_LEVEL_TRACE,
    /// debug = SPDLOG_LEVEL_DEBUG, 
    /// info = SPDLOG_LEVEL_INFO,
    /// warn = SPDLOG_LEVEL_WARN,
    /// err = SPDLOG_LEVEL_ERROR,
    /// critical = SPDLOG_LEVEL_CRITICAL,
    XILOU_EXPORT void xiloug_setloglevel(int level);

#endif
