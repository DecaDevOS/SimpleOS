# Simple Operating System

## Synopsis
Simple UNIX like operating system with kernel mode and usermode implementation buit from scratch not using any current Linux / UNIX source code. bootable via current existing boot loaders such as GRUB using a multiboot header format and an elf binary format. facilitating user input via a terminal program and utilizing a set of gnu based utilities ported from the current gnu tool sets along with various other ports from linux / unix like operating systems

### Tech Stack
- C Programming Language (GCC)
- Assembly Language (nasm)
- Binary Type
    - Elf32

### Kernel
The Kernel should contail the ability to load driver modules and be loadable via the bootsector. there should be simple memory management functions along with a basic text mode driver. A kernel mode shell will also be useful for debugging and initialization toward stage 2 and 3 loading to move in to usermode.

#### Feature Set
- Dynamic Userspoace for Lib loading for additional user modules
- Extensible and modular Kernel to allow for loadable driver modules
- UNIX like terminal / shell interface
- basic networking (TCP/IPV4)
- Aditional third party ports from other UNIX / Linux based Operating Systems and Open Source Libs

#### Basic Components
- DSA Kernel (core of the OS)
- Editor (text editor maybe a port of vi / vim)
- Terminal (terminal like xterm with 256 colour support)
- Dsh (shell to support pipes, redir, vars etc)

#### API for initial Kernel Implementation (Feature Set Base 1)
*The API or Core feature set will start as follows:*

*Kernel Core - Memory / Ports*
- Memory Copy (memcpy): Copy data from src to dest
- Memory Set (memset): set value starting at dest of count size
- String Length (strlen): return the length of a character array
- Read In port (inport): return the data from a port
- Write Out port (outport): write data to a port

*GFX Driver - Grapic Init / Text operations*
- Initialize Graphics (init_gfx): set the graphic memory in to an initialized state
- Set the Colour of the text (settextcolour): change the second half of the grphics memory data to the colour of choice
- Clear the screen (cls): manipulate the graphic memory to clear the buffers and move data out of scope
- Put Character to Screen (putch): add a single char data to the graphics memory and display on screen
- Put a string of chars to screen (puts): loop over putch calls using an array of chars as data

*Global Descriptor Table / Gate Operations*
- setup and install the gdt (gdt_install): initialize and install the global descriptor table
- link gdt and set gate (gdt_set_gate): set up the flags and link the global descriptor table set

*Interrupt Descriptor Table / Gate Operations*
- setup and install the idt (idt_install): initialize and install the interrupt descriptor table
- link idt and set gate (idt_set_gate): set up the flags and link the interrupt descriptor table set
