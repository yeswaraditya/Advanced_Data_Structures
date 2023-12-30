#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
struct data
{
int key;
int value;
};
struct data *array;
int capacity = 10;
int size = 0;
/* this function gives a unique hash code to the given key */
int hashcode(int key)
{
return (key % capacity);
}
void init_array()
{
int i;
capacity = capacity;
array = (struct data*) malloc(capacity * sizeof(struct data));
for (i = 0; i &lt; capacity; i++)
{

array[i].key = 0;
array[i].value = 0;
}
}

/* to insert a key in the hash table */
void insert(int key)
{
int index = hashcode(key);
if (array[index].value == 0)
{

/* key not present, insert it */
array[index].key = key;
array[index].value = 1;
size++;
printf(&quot;\n Key (%d) has been inserted \n&quot;, key);
}
else if(array[index].key == key)
{

/* updating already existing key */
printf(&quot;\n Key (%d) already present, hence updating its value \n&quot;, key);
array[index].value += 1;
}
else
{

/* key cannot be insert as the index is already containing some other key */
printf(&quot;\n ELEMENT CANNOT BE INSERTED \n&quot;);
}
}

/* to remove a key from hash table */
void remove_element(int key)
{
int index = hashcode(key);
if(array[index].value == 0)
{

printf(&quot;\n This key does not exist \n&quot;);

}
else {
array[index].key = 0;
array[index].value = 0;
size--;
printf(&quot;\n Key (%d) has been removed \n&quot;, key);
}
}
/* to display all the elements of a hash table */
void display()
{
int i;
for (i = 0; i &lt; capacity; i++)
{

if (array[i].value == 0)

{

printf(&quot;\n Array[%d] has no elements \n&quot;);
}
else

{ printf(&quot;\n array[%d] has elements -:\n key(%d) and value(%d)
\t&quot;, i, array[i].key, array[i].value);

}
}
}

int size_of_hashtable()
{
return size;
}

void main()
{
int choice, key, value, n, c;

init_array();

do {
printf(&quot;\n Implementation of Hash Table in C \n\n&quot;);
printf(&quot;MENU-: \n1.Inserting item in the Hash Table&quot;
&quot;\n2.Removing item from the Hash Table&quot;
&quot;\n3.Check the size of Hash Table&quot;

&quot;\n4.Display a Hash Table&quot;
&quot;\n\n Please enter your choice -:&quot;);

scanf(&quot;%d&quot;, &amp;choice);

switch(choice)

{

case 1: printf(&quot;Inserting element in Hash Table\n&quot;);
printf(&quot;Enter key -:\t&quot;);
scanf(&quot;%d&quot;, &amp;key);
insert(key);

break;

case 2:
printf(&quot;Deleting in Hash Table \n Enter the key to delete-:&quot;);
scanf(&quot;%d&quot;, &amp;key);
remove_element(key);

break;

case 3:
n = size_of_hashtable();
printf(&quot;Size of Hash Table is-:%d\n&quot;, n);

break;

case 4:
display();
break;

default:

printf(&quot;Wrong Input\n&quot;);

}

printf(&quot;\n Do you want to continue-:(press 1 for yes)\t&quot;);
scanf(&quot;%d&quot;, &amp;c);

}while(c == 1);}
