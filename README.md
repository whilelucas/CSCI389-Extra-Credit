# CSCI389 Extra-Credit Assignment
### by Lucas Yong

## Description
This project was undertaken for the "CSCI389 - Computer Systems" class at Reed College in the Fall 2018 semester.
The task is simply to optimize string to `uint32_t` conversion in C.
This project was completed on a MacBook Pro using the VirtualBox Ubuntu VM, with an 2.6 GHz Intel Core i5 processor.
Most code is written for us, and we merely have to optimize the following function: 

###Implementation #0:###

``` C
void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    nums[i] = atoi(lines[i]);
  }
}
```
This took roughly 0.041707 seconds on my machine (this was based on running the program 3 times and taking the average, and subsequent timings will also be recorded this way).

###Implementation #1:###

###Implementation #1:###

###Implementation #3:###

###Implementation #4:###
