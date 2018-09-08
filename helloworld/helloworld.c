#include <linux/kernel.h>
#include <asm/current.h>
#include <linux/sched.h>



asmlinkage long sys_helloworld(void){

	
	
	volatile long statenum = current->state; //this is the number representing the state. I need it to print as a word, and I don't know the easy way to do that. 
	//declare string, copy table, change print	
	char* state;
	if(statenum==0) state="TASK_RUNNING";
	if(statenum==1) state="TASK_INTERRUPTIBLE";
	if(statenum==2) state="TASK_UNINTERRUPTIBLE";
	if(statenum==4) state="__TASK_STOPPED";
	if(statenum==8) state="__TASK_TRACED";
	if(statenum==(4*16)) state="TASK_PARKED";
	if(statenum==(8*16)) state="TASK_DEAD";
	if(statenum==(16^2)) state="TASK_WAKEKILL";
	if(statenum==(2*16^2)) state="TASK_WAKING";
	if(statenum==(4*16^2)) state="TASK_NOLOAD";
	if(statenum==(8*16^2)) state="TASK_NEW";
	if(statenum==(16^3)) state="TASK_STATE_MAX";


	long static_priority = current->static_prio; //I think this is NICE
	long prio = current->prio; //normal=dynamic?
	long normal_prio = current->normal_prio;
	long rt_priority = current->rt_priority;
	long pid = current->pid; //the number
	
	printk("State: %s   Static Priority: %lx   Prio: %lx Normal Prio: %lx  RT Prio: %lx   Process ID: %lx \n", state, static_priority, prio, normal_prio, rt_priority, pid);

	return 0;
}
