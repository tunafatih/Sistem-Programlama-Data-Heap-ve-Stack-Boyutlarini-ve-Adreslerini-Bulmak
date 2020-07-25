#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fields.h"
#include "string.h"




int main(void)
{

  char *buf;

  buf = (char *) malloc(200);

  sprintf(buf, "/proc/%d/maps", getpid());


   IS is;
   int i;

   is = new_inputstruct(buf);
   
   char *data;
   char *heap;
   char *stack;
   
   
   while(get_line(is) >= 0) {
    for (i = 0; i < is->NF; i++) {

      if(strstr(is->fields[i], "r--p") != NULL && is->line==2) {
       data = is->fields[i-1];
        char *dataBaslangic;
        char *dataBitis;
        dataBaslangic = strtok(data, "-");
        dataBitis = strtok(NULL, "-");
        long dataBaslangicDex = strtol(dataBaslangic, NULL, 16);
        long dataBitisDex = strtol(dataBitis, NULL, 16);
        printf("Data Bölümü : başlangıç= 0x%s, boyut=%ld Byte\n",dataBaslangic,(dataBitisDex-dataBaslangicDex));
      }
      
      if(strstr(is->fields[i], "heap") != NULL) {
      heap = is->fields[i-5];
      char *heapBaslangic;
      char *heapBitis;
      heapBaslangic = strtok(heap, "-");
      heapBitis = strtok(NULL, "-");
      long heapBaslangicDex = strtol(heapBaslangic, NULL, 16);
      long heapBitisDex = strtol(heapBitis, NULL, 16);
      printf("Yığıt Bölümü: başlangıç= 0x%s, boyut=%ld Byte\n",heapBaslangic,(heapBitisDex-heapBaslangicDex)); 
      }

      if(strstr(is->fields[i], "stack") != NULL) {  
      stack = is->fields[i-5];
      char *stackBaslangic;
      char *stackBitis;
      stackBaslangic = strtok(stack, "-");
      stackBitis = strtok(NULL, "-");
      long stackBaslangicDex = strtol(stackBaslangic, NULL, 16);
      long stackBitisDex = strtol(stackBitis, NULL, 16);
      printf("Yığın Bölümü: başlangıç= 0x%s, boyut=%ld Byte\n",stackBaslangic,(stackBitisDex-stackBaslangicDex));
      }      
    }
  }
   
   
  jettison_inputstruct(is);
  exit(0);   

}

