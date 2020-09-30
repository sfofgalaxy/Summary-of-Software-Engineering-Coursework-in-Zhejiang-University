#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
  string stateCapital[][2] = {
    {"Alabama", "Montgomery"},
    {"Alaska", "Juneau"},
    {"Arizona", "Phoenix"},
    {"Arkansas", "Little Rock"},
    {"California", "Sacramento"},
    {"Colorado", "Denver"},
    {"Connecticut", "Hartford"},
    {"Delaware", "Dover"},
    {"Florida", "Tallahassee"},
    {"Georgia", "Atlanta"},
    {"Hawaii", "Honolulu"},
    {"Idaho", "Boise"},
    {"Illinois", "Springfield"},
    {"Indiana", "Indianapolis"},
    {"Iowa", "Des Moines"},
    {"Kansas", "Topeka"},
    {"Kentucky", "Frankfort"},
    {"Louisiana", "Baton Rouge"},
    {"Maine", "Augusta"},
    {"Maryland", "Annapolis"},
    {"Massachusettes", "Boston"},
    {"Michigan", "Lansing"},
    {"Minnesota", "Saint Paul"},
    {"Mississippi", "Jackson"},
    {"Missouri", "Jefferson City"},
    {"Montana", "Helena"},
    {"Nebraska", "Lincoln"},
    {"Nevada", "Carson City"},
    {"New Hampshire", "Concord"},
    {"New Jersey", "Trenton"},
    {"New York", "Albany"},
    {"New Mexico", "Santa Fe"},
    {"North Carolina", "Raleigh"},
    {"North Dakota", "Bismark"},
    {"Ohio", "Columbus"},
    {"Oklahoma", "Oklahoma City"},
    {"Oregon", "Salem"},
    {"Pennslyvania", "Harrisburg"},
    {"Rhode Island", "Providence"},
    {"South Carolina", "Columbia"},
    {"South Dakota", "Pierre"},
    {"Tennessee", "Nashville"},
    {"Texas", "Austin"},
    {"Utah", "Salt Lake City"},
    {"Vermont", "Montpelier"},
    {"Virginia", "Richmond"},
    {"Washington", "Olympia"},
    {"West Virginia", "Charleston"},
    {"Wisconsin", "Madison"},
    {"Wyoming", "Cheyenne"}
  };

  map<string, string> map1;
  for (int i = 0; i < 50; i++)
    map1.insert(
      map<string, string>::value_type(stateCapital[i][0], stateCapital[i][1]));

  cout << "Enter a state: ";
  string state;
  getline(cin, state);
  map<string, string>::iterator p;
  p = map1.find(state);
  if (p == map1.end())
    cout << "no such state";
  else
    cout << "The capital is " << p->second << endl;

  return 0;
}
