# My Experiment on Stencil Computation Code Optimization

## Summary

- **[Architecture](#architecture)**
  - **[CPU](#cpu)**
  - **[Memory](#memory)**
- **[Execution Timings](#execution-timings)**
  - **[Initialization](#initialization)**
  - **[Loop interchange](#loop-interchange)**
  - **[Optimization flags](#optimization-flags)**
  - **[Parallel loops](#parallel-loops)**
  - **[Tiling](#tiling)**
  - **[Dimension Augmentation (3-dimensional)](#dimension-augmentation)**

## Architecture

### CPU

Model name: Intel(R) Core(TM) i5-9600K CPU @ 3.70GHz \
CPU(s): 6 \
Socket(s): 1 \
Core(s) per socket: 6 \
Thread(s) per core: 1 \
Cache L1d: 192 KiB (6 instances) \
Cache L1i: 192 KiB (6 instances) \
Cache L2: 1.5 MiB (6 instances) \
Cache L3: 9 MiB (1 instance)
Intel Hyper-Threading Technology: No

### Memory

Size: 26164116 kB

## Execution Timings

In the following lines are represented the applied optimizations and their own timing for the architecture explained above.

### Initialization

[/code/0-initialization.c](/code/0-initialization.c) Initialization: 3.568044900894165 (s)

### Loop interchange

[/code/1-1-loop-interchange.c](/code/1-1-loop-interchange.c) Loop Interchange XY: 5.053354024887085 (s)\
[/code/1-2-loop-interchange.c](/code/1-2-loop-interchange.c) Loop Interchange YX: 55.834384918212891 (s)

### Optimization flags

[/code/2-1-optimization-flags.c](/code/2-1-optimization-flags.c) Optimization Flag -O0: 5.049360036849976 (s)\
[/code/2-2-optimization-flags.c](/code/2-2-optimization-flags.c) Optimization Flag -O1: 1.373454093933105 (s)\
[/code/2-3-optimization-flags.c](/code/2-3-optimization-flags.c) Optimization Flag -O2: 0.593156099319458 (s)\
[/code/2-4-optimization-flags.c](/code/2-4-optimization-flags.c) Optimization Flag -O3: 0.590475082397461 (s)

### Parallel loops

[/code/3-1-parallel-loops.c](/code/3-1-parallel-loops.c) Parallel loop on X: 0.458544969558716 (s)\
[/code/3-2-parallel-loops.c](/code/3-2-parallel-loops.c) Parallel loop on Y: 0.476073026657104 (s)\
[/code/3-3-parallel-loops.c](/code/3-3-parallel-loops.c) Parallel loops on X and Y: 0.741912126541138 (s)

### Tiling

[/code/4-1-tiling.c](/code/4-1-tiling.c) Tiling with size of 16384: 0.445145130157471 (s)\
[/code/4-2-tiling.c](/code/4-2-tiling.c) Tiling with size of 10922: 0.459971904754639 (s)\
[/code/4-3-tiling.c](/code/4-3-tiling.c) Tiling with size of 8192: 0.442295074462891 (s)\
[/code/4-4-tiling.c](/code/4-4-tiling.c) Tiling with size of 5461: 0.453767061233521 (s)

### Dimension Augmentation (3-dimensional)

[/code/5-1-dimension-augmentation.c](/code/5-1-dimension-augmentation.c) Dimension Augmentation - Tiling with size of 16384: 0.264962911605835 (s)\
[/code/5-2-dimension-augmentation.c](/code/5-2-dimension-augmentation.c) Dimension Augmentation - Tiling with size of 10922: 0.291139841079712 (s)\
[/code/5-3-dimension-augmentation.c](/code/5-3-dimension-augmentation.c) Dimension Augmentation - Tiling with size of 8192: 0.264523983001709 (s)\
[/code/5-4-dimension-augmentation.c](/code/5-4-dimension-augmentation.c) Dimension Augmentation - Tiling with size of 5461: 0.267640113830566 (s)
