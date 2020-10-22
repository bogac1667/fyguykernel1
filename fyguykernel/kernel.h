    #ifndef _KERNEL_H_  
    #define _KERNEL_H_  
      
    #define VGA_ADDRESS 0xB8000  
      
    #define WHITE_COLOR 15  
      
    typedef unsigned short UINT16;  
      
    int DIGIT_ASCII_CODES[10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};  
      
    unsigned int VGA_INDEX;  
      
    #define BUFSIZE 2200  
      
    UINT16* TERMINAL_BUFFER;  
      
    #endif   
    int digitCount(int num)  
    {  
      int count = 0;  
      if(num == 0)  
        return 1;  
      while(num > 0){  
        count++;  
        num = num/10;  
      }  
      return count;  
    }  
      
    void itoa(int num, char *number)  
    {  
      int digit_count = digitCount(num);  
      int index = digit_count - 1;  
      char x;  
      if(num == 0 && digit_count == 1){  
        number[0] = '0';  
        number[1] = '\0';  
      }else{  
        while(num != 0){  
          x = num % 10;  
          number[index] = x + '0';  
          index--;  
          num = num / 10;  
        }  
        number[digit_count] = '\0';  
      }  
    }  
      
    void printInt(int num)  
    {  
      char str_num[digitCount(num)+1];  
      itoa(num, str_num);  
      printString(str_num);  
    }  
        static int Y_INDEX = 1;  
      
    void printNewLine()  
    {  
      if(Y_INDEX >= 55){  
        Y_INDEX = 0;  
        Clear_VGA_Buffer(&TERMINAL_BUFFER);  
      }  
      VGA_INDEX = 80*Y_INDEX;  
      Y_INDEX++;  
    }  
    void KERNEL_MAIN()  
    {  
      TERMINAL_BUFFER = (UINT16*) VGA_ADDRESS;  
      printString("FYGUY KERNEL DEVELOPED BY FYGUY DEVELOPER TEAM AND BOGACHAN GUNER!");  
      printNewLine();  
      printInt(1234567890);  
      printNewLine();  
      printString(" TEST VERSION OF KERNEL!");  
    }  
    
