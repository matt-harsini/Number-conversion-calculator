#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
 
char mapping[16][5]  = {
"0000",
"0001",
"0010",
"0011",
"0100",
"0101",
"0110",
"0111",
"1000",
"1001",
"1010",
"1011",
"1100",
"1101",
"1110",
"1111"
};

char * numToBinHelper(char * ptr, char * result) {
  if (*ptr) {
  char * ch = malloc(sizeof(char) * 2);
  sprintf(ch, "%c", *ptr);
  strcat(result, mapping[strtol(ch, NULL, 16)]);
  return numToBinHelper(ptr + 1, result);
  } else {
    return result;
  }

}
char * numToBin(long long num) {
  char * ptr = malloc(sizeof(char) * 100);
  char * result = malloc(sizeof(char)* 100);
  //sprintf(result, "");
  sprintf(ptr, "%llx", num);
  return numToBinHelper(ptr, result);
}
   int StartsWith(const char *a, const char *b) {
      return (strncmp(a, b, strlen(b)));
   }
   char ** decimalToHexHelper(int i, int size, char** input, char** result) {
      if (i>=size) return result;
      result[i]=(char*)malloc(sizeof(char)*(10+ceil(log10(strtol(input[i],NULL,10))/log10(16))));
      sprintf(result[i], "%llx", strtoll(input[i],NULL,10));
      return decimalToHexHelper(i+1, size, input, result);
   }
   char ** decimalToHex(int size, char** input){
      char ** result;
      result = (char**)malloc(sizeof(char*)*size);
      return decimalToHexHelper(0, size, input, result);
   }
   char ** decimalToDecimalHelper(int i, int size, char** input, char** result) { 
       if(i>=size) return result;
        result[i] = (char*)malloc(sizeof(char)*1000);
        sprintf(result[i], "%s", input[i]);
        return decimalToDecimalHelper(i+1, size, input, result);
   }
   char ** decimalToDecimal (int size, char ** input) {
      char** result = (char**)malloc(sizeof(char*)*size);
      return decimalToDecimalHelper(0, size, input, result);
   }
   char ** decimalToBinaryHelper(int i, int size, char** input, char** result) {
      if (i>=size) return result;
      result[i]=(char*)malloc(sizeof(char)*1000);
      long long number = strtoll(input[i],NULL,10);
      result[i] = numToBin(number);
      return decimalToBinaryHelper(i+1, size, input, result);
   }

   char ** decimalToBinary (int size, char** input){
      char ** result;
      result = (char**)malloc(sizeof(char*)*size);
      return decimalToBinaryHelper(0, size, input, result);
   }

   char ** binaryToDecimalHelper(int i, int size, char**input, char**result) {
      if (i>=size) return result;
      result[i]=(char*)malloc(sizeof(char)*1000);
      sprintf(result[i], "%lld", strtoll(input[i], NULL, 2));
      return binaryToDecimalHelper(i+1, size, input, result);
   }
   char ** binaryToDecimal(int size, char ** input){
      char ** result;
      result = (char**)malloc(sizeof(char*)*size);
      return binaryToDecimalHelper(0, size, input, result);
   }
   char ** binaryToBinaryHelper(int i, int size, char**input, char**result) {
        if(i>=size) return result;
        result[i] = (char*)malloc(sizeof(char)*1000);
        sprintf(result[i], "%s", input[i]);
        return binaryToBinaryHelper(i+1, size, input, result);
   }
   char ** binaryToBinary (int argc, char ** input){ 
       //result size is input size]
        char** result = (char**)malloc(sizeof(char*)*argc);
        return binaryToBinaryHelper (0, argc, input, result);
       //loop through input[i] 
       //result[i]=input[i]
      //return input;
   }
   char ** binaryToHexHelper(int i, int size, char** input, char** result) {
      if (i>=size) return result;
      result[i]=(char*)malloc(sizeof(char)*(1000+ceil(log10((int)strtol(input[i],NULL,10))/log10(16))));
      sprintf(result[i], "%llx", strtoll(input[i], NULL, 2));
      return binaryToHexHelper(i+1, size, input, result);
   }
   char ** binaryToHex (int size, char ** input){
      char ** result;
      result = (char**)malloc(sizeof(char*)*size);
      return binaryToHexHelper(0, size, input, result);
   }
   char** hexToDecimalHelper(int i, int size, char**input, char**result) {
      if (i>=size) {
         // printf("%s", result[i]);
         return result;
      }
      long long unsigned x;
      sscanf(input[i],"%llx", &x);
      result[i]=(char*)malloc(sizeof(char)*100);
      sprintf(result[i], "%lld", x);
      // printf("%s", result[i]);
      return hexToDecimalHelper(i+1, size, input, result);
   }
   char ** hexToDecimal (int size, char ** input) {
      char ** result;
      result = (char**)malloc(sizeof(char*)*size);
      return hexToDecimalHelper(0, size, input, result);
      // printf("%s",result[0]);
   }
   char ** hexToBinaryHelper(int i, int size, char** input, char**result){
      if (i>=size) return result;
      result[i]=(char*)malloc(sizeof(char)*strlen(input[i]) * 40);
      unsigned int x;
      sscanf(input[i],"%x", &x); 
      result[i] = numToBin(x);
      return hexToBinaryHelper(i+1, size, input, result);
   }
   char ** hexToBinary (int size, char ** input) {
      char ** result;
      result = (char**)malloc(sizeof(char*)*size);
      return hexToBinaryHelper(0, size, input, result);
   }
   char ** hexToHexHelper(int i, int size, char**input, char**result) {
       if(i>=size) return result;
        result[i] = (char*)malloc(sizeof(char)*1000);
        sprintf(result[i], "%s", input[i]);
        return hexToHexHelper(i+1, size, input, result);
   }
   char ** hexToHex (int argc, char ** input){
       char** result = (char**)malloc(sizeof(char*)*argc);
       return hexToHexHelper(0, argc, input, result);
   }
   void seekUserInput(){
      //use scanf and placeholders for the input
      printf("Hello, enter the first argument (base you are providing numbers in).\nThen a second argument (base you want to convert).\nLastly the third and fourth, all the way up to n numbers is the sequence of numbers that need to be converted.");
   }
   
   void freeMemoryHelper(int i, int size, char ** result) {
     if (i < size) {
      free(result[i]);
      freeMemoryHelper(i + 1, size, result);
     }
   }
   void freeMemory(int size, char** result){
     //printf("freeMemory\n");
      //printf("%p\n",result);
      // freeMemoryHelper(0,size, result);
      freeMemoryHelper(0, size, result);
    //  printf("%p\n",result);
     free(result);
   }
   void printResult(int i, int size, char ** result){
      if(i<size){
         printf("\nResult %d: %s",i+1,result[i]);
         printResult(i+1,size,result);
      }
   }
   char ** binaryConversion(int argc, char *argv[]){
      if (StartsWith(argv[2], "dec") == 0)
         return binaryToDecimal(argc-3, argv+3);
      if (StartsWith(argv[2], "hex") == 0)
         return binaryToHex(argc-3, argv+3);
      if (StartsWith(argv[2], "bin") == 0)
         return binaryToBinary(argc-3, argv+3);
    return NULL;
   }
   char ** decimalConversion(int argc, char *argv[]){
      //char ** result = (char**)malloc(sizeof(char*)*argc);
      if (StartsWith(argv[2], "bin") == 0)
         return decimalToBinary(argc-3, argv+3);
      if (StartsWith(argv[2], "hex") == 0)
         return decimalToHex(argc-3, argv+3);
      if(StartsWith(argv[2], "dec") == 0)
         return decimalToDecimal(argc-3, argv+3);
    return NULL;
   }
   char ** hexConversion(int argc, char *argv[]){
      if (StartsWith(argv[2], "bin") == 0)
         return hexToBinary(argc-3, argv+3);
      if (StartsWith(argv[2], "hex") == 0)
         return hexToHex(argc-3, argv+3);
      if(StartsWith(argv[2], "dec") == 0)
         return hexToDecimal(argc-3, argv+3);
    return NULL;
   }
int main(int argc, char *argv[]) {
   char ** result;
   seekUserInput();
   if (argc < 4) {
      printf(" ERROR: You need three arguments.\n");
      return -1;
   }
   if (StartsWith(argv[1], "bin") == 0)
      result = binaryConversion(argc, argv);
 
   else if (StartsWith(argv[1], "hex") == 0) {
      result = hexConversion(argc, argv);
   }
   else if (StartsWith(argv[1], "dec") == 0) {
      result = decimalConversion(argc, argv);
   }
   else {
      printf("Error, paramaters not valid.");
      return -1;
   }
   printResult(0, argc-3, result);
   printf("\n");
   freeMemory(argc-3, result);
   return 0;
  // take three inputs from user
  // use if statements to determine the number conversion
  // ex: if first input is a binary and second input is hexadecimal, convert
  // binary to hexadecimal third input is the number that needs to be converted
  // up to x numbers use an array for the third input?? return the result
}