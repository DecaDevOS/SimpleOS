# Simple Operating System

## Synopsis
Simple UNIX like operating system with kernel mode and usermode implementation buit from scratch not using any current Linux / UNIX source code. bootable via current existing boot loaders such as GRUB using a multiboot header format and an elf binary format. facilitating user input via a terminal program and utilizing a set of gnu based utilities ported from the current gnu tool sets along with various other ports from linux / unix like operating systems

### Tech Stack
- C Programming Language (GCC)
- Assembly Language (nasm)
- Binary Type
    - Elf32
- Testing and Debugging
    - PC Emulator to run the OS (QEMU)
    - Debug console (remote serial on qemu)

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

### API for initial Kernel Implementation (Feature Set Base 1)

*The API or Core feature set will start as follows:*

#### *Kernel Core - Memory / Ports*
- Memory Copy (memcpy): Copy data from src to dest
- Memory Set (memset): set value starting at dest of count size
- String Length (strlen): return the length of a character array
- Read In port (inport): return the data from a port
- Write Out port (outport): write data to a port

##### Breakdown of core Functions

*memcpy*

 Copy from source to destination. Assumes that source and destination are not overlapping.

```C
extern void *memcpy(void * restrict dest, const void * restrict src, size_t count);
```

*memset*

Set a count ammount of bytes to a value.

```C
extern void *memset(void *dest, int val, size_t count);
```

*strlen*

Return the length of a given string.

```C
extern int strlen(const char *str);
```

*inport*

Read data from an I/O port.

```C
extern unsigned char inport (unsigned short _port);
```

*outport*

Write data to an I/O port.

```C
extern void outport (unsigned short _port, unsigned char _data);
```

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

*Interrupt Service Routines*
- Install Interrupt Service Routines (isrs_install): setup and initialize the installation and linkage of isrs

*Interrupt Handler IRQ init and management*
- setup install and init interrupts (irq_install): setup initial irq table to a known state
- Install irq handler (irq_install_handler): install the individual irq handler
- Uninstall irq handler (irq_uninstall_handler): uninstall the individual irq handler

*Timer Routines*
- Install the system Timer (timer_install): install and initialize the system timer driver
- System Timer Wait (timer_wait): wait for a number of ticks in the system timer

*Keyboard Routines*
- Install Keyboard (keyboard_install): Initialize the keyboard driver
- Wait for Key (keyboard_wait): wait for a key press via the keyboard driver

