
# Finding Absolute Value Without Using Conditional Statements


`arr[5] = {-123, 4, 234, -234, -3442};`

`for (int i = 0; i < 5; i++)`

`cout << ~(arr[i] - 1);`

But using Bitwise Not ("~") not always will yield in right answers,

in my vc code 

`cout << ~(-32 - 1); //returns 32`

but in GFG C++ online compiler

`cout << ~(-32 - 1); //returns 326296512`


## So for a robust approach I found out the below method:

```c++
int absFunc(int n)
    {
        uint32_t temp = n >> 31;
        n ^= temp;
        n += temp & 1;
        return n;
    }
```



Note that : 

6 -> **(0000 0000 0000 0000 0000 0000 0000 0110)** in 32 bit integer representation,

but for -ive integers, the 2's complement representation is used:

Therefore for -6,

first do (1's complement) of 6:

(1's complement) of 6 -> **(1111 1111 1111 1111 1111 1111 1111 1001)**

then add 1 

(added 1) to 6 -> 

**(1111 1111 1111 1111 1111 1111 1111 1010)** -> (32 bit binary reprsentation) of -6

>Also the M.S.B. is the sign bit: 1 for negative and 0 for positive

> When right shifting a -ive integer, 1s are put at the emptied places:

(-6) >> 31 (to get the signed bit) = **(1111 1111 1111 1111 1111 1111 1111 1111)**

> but for +ive integers, 0s are put at the emptied places as usual:
(6) >> 31 (to get the signed bit) = **(0000 0000 0000 0000 0000 0000 0000 0000)**



Now for the approach: 

(-6)^(-6>>31) will yield:

**(1111 1111 1111 1111 1111 1111 1111 1010)**

**(1111 1111 1111 1111 1111 1111 1111 1111)**

**(0000 0000 0000 0000 0000 0000 0000 0101)** -> 5

and (6)^(-6>>31) will yield:

**(0000 0000 0000 0000 0000 0000 0000 0110)**

**(0000 0000 0000 0000 0000 0000 0000 0000)**

**(0000 0000 0000 0000 0000 0000 0000 0110)** -> 6

*notice that*:

temp(which contain n>>31) & 1{

    will give either 1 (for -ive integers)
    or 0 (for +ive integers)

}

therefore {

    for -ive integers:
    n = n + (temp & 1) -> n = n + 1
    and for +ive integers:
    n = n + (temp & 1) -> n = n + 0

}

thus n (which has been XORed with temp) gives its absolute value when we add (temp & 1) to it.
