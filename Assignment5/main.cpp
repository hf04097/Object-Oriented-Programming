#include <cassert>
#include <cstring>

#include <iostream>

#include "SmartString.h"

using namespace std;

void RunTests()
{
const char* status[2] = { "Failed", "Passed" };
// Test 1
{
SmartString s1;
char test1_arr[1] = { '\0' };
bool test1 = s1 == "" && s1 == test1_arr && s1.Length() == 0;
cout << "Test 1: Should be an empty string if created with default constructor" << endl;
cout << status[test1] << endl << endl;
}

// Test 2
{
SmartString s2("Hello");
bool test2 = s2 == "Hello" && s2.Length() == 5;
cout << "Test 2: SmartString(\"Hello\").Show() should print \"Hello\""  << endl;
cout << status[test2] << endl << endl;
}

// Test 3
{
SmartString s1("Hello");
SmartString s2(s1);
bool test = s1 == s2 && s2 == "Hello" && s1.Length() == s2.Length();
s2 += " World";
test = test && s1 == "Hello";
cout << "Test 3: Copy constructor should work properly" << endl;
cout << status[test] << endl << endl;
}
// Test 4
{
SmartString s1;

s1.Join("");

bool test = s1 == "" && s1.Length() == 0;
s1.Join("Hello");

test = test && s1 == "Hello" && s1.Length() == 5;

SmartString s2;
s1.Join(s2);
test = test && s2 == "" && s1 == "Hello" && s1.Length() == 5;

s1.Join(s1);
test = test && s1 == "HelloHello" && s1.Length() == 10;

cout << "Test 4: SmartString::Join should work properly" << endl;
cout << status[test] << endl << endl;
}
// Test 5
{
SmartString s1;
bool test = (s1 + "") == "" && s1.Length() == 0;
test = test && (s1 + s1) == "" && s1.Length() == 0;
test = test && (s1 + "Hello") == "Hello" && s1.Length() == 0;
SmartString s2("World");
test = test && (s1 + s2) == "World" && s1 == "" && s2 == "World";
cout << "Test 5: + operator should work properly" << endl;
cout << status[test] << endl << endl;
}
// Test 6
{
SmartString s1;
s1 += s1;
bool test = s1 == "" && s1.Length() == 0;
s1 += "Hello";
test = test && s1 == "Hello" && s1.Length() == 5;
SmartString s2("World");
s1 += " ";
s1 += s2;
test = test && s1 == "Hello World" && s1.Length() == 11;
s2 += "";
s2 += s1 + s2;
test = test && s2 == "WorldHello WorldWorld" && s2.Length() == 21 && s1 == "Hello World";
cout << "Test 6: += operator should work properly" << endl;
cout << status[test] << endl << endl;
}
// Test 7
{
SmartString s1;
s1 = s1;
bool test = s1 == "" && s1.Length() == 0;
s1 = "Hello";
test = test && s1 == "Hello" && s1.Length() == 5;
SmartString s2("World");
s1 = s2;
test = test && s1 == "World" && s1 == s2 && s1.Length() == 5 && s2.Length() == 5;
s2 = "";
test = test && s2 == "" &&  s1 == "World" && s2.Length() == 0;
cout << "Test 7: = operator should work properly" << endl;
cout << status[test] << endl << endl;
}
// Test 8
{
SmartString s1;
s1 = s1;
bool test = s1 == "" && s1 == s1;
s1 = "Hello";
test = test && s1 == "Hello";
SmartString s2("World");
s1 = s2;
test = test && s1 == "World" && s1 == s2;
s2 = "";
test = test && s2 == "" &&  s1 == "World";
cout << "Test 8: == operator should work properly" << endl;
cout << status[test] << endl << endl;
}
}

int main(int argc, char** argv) {
  char hello_array[] = "Hello ";
  char world_array[] = "World!";
  char hello_world_array[] = "Hello World!";
  char* texts[] = {hello_array, world_array, hello_world_array};

  std::cout << "Testing " << std::flush;

  for (auto text_array : texts) {
    SmartString smart_string(text_array);
    assert(smart_string.Length() == strlen(text_array));
    std::cout << "." << std::flush;
    assert(smart_string.Length() == SmartString(smart_string).Length());
    std::cout << "." << std::flush;
    assert(smart_string == text_array);
    std::cout << "." << std::flush;
    assert(smart_string == SmartString(smart_string));
    std::cout << "." << std::flush;
  }

  {
    SmartString hello(hello_array);
    assert(hello + world_array == hello + SmartString(world_array));
    std::cout << "." << std::flush;
    SmartString temp(hello);
    temp += world_array;
    assert(temp == hello_world_array);
    std::cout << "." << std::flush;
    hello += SmartString(world_array);
    assert(temp == hello);
    std::cout << "." << std::flush;
  }

  {
    SmartString hello(hello_array);
    SmartString temp(hello);
    temp.Join(world_array);
    assert(temp == hello_world_array);
    std::cout << "." << std::flush;
    hello.Join(SmartString(world_array));
    assert(temp == hello);
    std::cout << "." << std::flush;
  }

  std::cout << "\nAll tests passed.\n";
  RunTests();

  return 0;
}

