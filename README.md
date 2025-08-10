# xv6 System Call Extensions and Virtual Memory Management

## 📌 Project Overview
This project extends the **xv6 operating system** with new system calls and enhancements to process creation, virtual memory management, and page fault handling.  
It introduces:
- A **multi-process spawn system call** for efficient process creation.
- Tools to **inspect virtual and physical memory mappings**.
- **Page table introspection** for both user and kernel space.
- A **custom page fault handler** with lazy allocation support.
- A simplified **mmap()** implementation for dynamic memory mapping.

The implementation focuses on:
- Exploring the xv6 process model.
- Understanding the virtual memory architecture.
- Managing page tables and demand paging.
- Writing and integrating kernel-level system calls.

---

## 🚀 Features

### **1. Process Management**
#### `int spawn(int n, int* pids)`
- Creates **n** child processes in a single call.
- Returns:
  - `0` in each child process.
  - The **number of children created** in the parent.
- Populates `pids[]` with child PIDs.
- Parent gracefully **reaps** all spawned children.

---

### **2. Virtual Memory Inspection**
#### `int getvasize(int pid)`
- Returns **virtual address space size** of a process.

#### `uint va2pa(uint virtual_addr)`
- Returns **physical address** mapped to a given virtual address.

---

### **3. Page Table Information**
#### `int get_pgtb_size()`
- Returns **total number of page table pages** allocated for the current process.

#### `int get_usr_pgtb_size()`
- Returns **number of page table pages allocated for user space**.

#### `int get_kernel_pgtb_size()`
- Returns **number of page table pages allocated for kernel space**.

---

### **4. Page Fault Handling**
#### Page Fault Trap (`T_PGFLT`)
- Extended `trap.c` to explicitly handle **page faults**.
- Prints:
  - Faulting process PID.
  - Faulting address.

---

### **5. Memory Mapping**
#### `mmap(size_t bytes)`
- Increases heap size by the given byte count.
- Allocates corresponding physical memory.

---

### **6. Lazy Allocation**
- Page fault handler modified to **allocate memory on demand**.
- Allocates a physical page only when accessed for the first time.
- Avoids unnecessary memory allocation.

---

