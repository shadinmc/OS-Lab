#include <stdio.h>
#include <string.h>
int main()  
{  
   char str1[100],str2[100]; 
   int i,j; 
    printf("Enter the string1: ");
  fgets(str1,100,stdin); 
  printf("Enter the string2: ");
  fgets(str2,100,stdin); 
        for(i=0;str1[i]!='$';i++); 
  for(j=0;str2[j]!='$';j++,i++)    
    str1[i]=str2[j];
  str1[i]='\0'; 
  printf("conatenated string is \n"); 
  printf("%s\n",str1); 
} 
 
