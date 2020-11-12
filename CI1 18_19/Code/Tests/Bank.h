#ifndef SRC_BANK_H_
#define SRC_BANK_H_

#include "Account.h"
#include "BankOfficer.h"

#include <vector>
#include <algorithm>
#include <string>


template <class T>
unsigned  int numberDifferent(const vector<T>& v1){
    std::vector<T> temp;
    for(const auto & element : v1){
        if(std::find(temp.begin(), temp.end(), element) == temp.end())
            temp.push_back(element);
    }
    return temp.size();
}

class Bank {
	vector<Account *> accounts;
	vector<BankOfficer> bankOfficers;
public:
	Bank();
	void addAccount(Account *a);
	void addBankOfficer(BankOfficer b);
	vector<BankOfficer> getBankOfficers() const;
	vector<Account *> getAccounts() const;

	//-------
	double getWithdraw(string cod1) const;
	vector<Account *> removeBankOfficer(string name);
	const BankOfficer& addAccountToBankOfficer(Account *ac, string name);
	void sortAccounts();
};


class NoBankOfficerException{
private:
    string _name;
public:
    NoBankOfficerException(string name):_name(name){}
    string getName()const{return _name;}
};

#endif /* SRC_BANK_H_ */
