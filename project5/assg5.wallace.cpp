#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <cstdlib>

using namespace std;

struct Money
{
  int value;
  string displayValue;
  int index;
};

struct Briefcase
{
  bool isOpened;
  bool isOwned;
  Money contents;
};

void clearScreen();
void displayBoard(Briefcase briefcase[], int round, string displayValues[], float values[]);
void assignContents(Briefcase briefcase[], float values[], string displayValues[]);
int inputValidate(Briefcase briefcase[], int choice);
int playRound(Briefcase briefcase[], float values[], string displayValues[], int round);
int getOffer(Briefcase briefcase[]);
int endingSequence(Briefcase briefcase[], int offer, bool deal);







int main()
{
  Briefcase briefcase[26];
  Money money[26];
  float values[26] = {.01, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750,
    1000, 5000, 10000, 25000, 50000, 75000, 100000, 200000, 300000, 400000,
    500000, 750000, 1000000}, round = 1;
  string displayValues[26] = {"1 penny", "1", "5", "10", "25", "50", "75", "100",
    "200", "300", "400", "500", "750", "1K", "5K", "10K", "25K", "50K", "75K",
    "100K", "200K", "300K", "400K", "500K", "750K", "1 Million"};
  char takeDeal = 'n', keepGoing = 'n';
  int selection;

  do
  {
    //initialize briefcase array
    for (int i=0; i<26; i++)
    {
      briefcase[i].isOpened = false;
      briefcase[i].isOwned = false;
    }

    assignContents(briefcase, values, displayValues);
    displayBoard(briefcase, round, displayValues, values);
    cout << "\nPlease select 'your' briefcase ";
    cin >> selection;
    selection = inputValidate(briefcase, selection);
    briefcase[selection-1].isOwned = true;
    briefcase[selection-1].isOpened = true;

    while(true)
    {
      round = playRound(briefcase, values, displayValues, round);
      if (round == 10)
        break;
    }

    cout << "\nDo you wish to play again? (y/n) ";
    cin >> keepGoing;

  }while(keepGoing == 'y' || keepGoing == 'Y');

  return 0;
}







void clearScreen()
{
  cout << string(90, '\n');
}

void displayBoard(Briefcase briefcase[], int round, string displayValues[], float values[])
{
  clearScreen();
  cout << setw(25) << right << "***********" << endl;
  cout << setw(22) << right << "* Round " << right << round << right << " *" << endl;
  cout << setw(25) << right << "***********" << endl;

  cout << "\n\nMoney remaining($)          Briefcases Remaining\n\n\n";
  for (int i=0; i<26; i++)
  {
    cout << setw(10) << left << displayValues[i];
    if (values[i])
    {
      if (!briefcase[i].isOpened)
      {
        cout << setw(30) << right << "Briefcase " << i+1;
      }
      cout << endl;
    }
  }
}

void assignContents(Briefcase briefcase[], float values[], string displayValues[])
{
  int counter = 0;
  float workingArray[26];

  for (int i=0; i<26; i++)
    workingArray[i] = values[i];
  srand(time(0));
  for (int i=0; i<26; i++)
  {
    int index = rand()%26;
    if (workingArray[index] == 0)
      i--;
    else
    {
      briefcase[i].contents.value = workingArray[index];
      briefcase[i].contents.displayValue = displayValues[index];
      briefcase[i].contents.index = index;
      workingArray[index] = 0;
      counter++;
    }
    if (counter == 26)
      break;
  }
}

int inputValidate(Briefcase briefcase[], int choice)
{
  if (choice<1 || choice>26)
  {
    cout << "\nYou entered a briefcase number that is not valid.\n";
    cout << "\nPlease try again.";
    cout << "\nPlease choose another briefcase: \n";
    cin >> choice;
    inputValidate(briefcase, choice);
  }

  if (briefcase[choice-1].isOpened == true)
  {
    cout << "\nThat briefcase has already been opened.\n";
    cout << "\nPlease try again.\n";
    cout << "\nPlease choose another briefcase: \n";
    cin >> choice;
    inputValidate(briefcase, choice);
  }

  return choice;
}

int playRound(Briefcase briefcase[], float values[], string displayValues[], int round)
{
  int offer = 0, casesToOpen = 7-round;
  char takeDeal = 'n';

  if (casesToOpen<=1)
    casesToOpen = 1;

  for (int i=0; i<casesToOpen; i++)
  {
    displayBoard(briefcase, round, displayValues, values);
    int choice = 0;
    cout << endl << endl;
    cout << "You have " << casesToOpen-i << setw(10) << left << ( ((casesToOpen-i)>1) ? " more cases" : " more case") << left << " to select." << endl;
    cout << "Please select a case to open ";
    cin >> choice;
    if (inputValidate(briefcase, choice) == 999)
      playRound(briefcase, values, displayValues, round);
    choice -= 1;
    briefcase[choice].isOpened = true;
    displayValues[briefcase[choice].contents.index] = "   ";
    cout << "The value of the case you selected is: " << briefcase[choice].contents.displayValue;
    cout << "\n\nPress <enter> to continue";
    cin.get();
    cin.ignore();
    displayBoard(briefcase, round, displayValues, values);
  }

  offer = getOffer(briefcase);
  cout << "\nThe Banker is offering you " << offer << " dollars.\n";
  cout << "\nDo you wish to take the deal? (y/n) ";
  cin >> takeDeal;
  if (takeDeal == 'y' || takeDeal == 'Y')
    round = endingSequence(briefcase, offer, true);
  if (round == 9)
  {
    for (int i=0; i<26; i++)
    {
      if (briefcase[i].isOwned == true)
        offer = briefcase[i].contents.value;
    }
    round = endingSequence(briefcase, offer, false);
  }
  round++;
  return round;
}

int getOffer(Briefcase briefcase[])
{
  float sum = 0, avg = 0;
  int counter = 0;

  for (int i=0; i<26; i++)
  {
    if (!briefcase[i].isOpened)
    {
      sum += briefcase[i].contents.value;
      counter++;
    }
  }

  avg = (sum/counter)*10;
  srand(time(0));
  switch (rand()%4)
  {
    case 0:
      avg /= 30;
      break;
    case 1:
      avg /= 31;
      break;
    case 2:
      avg /= 32;
      break;
    case 3:
      avg /= 33;
      break;
    default:
      cout << "Screwed the pooch again...error in switch";
  }

  return avg;
}

int endingSequence(Briefcase briefcase[], int offer, bool deal)
{
  if (deal)
  {
    clearScreen();
    cout << "You chose to accept the deal of " << offer << " dollars.\n\n";
    cout << "Had you chosen to keep going to the bitter end, you'd have ended up with: ";
    for (int i=0; i<26; i++)
    {
      if (briefcase[i].isOwned)
        cout << briefcase[i].contents.displayValue;
    }
    cout << " dollars." << endl;
  }
  else
  {
    clearScreen();
    cout << "Well you hung on to the end. Perserverence is your middle name.\n";
    cout << "\nWell, some might call it foolhardy. Let's see if you're genius or idiot...\n\n\n";
    cout << "Press <enter> to see what's in your case";
    cin.get();
    cin.ignore();
    clearScreen();
    cout << "********************************************************************************" << endl;
    cout << "********************************************************************************" << endl;
    cout << "                     Your briefcase holds " << offer << ((offer==1) ? " dollar !!! " : " dollars !!!") << endl;
    cout << "********************************************************************************" << endl;
    cout << "********************************************************************************" << endl;
  }


  return 9;
}
