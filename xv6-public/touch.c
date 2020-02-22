#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define STANDARD_INPUT_FD 0

char buf[512];

int main(int argc, char *argv[]){
	if(argc < 2 || argc > 3)
		printf(1, "# of arguments don't match\n");
	if(argc == 2){
		int src_fd = open(argv[1], O_CREATE); 
		close(src_fd);
	}
	if(argc == 3){
		if(argv[1][0] != '-' || argv[1][1] != 'w'){
			printf(1, "Flag not verified");
			exit();
		}
		int dst_fd = open(argv[2], O_RDWR);
		int inp = open("console", O_RDWR);
		read(inp, buf, sizeof(buf));
		write(dst_fd, buf, sizeof(buf));
		close(dst_fd);
		dst_fd = open(argv[2], O_RDWR);
		read(dst_fd, buf, sizeof(buf));
		printf(1, buf);
		close(dst_fd);
	}
	exit();
}