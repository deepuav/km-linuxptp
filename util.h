/**
 * @file util.h
 * @brief Various little utility functions that do not fit in elsewhere.
 * @note Copyright (C) 2011 Richard Cochran <richardcochran@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#ifndef HAVE_UTIL_H
#define HAVE_UTIL_H

#include "ddt.h"

/**
 * Table of human readable strings, one for each port state.
 */
extern char *ps_str[];

/**
 * Table of human readable strings, one for each port event.
 */
extern char *ev_str[];

/**
 * Convert a clock identity into a human readable string.
 *
 * Note that this function uses a static global variable to store the
 * result and therefore is not reentrant.
 *
 * @param id  Clock idendtity to show.
 * @return    Pointer to a static global buffer holding the result.
 */
char *cid2str(struct ClockIdentity *id);

/**
 * Convert a port identity into a human readable string.
 *
 * Note that this function uses a static global variable to store the
 * result and therefore is not reentrant.
 *
 * @param id  Port idendtity to show.
 * @return    Pointer to a static global buffer holding the result.
 */
char *pid2str(struct PortIdentity *id);

int generate_clock_identity(struct ClockIdentity *ci, char *name);

/**
 * Copies a PTPText to a static_ptp_text. This copies the text into
 * the static_ptp_text.
 * @param dst The static_ptp_text to copy to
 * @param src The PTPText to copy from
 * @return Zero on success, -1 if text in src is too long or not valid
 * UTF8
 */
int static_ptp_text_copy(struct static_ptp_text *dst, const struct PTPText *src);

/**
 * Copies a static_ptp_text to a PTPText. Caller must ensure it's
 * valid to write to the memory after the PTPText struct. The trailing
 * \0 is not copied.
 * @param dst The PTPText to copy to
 * @param src The static_ptp_text to copy from
 */
void ptp_text_copy(struct PTPText *dst, const struct static_ptp_text *src);

/**
 * Sets a PTPText from a null-terminated char*. Caller must ensure it's
 * valid to write to the memory after the PTPText struct. The trailing
 * \0 is not copied.
 * @param dst The PTPText to copy to
 * @param src The text to copy from
 * @return Zero on success, -1 if src is too long
 */
int ptp_text_set(struct PTPText *dst, const char *src);

/**
 * Sets a static_ptp_text from a null-terminated char*.
 * @param dst The static_ptp_text to copy to
 * @param src The text to copy from
 * @return Zero on success, -1 if text in src is too long or not valid
 * UTF8
 */
int static_ptp_text_set(struct static_ptp_text *dst, const char *src);

#endif
