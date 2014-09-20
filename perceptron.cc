#include "perceptron.h"

#include <fstream>
#include <strstream>
#include <iostream>
#include <ctime>

using namespace std;

Perceptron::Perceptron(){}
Perceptron::~Perceptron(){}

bool Perceptron::Init()
{
	return true;
}
bool Perceptron::Init(const string &modelfilename)
{
	ifstream fin(modelfilename.c_str());

        if (!fin)
        {
                cerr << "Can not open file: " << modelfilename << endl;
                return false;
        }
        string line;
        while (getline(fin, line))
        {
                if (line.empty())
                {
                        continue;
                }
                int pos = line.find_last_of(" ");
                m_model[line.substr(0,pos)] = atoi(line.substr(pos+1).c_str());
        }
        return Init();
}
void Perceptron::Update(const map<string, double> &updates)
{
	map<string, double>::const_iterator it;
	for(it = updates.begin(); it != updates.end(); it ++)
	{
		if(m_model.find(it->first) == m_model.end())
		{
			m_model[it->first] = it->second;
		}
		else
		{
			m_model[it->first] += it->second;
		}
	}

}

double Perceptron::GetFeatureValue(const string &key)
{
	map<string, double>::iterator it = m_model.find(key);

	if (it != m_model.end())
	{
		return it->second;
	}
	else
	{
		return 0.0;
	}
}
bool Perceptron::SaveModel(const string &filename)
{
	ofstream fout(filename.c_str());
	if (!fout)
	{
		cout << "Can not open file: " << filename << endl;
		return false;
	}

	map<string, double>::iterator it;

	for (it = m_model.begin(); it != m_model.end(); ++it)
	{
		fout << it->first << " " << it->second << endl;
	}

	fout.close();
	return true;
}
