#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

void dump (void *p, int n);

int main()
{
    BigInt a, x;
    long v = -1;
    long g = -25;
    long t = 0x00000000000000FF;
    long y = 0x01;
    //long u ;
    big_val(a, v);
    BigInt b,c, d, h;
    big_val(h, g);
    //big_val(b, t);
    big_val(c, y);
    //dump(c, sizeof(c));
    printf("\n\n");
    //dump(b, sizeof(b));
    //big_val(d, u);
    //big_sum(d, a, h);
    //big_val(a, v);
    big_comp2(x, c);
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
    int entrou = 2;

    for (i = 0; i< 16; i++){
       
        if(entrou == 2){
            c = *pa + *pb;
            //printf("\n%x2 -> c\n", c);
            //printf("\n%x2 -> *pa\n", *pa);
            //printf("\n%x2 -> *pb\n", *pb);
        }else{
            c = (*pa + *pb)+temp;
            *r = c;
            temp = 0;
            //printf("\n%x2 -> c\n", c);
            //printf("\n%x2 -> *pa\n", *pa);
            //printf("\n%x2 -> *pb\n", *pb);
            //printf("\n%x2 -> *r\n", *r);
        }

        if(*pa +*pb > 255){
            temp = (*pa +*pb) - 255;
            entrou = 1;
            *r = 255;
            //printf("\n%x2 -> *temp\n", temp);
            //printf("\n%x2 -> *r\n", *r);
        }
        pa++;
        pb++;
        r++;
    } 

    dump(res, sizeof(res)*2);
}

void big_comp2(BigInt res, BigInt a){

    unsigned char *r = res;
    unsigned char *v = a;
    unsigned char *inv;
    unsigned char msf = 0xFF;
    int i = 0;

    for(i = 0; i< 16; i++){
        if(*a == msf){
            *inv = 0x00;
        }else{
            *inv = msf;
        }
        inv++;
        a++;
    }
    dump(inv, sizeof(inv)*2);
    printf("\n\n");
}

void big_sub (BigInt res, BigInt a, BigInt b){

    unsigned char temp = 0;
    int i = 0;
    unsigned char  *pb = b;
    unsigned char *pa = a;
    unsigned char *r = res;
    unsigned char c = 0;
    int entrou = 2;
}

void dump (void *p, int n) {
  unsigned char *p1 = p;
  printf("\n-----\n");
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
  printf("\n-----\n");
}
