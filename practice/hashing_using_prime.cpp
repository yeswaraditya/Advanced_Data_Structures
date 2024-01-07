#include <iostream>
#include <vector>
#include <cmath>
static int count = 0;
using namespace std;
int is_prime(int a)
{
if (a < 2)
return 0;
for (int i = 2; i * i <= a; ++i)
{
if (a % i == 0)
return 0;
}
return 1;
}
int prime_number(int capacity)
{
while (true)
{
if (is_prime(capacity))
return capacity;
else
--capacity;
}
}
class Data
{
public:
int keyValue;
int keyCount;
};
class Hashtable
{
public:
int capacity, fun;
vector<Data> vec;
Hashtable(int capacity_, int fun_)
{
capacity = capacity_;
fun = fun_;
vec.resize(capacity);
for (int i = 0; i < capacity; i++)
{
vec[i].keyValue = 0;
vec[i].keyCount = 0;
}
}
int funselect(int key)
{
int hash_index = 0;
int r = 0;
int i = 0, j = 0, sum = 0;
double con = 0.5;
switch (fun)
{
case 1:
return key % capacity;
case 2:
{
int pow = key * key;
int number = pow;
string str = to_string(pow);
int a = str.size();
if (a % 2 == 0)
{
cout << "The square of the number is even and taken the 3rddigit
from last " << endl;
while (pow > 0 && i <= 3)
{
r = pow % 10;
pow = pow / 10;
i++;
}
hash_index = r;
}
else if (a == 1)
hash_index = key;
else
{
cout << "Taking the middle digit of square of the number" << endl;
while (number > 0 && j <= 2)
{
r = number % 10;
number = number / 10;
j++;
}
hash_index = r;
}
break;
}
case 3:
while (key > 0)
{
r = key % 10;
sum += r;
key = key / 10;
}
if (sum >= capacity)
hash_index = sum % capacity;
else
hash_index = sum;
break;
case 4:
hash_index = floor(capacity * ((con * key) - floor(con * key)));
break;
default:
cout << "Wrong Input\n";
exit(0);
}
return hash_index;
}
void rehash()
{
int newcapacity = capacity * 2;
int newprime = prime_number(newcapacity);
vector<Data> newvec;
newvec.resize(newprime);
for (int i = 0; i < newprime; i++)
{
newvec[i].keyValue = 0;
newvec[i].keyCount = 0;
}
for (int i = 0; i < capacity; i++)
{
if (vec[i].keyValue != 0)
{
int index = funselect(vec[i].keyValue);
newvec[index].keyValue = vec[i].keyValue;
newvec[index].keyCount = vec[i].keyCount;
}
}
vec = newvec;
capacity = newprime;
}
void insert(int key)
{
int index = funselect(key);
if (vec[index].keyValue != 0)
{
cout << "\nKey (" << key << ") already exists\n";
vec[index].keyCount++;
}
else
{
vec[index].keyValue = key;
vec[index].keyCount++;
cout << "\nKey (" << key << ") has been inserted\n";
count++;
}
int loadfactor = count / capacity;
if (loadfactor >= 0.75)
{
cout << "Rehashing" << endl;
rehash();
}
}
void remove_element(int key)
{
int index = funselect(key);
if (vec[index].keyValue == key)
{
vec[index].keyValue = 0;
vec[index].keyCount--;
cout << "\nKey (" << key << ") has been removed\n";
}
else
{
cout << "\nThis key does not exist\n";
}
}
int hashtablesize()
{
return vec.size();
}
void display()
{
cout << "Hashed key\t" << "key\t" << "Count" << endl;
for (int i = 0; i < capacity; i++)
{
cout << i << "\t\t" << vec[i].keyValue << "\t" << vec[i].keyCount <<endl;
}
}
void search(int key)
{
int index = funselect(key);
if (vec[index].keyValue == key)
{
cout << "\nKey (" << key << ") found at index " << index << endl;
}
else
{
cout << "\nKey (" << key << ") not found\n";
}
}
};
int main()
{
int choice, key, capacity, n, c, fun;
cout << "Enter the capacity of the hash table: ";
cin >> capacity;
cout << "\nWhich Hash Function to Use:\n";
cout << "1. Division Method\n" << "2. Mid Square Method\n" << "3. Folding Method\n" << "4. Multiplication Method\n\n" << "Please enter your choice -:";
cin >> fun;
capacity = prime_number(capacity);
Hashtable obj(capacity, fun);
cout << "Nearest Prime Number is:" << capacity << endl;
do
{
cout << "\nImplementation of Hash Table in C++ using vector\n\n";
cout << "MENU-:\n1. Inserting item in the Hash Table\n" << "2. Removing item from the Hash Table\n" << "3. Check the size of Hash Table\n" << "4. Display a Hash Table\n" << "5. Search an element in Hash Table\n" << "Please enter your choice -:";
cin >> choice;
switch (choice)
{
case 1:
cout << "Inserting element in Hash Table\nEnter key -:";
cin >> key;
obj.insert(key);
break;
case 2:
cout << "Deleting in Hash Table\nEnter the key to delete-:";
cin >> key;
obj.remove_element(key);
break;
case 3:
n = obj.hashtablesize();
cout << "Size of Hash Table is-:" << n << "\n";
break;
case 4:
obj.display();
break;
case 5:
cout << "Enter the element to search-:";
cin >> key;
obj.search(key);
break;
default:
cout << "Wrong Input\n";
}
cout << "\nDo you want to continue? (press 1 for yes)\t";
cin >> c;
} while (c == 1);
return 0;
}