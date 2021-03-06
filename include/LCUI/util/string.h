﻿/* ***************************************************************************
 * string.h -- The string operation set.
 *
 * Copyright (C) 2015-2016 by Liu Chao <lc-soft@live.cn>
 *
 * This file is part of the LCUI project, and may only be used, modified, and
 * distributed under the terms of the GPLv2.
 *
 * (GPLv2 is abbreviation of GNU General Public License Version 2)
 *
 * By continuing to use, modify, or distribute this file you indicate that you
 * have read the license and understand and accept it fully.
 *
 * The LCUI project is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GPL v2 for more details.
 *
 * You should have received a copy of the GPLv2 along with this file. It is
 * usually in the LICENSE.TXT file, If not, see <http://www.gnu.org/licenses/>.
 * ****************************************************************************/

/* ****************************************************************************
 * string.h -- 字符串相关操作函数。
 *
 * 版权所有 (C) 2015-2016 归属于 刘超 <lc-soft@live.cn>
 *
 * 这个文件是LCUI项目的一部分，并且只可以根据GPLv2许可协议来使用、更改和发布。
 *
 * (GPLv2 是 GNU通用公共许可证第二版 的英文缩写)
 *
 * 继续使用、修改或发布本文件，表明您已经阅读并完全理解和接受这个许可协议。
 *
 * LCUI 项目是基于使用目的而加以散布的，但不负任何担保责任，甚至没有适销性或特
 * 定用途的隐含担保，详情请参照GPLv2许可协议。
 *
 * 您应已收到附随于本文件的GPLv2许可协议的副本，它通常在LICENSE.TXT文件中，如果
 * 没有，请查看：<http://www.gnu.org/licenses/>.
 * ****************************************************************************/

#ifndef LCUI_UTIL_STRING_H
#define LCUI_UTIL_STRING_H

#ifdef LCUI_BUILD_IN_WIN32
#include <tchar.h>
#define strcasecmp _stricmp
#else
#ifdef _UNICODE
#define __T(x) L ## x
#define _T(x) __T(x)
#else
#define __T(x) x
#define _T(x) __T(x)
#endif
#endif

#ifndef _TCHAR_DEFINED
#if     !__STDC__
typedef char TCHAR;
#endif
#define _TCHAR_DEFINED
#endif

LCUI_BEGIN_HEADER

/**
 * 清除字符串首尾的字符
 * @param[out] outstr 处理后的字符串
 * @param[in] instr 需要处理的字符串
 * @param[in] charlist 需要清除的字符列表，当为NULL时，默认清除空白符
 * @return 处理后的字符串的长度
 */
LCUI_API int strtrim( char *outstr, const char *instr, const char *charlist );

/**
* 分割命令行字符串
* @param[in] cmd 需分割的命令行字符串
* @param[out] outargv 分割后的命令行参数列表
* @return 参数数量
*/
LCUI_API int cmdsplit( const char *cmd, char ***outargv );

/**
 * 分割字符串
 * @param[in] instr 需分割的字符串
 * @param[in] sep 分割标记字符串
 * @param[out] outstrs 分割后的字符串列表
 */
LCUI_API int strsplit( const char *instr, const char *sep, char ***outstrs );


/**
 * 向字符串组添加字符串
 * @param[in][out] strlist 字符串组
 * @param[in] str 字符串
 */
LCUI_API int strsadd( char ***strlist, const char *str );

/**
 * 判断字符串组中是否包含指定字符串
 * @param[in][out] strlist 字符串组
 * @param[in] str 字符串
 * @returns 如果包含则返回 1， 否则返回 0
 */
LCUI_API int strshas( char **strlist, const char *str );

/**
 * 从字符串组中删除指定字符串
 * @param[in][out] strlist 字符串组
 * @param[in] str 字符串
 * @returns 如果删除成功则返回 1， 否则返回 0
 */
LCUI_API int strsdel( char ***strlist, const char *str );

/**
 * 向已排序的字符串组添加字符串
 * @param[in][out] strlist 字符串组
 * @param[in] str 字符串
 */
LCUI_API int sortedstrsadd( char ***strlist, const char *str );

/** 释放字符串组 */
LCUI_API void freestrs( char **strs );

LCUI_END_HEADER

#endif
