# StartingPoint
all the way learning the book "算法竞赛入门经典" 2nd 



### 第一天

* 输入输出问题

  > 每行输出以回车符\n结尾
  >
  > 行首不应有多余空格
  >
  > 输出的每两个数/字符串之间以单个空格隔开

* 算法竞赛三件事：输入 计算 输出

* 小问题

  > M_PI不是ANSI_C所定义，可用acos(-1.0)计算pi
  >
  > KISS keep it simple and stupid
  >
  > 竟然刚开始忘记了怎么引入库文件。。。。#include <stdio.h>
  >
  > 判定三角形的方法简单到可以用确定的两边来算，大于差小于和



### 第二天

* 数据溢出问题用cpp解决（待定
* 要计算只包含加减乘的整数表达式除以n的余数可以在每步计算后分别取余，==结果不变==。（即如对和、差、积取余）
* c程序用time.h 中的   (double)clock()/==CLOCKS_PER_SEC== 计算
* ==鲁棒性==（robustness）容错性很重要，在题目要求之外的地方也做一定的预防
* 程序规模小的时候暴力也无所谓....

* 小问题

  > 尽量缩小变量定义范围（如for内
  >
  > ==浮点数比较误差==
  >
  > printf("%\*.\*f ", n,m,f )实现可变位的输出



### 第三天

*  a数组复制到b数组中使用memcpy(b,a,sizeof(type)*n); //在string.h里
* 赋值使用memset(a,0,sizeof(a));
* sprintf(dst, "%" , parameter);把字符串输入到dst中
* strchr(dst,c);在dst中查找字符c
* strlen(dst)
* 善用==库函数==（哭
* 常量数组做字典

* 小问题

  > 比较大的数组声明在主函数外（？



### 第四天

* 数组当==字典==

* 各种边界条件。。。。手搓代码的一天

* 小问题

  > 用索引可以取余但是用指针不方便取余，==环形==指针时比较麻烦



### 第五天

* flag的各种妙用/结合c语言的枚举
* 几道UVa easy题反而花了很大的篇幅（。
* 我错了 最后一道题才是最致命的（x
* ==数学方法==比模拟过程更科学
* 所以==不要==老想着模拟
* 可恶今天没做多少事



### 第六天

* 复习以前的代码



### 第七天

* 用另一种方法完成了第三单元的习题12。不得不说这个思路是真的很厉害。同时也意识到了自己的数学素养还没有达到促进自己的算法思维的境界，还需要多锻炼。之前的模拟思路可以保留留作一个问题。然后还可以去读读clib的源码。
* 恰当的利用==库函数==
* 还是开始第四单元吧。