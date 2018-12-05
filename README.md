# CSCI389 Extra-Credit Assignment
### by Lucas Yong

## Description
This project was undertaken for the "CSCI389 - Computer Systems" class at Reed College in the Fall 2018 semester.
The task is simply to optimize string to `uint32_t` conversion in C.
Most code is written for us, and we merely have to optimize the following function: 

``` C
void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    nums[i] = atoi(lines[i]);
  }
}
```
