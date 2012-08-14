/* -*- mode: c; c-file-style: "openbsd" -*- */
/*
 * Copyright (c) 2012 Vincent Bernat <bernat@luffy.cx>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _LOG_H
#define _LOG_H

/* log.c */
void             log_init(int, const char *);
void             log_warn(const char *, ...) __attribute__ ((format (printf, 1, 2)));
#define LLOG_WARN(x,...) log_warn("%s: " x, __FUNCTION__ , ## __VA_ARGS__)
void             log_warnx(const char *, ...) __attribute__ ((format (printf, 1, 2)));
#define LLOG_WARNX(x,...) log_warnx("%s: " x,  __FUNCTION__ , ## __VA_ARGS__)
void             log_info(const char *, ...) __attribute__ ((format (printf, 1, 2)));
#define LLOG_INFO(x,...) log_info("%s: " x, __FUNCTION__ , ## __VA_ARGS__)
void             log_debug(const char *, ...) __attribute__ ((format (printf, 1, 2)));
#define LLOG_DEBUG(x,...) log_debug("%s: " x, __FUNCTION__ , ## __VA_ARGS__)
void             fatal(const char *);
void             fatalx(const char *);

void		 log_register(void (*cb)(int, const char*));

#endif
