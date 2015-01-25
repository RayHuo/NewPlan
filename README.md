# Epistemic Planning

----------------------------------

## 依赖
    1. [boost](http://www.boost.org/)
    2. [flex bison]
    
## 命名约定
    1. 类名、函数名、枚举
    	单词首字母大写
``` cpp
class MyClass {
public:
	void ThisIsMethod();
};

void ThisIsFunction();

enum AtomType {
};
```
    2. 变量名（除类变量，但包括结构体变量）
        小写加下划线
``` cpp
int this_is_variable;

void ThisIsFunction(int this_is_variable);

struct Position {
	int x;
	int y;
};
```
    3. 类变量(不管是否static都一样)
        小写加下划线，最后在加一个下划线
``` cpp
class Position {
public:
	int x_;
	int y_;
    static int z_;
};
```
    4. 宏（尽量不要用）
        大写下划线
``` cpp
#define MAX_NUM 10
```
    5. 常量
        k开头，然后后面单词得首字母大写
``` cpp
const int kMaxNum = 100;
```
    6. 枚举变量
        和常量一样
``` cpp
enum AtomType {
	kDisjunt,
	kConjunt,
};
```
	7. 文件名
		小写加下划线
