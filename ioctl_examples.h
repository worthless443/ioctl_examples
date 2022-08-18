#define BUFSIZE 512

#define IOMASK_(n)  (n) | ((n) >> ((n) & 5))
#define IOMASK(n)  n | (n & 0xf) + ((n & (0xf+1))) + 1
