#ifndef CERTIFICATE_H
#define CERTIFICATE_H

#include <iostream>
#include "base.h"

using namespace std;

class Certificate {
private:
    string certificateID;
    string certificateName;
    string certificateRank;
    string certificateDate;
public:
    Certificate();
    
    ~Certificate();

    void setCertificateID(string certificateID);
    string getCertificateID();

    void setCertificateName(string certificateName);
    string getCertificateName();

    void setCertificateRank(string certificateRank);
    string getCertificateRank();

    void setCertificateDate(string certificateDate);
    string getCertificateDate();

    void showCert();
    void inputCert();
};

#endif
