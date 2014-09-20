#ifndef PERCEPTRON_H_
#define PERCEPTRON_H_
#include <fstream>
#include <map>
#include <string>
using namespace std;

class Perceptron
{
public:
	Perceptron();
	~Perceptron();
	map<string, double> m_model;
	bool Init();
	bool Init(const string &modefilename);	
	void Update(const map<string, double> &updates);
	double GetFeatureValue(const string &key);
	bool Loadparameter(const string &filename);
	bool SaveModel(const string &filename);

private:
	map<string, double> m_LRUcache_;

};

#endif
