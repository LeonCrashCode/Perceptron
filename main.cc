#include <iostream>
#include <map>
#include <string>
#include "perceptron.h"

using namespace std;

int main()
{
	Perceptron perceptron;
	perceptron.Init();
	map<string,double> updates;
	updates["abc"] = 0.4;
	updates["abc"] = 0.5;
	updates["bcd"] = -2.3;
	
	cout<<"ok"<<endl;
	perceptron.Update(updates);
	perceptron.SaveModel("model");
	return 0;
}
