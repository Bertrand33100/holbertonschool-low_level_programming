# Green Efficiency Analysis

## Measurement Methodology

Here are the data and analysis results concerning the measurements performed on your computer.

First, our prerequisites:

### Requirements

**Compilation**

All C files must compile with:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`

**General Rules**

* The provided source files are the starting point.
* Only the instrumentation exercise is intended to be modified.
* No external libraries beyond the C standard library.
* Benchmarking must be executed on the same machine/environment for all measurements.

During the first measurement, we executed:

`./baseline_loop`

three consecutive times, which gave the following results:

Iterations: 100000000

Execution time: 0.489476 seconds

Iterations: 100000000

Execution time: 0.481380 seconds

Iterations: 100000000

Execution time: 0.488913 seconds

This gives an average of **0.486590 seconds**.

Next, we measured two different algorithms, the execution time of the first algorithm (naive) and the second algorithm (single-pass). Here are the results:

`./comparison_algorithms`

### First measurement

Naive algorithm result: 625025000

Naive algorithm time: 3.261735 seconds

Single-pass algorithm result: 25000

Single-pass algorithm time: 0.000150 seconds

### Second measurement

Naive algorithm result: 625025000

Naive algorithm time: 3.260587 seconds

Single-pass algorithm result: 25000

Single-pass algorithm time: 0.000127 seconds

### Third measurement

Naive algorithm result: 625025000

Naive algorithm time: 3.257318 seconds

Single-pass algorithm result: 25000

Single-pass algorithm time: 0.000126 seconds

This gives:

Average Naive algorithm time: **3.259880 seconds**

Average Single-pass algorithm time: **0.000134 seconds**

Finally, we measured different stages:

`./instrumentation_lab`

TOTAL seconds: 0.001023

BUILD_DATA seconds: 0.000424

PROCESS seconds: 0.000264

REDUCE seconds: 0.000330

`./instrumentation_lab`

TOTAL seconds: 0.001070

BUILD_DATA seconds: 0.000471

PROCESS seconds: 0.000265

REDUCE seconds: 0.000330

`./instrumentation_lab`

TOTAL seconds: 0.001059

BUILD_DATA seconds: 0.000459

PROCESS seconds: 0.000264

REDUCE seconds: 0.000331

This gives:

Instrumentation:

* Average BUILD_DATA: 0.000451 seconds
* Average PROCESS: 0.000264 seconds
* Average REDUCE: 0.000330 seconds
* Average TOTAL: 0.001051 seconds

To perform these measurements, we added `clock()` in order to measure separately the dataset construction (BUILD_DATA), the processing (PROCESS), the checksum calculation (REDUCE), as well as the total execution time (TOTAL).

## Observed Performance Differences

We can observe an execution time variation of **0.008 seconds** after performing three baseline measurements, which shows that there is a slight variation but that the results remain stable and reproducible overall.

During these different measurements, we observed a difference between the naive algorithm and the single-pass algorithm because the average Naive algorithm time is **3.259880 seconds** and the average Single-pass algorithm time is **0.000134 seconds**. We can therefore say that the naive algorithm is approximately **24,327 times slower** than the single-pass algorithm. This difference comes from the fact that the first algorithm performs many more operations, while the second one goes through the data only once.

The measurements from the instrumentation exercise also show that the total execution time is distributed among the different stages of the program. The **BUILD_DATA** phase required the most time according to the recorded measurements.

## Relation Between Runtime and Energy Consumption

A program that takes longer to execute generally uses the processor for a longer period. Under identical conditions, this can lead to higher energy consumption.

The measurements therefore show that a faster algorithm can help reduce CPU usage time, which improves the overall efficiency of the program.

## Limitations of the Experiment

The measurements were performed on a single machine. Performance may vary depending on the processor, the available memory, the processes running in the background, or the operating system.

## Practical Engineering Takeaway

What should be remembered from these experiments is that programs must be tested in order to optimize them and improve their efficiency and quality. If the goal is to sell more phones and make them become obsolete more quickly, the solution would be to create more resource-intensive programs that consume more battery power and more memory.
