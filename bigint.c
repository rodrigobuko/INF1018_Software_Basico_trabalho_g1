#include <stdio.h>
#include <stdlib.h>

#define NUM_BYTES 16
typedef unsigned char BigInt[NUM_BYTES];
void dump (void *p, int n);

int main()
{
    BigInt a;
    long v = -1;
    long t = 0x00000000000000FF;
    long y = 0x01;
    //long u ;
    big_val(a, v);
    BigInt b,c, d;
    big_val(b, t);
    big_val(c, y);
    //dump(c, sizeof(c));
    printf("\n\n");
    //dump(b, sizeof(b));
    //big_val(d, u);
    big_sum(d, c, b);

    return 0;
}


void big_val (BigInt res, long val) {

    int cont = 0;
    int i = 0;
    unsigned char  *p = &val;
    unsigned char *r = res;

   for (i = 0; i< 16; i++){
        if (i < 8){
            *r = *p;
        }else {
            if (val>=0){
                *r=0x00;
            }else{
                *r = 0xFF;
            }
        }
        p++;
        r++; 
    } 

    //dump(res, sizeof(res)*2);
}

void big_sum(BigInt res, BigInt a, BigInt b){

    unsigned char temp = 0;
    int i = 0;
    unsigned char  *pb = b;
    unsigned char *pa = a;
    unsigned char *r = res;
    unsigned char c = 0;
    unsigned char comp = 0xFF;
    int entrou = 2;
    unsigned char comp3 = 0x00;
    unsigned char comp2 = 0x01;

   for (i = 0; i< 16; i++){
       
        c = *pa +*pb - comp;
        printf("\n%x2 pa\n", *pa);
        printf("\n%x2 pb\n", *pb);
        printf("\n%x2 c\n", c);
        if (c >= comp3) {
            temp = *pa + *pb - comp;
             printf("\n%x2 temp \n", temp);
            *r = temp - comp2;
             printf("\n%x2 r\n", *r);
            printf("NAOOOO ENTRAA AQUIII");
        }else {
            *r = *pa +*pb;
            temp = 0;
        }
        pa++;
        pb++;
        r++;
    } 

    dump(res, sizeof(res)*2);
}

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}
