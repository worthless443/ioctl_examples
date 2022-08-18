#include<termios.h>
#include<sys/ioctl.h>
#include<assert.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/random.h>

#include<ioctl_examples.h>
// TODO organize device file ioctl with their own functions

struct rand_pool_info_der {
	int bit_size;
	int byte_size;
};

int mk_struct_rand_pool(int size, void *r_info, int mask) { 
	if((size & mask)!=0) return -1;
	struct rand_pool_info_der *info = (struct rand_pool_info_der*)r_info;
	info->bit_size = size*8;
	info->byte_size = size;
	return 0;
}

int main() {
	struct termios argp;
	struct rand_pool_info r_info;
	int err;
	if((err  = mk_struct_rand_pool(256,&r_info,1))<0) {
		printf("error setting rand_pool\n");
		return -1;
	}
	//r_info.bit_count= BUFSIZE;
	//r_info.byte_count= BUFSIZE;
	
	int  fd = 	open("/dev/tty0", O_RDONLY), test, ent=0xffffff ;
	int  fd_rnd = 	open("/dev/urandom", O_RDONLY) ;
	int ret  = ioctl(fd, IOMASK(TCGETS) , &argp);
	int ret_rnd  = ioctl(fd_rnd, RNDADDENTROPY | RNDADDENTROPY, &r_info);
	int ret_rnd1  = ioctl(fd_rnd,RNDGETENTCNT, &test);
	int ret_rnd2  = ioctl(fd_rnd,RNDADDTOENTCNT, &ent);

	assert(ret_rnd == 0   && ret_rnd1 == 0 && ret_rnd2 == 0);
	printf("bufsize %d\n", r_info.buf_size);
	printf("%d\n", fd);
	printf("%d\n", ret);
	printf("%d\n", *(int*)&argp);
	printf("%d\n", test);
	printf("%d\n", ret_rnd2);
	return  0;
}
