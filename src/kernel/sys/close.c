/*
 * Copyright(C) 2011-2014 Pedro H. Penna <pedrohenriquepenna@gmail.com>
 * 
 * sys/close.c - close() system call implementation.
 */

#include <nanvix/const.h>
#include <nanvix/fs.h>
#include <nanvix/pm.h>
#include <errno.h>

/*
 * Closes a file.
 */
PUBLIC int sys_close(int fd)
{	
	/* Invalid file descriptor. */
	if ((fd < 0) || (fd >= OPEN_MAX) || (curr_proc->ofiles[fd] == NULL))
		return (-EINVAL);
	
	do_close(fd);
	
	return (0);
}
 
