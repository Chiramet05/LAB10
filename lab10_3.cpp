#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream> 

using namespace std;

int main()
{
    int count = 0;            
    float sum = 0.0;          
    float sum_of_square = 0.0; 
    string textline;
    ifstream source("score.txt");
    if (!source)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    while (getline(source, textline))
    {
        float score = stof(textline);  
        sum += score;                   
        sum_of_square += score * score; 
        count++;                        
    }
    float mean = sum / count;
    float variance = (sum_of_square / count) - (mean * mean);
    float standard_deviation = sqrt(variance);
    cout << "Number of data = " << count << "\n";
    stringstream ss;
    ss << fixed << setprecision(3) << mean;
    string mean_str = ss.str();
    if (mean_str[mean_str.size() - 1] == '0')
    {
        mean_str = mean_str.substr(0, mean_str.size() - 1); 
    }
    if (mean_str[mean_str.size() - 1] == '0')
    {
        mean_str = mean_str.substr(0, mean_str.size() - 1);
    }
    cout << "Mean = " << mean_str << "\n";
    ss.str("");
    ss << fixed << setprecision(3) << standard_deviation;
    string sd_str = ss.str();
    if (sd_str[sd_str.size() - 1] == '0')
    {
        sd_str = sd_str.substr(0, sd_str.size() - 1);
    }
    if (sd_str[sd_str.size() - 1] == '0')
    {
        sd_str = sd_str.substr(0, sd_str.size() - 1);
    }
    cout << "Standard deviation = " << sd_str << "\n";

    source.close();
    return 0;
}