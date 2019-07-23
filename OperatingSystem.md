# Operating System
- It acts as an intermediatory between hardware and user
- Resource Manager: manage system resources in an unbiased fashion both hardware and software
- Provide a platform on which other application programs are installed

### Goals of OS:
- Primary Goal: Covenience/userfriendly
- Secondary Goal: Efficiency

### Functions of OS:
- Process Management
- Memory Management
- I/O device management
- File Management
- Network management
- Security and Protection

## Evolution Of OS
### Batch Operating System:
In starting mainframe computers
- Common I/O & O/P devices were card readers and tape drivers
- User prepare a job which consisted of the program I/P data and control instructions
- I/P job is given in the form of punch cards and result also appear in the form of punch card after processing
- OS was very simple, always present in memory major task to transfer the control from one job to another

Problems: Speed mismatch of I/O and processor (Idle time zyada he), same requirements wala say ek specific language ke do job run kare toh do baar uska compiler load hoga no batch processing

Then came batch processing
- Jobs with simmilar needs are batched together and executed through the processor as a group
- Operator sort jobs as a deck of punch cards into batch with simmilar needs

Advantages: In a batch job executes one after another saving time from activities like loading compiler, During a batch execution no natural intervention is needed (nikalana card daalna card nahi baar baar)

Disadvantages: Memory limitation, interation of I/O device directly with CPU, Still ideal CPU time

### Spooling (Simultaneous peripheral operations online):
- I/O devices are relatively slow compare to CPU (digital)
- In spooling data is stored first onto the disk (secondary memory) and than CPU interacts with Disk (digital) via main memory
- Keyboard, mouse, printer, etc.
- Spooling is capable of overlapping I/O operations for one job with CPU operations of other jobs.

Advantages: No interaction of I/O devices with CPU directly, CPU utilization is more

Disadvantage: In starting spooling was uniprogramming no context switching

### Multiprogramming OS:
- Maximize CPU utilization
- Multiprogramming means more than one process in main memory which are ready to execute.
- Process generally require CPU time and I/O time. So if running process perform I/O or some other event which do not require CPU then instead of sitting idle CPU make a context switch and picks some other process and this idea will continue
- CPU never idle unless there's no process ready to execute or at time of context switch

Advantage: High CPU utilization, less waiting time more responsive, may be extended to multiple users, nowadays usefull when load is more

Disadvantage: Difficult scheduling, main memory management is required, memory fragmentation, paging (non contiguous memory allocation)

### Multitasking OS:
- Multitasking is multiprograming with time sharing
- Only one CPU but switches between processer so quickly that it gives illusion that all executing at same time.
- The task in multitasking may refer to multiple threads of the same program.
- Main idea is better response time and executing multiple process together

### Multiprocessing:
- Two or more CPU with in a single computer in close communication sharing the system bus, memory and other I/O devices
- Different process may run of different CPU, true parallel execution
- Symmetric: One OS control all CPU each CPU has equal rights
- Asymmetric: Master slave architecture, system task on one processor and application on other or one CPU will handle all hardware interrupt or I/O devices, they are easy to design but less efficient

Advantage: Increased throughput, increased reliability, cost saving, battery efficient, true parallel processing

Disadvantage: More complex, overhead or coupling reduced throughput, large main memory

## CPU Scheduling
- A process execution consist of a cycle of CPU execution and I/O execution
- Normally every process begins with CPU burst that may be followed by the I/O burst then another CPU burst and then I/O burst and so on eventually in the last will end up on CPU burst.

CPU bound process: These are the processes which require most of time on CPU<br>
I/O bound process: These are those process which require most of the time on I/O device on peripheral

A good CPU scheduling idea should choose the mixture of both so that both devices and CPU time can be utilized efficiently.

### Premitive & Non premitive approach of scheduling:
ek baar cpu milaa tab jab tak process naa release kare tab tak CPU nahi le sakte usse this is non premitive approach

Say ek high priority process run karna chahta he tab abhi wale task ko waiting state me daaldenge this is primitive approach

### Terminologies:
- Burst Time/ Execution Time/ Running Time: is the time process require for running on CPU
- Waiting Time: Time spend by a process in ready state waiting for CPU
- Arrival time: when a process enters ready state
- Exit time: when process completes execution and exit from system
- Turn around time: total time spend by a process in the system = TAT = ET - AT = BT + WT
- Response time: Time between a process enters ready queue and get scheduled on the CPU for the first time. Say process aaya 1ms wait kara then response mila then firse wait round robin me aese context switching hoti he.

### First Come First Scheduling:
- Simplest scheduling algorithm it assign CPU to the process which arrives first
- Easy to understand and can easily be implemented using queue data structure
- Always non premitive in nature ek baar processor ko process milaa hum nikaal nahi sakte

Convoy effect: Say ek process aayi which needs 100 BT at 0. Another process which requires just 1 BT comes at 1 toh First come first pehle waale ko run kardeta 2nd wale ko 99 wait time hota. ulta order me kare to wait time 1 unit hi hota bas.

- Smaller process have to wait for long time for bigger process to release CPU

Advantage: Simple, easy to use, easy to understand, easy to implement, must be used for background where execution is not urgent

Disadvantage: suffer from convoy effect, normally higher average waiting time, no consideration to priority or burst time, should not be used for interactive system.

> FIFO and Convoy me biasing nahi he starvation nahi hoga

### Shortest Job First (Non primitive)/ shorted remaining time first (premitive):
- Out of all available process CPU is assigned to the process having smallest BT requirement (no priority, no seniority)

say ek process ko run kar rahe he jo shortest BT ka he then naya aaya jiska usse bhi chota BT he tab agar humne rok diaa apne current process ko to run new then it's premitive otherwise non primitive

Advantage: Guarantees minimum average waiting time, provide a standard for other algo in terms of average waiting time, better average response time compare to First come first

Disadvantage: Algo cannot be implemented as there is no way to know the BT of a process beforehand, Process with longer CPU BT requirement will go into starvation (biased he processor), No idea of priority process with large BT have poor response time.

### Priority Algorithm:
- Here a priority is associated with each process
- At any instance of time out of all available process, CPU is allocated to the process which process the highest priority
- Tie is broken using FCFS order
- No importance to AT or BT
- Supports both non primitive and primitive

Advantage: Provides a facilitity of priority specially for system process, allows to run important process first even if it is a user process

Disadvantage: Here process with the smaller priority may starve for the CPU, No idea of response time or waiting time

> Aging technique of gradually increasing the priority of processes that wait system for long time tab unki priority badho dunga

### Round Robing Algorithm:
- This algo is designed for time sharing system where it is not nessesary to complete one process and then start another, but to be responsive and divide time of the CPU amoung the process in ready state
- Here ready queue will be treated as circular queue
- We fix a time quantum up to which a process can hold the CPU in one go with in which either a process terminate process must release the CPU and re enters in the queue and wait for the next chance.

Advantage: Perform best in terms of average response time, Works will in case of time sharing system, client server architecture and interactive system, kind of Shortest job implementation

Disadvantage: Longer process may starve, performance depends heavily on time quantum, no idea of priority.