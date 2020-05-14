## CPU Scheduling using FCFS and SJF
C program for FCFS and SJF that reads input from input.txt and writes the executed output in output.txt. The file is compiled using GCC-TDM and hence can be directly executed using program.exe. Our goal is to determine the average waiting time and average turnaround time for each method using the same input values. This will help us understand the concept of CPU Scheduling in a better way.

## Input
The input for the program should be supplied in "input.txt" as the following format:  
<process_id>,<arrival_time>,<burst_time>  
We will be using the following values for this example.  
  
![input](https://user-images.githubusercontent.com/32812640/81935233-f0fbda80-960d-11ea-9a8a-09e3dd632da4.PNG)

## Execution
Once the values are entered, simply run program.exe to execute the algorithms.
  
## FCFS
First Come First Serve simply queues processes in the order they arrive in the ready queue. Here, the process that comes first will be executed first and next process will start only after the previous gets fully executed.  
  
1. Completion Time: Time at which process completes its execution.  
2. Turn Around Time: Time Difference between completion time and arrival time. (Turn Around Time = Completion Time – Arrival Time)  
3. Waiting Time: Time Difference between turn around time and burst time. (Waiting Time = Turn Around Time – Burst Time)  
  
So, after executing program.exe, following will be the output for FCFS:  
  
![fcfs](https://user-images.githubusercontent.com/32812640/81937417-3968c780-9611-11ea-866b-415d2ab2f43a.PNG)

## SJF
Shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next. SJN is a non-preemptive algorithm.  
  
1. Completion Time: Time at which process completes its execution.
2. Turn Around Time: Time Difference between completion time and arrival time. (Turn Around Time = Completion Time – Arrival Time)
3. Waiting Time: Time Difference between turn around time and burst time. (Waiting Time = Turn Around Time – Burst Time)  
  
Following is the output for SJF:  
  
![sjf](https://user-images.githubusercontent.com/32812640/81938292-594cbb00-9612-11ea-9d30-060445c3164f.PNG)

## Output
By now your output should be written in "output.txt". (If this file does not exist, the program will create a new file. Otherwise it will override the existing file).  
  
![output](https://user-images.githubusercontent.com/32812640/81936073-42f13000-960f-11ea-8ede-fd235159bc6a.PNG)
