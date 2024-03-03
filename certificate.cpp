#ifndef CERTIFICATE_CPP
#define CERTIFICATE_CPP


#include "certificate.h"

Certificate::Certificate() { 

}
Certificate::~Certificate() {
}

void Certificate::setCertificateID(string certificateID) {
    this->certificateID = certificateID;
}

string Certificate::getCertificateID(){
    return certificateID;
}

void Certificate::setCertificateName(string certificateName){
    this->certificateName = certificateName;
}

string Certificate::getCertificateName(){
    return certificateName;
}

void Certificate::setCertificateRank(string certificateRank){
    this->certificateRank = certificateRank;
}

string Certificate::getCertificateRank(){
    return certificateRank;
}

void Certificate::setCertificateDate(string certificateDate){
    this->certificateDate = certificateDate;
}

string Certificate::getCertificateDate(){
    return certificateDate;
}
void Certificate::showCert()
{
    cout << " Certificate ID: " << getCertificateID() << endl;
    cout << " Certificate Name: " << getCertificateName() << endl;
    cout << " Certificate Rank: " << getCertificateRank() << endl;
    cout << " Certificate Date: " << getCertificateDate() << endl;
}

void Certificate::inputCert()
{
    cout << " Enter certificate ID: ";
    getline(cin, certificateID);

    cout << " Enter certificate Name: ";
    getline(cin, certificateName);

    cout << " Enter certificate Rank: ";
    getline(cin, certificateRank);

    cout << " Enter certificate Date: ";
    getline(cin, certificateDate);
}


#endif
