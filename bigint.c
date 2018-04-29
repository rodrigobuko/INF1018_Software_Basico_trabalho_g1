#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

void dump (void *p, int n);
BigInt zeroB;
int main()
{
    BigInt a, x;
    long v = 4;
    long g = -3;
    long t = 0x00000000000000FF;
    long y = 96;
		long zero = 0x00;
    //long u ;
    big_val(a, v);
    BigInt b,c, d, h;
    big_val(h, g);
    big_val(b, t);
    big_val(c, y);
		big_val(zeroB, zero);
    //dump(c, sizeof(c));
    //printf("\n\n");
    //dump(b, sizeof(b));
    //big_val(d, u);
    //big_sum(d, a, h);
		//dump(d, sizeof(x));
    //big_val(a, v);
    //big_comp2(x, c);
		//dump(x, sizeof(x));
		big_sum(d,a, h);
		dump(d, sizeof(d));
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
      c = (*pa + *pb)+temp;
      *r = c;

      if(c > 255){
         temp = 1;
      }
      else {
         temp = 0;
      }
      pa++;
      pb++;
      r++;
    } 

    //dump(res, sizeof(res)*2);
}

void big_comp2(BigInt res, BigInt a){

    unsigned char *r = res;
    unsigned char *v = a;
		unsigned char temp;
			
    int i = 0;

    for(i = 0; i< 16; i++){
				temp = ~(*v);
				//printf("%02x\n", temp);
				*r = temp;
        v++;
				r++;
    }
		//dump(v, sizeof(v)*2);
    //printf("\n\n");
		//dump(r, sizeof(r)*2);

		long y = 1;
		BigInt b;
		big_val(b, y);
		big_sum(res, res, b);
		//printf("\n\n");
		//dump(r, sizeof(r)*2);
}

void big_sub(BigInt res, BigInt a, BigInt b){

    unsigned char temp = 0;
    int i = 0;
    unsigned char  *pb = b;
    unsigned char *pa = a;
    unsigned char *r = res;
    unsigned char c = 0;
    int entrou = 2;
		BigInt tempb;
		
		big_comp2(tempb, b);		
	
		big_sum(res, a, tempb);	
}

void big_shl (BigInt res, BigInt a, int n){

		unsigned char temp = 0;
    int i = 0;
		res = a;
    unsigned char *r = res;
    unsigned char c = 0;
		
		
}

void big_shr (BigInt res, BigInt a, int n){

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
