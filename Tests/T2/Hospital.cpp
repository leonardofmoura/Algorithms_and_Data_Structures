/*
 * Hospital.cpp
 */

#include "Hospital.h"
//
#include <algorithm>
#include <iostream>


Hospital::Hospital(unsigned trayC):trayCapacity(trayC)
{ }

void Hospital::addDoctor(const Doctor &d1) {
	doctors.push_back(d1);
}

list<Doctor> Hospital::getDoctors() const {
	return doctors;
}

void Hospital::addTrays(stack<Patient> tray1) {
	letterTray.push_back(tray1);
}

list<stack<Patient> > Hospital::getTrays() const {
	return letterTray;
}



unsigned Hospital::numPatients(string medicalSpecialty) const
{
	list<Doctor>::const_iterator it;
	int count = 0;

	for (it = doctors.begin(); it != doctors.end(); it++) {
		if (it->getMedicalSpecialty() == medicalSpecialty) {
			count += it->getPatients().size();
		}
	}


	return count;
}

bool doc_compare(Doctor &d1, Doctor &d2) {
	if (d1.getPatients().size() == d2.getPatients().size()) {
		if (d1.getMedicalSpecialty() == d2.getMedicalSpecialty()) {
			return d1.getCode() < d2.getCode();
		}

		return d1.getMedicalSpecialty() < d2.getMedicalSpecialty();
	}

	return d1.getPatients().size() < d2.getPatients().size();
}

void Hospital::sortDoctors() {

	doctors.sort(doc_compare);

}



bool Hospital::addDoctor(unsigned codM1, string medicalSpecialty1) {
	list<Doctor>::const_iterator it;
	int doc_count = 0;

	for (it = doctors.begin(); it != doctors.end(); it++) {
		if (it->getMedicalSpecialty() == medicalSpecialty1) {
			doc_count++;
		}
	}

	if (doc_count >= 3) {
		return false;
	}

	Doctor d1 = Doctor(codM1,medicalSpecialty1);

	doctors.push_back(d1);

	return true;

}



queue<Patient> Hospital::removeDoctor(unsigned codM1) {
	list<Doctor>::const_iterator it;
	vector<Doctor> store;

	for (it = doctors.begin(); it != doctors.end(); it++) {
		if (it->getCode() == codM1) {
			store.push_back(*it);
			doctors.erase(it);

			return store[0].getPatients();
		}
	}

	throw Hospital::DoctorInexistent();

}


bool Hospital::putInLessBusyDoctor(unsigned cod1, string medicalSpecialty1) {
	Patient pa = Patient(cod1,medicalSpecialty1);
	unsigned doc_code ;
	int less_num = 9999999;
	list<Doctor>::iterator it;
	bool found = false;

	for (it = doctors.begin(); it != doctors.end(); it++) {
		if (it->getMedicalSpecialty() == medicalSpecialty1) {
			if (it->getPatients().size() <= less_num) {
				doc_code = it->getCode();
				less_num = it->getPatients().size();
				found = true;
			}
		}
	}

	if (!found) {
		return false;
	}

	for (it = doctors.begin(); it != doctors.end(); it++) {
		if (it->getCode() == doc_code) {
			it->addPatient(pa);

			return true;
		}
	}

	return false;

}


void Hospital::processPatient(unsigned codM1) {
	list<Doctor>::iterator it;
	list<stack<Patient>>::iterator it2;
	vector<Patient> store;
	bool found = false;

	for (it = doctors.begin(); it != doctors.end(); it++) {
		if (it->getCode() == codM1) {

			try {
				store.push_back(it->removeNextPatient());
			}
			catch (Doctor::PatientInexistent &e)  {
				return;
			}

			found = true;
			break;

		}
	}

	if (!found) {
		return;
	}

	for (it2 = letterTray.begin(); it2 != letterTray.end(); it2++) {
		if (it2->size() < trayCapacity) {
			it2->push(store[0]);
			return;
		}
	}

	stack<Patient> new_tray;
	new_tray.push(store[0]);

	letterTray.push_back(new_tray);
}


unsigned Hospital::removePatients(unsigned codP1) {
	list<stack<Patient>>::iterator it;
	vector<list<stack<Patient>>::iterator> store;
	unsigned count = 0;

	for (it = letterTray.begin(); it != letterTray.end(); it++) {
		if (it->top().getCode() == codP1) {
			it->pop();

			if (it->empty()) {
				store.push_back(it);
			}

			count++;
		}
	}

	if (store.size() > 0) {
		for (int i = 0; i < store.size(); i++) {
			letterTray.erase(store[i]);
		}
	}

	return count;

}



