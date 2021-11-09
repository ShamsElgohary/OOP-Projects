/*
 * Savings.cpp
 *
 *  Created on: Oct 4, 2021
 *      Author: Shams
 */

#include "Savings.h"

Savings::Savings(const std::string &name, double balance, float rate) : Account(name, balance), m_Rate(rate) {

}

Savings::~Savings() {

}

float Savings::GetInterestRate() const {
	return m_Rate;
}

void Savings::AccumulateInterest() {
	m_Balance += (m_Balance * m_Rate);
}
