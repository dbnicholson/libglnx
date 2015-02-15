/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2014,2015 Colin Walters <walters@verbum.org>.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#pragma once

#include <glnx-backport-autoptr.h>
#include <errno.h>

G_BEGIN_DECLS

#define glnx_set_error_from_errno(error)                \
  do {                                                  \
    int errsv = errno;                                  \
    g_set_error_literal (error, G_IO_ERROR,             \
                         g_io_error_from_errno (errsv), \
                         g_strerror (errsv));           \
    errno = errsv;                                      \
  } while (0);

#define glnx_set_prefix_error_from_errno(error, format, args...)            \
  do {                                                                  \
    int errsv = errno;                                                  \
    glnx_real_set_prefix_error_from_errno (error, errsv, format, args); \
    errno = errsv;                                                      \
  } while (0);

void glnx_real_set_prefix_error_from_errno (GError     **error,
                                            gint         errsv,
                                            const char  *format,
                                            ...) G_GNUC_PRINTF (3,4);

G_END_DECLS
