/*
 * Copyright (c) 2012, 2013 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _MTP_MEDIA_INFO_H_
#define _MTP_MEDIA_INFO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <glib.h>
#include "mtp_config.h"
#include "mtp_datatype.h"

#define MEDIA_PATH_COND			"MEDIA_PATH="
#define MEDIA_PATH_COND_LEN		13	/* MEDIA_PATH="" */
#define MEDIA_PATH_COND_OR		" OR "
#define MEDIA_PATH_COND_OR_LEN		4
#define MEDIA_PATH_COND_MAX_LEN		MEDIA_PATH_COND_LEN + MTP_MAX_PATHNAME_SIZE

#define MTP_PAL_SAFE_FREE(src)	{ g_free(src); src = NULL; }

/*
 * struct MtpCommonMetadata
 * This structure contains common metadata fields between
 * video and audio files.
 */
typedef struct {
	mtp_char *artist;		/* A pointer to Artist */
	mtp_char *album;		/* A pointer to Album name. */
	mtp_char *genre;		/* A pointer to Genre */
	mtp_char *author;		/* A pointer to Author name */
	mtp_char *copyright;		/* A pointer to Copyright info */
	mtp_char *year;			/* A pointer to release year */
	mtp_char *description;		/* A pointer to description */
	mtp_int32 duration;		/* Duration of the track */
	mtp_int32 audio_bitrate;	/* Audio bitrate */
	mtp_int32 sample_rate;
	mtp_int32 num_channel;
	mtp_int32 audio_codec;
	mtp_int32 rating;
} common_meta_t;

typedef struct {
	mtp_int32 video_fps;
	mtp_int32 video_br;
	mtp_int32 video_h;
	mtp_int32 video_w;
	mtp_char *track;
} video_meta_t;

typedef struct {
	mtp_int32 track;
} audio_meta_t;

typedef struct {
	mtp_int32 ht;
	mtp_int32 wt;
} image_meta_t;

typedef struct {
	common_meta_t commonmeta;
	audio_meta_t audiometa;
} comp_audio_meta_t;

typedef struct {
	common_meta_t commonmeta;
	video_meta_t videometa;
} comp_video_meta_t;

typedef struct {
	void *data;
	mtp_int32 count;
	guint tid;
	pthread_mutex_t *lock;
} timeout_data_t;

void _util_flush_db(void);

#ifdef __cplusplus
}
#endif

#endif /* _MTP_MEDIA_INFO_H_ */
