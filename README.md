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

### Memory

Size: 26164116 kB

## Execution Timings

In the following lines are represented the applied optimizations and their own timing for the architecture explained above.

### Initialization

[/code/0-initialization.c](/code/0-initialization.c) Initialization: 2.261993885040283 (s)

### Loop interchange

[/code/1-1-loop-interchange.c](/code/1-1-loop-interchange.c) Loop Interchange XY: 5.190601825714111 (s)\
[/code/1-2-loop-interchange.c](/code/1-2-loop-interchange.c) Loop Interchange YX: 72.951828956604004 (s)

### Optimization flags

[/code/2-optimization-flags.c](/code/2-optimization-flags.c) Optimization Flag -O0: 5.178014993667603 (s)\
[/code/2-optimization-flags.c](/code/2-optimization-flags.c) Optimization Flag -O1: 1.435785055160522 (s)\
[/code/2-optimization-flags.c](/code/2-optimization-flags.c) Optimization Flag -O2: 0.622833967208862 (s)\
[/code/2-optimization-flags.c](/code/2-optimization-flags.c) Optimization Flag -O3: 0.633367061614990 (s)

### Parallel loops

[/code/3-1-parallel-loops.c](/code/3-1-parallel-loops.c) Parallel loop on X: 0.463387012481689 (s)\
[/code/3-2-parallel-loops.c](/code/3-2-parallel-loops.c) Parallel loop on Y: 0.544896125793457 (s)\
[/code/3-3-parallel-loops.c](/code/3-3-parallel-loops.c) Parallel loops on X and Y: 1.135539054870605 (s)

### Tiling

[/code/4-1-tiling.c](/code/4-1-tiling.c) Tiling with size of 512: 8.498560905456543 (s)\
[/code/4-1-tiling.c](/code/4-1-tiling.c) Tiling with size of 256: 6.340093135833740 (s)\
[/code/4-1-tiling.c](/code/4-1-tiling.c) Tiling with size of 128: 6.214891910552979 (s)\
[/code/4-1-tiling.c](/code/4-1-tiling.c) Tiling with size of 64: 6.244905948638916 (s)\
[/code/4-1-tiling.c](/code/4-1-tiling.c) Tiling with size of 32: 6.051318168640137 (s)\
[/code/4-1-tiling.c](/code/4-1-tiling.c) Tiling with size of 16: 5.508785009384155 (s)\
[/code/4-1-tiling.c](/code/4-1-tiling.c) Tiling with size of 8: 5.836018085479736 (s)\
[/code/4-1-tiling.c](/code/4-1-tiling.c) Tiling with size of 4: 6.414444923400879 (s)\
[/code/4-1-tiling.c](/code/4-1-tiling.c) Tiling with size of 2: 6.079902887344360 (s)
