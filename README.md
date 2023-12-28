# CPU Scheduler Simulator
A project to simulate CPU scheduling and to compare statistics across various scheduling algorithms.

## Project Phases
The project is split into the following phases:

### Phase I
 - Single Core
 - The processes do not have priorities
 - Simulation using a single thread

### Phase II
 - Single Core
 - The processes have priorities
 - Simulation using a single thread

### Phase III
 - Multi Core
 - The processes have priorities
 - Simulation using a single thread

### Phase IV
 - Multi Core
 - The processes have priorities
 - Simulation using a multiple threads. Each process will run in a separate thread

## Simulation Framework
In phases I-III, each process is an object with the following randomly generated fields:
- process ID - to identify each process
- arrival time - when the process arrived at the scheduler
- burst time - expected number of cycles to run this process
The limits for the above fields can be customized.

A vector of processes is passed to the scheduler, and the scheduler simulates the various algorithms and calculates the following statistics for each:
- CPU Utilization
- Throughput
- Average Turnaround Time
- Average Wait Time

## Scheduling Algorithms
These are the basic algorithms that we will be implementing in the various phases

### First Come First Served (FCFS)
The processes are executed in the order in which they arrive.

### Shortest Job First (SJF)
When a core becomes available, it picks up the waiting process with the shortest burst time to run next.

### Round Robin (RR)
Each waiting process is given a certain number of cycles (called a round) before core switches to the next process.

## Results
The process parameters were generated subject to the following constraints
```
n = 200
0 <= i < n
1 <= arrivalTime[i] <= n * 2
1 <= burstTime[i] <= n / 2
```

### Phase I

|      | FCFS | SJF | RR |
|:------:|:------:|:-----:|:------:|
| CPU Utilization |  0.999811 |  0.999811 |  0.999811 |
| Throughput (processes completed / cycles taken) | 0.0188733 | 0.0188733 | 0.0188733 |
| Average Turnaround Time (in CPU cycles) | 5005.69 | 3487.11 | 6988.02 |
| Average Wait Time (in CPU cycles) | 4952.71 | 3434.14 | 96.65 |
