#include <ctime>             //to get the time of the calender
#include <string>            //to get the built in func. which I may need
#include <fstream>          //to use the file
#include <iostream>         //to defines the procedures for input/output
using namespace std;        //to tell the compiler that it should look in the std namespace for any identifier we haven’t defined
struct Task                //making a struct called task
{
	string Title, Details, Priority, MarkAsDone;         //defining strings of task details
	int DayDeadline, MonthDeadline, YearDeadline;      //defining integers of the date
};
Task task[10];                                         //making an array of a struct called task its size is 10
int Read(int&counter, int& Choice, Task task[])       //making a fucn called read to save all the data in the file
{
	ofstream Fout;                                    //defining operators 
	Fout.open("TODOList.txt");              //to oepn a certain file
	for (int i = 0; i < counter; i++)                  //initializing for loop to go through every place in the counter and putting it in the file with the same sort
	{
		Fout << task[i].Title << endl;                 //to save the title of each task in the file
		Fout << task[i].Details << endl;               //to save the description of each task in the file
		Fout << task[i].DayDeadline << endl;          //to save the day of each task in the file
		Fout << task[i].MonthDeadline << endl;       //to save the month of each task in the file
		Fout << task[i].YearDeadline << endl;         //to save the year of each task in the file
		Fout << task[i].Priority << endl;              //to save the priority of each task in the file
		Fout << task[i].MarkAsDone << endl;
	}
	Fout.close();                                     //to close the file
	return 0;                                        //to close the whole program
}
void Write(int &counter, int& Choice, Task task[])    //making a fucn called write to take all the data back from the file
{
	ifstream Fin;                                      //defining operators 
	Fin.open("TODOList.txt", ios::app);                //to open the file
	if (Fin.is_open())                                 //if condition to make sure that the file is open 
	{
		for (int i = 0; i < counter; i++)              //for loop to go throgh every line in the file to get it sorted and put it back in the array
		{
			cin.ignore();
			getline(Fin, task[i].Title);
			getline(Fin, task[i].Details);
			Fin >> task[i].DayDeadline;                //to take the day of each task from the file
			Fin >> task[i].MonthDeadline;              //to take the month of each task from the file
			Fin >> task[i].YearDeadline;                //to take the year of each task from the file
			Fin >> task[i].Priority;                    //to take the priority of each task from the file
			Fin >> task[i].MarkAsDone;
		}
	}
	Fin.close();                                       //to close the file
}
void Time(int& Year, int& Month, int& Day)         //making a func to take the Current time function
{
	time_t now = time(NULL);                       //to take the time with built in func from #include <ctime>
	tm ltm;
	localtime_s(&ltm, &now);                        //to take the local time 
	cout << "The Current Year: " << 1900 + ltm.tm_year << endl;    //printing the year with a certain func 
	cout << "The Current Month: " << 1 + ltm.tm_mon << endl;      //printing the month with a certain func 
	cout << "The Current Day: " << ltm.tm_mday << endl;            //printing the day with a certain func 
	Year = 1900 + ltm.tm_year;                                     //we need to initialize this to use it in another funcs like today's task
	Month = 1 + ltm.tm_mon;                                       //we need to initialize this to use it in another funcs like today's task
	Day = ltm.tm_mday;                                            //we need to initialize this to use it in another funcs like today's task
}
void Main_List()                                                   //VIEW THE MAIN LIST FUNCTION to choose from it wich path does the user want to go through 
{
	cout << "What would you like to do ?" << endl;
	cout << "1. Add a task to my to do list" << endl;
	cout << "2. Edit a task" << endl;
	cout << "3. Search for a specific thing in a task by using title" << endl;
	cout << "4. Delete a task" << endl;
	cout << "5. Mark the task as done" << endl;
	cout << "6. Print" << endl;
	cout << "7. Exit" << endl;
}
void Add_Title(Task task[], int& counter)          //making a func to use it to fill the title and the description space in the array of a certain task *a certain number*
{
	cout << "What's Your Task Title ?" << endl;   //to make it easy to coumunicate with the user to get the data that i need
	cin.ignore();                                  //to get the first letter of the title
	getline(cin, task[counter].Title);              //to get the whole title
	cout << "Kindly Describe Your Task " << endl;//to make it easy to coumunicate with the user to get the data that i need
	getline(cin, task[counter].Details);           //to get the whole description
}
void year_arr_fun(Task task[], int& counter)      //making a func to add the year of a certain task 
{
	cout << "What's Your Dradline Year ? " << endl;//to make it easy to coumunicate with the user to get the data that i need
	cin >> task[counter].YearDeadline;               //to get the year from the user
	if (task[counter].YearDeadline < 2018)          //if statment to handle the case of the year *it's not reasonable to get a year less than the current year*
	{
		cout << "PLEASE, Put A Number More Than 2018: \n" << endl;      //to make it easy to coumunicate with the user to get the data that i need
		cin >> task[counter].YearDeadline;                                    //to get the data again if he didn't give us what we aim
	}
}
void month_arr_fun(Task task[], int& counter)                                //making a func to add the month of a certain task 
{
	cout << "What's Your Deadline Month ? " << endl;                             //to make it easy to coumunicate with the user to get the data that i need
	cin >> task[counter].MonthDeadline;                                           //to get the data from the user
	if ((task[counter].MonthDeadline < 1) || (task[counter].MonthDeadline > 12)) //to handle the case of the month because there's a range for the months which is [1,12] so the user can't put a number less than 1 and higher than 12
	{
		cout << "PLEASE, Enter A Number In The Limit Of Month: \n" << endl;  //to make it easy to coumunicate with the user to get the data that i need
		cin >> task[counter].MonthDeadline;                                      //to get the data from the user
	}
}
void day_arr_fun(Task task[], int& counter)                                     //to make a func to get the day from the user
{
	cout << "What's Your Deadline Day ? " << endl;//to make it easy to coumunicate with the user to get the data that i need
	cin >> task[counter].DayDeadline;//to get the data from the user
	//as you know there's a reange for the days in the month so it's between 1 and 30 or 1 and 31 there're some months take the first range and others take the second
	if (task[counter].DayDeadline < 1)//if the user entered a number less than 1
	{
		while (true)
		{
			cout << "Please Put A Positive Number" << endl;//to make it easy to coumunicate with the user to get the data that i need
			cin >> task[counter].DayDeadline;//to get the data from the user
		}
	}
	else if (task[counter].DayDeadline >= 32)//if the user entered a number higher than 31
	{
		cout << "Please Put A Number Less Than 32" << endl;//to make it easy to coumunicate with the user to get the data that i need
		cin >> task[counter].DayDeadline;//to get the data from the user
	}
	else if ((task[counter].MonthDeadline == 2) && (task[counter].DayDeadline>28))//feburary case *its range is berween 1 and 28*
	{
		cout << "Please Put A Number Less Than 29 And Greater Than 0" << endl;//to make it easy to coumunicate with the user to get the data that i need
		cin >> task[counter].DayDeadline;//to get the data from the user
	}
	else if ((task[counter].DayDeadline > 30) && ((task[counter].MonthDeadline == 4) || (task[counter].MonthDeadline == 6) || (task[counter].MonthDeadline == 9) || (task[counter].MonthDeadline == 11)))//the month that takes days from 1 to 30 and only 30
	{
		cout << "Please Put A Number Less Than 31 And Greater Than 0" << endl;//to make it easy to coumunicate with the user to get the data that i need
		cin >> task[counter].DayDeadline;//to get the data from the user
	}
	else if ((task[counter].DayDeadline > 31) && ((task[counter].MonthDeadline == 1) || (task[counter].MonthDeadline == 3) || (task[counter].MonthDeadline == 5) || (task[counter].MonthDeadline == 7) || (task[counter].MonthDeadline == 8) || (task[counter].MonthDeadline == 10) || (task[counter].MonthDeadline == 12)))//the months that take days between 1 and 31
	{
		cout << "Please Put A Number Less Than 32 And Greater Than 0" << endl;     //to make it easy to coumunicate with the user to get the data that i need
		cin >> task[counter].DayDeadline;                                              //to get the data from the user
	}
}
void Add_Priority(Task task[], int& counter)//making a func to get the priority of the task
{
	cout << "What's Your Task Priority ? (High / Medium / Low ) " << endl; // to make it easy to coumunicate with the user to get the data that i need
	cin >> task[counter].Priority;//to get the data from the user
	if (((task[counter].Priority) != "high") && ((task[counter].Priority) != "medium") && ((task[counter].Priority) != "low"))//in case that the user entered a word which is not from that list 
	{
		cout << "Please Type A Valid Priority: \t"; // to make it easy to coumunicate with the user to get the data that i need
		cin >> task[counter].Priority;//to get the data from the user
	}
}
void Edit_List()      //display the edit list
{
	cout << "What Do You Want Edit ?" << endl;
	cout << "1. Edit A Title" << endl;
	cout << "2. Edit The Details" << endl;
	cout << "3. Edit The Date" << endl;
	cout << "4. Edit The Priority" << endl;
}
void Edit(bool& Menu, Task task[]) //edit func. thet will replace the old task details with A new one
{
	bool Editt;                     //Editt bool to control the do while loop
	do
	{
		Editt = true;
		int EditChoice;        //user going to enter which part he'll edit
		Edit_List();           //calling edit list to be displayed to the user
		cin >> EditChoice;      //reading the part to be editted from the user
		if ((EditChoice != 1) && (EditChoice != 2) && (EditChoice != 3) && (EditChoice != 4)) //case to handle the wrong choice
		{
			Editt = false;     //return bool to false to make the loop continue its itteration till the correct choice
		}
		else if (EditChoice == 1) //in case the user wanted to edit the title
		{
			cout << "Which Task That You Want To Edit" << endl;
			int n;              //variable to know the number of the task to be editted in it
			cin >> n;          //reading task number from the user
			string input2;     //variable to carry the new title
			cout << "Enter The New Title" << endl;
			cin.ignore();
			getline(cin, input2);     //Reading the new title of task No. n 
			task[n - 1].Title = input2;  //assignment operator to make the old title equals the new title
			Menu = false;
		}
		else if (EditChoice == 2)  //in case the user wanted to edit the detail
		{
			cout << "Which Task That You Want To Edit" << endl;
			int n;               //variable to know the number of the task to be editted in it
			cin >> n;            //reading task number from the user
			string input3;        //variable to carry the new detail
			cout << "Enter The New Details" << endl;
			cin.ignore();
			getline(cin, input3);  //Reading the new detail of task No. n 
			task[n - 1].Details = input3;  //assignment operator to make the old detail equals the new detail
			Menu = false;
		}
		else if (EditChoice == 3)  //in case the user wanted to edit the date
		{
			bool Edc;             //bool to make the loop stop
			do
			{
				Edc = true;
				cout << "Which Task That You Want To Edit" << endl;
				int n;        //variable to know the number of the task to be editted in it
				cin >> n;      //reading task number from the user
				cout << "Which Thing You Want To Change In The Date?" << endl;
				cout << "1.The Year" << endl;
				cout << "2.The Month" << endl;
				cout << "3.The Day" << endl;
				int input4;    //variable to carry the new date information
				cin >> input4;
				if ((input4 != 1) && (input4 != 2) && (input4 != 3))
				{
					Edc = false;     //return bool to false to make the loop continue its itteration till the correct choice
				}
				else if (input4 == 1)   //in case the user wanted to edit the year
				{
					int NewYear;        //variable to carry the new year information
					do
					{
						cout << "What's Your New Deadline Year ? " << endl;
						cin >> NewYear;                      //Reading the new year of task No. n 
						task[n - 1].YearDeadline = NewYear;  //assignment operator to make the old year equals the new year
					} while (NewYear < 2018);
					Menu = false;
				}
				else if (input4 == 2)       //in case the user wanted to edit the month
				{
					int NewMonth;        //variable to carry the new month information
					do
					{
						cout << "What's Your New Deadline Month ? " << endl;
						cin >> NewMonth;                        //Reading the new year of task No. n 
						task[n - 1].MonthDeadline = NewMonth;  //assignment operator to make the old month equals the new month
					} while (NewMonth < 1 || NewMonth > 12);
					Menu = false;
				}
				else if (input4 == 3)    //in case the user wanted to edit the day
				{
					bool Day;
					int NewDay;        //variable to carry the new day information
					do
					{
						Day = true;
						cout << "What's Your New Deadline Day ? " << endl;
						cin >> NewDay;    //Reading the new day of task No. n
						//Checking the validity of the new day
						if (NewDay < 1)
						{
							cout << "Please Put A Positive Number" << endl;
							Day = false;
						}
						else if (NewDay >= 32)
						{
							cout << "Please Put A Number Less Than 32" << endl;
							Day = false;
						}
						else if ((task[n - 1].MonthDeadline == 2) && (NewDay>28))
						{
							cout << "Please Put A Number Less Than 29 And Greater Than 0" << endl;
							Day = false;
						}
						else if ((NewDay > 30) && ((task[n - 1].MonthDeadline == 4) || (task[n - 1].MonthDeadline == 6) || (task[n - 1].MonthDeadline == 9) || (task[n - 1].MonthDeadline == 11)))
						{
							cout << "Please Put A Number Less Than 31 And Greater Than 0" << endl;
							Day = false;
						}
						else if ((NewDay > 31) && ((task[n - 1].MonthDeadline == 1) || (task[n - 1].MonthDeadline == 3) || (task[n - 1].MonthDeadline == 5) || (task[n - 1].MonthDeadline == 7) || (task[n - 1].MonthDeadline == 8) || (task[n - 1].MonthDeadline == 10) || (task[n - 1].MonthDeadline == 12)))
						{
							cout << "Please Put A Number Less Than 32 And Greater Than 0" << endl;
							Day = false;
						}
					} while (!Day);
					task[n - 1].DayDeadline = NewDay;   //assignment operator to make the old day equals the new day
				}
			} while (!Edc);
			Menu = false;
		}
		else if (EditChoice == 4)       //in case the user wanted to edit the priority
		{
			cout << "Which Task That You Want To Edit !" << endl;
			int n;               //variable to know the number of the task to be editted in it
			cin >> n;            //reading task number from the user
			string input5;      //variable to carry the new priority
			do
			{
				cout << "Enter The New Priority (High / Medium / Low) " << endl;
				cin.ignore();
				getline(cin, input5);      //Reading the new priority of task No. n 
				if (((input5) == "high") || ((input5) == "medium") || ((input5) == "low"))		//Checking the validity of the new priority
				{
					break;
				}
			} while (true);
			task[n - 1].Priority = input5;      //assignment operator to make the old priority equals the new priority
		}
	} while (!Editt);
	Menu = false;
}
void Search(Task task[], int& counter)         //A func. to search for a specific task by its title
{
	cout << "What Do You Want To Search For ? (Searching By A Title)" << endl;
	string Search;      //variable to know which task to search for
	cin.ignore();
	getline(cin, Search); //reading the title of the task to search
	bool Found;          //flag to detect if the task is found or not
	for (int i = 0; i <= counter; i++) //for loop to search in the whole written tasks
	{
		if (task[i].Title == Search) //statement to display the found task
		{
			Found = true;
			cout << "This Title Is Founded In Task Number " << i + 1 << endl;
			cout << "===============================================" << endl;
			cout << " Task " << i + 1 << endl;
			cout << "===============================================" << endl;
			cout << "Task " << i + 1 << " Title : " << task[i].Title << endl;
			cout << "Task " << i + 1 << " Details : " << task[i].Details << endl;
			cout << "Task " << i + 1 << " Deadline Date is : " << task[i].DayDeadline << "/";
			cout << task[i].MonthDeadline << "/";
			cout << task[i].YearDeadline << endl;
			cout << "Task " << i + 1 << " Priority : " << task[i].Priority << endl;
			cout << "===============================================" << endl;
			break;
		}
		else if (task[i].Title != Search) //statement to return the bool to false if the task wasn't found
		{
			Found = false;
			continue;
		}
	}
	if (!Found)
	{
		cout << "This Title Is Not Founded" << endl; //displaying that the task wasn't found in the array
	}
}
void Delete(Task task[]) //func. to delete a specific task
{
	cout << "Which Task Do You Want To Delete?" << endl;
	int n;
	cin >> n;
	task[n - 1].Title = " ";
	task[n - 1].Details = " ";
	task[n - 1].DayDeadline = 0;
	task[n - 1].MonthDeadline = 0;
	task[n - 1].YearDeadline = 0;
	task[n - 1].Priority = " ";
}
void Marked_Done(Task task[]) //func. to mark a task as done
{
	cout << "Which Task Do You Want To Mark As Done" << endl;
	int n;        //variable to know the number of the task to be marked as done
	cin >> n;      //reading task number from the user
	task[n - 1].MarkAsDone = "yes";

}
void Print_List() //func. to print the list of whole tasks
{
	cout << "What Do You Want To Print" << endl;
	cout << "1. The Whole Tasks" << endl;
	cout << "2. The Done Tasks" << endl;
	cout << "3. The Overdue Tasks" << endl;
	cout << "4. The Tasks That Have To Be Done Today" << endl;
}
void DisplayAll(int& counter, Task task[]) //in case user entered 1 from the print list func.
{
	for (int k = 0; k < (counter); k++)
	{
		cout << "===============================================" << endl;
		cout << " Task " << k + 1 << endl;
		cout << "===============================================" << endl;
		cout << "Task " << k + 1 << " Title : " << task[k].Title << endl;
		cout << "Task " << k + 1 << " Details : " << task[k].Details << endl;
		cout << "Task " << k + 1 << " Deadline Date is : " << task[k].DayDeadline << " / ";
		cout << task[k].MonthDeadline << " / ";
		cout << task[k].YearDeadline << endl;
		cout << "Task " << k + 1 << " Priority : " << task[k].Priority << endl;
		cout << "===============================================" << endl;
	}
}
void DisplayDoneTasks(int& counter, Task task[])  //in case user entered 2 from the print list func.
{
	bool Done;          //flag to detect if the task is found or not
	for (int i = 0; i <= counter; i++) //for loop to search in the whole written tasks
	{
		if (task[i].MarkAsDone == "yes")
		{
			Done = true;
			cout << "===============================================" << endl;
			cout << " Task " << i + 1 << endl;
			cout << "===============================================" << endl;
			cout << "Task " << i + 1 << " Title : " << task[i].Title << endl;
			cout << "Task " << i + 1 << " Details : " << task[i].Details << endl;
			cout << "Task " << i + 1 << " Deadline Date is : " << task[i].DayDeadline << "/";
			cout << task[i].MonthDeadline << "/";
			cout << task[i].YearDeadline << endl;
			cout << "Task " << i + 1 << " Priority : " << task[i].Priority << endl;
			cout << "===============================================" << endl;
		}
		else if (task[i].MarkAsDone != "yes") //statement to return the bool to false if the task wasn't found
		{
			Done = false;
			continue;
		}
	}
	if (!Done)
	{
		cout << "There is no done tasks." << endl;
	}
}
void DisplayTodayTask(int& counter, Task task[])  //in case user entered 3 from the print list func.
{
	for (int k = 0; k < (counter); k++)
	{
		int Year, Month, Day;
		Time(Year, Month, Day);
		if ((task[k].DayDeadline - Day == 0) && (task[k].MonthDeadline - Month == 0) && (task[k].YearDeadline - Year == 0))
		{

			cout << "===============================================" << endl;
			cout << " Task " << k + 1 << endl;
			cout << "===============================================" << endl;
			cout << "Task " << k + 1 << " Title : " << task[k].Title << endl;
			cout << "Task " << k + 1 << " Details : " << task[k].Details << endl;
			cout << "Task " << k + 1 << " Deadline Date is : " << task[k].DayDeadline << " / ";
			cout << task[k].MonthDeadline << " / ";
			cout << task[k].YearDeadline << endl;
			cout << "Task " << k + 1 << " Priority : " << task[k].Priority << endl;
			cout << "===============================================" << endl;
		}
	}
}
void DisplayOverdue(int& counter, Task task[])   //in case user entered 4 from the print list func.
{
	int Year, Month, Day;
	for (int k = 0; k < (counter); k++)
	{
		Time(Year, Month, Day); //calling func. of the time
		if (task[k].YearDeadline - Year < 0)
		{
			cout << "===============================================" << endl;
			cout << " Task " << k + 1 << endl;
			cout << "===============================================" << endl;
			cout << "Task " << k + 1 << " Title : " << task[k].Title << endl;
			cout << "Task " << k + 1 << " Details : " << task[k].Details << endl;
			cout << "Task " << k + 1 << " Deadline Date is : " << task[k].DayDeadline << "/";
			cout << task[k].MonthDeadline << "/";
			cout << task[k].YearDeadline << endl;
			cout << "Task " << k + 1 << " Priority : " << task[k].Priority << endl;
			cout << "===============================================" << endl;
			break;
		}
		else if ((task[k].YearDeadline - Year >= 0) && (task[k].MonthDeadline - Month < 0))
		{
			cout << "===============================================" << endl;
			cout << " Task " << k + 1 << endl;
			cout << "===============================================" << endl;
			cout << "Task " << k + 1 << " Title : " << task[k].Title << endl;
			cout << "Task " << k + 1 << " Details : " << task[k].Details << endl;
			cout << "Task " << k + 1 << " Deadline Date is : " << task[k].DayDeadline << "/";
			cout << task[k].MonthDeadline << "/";
			cout << task[k].YearDeadline << endl;
			cout << "Task " << k + 1 << " Priority : " << task[k].Priority << endl;
			cout << "===============================================" << endl;
			break;
		}
		else if ((task[k].YearDeadline - Year >= 0) && (task[k].MonthDeadline - Month >= 0) && (task[k].DayDeadline - Day < 0))
		{
			cout << "===============================================" << endl;
			cout << " Task " << k + 1 << endl;
			cout << "===============================================" << endl;
			cout << "Task " << k + 1 << " Title : " << task[k].Title << endl;
			cout << "Task " << k + 1 << " Details : " << task[k].Details << endl;
			cout << "Task " << k + 1 << " Deadline Date is : " << task[k].DayDeadline << " / ";
			cout << task[k].MonthDeadline << " / ";
			cout << task[k].YearDeadline << endl;
			cout << "Task " << k + 1 << " Priority : " << task[k].Priority << endl;
			cout << "===============================================" << endl;
			continue;
		}
	}
}
void main()
{
	int counter, Choice; //setting a counter to define the number of written tasks, a choice to define what the user will do
	cout << "===============================================" << endl;
	cout << "How Many Tasks That You Entered ?" << endl;
	cout << "===============================================" << endl;
	cin >> counter;  //reading No. of written tasks from the user
	Write(counter, Choice, task);  //calling "Save in file" func.
	string answer;
	bool Menu;
	int Year, Month, Day;     //variables for setting the time func.
	cout << "===============================================" << endl;
	cout << "             Welcome" << endl;
	cout << "===============================================" << endl;
	Time(Year, Month, Day);  //calling "Time" func.
	cout << "===============================================" << endl;

	do
	{
		Menu = true;
		do
		{
			Main_List();        //calling "the main list" func.
			cin >> Choice;
		} while ((Choice != 1) && (Choice != 2) && (Choice != 3) && (Choice != 4) && (Choice != 5) && (Choice != 6) && (Choice != 7));
		if (Choice == 1)
		{
			Add_Title(task, counter);         //calling "Add title" func.
			day_arr_fun(task, counter);       //calling "Add day" func.
			month_arr_fun(task, counter);    //calling "Add month" func.
			year_arr_fun(task, counter);     //calling "Add year" func.
			Add_Priority(task, counter);    //calling "Add priority" func.
			counter++;           //incrementing the counter after adding another task
			Menu = false;
			string answer;
		}
		else if (Choice == 2)
		{
			Edit(Menu, task);      //calling "Edit" func.
		}
		else if (Choice == 3)
		{
			Search(task, counter);   //calling "Search" func.
			Menu = false;
		}
		else if (Choice == 4)
		{
			Delete(task);         //calling "Delete" func.
			Menu = false;
		}
		else if (Choice == 5)
		{
			Marked_Done(task);  //calling "Marked as done" func.
			Menu = false;
		}
		else if (Choice == 6)
		{
			Print_List();         //calling the "Print list" func.
			int Print;            //variable to know which list to be printed
			cin >> Print;         //reading the choice from the user
			if (Print == 1)
			{
				DisplayAll(counter, task);         //calling "Display all tasks" func.
				Menu = false;
			}
			else if (Print == 2)
			{
				DisplayDoneTasks(counter, task);   //calling "Display done tasks" func. 
				Menu = false;
			}
			else if (Print == 3)
			{
				DisplayOverdue(counter, task);     //calling "Display Overdue tasks" func.
				Menu = false;
			}
			else if (Print == 4)
			{
				DisplayTodayTask(counter, task);  //calling "Display today tasks" func.
				Menu = false;
			}
		}
		else if (Choice == 7)
		{
			Read(counter, Choice, task);       //calling "exit" func.
		}
	} while (!Menu);
}