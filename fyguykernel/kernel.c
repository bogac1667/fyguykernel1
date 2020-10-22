     #include"kernel.h"  
      
    static UINT16 VGA_DefaultEntry(unsigned char to_print) {  
        return (UINT16) to_print | (UINT16)WHITE_COLOR << 8;  
    }  
      
    void KERNEL_MAIN()  
    {  
      TERMINAL_BUFFER = (UINT16*) VGA_ADDRESS;  
      
      TERMINAL_BUFFER[0] = VGA_DefaultEntry('F');  
      TERMINAL_BUFFER[1] = VGA_DefaultEntry('Y');  
      TERMINAL_BUFFER[2] = VGA_DefaultEntry('G');  
      TERMINAL_BUFFER[3] = VGA_DefaultEntry('U');  
      TERMINAL_BUFFER[4] = VGA_DefaultEntry('Y');  
      TERMINAL_BUFFER[5] = VGA_DefaultEntry(' ');  
      TERMINAL_BUFFER[6] = VGA_DefaultEntry('O');  
      TERMINAL_BUFFER[7] = VGA_DefaultEntry('S');  
      TERMINAL_BUFFER[8] = VGA_DefaultEntry('O');  
      TERMINAL_BUFFER[9] = VGA_DefaultEntry('N');  
      TERMINAL_BUFFER[10] = VGA_DefaultEntry('E');  
    }  

