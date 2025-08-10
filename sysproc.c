#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}
int 
sys_numberofprocesses(){
  return numberofprocesses();
}

int 
sys_getvasize(){
int id;
if(argint(0,&id)<0){return -1;}
struct proc *p=getProcess(id);
return p->sz;

}

int
sys_mysystem_call(void){
int arg;
if(argint(0, &arg) < 0)
    return -1;  // Return an error if fetching the argument fails

   mysystem_call(arg);
   return 0;
}
int sys_worldpeace(void){
cprintf("Systems are vital to world peace !!");
return 0;
}
int
sys_va2pa(void){
int virtual_addr;
if(argint(0,&virtual_addr)<0){
return -1;
}
return va2pa(virtual_addr);
}
int 
sys_get_pgtb_size(void)
{
return get_pgtb_size();
}
int
sys_get_usr_pgtb_size()
{
return get_usr_pgtb_size();}
int
sys_get_kernel_pgtb_size(){
return get_kernel_pgtb_size();
}
int 
sys_getpasize(void){
int id;
if(argint(0,&id)<0){return -1;}
return getpasize(id);
}
int 
sys_spawn(void) 
{
int n;
int *pid;
int count=0;
if(argint(0,&n)<0){return -1;}
if (argptr(1, (char **)&pid, sizeof(int) * n) < 0)
    return -1;

for(int i=0;i<n;i++){
pid[i]=fork();
count++;
}
return count;

}
int 
sys_mmap(void){
int n;
if(argint(0,&n)<0){return 0;}
return mmap(n);


}
int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
