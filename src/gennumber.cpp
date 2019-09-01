#include "gennumber.h"

GenNumber::GenNumber()
{
}

void GenNumber::getVector(int number, vector<int> &vecNumber)
{
    double tmp_num = number;
    do {
        vecNumber.push_back(tmp_num - (int)(tmp_num/10)*10 );
        tmp_num = (int)(tmp_num/10);
    }while(tmp_num != 0);
}

void GenNumber::getTimeVector(int number, vector<int> &vecNumber)
{
    double tmp_num = number;
    int min = (int)(tmp_num/60);
    tmp_num -= (min * 60);
    if (tmp_num<10)
    {
      vecNumber.push_back(tmp_num);
      vecNumber.push_back(0);
    } else
    {
        do {
            vecNumber.push_back(tmp_num - (int)(tmp_num/10)*10 );
            tmp_num = (int)(tmp_num/10);
        }while(tmp_num != 0);
    }
    vecNumber.push_back(-1);
    if (min < 10)
    {
      vecNumber.push_back(min);
      vecNumber.push_back(0);
    }
    else
    {
        tmp_num = min;
        do {
            vecNumber.push_back(tmp_num - (int)(tmp_num/10)*10 );
            tmp_num = (int)(tmp_num/10);
        }while(tmp_num != 0);
    }
}

void GenNumber::getNumber(int number, vector<UIElements*> &vecElements, bool isTime)
{
    vector<int> vecNumber;
    string str = "/home/roman/Desktop/OpenGL_Practice_FULL/res/Menu/Numbers/";
    string tmp;
    if (isTime)
        getTimeVector(number,vecNumber);
    else
        getVector(number,vecNumber);
    vecElements.clear();
    for (int i=0; i<vecNumber.size(); i++)
    {
        if (vecNumber[vecNumber.size()-1-i] == -1)
            tmp = str + "space.png";
        else
            tmp = str + to_string(vecNumber[vecNumber.size()-1-i])+".png";
        vecElements.push_back(new UIElements(tmp.c_str(),0,0,0.5,0.5));
        vecElements[i]->move(i*15,0);
        tmp.clear();
    }
}
