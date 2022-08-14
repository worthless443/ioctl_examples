#include<termios.h>
#include<sys/ioctl.h>
#include<assert.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/random.h>

int main() {
	struct termios argp;
	struct rand_pool_info r_info;
	//r_info.bit_count= BUFSIZE;
	//r_info.byte_count= BUFSIZE;
	
	int  fd = 	open("/dev/tty0", O_RDONLY), test, ent=0xffffff & 0xf;
	int  fd_rnd = 	open("/dev/urandom", O_RDONLY) ;
	int ret  = ioctl(fd, _IOR(_IOC_TYPE(TCGETS), _IOC_NR(TCGETS), argp) , &argp);
	int ret_rnd  = ioctl(fd_rnd, RNDADDENTROPY | RNDADDENTROPY, &r_info);
	int ret_rnd1  = ioctl(fd_rnd,RNDGETENTCNT, &test);
	int ret_rnd2  = ioctl(fd_rnd,RNDADDTOENTCNT, &ent);

	assert(ret_rnd == 0   && ret_rnd1 == 0 && ret_rnd2 == 0);
	printf("%d\n", fd);
	printf("%d\n", ret);
	printf("%d\n", *(int*)&argp);
	printf("%d\n", test);
	printf("%d\n", ret_rnd2);
	
	//assert(ret==0);

}
