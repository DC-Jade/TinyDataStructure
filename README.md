# TinyDataStructure
## Intrucduction
- This is a datastructure learning notebook

- Ref: \

  [数据结构-邓俊辉](https://www.xuetangx.com/course/THU08091000384/1391601)\

## Supported

* os

  Ubuntu 16.04 LTS

* compiler

  g++ version 9.4.0

## Required

* Use cmake version 3.22 to build this project

## Run test

1. git clone
```bash
$ git clone git@github.com:DC-Jade/TinyDataStructure.git
```
2. build && run
```bash
$ cmake ./ && make && ./bin/main.o
```

## BitMap

```C
/* k >> 3 refers to the index of k in array */
/* k & 0x07 equal to k % 8 */
/* 1 << (k & 0x07) refers to index in a char(8 bits) */
void Set(int k)   { Expand(k); _M[k >> 3] |= (1 << (k & 0x07)); }
void Clear(int k) { Expand(k); _M[k >> 3] &= ~(1 << (k & 0x07)); }
bool Test(int k)  { Expand(k); return _M[k >> 3] & (1 << (k & 0x07)); }
```



