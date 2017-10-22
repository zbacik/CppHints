# CppHints
CppHint is a series of examples which can be usefull for developers

## Value Categories
Meaning of value categories change over the time and some time is difficult to determine to which value category given expression belong. I give you usefull macro which help you exampine value category.
* [Source](https://github.com/zbacik/CppHints/tree/master/ValueCategory)
* [Reference](https://medium.com/@barryrevzin/value-categories-in-c-17-f56ae54bccbe)

## Default move constructor and assigment operator
If the definition of a class X does not explicitly declare a move constructor, one will be implicitly declared as defaulted if and only if

*  X does not have a user-declared copy constructor, and
*  X does not have a user-declared copy assignment operator,
*  X does not have a user-declared move assignment operator,
*  X does not have a user-declared destructor, and
*  the move constructor would not be implicitly defined as deleted.
[Source](https://github.com/zbacik/CppHints/tree/master/DefaultOperators)

## Universal reference

## Template
Template are very powerful tool to write C++ code. Over the time I encounter with many special cases which I try to summarize it. Maybe you find some things which can be useful.

#### 1. Template template parameters
Simply said: template argument dependent on another template argument. 


# Resources
* https://www.fluentcpp.com
* http://CppCon.org
* https://gcc.godbolt.org
* https://medium.com

