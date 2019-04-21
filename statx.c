
#define _GNU_SOURCE
#define _ATFILE_SOURCE


#include <sys/types.h>
#include <sys/stat.h>
//##include <linux/stat.h>
#include <unistd.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <stdio.h>


int statx(int dirfd, const char *pathname, int flags,  unsigned int mask, struct statx *statxbuf);

int main(void) {
	struct statx statx_buf;

	printf("Creating testfile\n");
	FILE *f = fopen("testfile", "w");
	int ret = 0;
	fclose(f);


	ret = statx(AT_FDCWD, "testfile", 0, STATX_UID, &statx_buf);

	if ( ret == 0 ) {
		printf("File's owner is %i\n", statx_buf.stx_uid);
	} else {
		perror("statx failed");
	}

}
