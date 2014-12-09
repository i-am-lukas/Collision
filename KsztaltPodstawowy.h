#include <string>
using namespace std;
class KsztaltPodstawowy{
public:
	string identyfikator;
	virtual void PrintMe() = 0;
	virtual void przesun(double = 0, double = 0) = 0;
	virtual void obroc(double = 0) = 0;
	virtual bool czyKoliduje(KsztaltPodstawowy &) = 0;
};