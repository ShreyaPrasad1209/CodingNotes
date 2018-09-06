# C++ Important Concepts

## 1. Introduction:
Using C++ we can literally control any instruction of CPU. Other languages like C# and Java differs because they run on a virtual machine that's why many platforms applications can be developed through C++. It's native so it's fast but a bad C++ code will be slower whears in C# and Java there are optimizations done by their compilers which makes them handle fast without worrying much about code.

**#statements** is a pre processor statement it preprocesses before the actual process. main function is the entry point. Even though int main we don't need to return any value for it. it assumes that we are returning value 0.<br><br>
Header files are not compiled they are included C++ files are compiled only. Every C++ file gets compiled individually and converted to an object file. Linker takes all obj files of c++ and makes an executable.<br><br>
Declaration is like telling compiler that hey this function exists. And defination is telling that this is the body of this function.

```c++
//Defination
void Log(const char* msg)
{
    cout << msg << endl;
}

//Declaration
void Log(const char* msg);
```

To call a function from other c++ file just add declaration. While compiling compiler will trust that the function exists and if the function doesnt exists compiler won't give any error linker will give error. Linker job is to link up the functions.

**#include** copy pastes data from header file to our's<br>
**#define** find and replaces<br>
**#if** for conditions

## 2. Compilation:
Functions linking done through linker even if it's a project of one c++ file linker job is to define the entry point. If a file with no main function only present no compiler error but linker error.
functions have signatures which are used for linking.

Static are called only for that file and if it is included in some other file then it won't work.
Inline makes the compiler replace the code block into a line where it is used so making execution time faster.

**int** 2 bytes (32 bit) 4 bytes (64 bytes) compiler based<br>
1 bit is for sign 2^31 maximum number that can be stored.<br>
**unsigned int** means only positive<br>
**char** 1 byte<br>
**short** 2 byte<br>
**long**  4 byte<br>
**long long** 8 byte
**float** 4 byte with f prefix
**double** 8 byte
**bool** 1 byte it uses 1 bit only for 0 or 1 but to address memory 1 byte has to be occupied.

For creating function a stack for the function is created then all parameters are pushed there also return address is pushed to the stack. Jumping from one memory instruction to another for function then return back to the original. So all of this slows down program aswell.

Headers are basically used to store declarations. Since declarations are not required in modern java and C# programs no header files in it.
in header file #pragma once it tells compiler to include the header file only once in a translation unit.

```c++
One way to replace pragma once is 
#ifndef _BOOL
#define _BOOL
....
#endif
```

Basically it will check if **_BOOL** is not defined then it will define and end the condition.
Angle brackets are used to include header files that are in the system include directory otherwise for custom we use "

Quotes can be also used for include director aswell
C++ header files like iostream don't have .h extension while math.h kind of has because to distinguish between C++ header files and C header files by the developer

Constant folding: During debug mode it doesn't happen but in release mode when compiler optimizations take place compiler just reduce code for constant aritmetic operations simplifing the program.

Compiler also improves many operations such as one given below to bitshift operations which are faster in performance.

There are some compiler centric definations like #if _DEBUG in Visual Studio means the debug configuration condition of the program.

In a class 'this' keyword is used to reference current instance of the class
```c++
class Entity
{
public:
	int x, y;
	Entity(int x, int y)
	{
		Entity* e = this;
		e->x = x;
	}
};
```

## 3. Memory Allocation:

Dynamic Allocation is allocation at runtime<br>
Stack Allocation is allocation at compiletime

```c++
//creates a char and stores it address.
char* buffer = new char[8];
//assigns 8 zeroes in buffer address memory
memset(buffer, 0, 8);
//delete buffer from memory
delete[] buffer;
```

Pointers also gets stored in stack so pointer to pointer is meaningful.

We can use void* ptr (null pointer) but then derefrencing and adding value will be a problem.

```c++
void increment(int& value)
{
    value++;
}
```

This function when executed from main function will reference the parameter inputted and make changes in it so basically it is a cleaner way for pointer implementation.

Once reference declared it cannot be changed 

```c++
int a = 5;
int b = 8;
int& ref = a;
ref = b;
```

In this case ref will not become b but a's value will get to b

Array created through heap -
```c++
int* array = new int[5];
delete[] another;
```
normal array is created on stack and hence will get removed once memory is free by moving out of function heap created will be alive and need to be manually deleted.

New object will be created in heap so it will be stored unless manually deleted
stacks are used basically in heap we can have memory leaks if we forget to free memory so heaps are used when we need to extend visibility of objects.
smart pointers are something which can be created on heap and also deleted.

finding memory allocation in memory say when we declare an int 4 bytes of memory needed to be searched in memory. There's a free list in memory which tracks pointer of free memory.

```c++
malloc(bytes of memory)
//returns a pointer of heap memory it is simmilar to new keyword of C++

int* temp = (int*) malloc(sizeof(int));
int* temp = new int;
```

## 4. Derrived Data Types:

```c++
class Player
{
public:
    int x, y;
    int speed;

    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
};

int main()
{
    Player player;
    player.Move(5, 9);
}
```

Functions inside a class are called method.

Struct and class has no difference except default it's private in class but it's public in struct. It exists because of compatibility for C in C++ because C has no class.

static in C++ has two meanings for OOPS based it is same for all instance while for non OOPS it means that linker will not look for that variable while linking and that variable is for that translation unit only.

```c++
//main.cpp
int myvar = 5;
//new.cpp
int myvar = 6;
```

This will give a linker error
If static int myvar = 6 then no linker error and value of main.cpp myvar will be 5.

```c++
//main.cpp
extern int myvar;
```

This makes it 6 as it will look for external linking for the variable.

```c++
class Entity
{
    static int x, y;
public:
    int size;
};

int Entity::x;
int Entity::y;

int main()
{
    Entity e;
    Entity::x = 2;
    Entity::y = 5;
    e.size = 5;
}
```

```c++
void Function()
{
    //It will log 1 per function call
    //If it was static int i = 0 then it would have logged 1, 2, 3, 4
    int i = 0;
    std::cout << i++ << std::endl;
}
int main()
{
    Function();
    Function();
    Function();
    Function();
}
```

Exception handling can be done using try catch block
```c++
try
{
    x = new float[1000];
}
catch (bad_alloc e)
{
    throw "Out of memory exception!";
    exit(1);
    //Exit will exit the entire program. It is used to debug that something wrong has happened.
}
```

There are some defined exceptions: 
std::exception, std::bad_alloc, std::bad_cast, std::bad_exception, std::bad_typeid, std::logic_error, std::domain_error, std::invalid_argument, std::length_error, std::out_of_range, std::runtime_error, std::overflow_error, std::range_error, std::underflow_error

A new exception can be even defined like this
```c++
struct MyException : public exception
{
    const char * what () const throw ()
    {
        return "C++ Exception";
    }
};
```

```c++
enum level
{
    A, B, C
};
```

Here A=0, B=1, C=2<br>
if A=0, B, C<br>
B and C will automatically get 1, 2<br>
enum names doesn't mean anything in C++

```c++
class Entity
{
public:
    int x, y;

    Entity()
    {
        x=0;
        y=0;
    }
};
```

There's a default constructor in C++ if we have

```c++
Entity() = delete;
```

that constructor is also deleted meaning we cannot create instance of the method.

If we throw an exception inside a constructor then the constructor won't call hence desrupting the creation of the object. Exceptions are used to signal the occurence of an error.

```c++
throw "Incorrect parameter exception";
```

```c++
~Entity()
{
    x=0;
    y=0;
}
```
A destructor method will call after the object will destroy.

```c++
int main()
{
    {
        Function();
        void* ptr = new Function();
    }
}
```

Here the function's address is stored in stack which will be cleared right after the code exits from a brace (if condition, function end, loop body, etc...)

However using new operator for creating will create it in heap memory so it won't get cleared unless **delete ptr;** is called.

```c++
class sub : public parent
{
    ...
};
```

Inherting will give access to all parent class member. If we do sizeOf(sub) it will be size of all variables in sub and parent. Virtual method in parent class can be overrided from sub class

```c++
int main()
{
    Entity* e = new Entity();
    std::cout << e->GetName() << std::endl;
}
```
Virtual functions do something called dynamic dispatch it is implemented by v table. V table is a table that contains mapping for all the virtual tables.

```c++
std::string GetName() override
{
    return name;
}
```

Virtual functions has memory cost first at the time of initialization of v table and then at every time while looking through the table

pure virtual function or interface in C++ they are abstract functions in Java & C#

```c++
class Entity
{
public:
	virtual std::string GetName() = 0;
};
```

GetName is a virtual abstract function means it will have implementation in sub class only and also instance of Entity class cannot be created.
All abstract functions are needed to be implemented in sub class otherwise an error will show.

**Private:** visible to current and friend class<br>
**Public:** visible to all<br>
**Protected:** visible to current and sub class only

```c++
int main()
{
	const char* name = "che\0rno";
	std::cout << strlen(name) << std::endl;
	std::cin.get();
}
```
Here it will give 3

```c++
/*
wchar_t char16_t char32_t all are used to represent strings. wchar_t  represent distinct codes for all members of the largest extended character. char16 is smaller char32 is bigger than that. char* is the smallest.
*/

const char* name = u8"Cherno";
const wchar_t* name2 = L"Cherno";
const char16_t* name3 = u"Cherno";
const char32_t* name4 = U"Cherno";
```

Const keyword: It is like a promise to the compiler that this won't change it will stay constant then the compiler performs compilation performance improvements based on that. We can break this promise however by changing the value from memory resource manager but it's not good.

```c++
const int MAX_AGE = 90;
const int* a = new int;
*a = 2;                 //ERROR since a is constant
a = (int*)&MAX_AGE;     //No Error now
//Can't change content of the pointer here but can change pointer address

const int MAX_AGE = 90;
int* const a = new int;
//or int const* a = new int;
*a = 2;                 //No Error here
a = (int*)&MAX_AGE;     //ERROR since pointer of a is constant
//Can't change the pointer address here

const int* const a = new int;
//can't change anything now
```

Const in a method means that it can only read variables and not change them
however a mutable variable can be still changed from inside of the const method

```c++
class Entity
{
private:
    int m_x, m_y;
    int GetX() const
    {
        return m_x;
    }
};
```

Member Initializer Lists in C++ are used to initialize values in class constructor. It should be used for style purpose as it makes things in one line and also because normally initializing variables inside class will create a new object and then remove previous objects so using this is more optimized.

```c++
class Entity
{
private:
    int a, b;
public:
    Entity() : a(0), b(0)
    {
        Init();
    }
};
```

Must be initialized in proper sequence so b(0), a(0 is not correct.

```c++
int main()
{
    Entity a("abc");
    //is simillar to
    Entity a = "abc";
    //implicit conversion is happening
}

//if a function
void Function(Entity& entity)
{
}

int main()
{
    Function("abc");
    //this will work because string is a valid constructor for Entity object and hence implicit coversion will take place
}
```

If there is explicit keyword before constructor then implicit conversion won't take place

```c++
Entity
{
private:
    std::string m_Name;
public:
    explicit Entity(std::string& name) : m_Name(name) {}
};
```

There's function overloading in which we have two functions with same name but different parameters and different implementations.

Operator overloading can be done here we have a struct for maths vector which we want to work with cout.

```c++
struct Vector2
{
    float x, y;
    Vector2(float _x, float _y) : x(_x), y(_y) {};
    Vector2 Add(const Vector2& other) const
    {
        return Vector2(x+other.x, y+other.y);
    }
    Vector2 operator+(const Vector2& other) const
    {
        return Add(other);
    }
};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
    stream << other.x << ", " << other.y;
}

int main()
{
    Vector2 posA(5.0f, 7.0f);
    Vector2 posB(9.0, 10.0f);
    cout::cout << (posA + posB) << cout::endl;
}
```

## 5. Advanced Pointers Concepts:

Smart pointer is allocated on heap but it gets automatically deleted after specific time.

1) Unique pointer :
```c++
class uniquePtr
{
private:
    Entity* m_Ptr;
public:
    uniquePtr(Entity* ptr) : m_Ptr(ptr) {}
    ~uniquePtr(Entity* ptr)
    {
        delete m_Ptr;
    }
};

int main()
{
    {
        uniquePtr e = new Entity();
    }
}
```

This heap allocation will get destroyed once out of the scope

OR

```c++
#include <memory>
int main()
{
    {
        std::unique_ptr<Entity> e = std::make_unique<Entity>();
		//OR
        std::unique_ptr<Entity> e(new Entity());
        
        e->ANYFUNCTION();
    }
}
```

Using new Entity() from constructor is not preffered using make_unique is better because of exception safety. It is slightly safer if constructor happens to throw exception it will end up with dangling points with no reference and hence memory leaks.

```c++
//Copying unique_ptr is not possible
std::unique_ptr<Entity> e1 = std::make_unique<Entity>();
//It will give error
```

2) Shared_Ptr:

```c++
#include <memory>
int main()
{
	{
		std::shared_ptr<Entity> e0;
		{
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			e0 = shared_ptr;
		}
	}
}
```
It gives copying ptr ability and once all copy gets out of scope then the memory gets free. First shared ptr dies after end of first scope but it gets copied to e0 shared_ptr so when that scope dies then only Entity is destroyed

3) Weak_Ptr:
```c++
Same as shared pointer but it doesn't matter if it is alive it won't keep Entity alive
#include <memory>
int main()
{
    {
        std::weak_ptr<Entity> e0;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e0 = shared_ptr;
        }
    }
}
```

Here now entity gets destroyed after first scope. We can use entity object from e0 but it's presence won't keep entity alive.

Smart pointers are very useful it is very memory managed so it can be used any time. it doesn't replace new and delete it is a smart defined way to handle heap allocations.

```c++
struct Vector2
{
    float x, y
};

int main()
{
    Vector2 a = { 1.0f, 2.0f };
}

memcpy(m_Buffer, string, m_Size);
m_Buffer & string are of type char*

class String
{
private:
    char* m_Buffer;
    unsigned int m_size;
public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }

    ~String()
    {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

int main()
{
    String string = "Cherno";
    String string2 = string;
    string2[2] = 'a';

    std::cout << string << std::endl;
    std::cout << string2 << std::endl;
}
```

Because of the function operator << of cout declared as friend of String class it can access it's private variable m_Buffer
In this case both string will output will be Charno and at the end of scope an error will occur. It is because while copying the exact pointer gets coppied so when destructor is called m_Buffer is deleted and then the next class also tries to delete the already deleted m_Buffer which gives the error so we need that when we copy the class the pointer gets a new block of memory this is called deep copying

inside class

```c++
String(const String& other) = delete 
this will make it un coppiable like in unique pointer
String(const String& other) : m_Size(other.m_Size)
{
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
}
```

## 5. Extra Concepts:

```c++
Struct Vector3
{
    float x, y, z;
};

int main()
{
    int offset = (int)&((Vector3*)nullptr)->z;
}
```

offset is 8 for z 4 for y 0 for x

Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms and iterators. It is a generalized library and so, its components are parameterized.

It containts - Sorting, Searching, reversing, max element, min element, accumulate which is sum of elements of an itterator, count in itterator, find, binary_search, lower_bound which is the itterator, first or lower occurence of the element in the itterator, upper_bound, erase, distance which is distance between two iterators, next_permutation, prev_permutation.

5 10 15 20 20 23 42 45 <br>
Vector after performing next permutation:<br>
5 10 15 20 20 23 45 42 <br>
Vector after performing prev permutation:<br>
5 10 15 20 20 23 42 45 

Array Algorithms include all_of() which is like running a loop on the array.

```c++
all_of(ar, ar+6, [](int x) { return x>0; })?
          cout << "All are positive elements" :
          cout << "All are not positive elements";
```

any_of() it is same as all_of except it will return after finding any true case, none_of()

copy_n() to copy arrays

```c++
copy_n(ar, 6, ar1);
```

iota() it assigns constant values to the array. like - 20 21 22 23 24 25

```c++
iota(ar, ar+6, 20);
```

There are helpers for - vector, list, deque, arrays, forward_list, queue, priority_queue, stack, set, multiset, map, multimap, Functors, Iterators, pair.

Foreach loops are a short hand

```c++
std::vector<Vertex> vertices;
vertices.push_back({1, 2, 3});

for(Vertex& v : vertices)
    std::cout << v << endl;
```

vector will resize like 1 then 2 then 4 then 8 so if we are planning to have atleast 4 elemets then we can reserve it in that way unecessary copying and deletion of previous memory allocation can be avoided.
std::vertices.reserve(3);

Second optimization strategy is that using push_back results in copying of object to the vector memory which can be avoided by
vertices.emplace_back(1, 2, 3);

Linking projects with external libraries. Static linking is in which the
source code gets included in the final exe whearas in dynamic linking,
linking libraries is done at runtime. (DLL file - Dynamic Linking Library)
Static linking is faster.

To return multiple values from the function we can return a struct with
those values, or we can return a vector containing that values or pointer to the
values, or we can return a tuple

```c++
#include <utility>
std::tuple<std::string, int> returnsomevalue()
{
    return std::make_pair("as", 12);
}

int main()
{
    //std::tuple<std::string, int> sources = returnsomevalue();
    auto sources = returnsomevalue();
    std::string a = std::get<0>(sources);
    int b = std::get<1>(sources);
}
```

same way we can use pair it will have 2 non simmilar values only. then we can use

```c++
auto sources = returnsomevalue();
std::string a = sources.first;
```

or sources.second

struct is more better because it is much clearer and easy to read instead
of first second we can use direct variable name.

Function pointers are void*

```c++
void HelloWorld()
{
    std::cout << "Hello World" << std::endl;
}

int main()
{
    auto function = HelloWorld;
    //or void(*functionName)() = HelloWorld;
    function();
    function();
}
```

This gets meaningful if we want to pass function to another function. This will retrieve the memory location of the function

```c++
void ForEach(const std::vector<int> &values, void(*func)(int))
{
    for (int value : values)
        func(value);
}

int main()
{
    std::vector<int> values = { 1, 2, 3, 4 };
    ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });
}

Inline functions which is to replace function pointers are the lambda functions

std::vector<int> values = { 1, 5, 4, 2, 3 };
auto it = std::find_if(values.begin(), values.end(), [](int value) { return value > 3; });
std::cout << *it << std::endl;
//5
```

Threads in C++

```c++
static bool s_Finished = false;

void DoWork()
{
	using namespace std::literals::chrono_literals;
	while (!s_Finished)
	{
		std::cout << "Working...\n";
		std::this_thread::sleep_for(1s);
	}
}

int main()
{
	std::thread worker(DoWork);
	std::cin.get();
	s_Finished = true;
	worker.join();
	std::cin.get();
}
```

Output-<br>
Working...<br>
Working...<br>
Working...<br>
Working...<br>
unless something is input by user then the thread get's completed.

Timer functions to precisely calculate time of the system is very important for example to find the duration of time taken by an algorithm.

```c++
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    using namespace std::literals::chrono_literals;
	
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(1s);
    auto end =  std::chrono::high_resolution_clock::now();
	
    std::chrono::duration<float> duration = start - end;
    std::cout << duration.count() << "s" << std::endl;

    std::cin.get();
}
```

```c++
int** a2d = new int*[50];
for(int i=0; i<50; i++)
    a2d[i] = new int[50];

int*** a3d = new int**[50];
for(int i=0; i<50; i++)
{
    a3d[i] = new int*[50];
    for(int j=0; j<50; j++)
        a3d[i][j] = new int[50]
}

a2d[0][0] = 1;
a3d[0][0][0] = 1;

for(int i=0; i<50; i++)
    delete[] a2d[i];
delete[] a2d;

for(int i=0; i<50; i++)
{
    for(int j=0; j<50; j++)
        delete[] a2d[i][j];
    delete[] a2d[i];
}
delete[] a2d;
```

Here we are reserving different block of memory for different rows or columns that we are making and hence it can be far in the memory address.
Fetching those far memories can result in slow speed hence we should essentially make our own allocator that can allocate memory for us nearer.

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> values = { 3, 5, 1, 4, 2 };
	std::sort(values.begin(), values.end(), [](int a, int b)
	{
		return a < b;
	});
}
```

Output: 1 2 3 4 5

instead of lambda we can pass inbuilt functions from functional std::greater<int>()

compare function if return true then a will be placed before b otherwise opposite.

struct or class occupies sum of memory occupied by individuals however a union occuies memory of the most memory costly item.

```c++
struct Vector2
{
	float x, y;
};

struct Vector4
{
	union
	{
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			Vector2 a, b;
		};
	};
};
```

Now here if we set b value of the vector4 struct then z also get's changed to the same

```c++
class Base
{
    Base() { std::cout << "Base Constructed\n;" }
    ~Base() { std::cout << "Base Destructed\n;" }
}
class Derrived : public Base
{
    Derrived() { std::cout << "Derrived Constructed\n;" }
    ~Derrived() { std::cout << "Derrived Destructed\n;" }
}

int main()
{
    Base* base = new Base();
    delete base;
	
    //Base Constructed
    //Base Destructed

    Derrived* derrived = new Derrived();
    delete derrived;
	
    //Base Constructed
    //Derrived Constructed
    //Derrived Destructed
    //Base Destructed

    Base* poly = new Derrived();
    delete poly;
	
    //Base Constructed
    //Derrived Constructed
    //Base Destructed
}
```

making destructor virtual of the base class will make polymorphic function call
destructor as well hence avoiding memory leaks.

Type casting done explicitly by paranthesis is the c style type casting whereas
C++ type castings are - static_cast, dynamic_cast, const_cast, interpret_cast

```c++
double s = static_cast<double>(integer);
```

dynamic cast will perform type casting at runtime if it is possible. value gets
null if the conversion is not possible.

C++ type casting makes code readiblity better. C style and C++ both are equivalent
