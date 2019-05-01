# Question 1

## Part 1

### 1

- Third code run fastest
- Time difference between second and third code is not that significant

  Code Number | Time 
  ----------- | -------- 
  1 | 16.097 s 
  2 | 0.031 s 
  3 | 0.030 s

### 2

- Time reduces significantly in comparision to unchanged code
- However it is still very less as compared to code2 and code3

  Code | Time 
  ----------- | ------- 
  1_changed | 0.257 s

## Part 2

### 1

- schedule(guided) and schedue(dynamic) are taking least time

  Scheduling Type | Time
  --------------- | --------
  Guided          | 36.002 s
  Static          | 54.002 s
  Dynamic         | 36.002 s

# Question 2

- Time Taken by code is as follow

  Number of Threads | Time
  ----------------- | -------
  1 Thread          | 4.435 s
  2 Threads         | 2.409 s
  4 Threads         | 1.228 s
  6 Threads         | 0.843 s
  24 Threads        | 0.435 s

- When using 6 threads over 1 thread the speedup is 5.2 times.
- When using 4 threads over 1 thread the speedup is 3.6 times.
- The reason for the time not reducing to (1/4)th is because of overhead.
<img id="RuPic" src="user2/graph"/>

# Question 3

- Time Taken by code is as follow

  Number of Threads | Time
  ----------------- | -------
  1 Thread          | 7.053 s
  2 Threads         | 3.767 s
  4 Threads         | 1.864 s
  6 Threads         | 1.285 s

- Time Taken by code is as follow

  Chunk Size         | 100     | 200
  ------------------ | ------- | -------
  Guided Scheduling  | 1.592 s | 1.504 s
  Static Scheduling  | 2.327 s | 2.312 s
  Dynamic Scheduling | 1.562 s | 1.608 s

- The Speedup for 6 cores vs 1 core is 5.488

- Using Scheduling as guided and chunk size 100 the time taken is minimum using 6 threads
<img id="RuPic" src="./user3/graph"/>
# Question 4

## Part 1

- Starting Balance 0.00
- After deposit balance 10000000.00
- After withdrawl balance 0.00

## Part 2

- Starting Balance 0.00
- After deposit balance 2892800.00
- After withdrawl balance 98550.00

## Part 3

- Starting Balance 0.00
- After deposit balance 0.00
- After withdrawl balance 0.00
- Same result both times

## Part 4

- Starting Balance 0.00
- After deposit balance 10000000.00
- After withdrawl balance 0.00
- Same result both times

## Part 5

- Starting Balance 0.00
- After deposit balance 10000000.00
- After withdrawl balance 0.00

## Observations:
- In part 4 the balance variable is made critical thus the result are accurate.
- In part 5 we are using reduction thats why results are acurate.