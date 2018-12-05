# CSCI389 Extra-Credit Assignment
### by Lucas Yong

## Description
This project was undertaken for the "CSCI389 - Computer Systems" class at Reed College in the Fall 2018 semester.
The task is simply to optimize string to `uint32_t` conversion in C.
This project was completed on a MacBook Pro using the VirtualBox Ubuntu VM, with an 2.6 GHz Intel Core i5 processor.
Most code is written for us, and we merely have to optimize the following function: 

### Implementation #0:

``` C
void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    nums[i] = atoi(lines[i]);
  }
}
```
This took roughly **0.041707 seconds** on my machine (this was based on running the program 3 times and taking the average, and subsequent timings will also be recorded this way).

### Implementation #1:
The standard library function `atoi` takes a whole string and magically transforms it into a number. Then it struck me that the 'a' in '`atoi`' stands for ASCII, and I thought I'd use the ASCII table to convert not a whole string, but one character (which is a digit in this case) at a time. This led me to this code:
``` C
void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; ++i) {
    char *line = lines[i];
    quote_t num = 0;
    // While the next character (digit) is in range [0,9], take the number multiply it by 10 (to make room for the next digit)
    // Add the next digit, which is obtained by subtracting the ASCII code of that character (digit) with the ASCII code for '0'
    // This way, the character '0' gives the number 0, '1' gives 1, and so on
    while (*line >= '0' && *line <= '9') {
        num = (num * 10) + (*line - '0');
        ++line;
    }
    nums[i] = num;
  }
}
```
As a side note, I also changed from post-increment (`i++`) to pre-increment (`++i`) in the original `for` loop since Eitan said this is actually faster. Not sure if made a significant impact, but I guess every bit counts!
Overall I was skeptical of this working because it added another loop into the mix, but it turns that this first implementation would be my most dramatic performance improvement! Average runtime at this point is now **0.009534 seconds**, or 4.37x faster!

### Implementation #2:
Next, since my `while` loop condition checked two things, I decided to change the loop condition to instead check for the 'empty' character (`'\0'`), which would mean the loop would run until it hit the end of the string. This produced the same result, but checked one thing instead of two. Simply put, I went from this:
``` C
while (*line >= '0' && *line <= '9')
```
to this:
``` C
while (*line != '\0')
```
This change brought average runtime down to **0.007391 seconds**, or 1.29x faster than implementation #1.

### Implementation #3:
I wasn't really sure if there was anything left to do at this point (short of erasing everything and starting afresh), but then I thought about more about this line:
``` C
num = (num * 10) + (*line - '0');
```
Staring at it made me realise that perhaps `num * 10` was a costly operation. Since I was always going to be multiplying by 10, I thought it might be faster to perform that operation using the left-shift operator (`<<`). So that line became:
``` C
num = (num<<3) + (num <<1) + (*line - 48);
```
As you can see, I changed a straightforward to x10 to a more convoluted 'shift left by 3' (x8) + 'shift left by 1' (x2). Despite the convolution it did end up being marginally faster, and now my runtime is **0.007134 seconds**. This is a measly 1.04x faster than implementation #2, but still: *faster*. 😁

### Summary:
So by the end, my `convert_all` function looks like this:
``` C
void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; ++i) {
    char *line = lines[i];
    quote_t num = 0;
    while (*line != '\0') {
        num = (num<<3) + (num <<1) + (*line - '0');
        ++line;
    }
    nums[i] = num;
  }
}
```
and my timings are as follows:
| Implementation | Average Runtime | Speedup from Previous |
| -------------  | :-------------: | :-------:             |
| #0 (original)  | 0.041707        | baseline              |
| #1             | 0.009534        | 4.37x                 |
| #2             | 0.007391        | 1.29x                 |
| #3             | 0.007134        | 1.04x (5.85x overall) |




