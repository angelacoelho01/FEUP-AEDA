#include "Bank.h"

Bank::Bank() {}

void Bank::addAccount(Account *a) {
	accounts.push_back(a);
}

void Bank::addBankOfficer(BankOfficer b){
	bankOfficers.push_back(b);
}

vector<BankOfficer> Bank::getBankOfficers() const {
	return bankOfficers;
}

vector<Account *> Bank::getAccounts() const {
	return accounts;
}


// ----------------------------------------------------------------------------------------------


double Bank::getWithdraw(string cod1) const{
    double total = 0;
	for(const auto & account : accounts){
	    if(account->getCodH() == cod1)
            total += account->getWithdraw();
	}
	return total;
}

vector<Account *> Bank::removeBankOfficer(string name){
	vector<Account *> officerAccounts;
    for(auto it = bankOfficers.begin(); it != bankOfficers.end(); it++){
        if(it->getName() == name){
            officerAccounts = it->getAccounts();
            bankOfficers.erase(it);
            return officerAccounts;
        }
    }
    return officerAccounts;
}

const BankOfficer & Bank::addAccountToBankOfficer(Account *ac, string name) {
    for(auto it = bankOfficers.begin(); it != bankOfficers.end(); it++){
        if(name == it->getName()) {
            it->addAccount(ac);
            return *it;
        }
    }
    throw NoBankOfficerException(name);
}

void Bank::sortAccounts() {
    sort(accounts.begin(), accounts.end(), [](Account* ac1, Account* ac2){
        if(ac1->getBalance() == ac2->getBalance())
            return ac1->getCodIBAN() < ac2->getCodIBAN();
        return ac1->getBalance() < ac2->getBalance();
    });
}

