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


