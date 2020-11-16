/*
 * Doctor.cpp
 */

#include "Doctor.h"
#include <iostream>


Patient::Patient(unsigned codP, string mS): codeP(codP), medicalSpecialty(mS)
{}

string Patient::getMedicalSpecialty() const {
	return medicalSpecialty;
}

unsigned Patient::getCode() const {
	return codeP;
}

Doctor::Doctor(unsigned codM, string mS): codeM(codM), medicalSpecialty(mS)
{}


Doctor::Doctor(unsigned codM, string mS, queue<Patient> patients1): codeM(codM), medicalSpecialty(mS), patients(patients1)
{}

unsigned Doctor::getCode() const {
	return codeM;
}

string Doctor::getMedicalSpecialty() const {
	return medicalSpecialty;
}

queue<Patient> Doctor::getPatients() const {
	return patients;
}

void Doctor::addPatient(const Patient &p1) {
	patients.push(p1);
}

Patient Doctor::removeNextPatient() {
	if (!patients.empty()) {
		Patient p1 = patients.front();
		patients.pop();
		return p1;
	}
	else throw PatientInexistent();
}




void Doctor::moveToFront(unsigned codP1) {
		queue<Patient> temp;
		vector<Patient> store;
		bool found = false;

		while (!patients.empty()) {
			if (patients.front().getCode() == codP1) {
				store.push_back(patients.front());
				patients.pop();
				found = true;
			}
			else {
				temp.push(patients.front());
				patients.pop();
			}
		}

		if (found) {
			patients.push(store[0]);

			while(!temp.empty()) {
				patients.push(temp.front());
				temp.pop();
			}

		}
		else {
			while(!temp.empty()) {
				patients.push(temp.front());
				temp.pop();
			}
		}

}

