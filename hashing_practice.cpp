//implementation of hashtable using vector(arrays) with simple mod function

#include<iostream>
#include<vector>
using namespace std;

class Hashtable{

public:

  struct data{
     int key,value;
  };

  vector<data> array;
  int capacity;
  int size;

  Hashtable (int initialcapacity=10)  // default size is 10
  {
     capacity = initialcapacity;
     size=0;
     array.resize(capacity,{0,0}); // using resize method we are resizing with default value and inserting key,value to 0
  }

  int hashcode(int key)
  {
      return(key%capacity);
  }

  void insert( int key)
  {
       int tablekey=hashcode(key);

       if(array[tablekey].key==0)
       {
          array[tablekey].key=key;
          array[tablekey].value=1;
          size++;
          cout<<"key"<<key<<"inserted into table"<<endl;
       }

       else if(array[tablekey].key==key)
       {
         cout<<"collosion occured ,hence incrementing  value"<<endl;
         array[tablekey].value+=1;

       }
       else
       {
         cout<<" element cant be inserted"<<endl;
       }
  }

void removeelement(int key)
  {
     int tablekey=hashcode(key);

     if(array[tablekey].key==0)
     {
       cout<<"cant remove as no element is present"<<endl;
     }

     else
     {
        array[tablekey].key=0;
        array[tablekey].value=0;
        size--;
        cout<<"key"<<key<<"has been removed from table"<<endl;
     }

  }

  int sizeofhashtable()
  {
    return size;
  }

  void display()
  {
     for(int i=0;i<capacity;i++)
     {
       if(array[i].value==0)
       {
         cout<<" array "<<i<<"has no elements"<<endl;
       }
       else
       {
         cout<<" array "<<i<<"has  elements"<<endl;
         cout<<array[i].key<<""<<"and value"<<array[i].value<<endl;

       }
     }
  }

};
int main()
{
   Hashtable hash;
   int choice,keyval,a;
   cout<<"implementation of hashing using simple mod function"<<endl;
   cout<<"enter 1 to continue"<<endl;
   cin>>a;
   while(a==1)
   {
     cout<<"1 insert an element into hashtable\n"
       <<"2 remove an element from hashtable\n"
       <<"3 size of hashtable\n"
       <<"4 display hashtable\n"
       <<"5 exit\n";

       cout<<"enter your choice"<<endl;
       cin>>choice;

       switch(choice)
       {
         case 1:
                cout<<"enter key value";
                cin>>keyval;
                hash.insert(keyval);
                break;

        case 2:
             cout<<"enter key value to delete";
             cin>>keyval;
             hash.removeelement(keyval);
             break;

        case 3:
             cout<<"the size of hashtable is : "<<hash.sizeofhashtable()<<endl;
             break;

        case 4:
             cout<<"the hashtable is "<<endl;
             hash.display();
             break;

        case 5:
             exit(1);

        default :
              cout<<"operation not allowed"<<endl;






       }

   }
}
