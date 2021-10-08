//add include statements
#include <string>
#include <iostream>
//add function code here

double get_gc_content(const std::string& dna)
{
    double gc_counter = 0;

    for (auto ch: dna)
    {
        if (ch == 'G' || ch == 'C')
        {
            gc_counter++;
        }
    }

    return gc_counter / dna.length();
}

std::string get_reverse_string(std::string str)
{
    std::string output_string;

    for (char ch: str)
    {
        output_string.insert(0, 1, ch);
    }

    return output_string;
}

std::string get_dna_complement(std::string dna)
{
    dna = get_reverse_string(dna);

    for (char& ch: dna)
    {
        if(ch == 'A')
        {
            ch = 'T';
        }
        else if(ch == 'T')
        {
            ch = 'A';
        }
        else if(ch == 'C')
        {
            ch = 'G';
        }
        else if(ch == 'G')
        {
            ch = 'C';
        }
    }
    
    return dna;
}

// Menu functions 

std::string get_str(std::string prompt)
{
    std::cout<<prompt;
    std::string str;
    std::cin>>str;
    for (char ch: str)
    {
        if (ch != 'A' && ch != 'T' && ch != 'G' && ch != 'C')
        {
            return get_str("Please enter a valid DNA string (can only contain A,T,G,C): ");
        }
    }
    return str;
}

int get_int(std::string prompt)
{
    std::cout<<prompt;
    int num;
    std::cin>>num;
    
    return num;
}

void print_menu()
{
    std::cout<<"\n\n1-Get GC Content\n2-Get DNA Complement\n3-Exit\n\n";
}

bool run_menu_choice()
{
    int choice = get_int("Please enter a menu option: ");

    switch (choice)
    {
    case 1:

        std::cout<<get_gc_content(get_str("Please enter a DNA string in all caps: "))<<std::endl;
        break;
    
    case 2:

        std::cout<<get_dna_complement(get_str("Please enter a DNA string in all caps: "))<<std::endl;
        break;
    
    case 3:
        std::cout<<"Are you sure you would like to exit y/n: ";

        char exit;

        std::cin>>exit;

        if(exit == 'y')
        {
            return false;
        }
        break;

    default:
        break;
    }
    return true;
}