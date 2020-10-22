     #assemble boot.s file  
    as boot.s -o boot.o  
      
    #compile kernel.c file  
    gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra  
      
    #linking the kernel with kernel.o and boot.o files  
    gcc -T linker.ld -o FYGUYOS.bin -ffreestanding -O2 -nostdlib kernel.o boot.o -lgcc  
      
    #check FYGUYOS.bin file is x86 multiboot file or not  
    grub-file --is-x86-multiboot FYGUYOS.bin  
      
    #building the iso file  
    mkdir -p isodir/boot/grub  
    cp FYGUYOS.bin isodir/boot/FYGUYOS.bin  
    cp grub.cfg isodir/boot/grub/grub.cfg  
    grub-mkrescue -o FYGUYOS.iso isodir  
      
    #run it in qemu  
    qemu-system-x86_64 -cdrom FYGUYOS.iso  

