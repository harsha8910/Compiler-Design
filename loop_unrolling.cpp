#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;
int main() 
{
    // Open the input file
    std::ifstream inputFile("input.txt");

    if (!inputFile) 
    {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }
    ofstream outputFile("output.txt");
    if (!outputFile) 
    {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }
    // Read the file line by line
    std::string line;
    int lineNumber = 0, loopLine=INT_MAX, isBody=false, nValue;
    vector<string> loopBody;

    while (std::getline(inputFile, line)) 
    {
        lineNumber++;
        if(lineNumber>loopLine && line.find("{")!=string::npos)
        {
            isBody=true;
            continue;
        }
        if(lineNumber>loopLine && line.find("}")!=string::npos)
        {
            //cout<<line<<endl;
            isBody = false;
            loopLine =INT_MAX;
            for(int i=1 ; i<= nValue ; i++)
            {
                
                for(int j=0 ; j<loopBody.size() ; j++)
                {
                    outputFile << loopBody[j] << "\n";
                }
                outputFile << "\n";
            }
            continue;
        }
        
        if(lineNumber>loopLine && isBody==true)
        {
            loopBody.push_back(line);
        }
        
        // Check if the line starts with "for"
        if (line.find("for") != string::npos) 
        {
            //cout << "Line " << lineNumber << ": " << line << std::endl;
            loopLine = lineNumber;
            string s = line;
            s.erase(remove(s.begin(), s.end(), ' '), s.end());

            // Find the position of ';' and ';'
            size_t equalPos = s.find(';');
            size_t semicolonPos = (s.substr(equalPos+1)).find(';');
        
            if (equalPos != string::npos && semicolonPos != string::npos) 
            {
                // Extract the substring between ';' and ';'
                string nSubstring = s.substr(equalPos + 1, semicolonPos);
                if(nSubstring.find('='))
                    nSubstring = nSubstring.substr(nSubstring.find('=')+1);
                if(nSubstring.find('<'))
                    nSubstring = nSubstring.substr(nSubstring.find('<')+1);
                if(nSubstring.find('>'))
                    nSubstring = nSubstring.substr(nSubstring.find('>')+1);
                try 
                {
                    nValue = stoi(nSubstring);      // Convert the substring to an integer
                    cout << "The value of 'n' is: " << nValue << endl;
                } 
                catch (...) 
                {
                    cerr << "Error converting 'n' to an integer: "  <<endl;
                } 
            }
            else 
            {
                cerr << "Invalid format of the input string." << endl;
            }
        }
        else if(isBody==false)    //non-loop part of code
        {
            outputFile << line << "\n";
        }
    }
    inputFile.close();      // Close the input file
    outputFile.close();     // Close the output file
    std::cout << "Code transformation complete. Check 'output.txt'." << std::endl;
    return 0;
}
