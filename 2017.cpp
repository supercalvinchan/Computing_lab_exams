/*
unrestrict:
6435st    59
754re     33

restrict
789sd    43    897df
568er    39    985de

output:
unrestrict:
[6435st]    [59]
[754re]     [33]

unrestrict least quantity is : [754re]     [33]

restrict
[789sd]    [43]    [897df]
[568er]    [39]    [985de]

restrict least quantity is : [568er]    [39]    [985de]

requirement:
1. put two types of items in twp different lists
2.using sort algorithm.
3.follow the output format
4.using overload operator <<
5.using suitable inheritance and polymorphism
*/
/*====================================================================================*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <list>
#include <fstream>
using namespace std;

class unrestrict
{
public:
  string code_item;
  int quantity;
  unrestrict(){}
  unrestrict(const string& code_item_tmp, const int& quantity_tmp)
  {
    code_item = code_item_tmp;
    quantity = quantity_tmp;
  }

  friend ostream& operator <<(ostream& out, const unrestrict& ur)
  {

    out << "[" <<ur.code_item << "]" <<"[" << ur.quantity << "]" << endl;
    return out;
  }


};


class restrict : public unrestrict
{
private:
  string code_people;

public:
  restrict(){}
  restrict(const string& code_item_tmp, const int& quantity_tmp, const string& code_people_tmp){
    code_item = code_item_tmp;
    quantity = quantity_tmp;
    code_people = code_people_tmp;
  }
  friend ostream& operator <<(ostream& out, const restrict& r)
  {
    out << "["<<r.code_item<< "]" <<"[" << r.quantity << "]"  << "[" <<r.code_people << "]" << endl;
    return out;
  }


};

bool compare_quantity(const unrestrict& first, const unrestrict& second)
{

  return ( first.quantity < second.quantity );
}

int main()
{

  ifstream infile_1;
  ifstream infile_2;

  //Push unrestrict into list
  string x;
  double y;
  infile_1.open("unrestrict.txt");
  list<unrestrict> un_List;
  while(infile_1 >> x >> y)
  {
    unrestrict un(x, y);
    un_List.push_back(un);
  }

  un_List.sort(compare_quantity);

  for(auto it = un_List.begin(); it!=un_List.end(); ++it)
  {
    cout << *it;
  }
  if(un_List.begin() != un_List.end())
  {
    cout << "unrestrict least quantity is:" << *un_List.begin();
  }

  //Push restrict into list
  string a;
  double b;
  string c;
  list<restrict> re_List;
  infile_2.open("restrict.txt");
  while(infile_2 >> a >> b >> c)
  {
    restrict re(a, b, c);
    re_List.push_back(re);
  }

  re_List.sort(compare_quantity);
  for(auto it = re_List.begin(); it!=re_List.end(); ++it)
  {
    cout << *it;
  }
  if(re_List.begin() != re_List.end())
  {cout << "restrict least quantity is:" << *re_List.begin();
}









  return 0;
}
