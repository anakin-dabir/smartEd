#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const int FACULTY = 58;
struct Facultymem
{
    string name;
    string position;
    string department;
    string email;
};

struct Inventory_item
{
    string name;
    string item_ID;
    string Category;
    int item_count;
    // added total items because wanted to dynamicallay allocate and store data into file
    int total_item;
    // taken pointer so we could dynamically allocate the array while reading the file
    Facultymem *Allocated_to;
};
int options();
void Filewrite(Inventory_item *, fstream &);
Inventory_item Fileread(fstream &);
void AddInvitem();
void viewItems();
void searchItem();
void displayInfo(Inventory_item *);
void editItems();
void delItem();
void assignItem(Facultymem *);
void retrieveItem();
void specificItem();
void CopyArr(Facultymem *, Facultymem *, int);
bool repetitionCheck(Inventory_item *);
int main()
{
    Facultymem Members[FACULTY] = {
        {"Dr. Shahzad Sarwar", "Dean Faculty of Computing and Information Technology", "Computer Science", "Principal@pucit.edu.pk"},
        {"Ch Ejaz Ashraf", "Assistant Professor", "Computer Science", "ejaz@pucit.edu.pk"},
        {"Dr. Laeeq Aslam", "Assistant Professor", "Computer Science", "laeeq.aslam@pucit.edu.pk"},
        {"Tayyaba Tariq", "Assistant Professor", "Computer Science", "tayyaba.tariq@pucit.edu.pk"},
        {"Asim Rasul", "Assistant Professor", "Computer Science", "asim@pucit.edu.pk"},
        {"Dr. Faisal Aslam", "Assistant Professor", "Computer Science", "faisal.aslam@gmail.com"},
        {"Dr. Saadia Shahzad", "Assistant Professor", "Computer Science", "saadia.shahzad@pucit.edu.pk"},
        {"Nastaeen Fatima", "Assistant Professor", "Computer Science", "nfatimaa@pucit.edu.pk"},
        {"Dr. Zobia Suhail", "Assistant Professor", "Computer Science", "zobia.suhail@pucit.edu.pk"},
        {"Dr. Muhammad Shahid Farid", "Assistant Professor", "Computer Science", "shahid@pucit.edu.pk"},
        {"Dr. Muhammad Hassan Khan", "Assistant Professor", "Computer Science", "Hassankhan@pucit.edu.pk"},
        {"Dr. Nazar Khan", "Assistant Professor", "Computer Science", "nazarkhan@pucit.edu.pk"},
        {"Abdul Mateen", "Assistant Professor", "Computer Science", "amateen@pucit.edu.pk"},
        {"Umair Babar", "Assistant Professor", "Computer Science", "umair.babar@pucit.edu.pk"},
        {"Esha Aftab", "Assistant Professor", "Computer Science", "NO MAIL"},
        {"Dr. Muhammad Younis", "Assistant Professor", "Computer Science", "younis@pucit.edu.pk"},
        {"Khadija Mariam", "Assistant Professor", "Computer Science", "khadija.mariam@pucit.edu.pk"},
        {"Dr. Muhammad Murtaza Yousaf", "Chairman Department of Software Engineering", "Software Engineering", "murtaza@pucit.edu.pk"},
        {"Fareed Ul Hassan Baig", "Assistant Professor", "Software Engineering", "fareed@pucit.edu.pk"},
        {"Abdul Khaliq", "Assistant Professor", "Software Engineering", "abdul.khaliq@pucit.edu.pk"},
        {"Farhan Ahmad Ch", "Assistant Professor", "Software Engineering", "farhan@pucit.edu.pk"},
        {"Muhammad Zia Afzal", "Assistant Professor", "Software Engineering", "zia@pucit.edu.pk"},
        {"Omer Nawaz", "Assistant Professor", "Software Engineering", "umer.nawaz@pucit.edu.pk"},
        {"Muddassira Arshad", "Assistant Professor", "Software Engineering", "muddassira@pucit.edu.pk"},
        {"Amina Mustansir", "Assistant Professor", "Software Engineering", "amina.mustansir@pucit.edu.pk"},
        {"Dr. Shuja-ur-rehman Baig", "Assistant Professor (Adhoc)", "Software Engineering", "shuja@pucit.edu.pk"},
        {"Dr. Arifa Mirza", "Assistant Professor (Adhoc)", "Software Engineering", "arifa.mirza@pucit.edu.pk"},
        {"Mehwish Kayani", "Lecturer", "Software Engineering", "mehwish.kayani@pucit.edu.pk"},
        {"Sanam Ahmed", "Assistant Professor", "Software Engineering", "madiha.khalid@pucit.edu.pk"},
        {"Natalia Chaudhry", "Assistant Professor", "Software Engineering", "natalia.chaudhry@pucit.edu.pk"},
        {"Dr. Waqar ul Qounain", "Chairman Department of Information Technology", "Information Technology", "swjaffry@pucit.edu.pk"},
        {"Dr. Muhammad Kamran Malik", "Associate Professor", "Information Technology", "kamran.malik@pucit.edu.pk"},
        {"Dr. Asif Sohail", "Assistant Professor", "Information Technology", "asif@pucit.edu.pk"},
        {"Dr. Muhammad Adeel Nisar", "Assistant Professor", "Information Technology", "Adeel.nisar@pucit.edu.pk"},
        {"Muhammad Ahmad Ghazali", "Assistant Professor", "Information Technology", "ahmad.ghazali@pucit.edu.pk"},
        {"Sadeeqa Riaz Khan", "Assistant Professor", "Information Technology", "sadeeqa@pucit.edu.pk"},
        {"Kashif Murtaza", "Assistant Professor", "Information Technology", "kashif.murtaza@pucit.edu.pk"},
        {"Hafiz Anzar Ahmad", "Assistant Professor", "Information Technology", "anzar@pucit.edu.pk"},
        {"Dr. Farsia Hussain", "Assistant Professor", "Information Technology", "Farsia.hussain@pucit.edu.pk"},
        {"Dr. Mian Muhammad Mubasher", "Assistant Professor", "Information Technology", "mubasher@pucit.edu.pk"},
        {"Dr. Muhammad Farooq", "Assistant Professor (Adhoc)", "Information Technology", "Mfarooq@pucit.edu.pk"},
        {"Dr. Zara Nasar", "Assistant Professor (Adhoc)", "Information Technology", "zara.nasar@pucit.edu.pk"},
        {"Fakhra Jabeen", "Lecturer (study leave)", "Information Technology", "fakhra@pucit.edu.pk"},
        {"Maryam Nawaz Awan", "Lecturer", "Information Technology", "maryam.nawaz@pucit.edu.pk"},
        {"Dr. Shahid Manzoor", "Chairman Department of Data Science", "Data Science", "chairman.dds@pucit.edu.pk"},
        {"Dr. Muhammad Nadeem Majeed", "Associate Professor", "Data Science", "nadeem.majeed@pucit.edu.pk"},
        {"Dr. Syed Faisal Bukhari", "Associate Professor", "Data Science", "faisal.bukhari@pucit.edu.pk"},
        {"Dr. Khurram Shahzad", "Associate Professor", "Data Science", "khurram@pucit.edu.pk"},
        {"Dr. Waheed Iqbal", "Associate Professor", "Data Science", "waheed.iqbal@pucit.edu.pk"},
        {"Maj. (retd.) Dr. Muhammad Arif Butt", "Assistant Professor", "Data Science", "arif@pucit.edu.pk"},
        {"Dr. Muhammad Idrees", "Assistant Professor", "Data Science", "idrees@pucit.edu.pk"},
        {"Tariq Mahmood Butt", "Assistant Professor", "Data Science", "tariq.butt@pucit.edu.pk"},
        {"Dr. Syed Muhammad Ali", "Assistant Professor", "Data Science", "muhammad.ali@pucit.edu.pk"},
        {"Dr. Ather Ashraf", "Assistant Professor", "Data Science", "ather@pucit.edu.pk"},
        {"Imran Javed", "Assistant Professor", "Data Science", "Imranj@pucit.edu.pk"},
        {"Dr. Zubair Nawaz", "Assistant Professor", "Data Science", "znawaz@pucit.edu.pk"},
        {"Dr. Rukhsana Kausar", "Assistant Professor (Adhoc)", "Data Science", "rukhsana@pucit.edu.pk"},
        {"Dr. Muhammad Abdullah", "Assistant Professor (Adhoc)", "Data Science", "muhammad.abdullah@pucit.edu.pk"}};
    int choice = 0;
    do
    {
        choice = options();
        switch (choice)
        {
        case 1:
            AddInvitem();
            break;
        case 2:
            viewItems();
            break;
        case 3:
            searchItem();
            break;
        case 4:
            editItems();
            break;
        case 5:
            delItem();
            break;
        case 6:
            assignItem(Members);
            break;
        case 7:
            retrieveItem();
            break;
        case 8:
            specificItem();
            break;
        default:
            return 0;
        }
    } while (choice != 9);
    return 0;
}
int options()
{

    int choice;
    cout << "Select one of the options below: \n"
         << "1. Add Inventory items \n"
         << "2. View all inventory items \n"
         << "3. Search inventory item \n"
         << "4. Edit inventory item \n"
         << "5. Delete inventory item \n"
         << "6. Assign inventory item \n"
         << "7. Retrieve inventory item \n"
         << "8. List of faculty members who have borrowed a specific item \n"
         << "9. Exit the program \n";
    cin >> choice;
    return choice;
}
// writes the inventory item to the end of the file
void Filewrite(Inventory_item *x, fstream &outputFile)
{
    if (outputFile)
    {
        outputFile.write(x->name.c_str(), x->name.size());
        outputFile.write("\0", sizeof(char));
        outputFile.write(x->item_ID.c_str(), x->item_ID.size());
        outputFile.write("\0", sizeof(char));
        outputFile.write(x->Category.c_str(), x->Category.size());
        outputFile.write("\0", sizeof(char));
        outputFile.write(reinterpret_cast<char *>(&x->item_count), sizeof(int) * 2);
        for (int i = 0; i < x->total_item - x->item_count; i++)
        {
            outputFile.write(x->Allocated_to[i].name.c_str(), x->Allocated_to[i].name.size());
            outputFile.write("\0", sizeof(char));
            outputFile.write(x->Allocated_to[i].position.c_str(), x->Allocated_to[i].position.size());
            outputFile.write("\0", sizeof(char));
            outputFile.write(x->Allocated_to[i].department.c_str(), x->Allocated_to[i].department.size());
            outputFile.write("\0", sizeof(char));
            outputFile.write(x->Allocated_to[i].email.c_str(), x->Allocated_to[i].email.size());
            outputFile.write("\0", sizeof(char));
        }
    }
    else
    {
        cout << "File failed \n";
    }
}
// reads the inventory item from the file
Inventory_item Fileread(fstream &fin)
{
    Inventory_item x;
    getline(fin, x.name, '\0');
    getline(fin, x.item_ID, '\0');
    getline(fin, x.Category, '\0');
    fin.read(reinterpret_cast<char *>(&x.item_count), sizeof(int) * 2);
    x.Allocated_to = new Facultymem[x.total_item - x.item_count];
    for (int i = 0; i < x.total_item - x.item_count; i++)
    {
        getline(fin, x.Allocated_to[i].name, '\0');
        getline(fin, x.Allocated_to[i].position, '\0');
        getline(fin, x.Allocated_to[i].department, '\0');
        getline(fin, x.Allocated_to[i].email, '\0');
    }
    return x;
}
// Adding Inventory items directly to file
void AddInvitem()
{
    Inventory_item item;
    cout << "Enter the name of the item: ";
    cin.ignore();
    getline(cin, item.name);
    cout << "Enter the item ID: ";
    getline(cin, item.item_ID);
    cout << "Enter the Category of the item: ";
    getline(cin, item.Category);
    cout << "Enter the item count : ";
    cin >> item.item_count;
    while (item.item_count <= 0)
    {
        cout << "The item count cannot be zero or less than zero \n";
        cout << "Enter the item count : ";
        cin >> item.item_count;
    }

    item.total_item = item.item_count;
    item.Allocated_to = nullptr;
    fstream outputFile("inventory_item_data.dat", ios::binary | ios::app | ios::out);
    if (repetitionCheck(&item))
    {
        Filewrite(&item, outputFile);
        outputFile.close();
    }
    else
    {
        cout << "The item ID should be unique \n";
        return;
    }
}
// To check the repetition of the item
bool repetitionCheck(Inventory_item *check)
{
    Inventory_item filecheck;
    fstream file("inventory_item_data.dat", ios::in | ios::binary | ios::out);
    while (true)
    {
        filecheck = Fileread(file);
        if (file.eof())
            return true;
        if (filecheck.item_ID == check->item_ID)
            return false;
    }
}
// Viewing items directly from file
void viewItems()
{
    Inventory_item x;
    fstream Infile("inventory_item_data.dat", ios::in | ios::binary);
    if (Infile)
        while (true)
        {
            x = Fileread(Infile);
            if (Infile.eof())
            {
                Infile.close();
                delete[] x.Allocated_to;
                break;
            }
            displayInfo(&x);
            delete[] x.Allocated_to;
        }
    else
        cout << "There is nothing on your file";
}
// Used to search the item
void searchItem()
{
    string ID;
    cout << "Enter the ID of item you want to search: ";
    cin.ignore();
    getline(cin, ID);
    Inventory_item x;
    fstream Infile("inventory_item_data.dat", ios::in | ios::binary);
    while (true)
    {
        x = Fileread(Infile);
        if (Infile.eof())
            break;
        if (x.item_ID == ID)
        {
            displayInfo(&x);
            Infile.close();
            delete[] x.Allocated_to;
            return;
        }
        delete[] x.Allocated_to;
    }
    cout << "We could not find the item of which you specified the ID of\n";
    Infile.close();
}
// To display the info of the specific item
void displayInfo(Inventory_item *items)
{

    cout << "*****ITEM FOUND*******\n";
    cout << "ITEM NAME: " << items->name << endl
         << "ITEM ID: " << items->item_ID << endl
         << "ITEM CATEGORY: " << items->Category << endl
         << "ITEM COUNT: " << items->item_count << endl
         << "TOTAL ITEM COUNT: " << items->total_item << endl
         << "This item is currently Allocated to: " << endl;
    for (int j = 0; j < items->total_item - items->item_count; j++)
    {
        cout << left << setw(25) << items->Allocated_to[j].name << setw(54) << items->Allocated_to[j].position << setw(25) << items->Allocated_to[j].department << setw(25) << items->Allocated_to[j].email;
        cout << endl;
    }
    if (items->total_item - items->item_count == 0)
    {
        cout << "No One \n";
    }
}
// To edit the information of a specific inventory item
void editItems()
{
    string ID;
    cout << "Enter the ID of the item you want to change: ";
    cin.ignore();
    getline(cin, ID);
    Inventory_item x;
    bool find = false;
    fstream Infile("inventory_item_data.dat", ios::in | ios::binary);
    fstream Offile("new.txt", ios::out | ios::binary);
    while (true)
    {
        x = Fileread(Infile);
        if (Infile.eof())
        {
            delete[] x.Allocated_to;
            break;
        }
        if (x.item_ID != ID)
            Filewrite(&x, Offile);
        else
        {
            find = true;
            int prevcount = x.total_item;
            displayInfo(&x);
            cout << "Enter the new name of the item :";
            getline(cin, x.name);
            cout << "Enter the new Category of the item: ";
            getline(cin, x.Category);
            cout << "Enter the new total count of the item: ";
            cin >> x.total_item;
            // to check that the new count is not less than already assigned elements in the file
            while (x.total_item < prevcount - x.item_count)
            {
                cout << prevcount - x.item_count << "items are already allocated \n"
                     << "So new item count shoud be greater than this \n";
                cout << "Enter the new total count of the item: ";
                cin >> x.total_item;
            }
            x.item_count += x.total_item - prevcount;
            Filewrite(&x, Offile);
        }
        delete[] x.Allocated_to;
    }
    if (!find)
        cout << "There is no item matching your input ID\n";
    Infile.close();
    Offile.close();
    remove("inventory_item_data.dat");
    rename("new.txt", "inventory_item_data.dat");
}
// To delete a specific item in the inventory
void delItem()
{
    string ID;
    cout << "Enter the ID of the item you want to delete: ";
    cin.ignore();
    getline(cin, ID);
    Inventory_item x;
    bool find = false;
    fstream Infile("inventory_item_data.dat", ios::in | ios::binary);
    fstream Offile("new.txt", ios::out | ios::binary);
    while (true)
    {
        x = Fileread(Infile);
        if (Infile.eof())
        {
            delete[] x.Allocated_to;
            break;
        }
        if (x.item_ID != ID)
        {

            Filewrite(&x, Offile);
            delete[] x.Allocated_to;
        }
        else
        {
            find = true;
            delete[] x.Allocated_to;
        }
    }
    if (!find)
        cout << "There is no item matching your input ID\n";
    else
        cout << "The specified item has been removed \n";
    Infile.close();
    Offile.close();
    remove("inventory_item_data.dat");
    rename("new.txt", "inventory_item_data.dat");
}
// To assign the item to a specific faculty member
void assignItem(Facultymem *arr)
{
    string ID, Assign_to;
    cout << "Enter the Item you want to assign: ";
    cin.ignore();
    getline(cin, ID);
    cout << "Enter the name of the faculty member allocate the item to: ";
    getline(cin, Assign_to);
    Inventory_item x;
    bool find = false;
    fstream Infile("inventory_item_data.dat", ios::in | ios::binary);
    fstream Offile("new.txt", ios::out | ios::binary);
    while (true)
    {
        x = Fileread(Infile);
        if (Infile.eof())
        {
            Infile.close();
            delete[] x.Allocated_to;
            break;
        }
        if (x.item_ID != ID)
        {
            Filewrite(&x, Offile);
        }
        else
        {
            find = true;
            if (x.item_count > 0)
            {
                //****************************************************************************************************************************
                // ALL THIS TO INCREASE THE SIZE OF DYNAMIC ARRAY BY 1
                // copying previous data of the array in a temporary array
                Facultymem *temp = new Facultymem[x.total_item - x.item_count];
                CopyArr(temp, x.Allocated_to, x.total_item - x.item_count);
                x.item_count -= 1;
                delete[] x.Allocated_to;
                // making a new array of one greater size and copying the data preciously stored in it
                x.Allocated_to = new Facultymem[x.total_item - x.item_count];
                CopyArr(x.Allocated_to, temp, x.total_item - x.item_count - 1);
                delete[] temp;
                //****************************************************************************************************************************
                // Matching the name of the faculty member from the array containing faculty members data
                for (int i = 0; i < FACULTY; i++)
                {
                    if (arr[i].name == Assign_to)
                    {
                        x.Allocated_to[x.total_item - x.item_count - 1] = arr[i];
                        break;
                    }
                    else if (i == FACULTY - 1)
                    {
                        cout << "You did not enter correct faculty member name Try again \n";
                        cout << "Enter the name of the faculty member allocate the item to: ";
                        getline(cin, Assign_to);
                        i = 0;
                        if (Assign_to == "")
                        {
                            remove("new.txt");
                            return;
                        }
                    }
                }
                Filewrite(&x, Offile);
            }
            else
            {
                cout << "There is no more item left to be assigned \n";
                Filewrite(&x, Offile);
            }
        }
        delete[] x.Allocated_to;
    }
    if (!find)
        cout << "There is no item matching your input ID\n";
    Infile.close();
    Offile.close();
    remove("inventory_item_data.dat");
    rename("new.txt", "inventory_item_data.dat");
}
// To retrieve a certain Item
void retrieveItem()
{
    string ID, Retrieve;
    cout << "Enter the ID of the item you want to retrieve: ";
    cin.ignore();
    getline(cin, ID);
    cout << "Enter the name of the faculty member you want to retrieve the item from: ";
    getline(cin, Retrieve);
    Inventory_item x;
    bool find = false;
    fstream Infile("inventory_item_data.dat", ios::in | ios::binary);
    fstream Offile("new.txt", ios::out | ios::binary);
    while (true)
    {
        x = Fileread(Infile);
        if (Infile.eof())
        {
            Infile.close();
            delete[] x.Allocated_to;
            break;
        }
        if (x.item_ID != ID)
        {
            Filewrite(&x, Offile);
        }
        else
        {
            find = true;
            // taking another bool to check if we find the given name in the allocated_to array
            bool find2 = false;
            if (x.item_count < x.total_item)
            {
                x.item_count += 1;
                Facultymem *temp = new Facultymem[x.total_item - x.item_count];
                for (int i = 0; i < (x.total_item - x.item_count) + 1; i++)
                {
                    if (x.Allocated_to[i].name == Retrieve && !find2)
                    {
                        find2 = true;
                        continue;
                    }
                    if ((i == (x.total_item - x.item_count)) && !find2)
                    {
                        cout << "You did not enter correct faculty member name Try again \n";
                        cout << "Enter the name of the faculty member to Retrieve the item given to them: ";
                        getline(cin, Retrieve);
                        i = 0;
                        if (Retrieve == "")
                        {
                            remove("new.txt");
                            return;
                        }
                    }
                    // Storing everything into the temporary array except the match
                    temp[i - find2] = x.Allocated_to[i];
                }
                delete[] x.Allocated_to;
                // Decreasing size of allocated to by 1 and deleting all the data previously stored in the file
                x.Allocated_to = new Facultymem[x.total_item - x.item_count];
                CopyArr(x.Allocated_to, temp, x.total_item - x.item_count);
                delete[] temp;
                Filewrite(&x, Offile);
            }
            else
            {
                cout << "There is no item currently allocated to someone\n";
            }
        }
        delete[] x.Allocated_to;
    }
    if (!find)
        cout << "There is no item matching your input ID\n";
    Infile.close();
    Offile.close();
    remove("inventory_item_data.dat");
    rename("new.txt", "inventory_item_data.dat");
}
void specificItem()
{
    string ID;
    bool flag = true;
    cout << "Enter the ID of the specific item you want to check: ";
    cin.ignore();
    getline(cin, ID);
    Inventory_item x;
    fstream inputFile("inventory_item_data.dat", ios::in | ios::binary);
    while (flag)
    {
        x = Fileread(inputFile);
        if (inputFile.eof())
        {
            inputFile.close();
            delete[] x.Allocated_to;
            break;
        }
        if (x.item_ID == ID)
        {
            flag = false;
            cout << "This item is currently assigned to: \n";
            for (int j = 0; j < x.total_item - x.item_count; j++)
            {
                cout << x.Allocated_to[j].name << "\t" << x.Allocated_to[j].position << "\t" << x.Allocated_to[j].department << "\t" << x.Allocated_to[j].email;
                cout << endl;
            }
            if (x.total_item - x.item_count == 0)
            {
                cout << "No One \n";
            }
        }
        delete[] x.Allocated_to;
    }
    if (flag)
        cout << "There is no item of the specified ID \n";
}
void CopyArr(Facultymem *arr1, Facultymem *arr2, int size)
{
    for (int i = 0; i < size; i++)
        arr1[i] = arr2[i];
}