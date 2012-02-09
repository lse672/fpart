/*-
 * Copyright (c) 2011 Ganael LAPLANCHE <ganael.laplanche@martymac.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _FILE_MEMORY_H
#define _FILE_MEMORY_H

#if defined(WITH_FILE_MEMORY)

#include "types.h"

/* size_t */
#include <stdlib.h>

#if !defined(FILE_MEMORY_CHUNK_SIZE)
#define FILE_MEMORY_CHUNK_SIZE (32 * 1024 * 1024) /* 32 MB */
#endif
#if !defined(MAX_FILE_MEMORY_CHUNKS)
#define MAX_FILE_MEMORY_CHUNKS 0    /* maximum number of allowed chunks
                                       (0 = unlimited) */
#endif

int init_memory(char *base_path, fnum_t max_chunks);
void uninit_memory();

void *file_malloc(size_t size);     /* simple malloc() */
void file_free(void *ptr);          /* simple free() */

#define fmalloc file_malloc
#define ffree   file_free

#else  /* WITH_FILE_MEMORY undefined */

#define fmalloc malloc
#define ffree   free

#endif /* WITH_FILE_MEMORY */

#endif /* _FILE_MEMORY_H */
