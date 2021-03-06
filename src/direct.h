/*
 * Copyright 2010-2011 Red Hat, Inc.
 *
 * This copyrighted material is made available to anyone wishing to use,
 * modify, copy, or redistribute it subject to the terms and conditions
 * of the GNU General Public License v2 or (at your option) any later version.
 */

#ifndef __DIRECT_H__
#define __DIRECT_H__

int direct_acquire(struct task *task, int io_timeout,
                   struct sanlk_resource *res,
                   int num_hosts,
                   uint64_t local_host_id,
                   uint64_t local_host_generation,
                   struct leader_record *leader_ret);

int direct_release(struct task *task, int io_timeout,
                   struct sanlk_resource *res,
                   struct leader_record *leader_ret);

int direct_acquire_id(struct task *task, int io_timeout,
		      struct sanlk_lockspace *ls,
		      char *our_host_name);

int direct_release_id(struct task *task, int io_timeout,
		      struct sanlk_lockspace *ls);

int direct_renew_id(struct task *task, int io_timeout,
		    struct sanlk_lockspace *ls);

int direct_align(struct sync_disk *disk);

/* io_timeout is written in the leader record and used for the
   write call itself */
int direct_write_lockspace(struct task *task, struct sanlk_lockspace *ls,
			   int max_hosts, uint32_t io_timeout);

int direct_write_resource(struct task *task, struct sanlk_resource *res,
			  int max_hosts, int num_hosts, int write_clear);

int direct_read_leader(struct task *task, int io_timeout,
                       struct sanlk_lockspace *ls,
                       struct sanlk_resource *res,
                       struct leader_record *leader_ret);

int direct_write_leader(struct task *task,
                        int io_timeout,
                        struct sanlk_lockspace *ls,
                        struct sanlk_resource *res,
                        struct leader_record *leader);

int direct_dump(struct task *task, char *dump_path, int force_mode);

int direct_next_free(struct task *task, char *path);

int direct_rindex_format(struct task *task, struct sanlk_rindex *ri);
int direct_rindex_rebuild(struct task *task, struct sanlk_rindex *ri,
			  uint32_t cmd_flags);
int direct_rindex_lookup(struct task *task, struct sanlk_rindex *ri,
                         struct sanlk_rentry *re, uint32_t cmd_flags);
int direct_rindex_update(struct task *task, struct sanlk_rindex *ri,
                         struct sanlk_rentry *re, uint32_t cmd_flags);

#endif
