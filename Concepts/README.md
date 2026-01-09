📌 Overview

The Customised Virtual File System (CVFS) is a technical implementation of an in-memory file system layer that emulates core Unix/POSIX system calls.
This project demonstrates how an Operating System internally manages files, including metadata handling, data block allocation, and the lifecycle of file descriptors—without using the host OS file system.

The entire file system exists in memory and closely mirrors real kernel-level behavior.

🎯 Project Objectives

Understand internal working of Unix File Systems

Simulate kernel-level file handling mechanisms

Implement POSIX-compliant system calls

Manage file metadata, blocks, and descriptors manually

🛠️ Implemented System Calls

The core functionality is built around the following POSIX-style system calls, which form the primary interface for interacting with the virtual storage.

🔹 1. File Lifecycle Management
creat(name, mode)

Allocates a new Inode

Initializes file metadata

Creates a directory entry

Returns a unique File Descriptor (FD)

open(name, mode)

Searches for the file’s Inode by name

Creates an entry in the Global File Table

Returns a File Descriptor

close(fd)

Releases the File Descriptor

Updates the process-specific FD table

Decrements reference count in the Global File Table

unlink(name)

Removes the filename-to-Inode link

Decrements link count

Frees data blocks when link count reaches zero

🔹 2. Data I/O and File Navigation
write(fd, buffer, size)

Writes data from user buffer into virtual disk blocks

Automatically allocates blocks if file grows

read(fd, buffer, size)

Reads data from virtual blocks

Starts from the current file offset

Prevents reading beyond EOF

lseek(fd, offset, whence)

Modifies the current read/write offset.

SEEK_SET → From beginning of file

SEEK_CUR → From current offset

SEEK_END → From end of file

🏗️ Internal Data Structures

The system relies on the following kernel-level abstractions:

Structure	Purpose
Inode	Stores file metadata such as size, type, permissions, and block pointers
File Descriptor Table	Per-process table mapping FDs to open files
Global File Table	Maintains offset, mode, and reference count for open files
Block Bitmap	Tracks free and allocated memory blocks efficiently

🔄 Core Logic Flow
🔹 Space Allocation

During creat() or write()

  Block Bitmap is scanned for the first free block

  Block is marked allocated

🔹 Address Translation

  Logical byte offset → Physical block address

  Uses Inode’s block pointer array

🔹 Reference Counting

  Managed via the Global File Table

  Ensures file persists as long as at least one FD is open

🧠 Learning Outcomes

  Deep understanding of file system internals

  Practical exposure to OS kernel concepts

  Hands-on experience with memory management

  Strong foundation for system programming & OS interviews

🚀 Use Cases

  Operating System coursework

  Interview preparation (OS + Systems)

  Learning Unix internals

  Academic demonstrations


👨‍💻 Author

Aditya Sanap
Aspiring System Programmer & Software Developer

📄 License

This project is open-source and available under the MIT License.

⭐ If this project helped you understand file systems, consider giving it a star!
