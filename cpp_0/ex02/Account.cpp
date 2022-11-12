# include "Account.hpp"
# include <iostream>
# include <ctime>

Account::Account( int initial_deposit ) {
	this->_accountIndex		= Account::_nbAccounts;
	this->_amount			= initial_deposit;
	this->_nbDeposits		= 0;
	this->_nbWithdrawals	= 0;
	Account::_totalAmount	+= initial_deposit;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	return ;
}

Account::~Account() {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	Account::_nbAccounts--;
	return ;
}

int	Account::getNbAccounts() {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount() {
	return Account::_totalAmount;
}

int Account::getNbDeposits() {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals() {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount()
	<< ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount <<
	";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << ++this->_nbDeposits << std::endl;
	this->_amount			+= deposit;
	Account::_totalAmount	+= deposit;
	Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (this->_amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount - withdrawal
	<< ";withdraws:" << ++this->_nbWithdrawals << std::endl;
	this->_amount 			-= withdrawal;
	Account::_totalAmount	-= withdrawal;
	Account::_totalNbWithdrawals++;
	return true;
}

int	Account::checkAmount() const {
	std::cout << "au au" << std::endl;
	return 0;
}

void Account::displayStatus() const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << 
	";deposits:" << this->_nbDeposits << ";withdraws:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp() {	
	char			buf[50];
	std::time_t 	now 			= std::time(&now);
	tm				ts 				= *localtime(&now);

	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &ts);
	std::cout << "[" << buf << "] ";
}

int Account::_totalNbDeposits = 0, Account::_totalAmount = 0,
	Account::_totalNbWithdrawals = 0, Account::_nbAccounts = 0;